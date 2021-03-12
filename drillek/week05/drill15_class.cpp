#include "std_lib_facilities.h"

struct Person
{
	Person(string fname = "Senk", string lname = "Imre", int inage = 0): firstname{fname}, lastname{lname}, p_age{inage} 
	{
		isvalid_age(p_age);
		isvalid_name(firstname);
		isvalid_name(lastname);
	} 

	string name() const { return firstname + " " + lastname; }
	int age() const { return p_age; }

	void set_fname(string str) { firstname = str; }
	void set_lname(string str) { lastname = str; }
	void set_age(int i) { p_age = i; }

	void isvalid_age(int age);
	void isvalid_name(string& name);

private:
	string firstname;
	string lastname;
	int p_age;


};

ostream& operator << (ostream& out, Person& per)
{
	out << "Name: " << per.name();
	out << "\tAge: " << per.age();

	return out;
}

istream& operator >> (istream& in, Person& per)
{
	int tempi;
	string tempstr1, tempstr2;

	in >> tempstr1;
	per.set_fname(tempstr1);
	per.isvalid_name(tempstr1);

	in >> tempstr2;
	per.set_lname(tempstr2);
	per.isvalid_name(tempstr2);

	in >> tempi;
	per.set_age(tempi);
	per.isvalid_age(tempi);

	return in;
}

int main()
{
	Person bela {"Bela", "Bena", 72};
	cout << bela << endl;

	Person noone;
	cout << noone << endl;

	//Person error1 {"Er:ror J4n!", 20};
	//Person error2 {"Gyulus", -17};


	vector<Person> group;
	for(int i = 0; i < 5; ++i)
	{
		Person temp;
		cin >> temp;

		group.push_back(temp);
	}

	for(Person& p : group)
		cout << p << endl;

	return 0;
}

void Person::isvalid_age(int i)
{
	if(i < 0 || i >= 150) error("Age is out of bound!\n");
}

void Person::isvalid_name(string& str)
{
	for(int i = 0; i < str.length(); ++i)
		if(!isalpha(str[i])) error("Name contains invalid character!\n");
}