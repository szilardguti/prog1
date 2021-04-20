#include "std_lib_facilities.h"

struct Item {
	Item(): name{"NA"}, iid{-1}, value{-1} {}
	Item(std::string n, int id, double v): name{n}, iid{id}, value{v} {}

	std::string name;
	int iid;
	double value;
};

std::ostream& operator<< (std::ostream& os, Item& i)
{
	os << i.name << '\t' << i.iid << '\t' << i.value;

	return os;
}

std::istream& operator>> (std::istream& is, Item& i)
{
	if(!(is >> i.name >> i.iid >> i.value ))
		std::cerr << "Error in Item istream operator\n";

	return is;
}

bool operator== (const Item& a, const Item& b)
{
	if(a.iid == b.iid || a.name == b.name) return true;

	return false;
}

template <typename T>
void my_print(T& t)
{
	for(auto& a : t)
		std::cout << a << std::endl;
}


int main()
{
	vector<Item> vi;
	list<Item> li;

	std::ifstream ifs ("Items.txt");

	for(int i = 0; i < 10; ++i)
	{
		Item tempI;
		ifs >> tempI;

		vi.emplace_back(tempI);
		li.emplace_back(tempI);
	}
	ifs.close();

	std::cout << "original condition:\n";
	my_print(vi);
	
	std::cout << "\nsort by name:\n";
	sort(vi.begin(), vi.end(), [](Item& a, Item& b){ return a.name < b.name ; });
	my_print(vi);

	std::cout << "\nsort by iid:\n";
	sort(vi.begin(), vi.end(), [](Item& a, Item& b){ return a.iid < b.iid ; });
	my_print(vi);

	std::cout << "\nsort by value:\n";
	sort(vi.begin(), vi.end(), [](Item& a, Item& b){ return a.value > b.value ; });
	my_print(vi);

	std::cout << "\ninsert items:\n";
	vi.emplace_back(Item("horse shoe", 99, 12.34));
	vi.emplace_back(Item("Canon S400", 9988, 499.95));
	my_print(vi);

	std::cout << "\nremove by name:\n";

	Item search;
	search.name = "gyurka";
	vi.erase(find(vi.begin(), vi.end(), search));
	search.name = "kőőő";
	vi.erase(find(vi.begin(), vi.end(), search));

	my_print(vi);

	std::cout << "\nremove by iid:\n";
	search.name = "NA";
	search.iid = 69;
	vi.erase(find(vi.begin(), vi.end(), search));
	search.iid = 20;
	vi.erase(find(vi.begin(), vi.end(), search));

	my_print(vi);

	std::cout << "/////////////////////////list/////////////////////////\n";

	li.sort([](Item& a, Item& b){ return a.name < b.name ; });
	li.sort([](Item& a, Item& b){ return a.iid < b.iid ; });
	li.sort([](Item& a, Item& b){ return a.value > b.value ; });

	li.emplace_back(Item("horse shoe", 99, 12.34));
	li.emplace_back(Item("Canon S400", 9988, 499.95));

	search.iid = -1;
	search.name = "gyurka";
	li.erase(find(li.begin(), li.end(), search));
	search.name = "kőőő";
	li.erase(find(li.begin(), li.end(), search));
	search.name = "NA";
	search.iid = 69;
	li.erase(find(li.begin(), li.end(), search));
	search.iid = 20;
	li.erase(find(li.begin(), li.end(), search));

	my_print(li);

	return 0;
}