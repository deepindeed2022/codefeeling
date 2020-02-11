#include <iostream>
using namespace std;

struct Base {
	int j;
	virtual void f() {std::cout << "Base::f()\n";}
};

struct Derived: Base {
	void f() {
		std::cout << "Derived::f()\n";
	}
};

void placement_new_test1()
{
	Base b;
	b.f();
	b.~Base();
	new (&b) Derived;
	b.f();
}