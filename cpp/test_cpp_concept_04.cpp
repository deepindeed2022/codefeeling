#include <cstdio>
class A {
public:
	A(int value) {
		m_value = value;
	}

	void Print1() {
		fprintf(stderr, "hello world\n");
	}
	
	void Print2() {
		fprintf(stderr, "%d\n", m_value);
	}
private:
	int m_value;
};

int main(int argc, char* argv[])
{
	A* pA = NULL;
	
	pA->Print1();

	pA->Print2();
	return 0;
}
/**************************************************************************
答案:
Print1调用正常，打印出hello world，但运行至Print2时，程序崩溃。
分析：
调用Print1时，并不需要pA的地址，因为Print1的函数地址是固定的。编译器会给Print1传入一个this指针，该指针为NULL，
但在Print1中该this指针并没有用到。只要程序运行时没有访问不该访问的内存就不会出错，因此运行正常。
在运行print2时，需要this指针才能得到m_value的值。由于此时this指针为NULL，因此程序崩溃了。
**************************************************************************/