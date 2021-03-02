#include <iostream>

using namespace std;

void var_name(string str) { cout << str << ":\n"; }

class B {
public:
	virtual void pvf() = 0;
};

struct B1 : B {
	virtual void vf() const { cout << "B1::vf()\n"; }
	void f() const { cout << "B1::f()\n"; }
	void pvf() { cout << "B1::pvf()\n"; }
};

struct D1 : B1 {
	void vf() const override { cout << "D1::vf()\n"; }
	void f() const { cout << "D1::f()\n"; }
	void pvf() { cout << "D1::pvf()\n"; }
};

struct D2 : D1 {
	void pvf() { cout << "D2::pvf()\n"; }
};

class B2 {
public:
	virtual void pvf() = 0;
};

struct D21 : B2 {

	void pvf() override { cout << str << endl; }
private:
	string str = "Hello from D21::pvf()!";
};

struct D22 : B2 {
	void pvf() override { cout << i << endl; }
private:
	int i = 21;
};

void f(const B2& b2ref)
{ 
	b2ref.pvf();
}

int main()
{
	var_name("b");
	B1 b;
	b.vf();
	b.f();
	b.pvf();

	var_name("d");
	D1 d;
	d.vf();
	d.f();
	d.pvf();

	var_name("bref");
	B1& bref = d;
	bref.vf();
	bref.f();
	bref.pvf();

	var_name("d2");
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	var_name("7. feladat");
	D21 d21;
	D22 d22;

	f(d21);
	f(d22);

	return 0;
}