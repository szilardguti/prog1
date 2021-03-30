#include "std_lib_facilities.h"

template<typename T> struct S
{
	S() {}
	S(T v): val{v} {}

	T& get(); 
	const T& get() const;

	void set(T t) { val = t; }
	S& operator= (const T& t) { val = t; return *this; }

	friend istream& operator>> (istream& is, S<T>& t)
	{
		is >> t.val;
		return is;
	}

private:
	T val;
};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
const T& S<T>::get() const
{
	return val;
}

template<typename T>
void read_val(T& v)
{
	cin >> v;
}

int main()
try
{
	S<int> si {5};
	si.set(17);
	cout << si.get() << endl << "new sint: ";
	read_val(si);
	cout << si.get() << endl;

	S<char> sc {'y'};
	cout << sc.get() << endl << "new schar: ";
	read_val(sc);
	cout << sc.get() << endl;

	S<double> sd {1.234};
	cout << sd.get() << endl << "new sdouble: ";
	read_val(sd);
	cout << sd.get() << endl;
	
	S<string> sstr {"hola"};
	cout << sstr.get() << endl;

	S<vector<int>> sivec {vector<int>(10,0)};
	for(auto i : sivec.get())
	cout << i << endl;
	
	return 0;

}catch(exception& e)
{
	cerr << e.what() << endl;
}catch(...)
{
	cerr << "F\n"; 
}