#include <iostream>
#include <map>
#include <string>

template <typename T1, typename T2>
std::ostream& operator<< (std::ostream& os, std::pair<T1,T2>& p)
{
	os << p.first << ' ' << p.second;

	return os;
}

template <typename T1, typename T2>
std::istream& operator>> (std::istream& is, std::pair<T1,T2>& p)
{
	is >> p.first >> p.second;

	return is;
}

template <typename T>
void my_print(T& t)
{
	for(auto& a : t)
		std::cout << a << std::endl;
}


int main()
{
	std::map<std::string,int> msi;

	std::string test = "a";
	for(int i = 0; i < 10; ++i)
	{
		msi.insert(std::pair<std::string,int>(test, i + 1 ));
		test += "a";
	}

	my_print(msi);

	msi.erase(msi.begin(), msi.end());

	std::cout << "erase is done!\n";
	my_print(msi);

	std::cout << "please write 10 <string,int> pair!\n";

	for(int i = 0;i < 10; ++i)
	{
		std::pair<std::string, int> p;
		std::cin >> p;
		msi.insert(p);
	}

	std::cout << "elements of msi:\n";
	my_print(msi);

	int msi_sum = 0;
	std::map<std::string,int>::iterator it;
	for(it = msi.begin(); it != msi.end(); ++it)
		msi_sum += it->second;

	std::cout << "sum of integers in msi:\t" << msi_sum << std::endl;


	std::map<int,std::string> mis;
	for(it = msi.begin(); it != msi.end(); ++it)
	{
		std::pair<int, std::string> p {it->second, it->first};
		mis.insert(p);
	}

	my_print(mis);

	return 0;
}