#include <cstdio>
class A
{
public:
	A() {
		printf("%s\n", "A construct");
	}
	virtual void test() {
		fprintf(stderr, "%s\n", "this in A::test");
	}
	
};

class B: public A
{
public:
	B(){}
	virtual void test() {
		fprintf(stderr, "%s\n", "this in B::test");
	}	
};
int main(int argc, char const *argv[])
{
	A* a = new B();
	a->test();
	return 0;
}