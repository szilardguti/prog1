#include "std_lib_facilities.h"
//TODO: -MEMORY LEAKS!	-INSERT,ERASE

template <typename Elem>
struct Link
{
	Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0): prev{p}, succ{s}, val{v} {}

	Link* prev;
	Link* succ;	
	Elem val;


	void printL() { cout << val << ' ' << prev << ' ' << succ << endl; } 
};

template <typename Elem>
class mylist
{
private:
	Link<Elem>* first;
	Link<Elem>*	last; //one beyond the last link!
public:
	mylist(): first(new Link<Elem>()), last(first) {}

	class iterator;

	iterator begin() { return iterator(first); }	// iterator to first element
	iterator end( ) { return iterator(last); }	// iterator to one beyond last element
	iterator lastly() { return iterator(last->prev); } // iterator to the LAST element

	iterator insert(iterator p, const Elem& v);// insert v into list after p
	iterator erase(iterator p);// remove p from the list

	void push_back(const Elem& v);// insert v at end
	void push_front(const Elem& v);// insert v at front
	void pop_front();// remove the first element
	void pop_back();// remove the last element

	Elem& front() { return *begin(); }
	Elem& back() { return *lastly(); }

	void debug()
	{
		iterator p(first);
		while(p != end())
		{
			p.print_debug();
			++p;
		}
		cout << "one-and-beyond support Link: "; p.print_debug();
	}

};

template<typename Elem>
class mylist<Elem>::iterator 
{
	Link<Elem>* curr;	
public:
	iterator(Link<Elem>* p) :curr{p} { }
	~iterator() { cout << "Iterator destructor called!\n"; } 

	iterator& operator++() {curr = curr->succ; return *this; } // forward
	iterator& operator--() { curr = curr->prev; return *this; } // backward

	Elem& operator*() { return curr->val; } // get value (dereference)

	bool operator==(const iterator& b) const { return curr==b.curr; }
	bool operator!= (const iterator& b) const { return curr!=b.curr; }

	void print_debug() { cout << curr << ": " << '\t' << curr->val << '\t' << curr->prev << '\t' << curr->succ << endl; }
};

template<typename Elem>
void mylist<Elem>::push_front(const Elem& v)
{
	first = new Link<Elem>(v, 0, first);
	if(last != first)
		first->succ->prev = first;
}

template<typename Elem>
void mylist<Elem>::push_back(const Elem& v)
{

	last->prev = new Link<Elem>(v, last->prev, last);
	if(last == first) first = last->prev;
		else last->prev->prev->succ = last->prev;
}

template<typename Elem>
void mylist<Elem>::pop_front()
{
	if(first != last)
	{
		first = first->succ;
		first->prev = 0;
	}
}

template<typename Elem>
void mylist<Elem>::pop_back()
{
	if(first != last)
	{
		last->prev->prev->succ = last;
		last->prev = last->prev->prev;
	}
}


int main()
{
	mylist<int> ml;

	for(int k = 0; cin >> k; )
		{ ml.push_back(k);}

	ml.debug();

	ml.pop_front();

	ml.debug();

	ml.pop_back();

	ml.debug();	

	//cout << ml.front() << '\t' << ml.back() << endl;

	return 0;
}