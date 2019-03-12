/**************************************************************************
 * 测试cv-qualifier不能使用的情况。
 * 
 * 有两种情况下不能使用cv-qualifier（即const和volatile限定）
 * 1. 非成员函数
 * 2. static成员函数
**************************************************************************/
#include <iostream>
double getVolume() const { // error: non-member function ‘double getVolume()’ cannot have cv-qualifier
    return 0.0;
}
class A {
public:
	static int value() const { // error: static member function ‘static int A::value()’ cannot have cv-qualifier
		return 1;
	}
};

int main(int argc, char const *argv[])
{
	A a;
	std::cout << a.value() << std::endl;
	return 0;
}
