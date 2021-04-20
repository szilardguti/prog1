#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
	std::vector<double> vd;

	std::ifstream ifs("Floats.txt");

	while(!ifs.eof())
	{
		double tempd;
		ifs >> tempd;

		if(tempd != ' ') vd.push_back(tempd);
	}
	ifs.close();


	std::vector<int> vi(vd.size(), 0);
	copy(vd.begin(), vd.end(), vi.begin());

	for(int i = 0;i < vd.size(); ++i)
		std::cout << vd[i] << '\t' << vi[i] << std::endl;

	double vd_sum = std::accumulate(vd.begin(), vd.end(), 0.0);
	std::cout << "sum of vd:\t" << vd_sum << std::endl;

	std::cout << "difference between the two sum:\t" << 
		vd_sum - std::accumulate(vi.begin(), vi.end(), 0) << std::endl;

	std::cout << "reversed vd: ";
	std::reverse(vd.begin(), vd.end());
	for(auto& d : vd)
		std::cout << d << ' ';

	double vd_avg = vd_sum/vd.size();
	std::cout << "\nmean value of vd:\t" << vd_avg << std::endl;

	int n = 0;
	for(int i = 0; i < vd.size(); ++i) if(vd[i] < vd_avg) ++n;
	std::vector<double> vd2(n, 0);

	std::copy_if(vd.begin(), vd.end(), vd2.begin(), [vd_avg](double x){ return x < vd_avg; });
	std::cout << "less than mean number (vd2): ";
	for(auto& d : vd2)
		std::cout << d << ' ';
	std::cout << std::endl;


	sort(vd.begin(), vd.end());
	std::cout << "sorted vd: ";
	for(auto& d : vd)
		std::cout << d << ' ';
	std::cout << std::endl;


	return 0;
}