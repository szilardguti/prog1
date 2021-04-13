#include "std_lib_facilities.h"

template <typename T>
void printer (T& t)
{
	for(auto& i : t)
		cout << i << '\t';
	cout << endl;
}

template <typename Iter1, typename Iter2> //copies Iter1 into Iter2
Iter2 mycopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(f1 != e1)
	{
		*f2 = *f1;
		f1++; f2++;
	}

	return f2;
}

int main()
{
	int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	vector<int> vec1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	list<int> ls1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


	int arr2[10];
	for(int i = 0; i < 10; ++i) arr2[i] = arr1[i];

	vector<int> vec2 = vec1;

	list<int> ls2 = ls1;


	for(auto& i : arr2) i += 2;

	for(auto& i : vec2) i += 3;

	for(auto& i : ls2) i += 5;

	cout << "initial condition:\n";
	cout << "arrays: \n";
	printer(arr1);
	printer(arr2);

	cout << "vectors: \n";
	printer(vec1);
	printer(vec2);

	cout << "lists: \n";
	printer(ls1);
	printer(ls2);

	mycopy(arr2, &arr2[10], vec1.begin());
	mycopy(ls2.begin(), ls2.end(), arr1);


	cout << "\nafter the copies:\n";
	cout << "arrays: \n";
	printer(arr1);
	printer(arr2);

	cout << "vectors: \n";
	printer(vec1);
	printer(vec2);

	cout << "lists: \n";
	printer(ls1);
	printer(ls2);


	//////vector find//////
	vector<int>::iterator it = find(vec1.begin(), vec1.end(), 3);
	if(it != vec1.end()) cout << "value found at this position: " << distance(vec1.begin(), it) << endl;
		else cout << "the value is not in the vector!:(\n";

	//////list find//////
	list<int>::iterator itl = find(ls1.begin(), ls1.end(), 27);
	if(itl != ls1.end()) cout << "value found at this position: " << distance(ls1.begin(), itl) << endl;
		else cout << "the value is not in the list!:(\n";


	return 0;
}