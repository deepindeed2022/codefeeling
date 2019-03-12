#include <cstdio>
class A
{
private:
	int m_value;
public:
	A(int value)
	{
		m_value = value;
	}
	void Print1()
	{
		fprintf(stderr, "hello world\n");
	}
	virtual void Print2()
	{
		fprintf(stderr, "hello world\n");
	}
};

int main(int argc, char* argv[])
{
	A* pA = NULL;
	pA->Print1();
	pA->Print2();
	return 0;
}
/*
分析：答案是Print1调用正常，打印出hello world，但运行至Print2时，程序崩溃。
Print1的调用情况和上面的题目一样，不在赘述。
由于Print2是虚函数。C++调用虚函数的时候，要根据实例（即this指针指向的实例）中虚函数表指针得到虚函数表，
再从虚函数表中找到函数的地址。由于这一步需要访问实例的地址（即this指针），而此时this指针为空指针，因此导致内存访问出错。
*/