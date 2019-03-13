#include <iostream>
class A {
public:
	A() {
		std::cout << "A is created." << std::endl;
	}
	~A() {
		std::cout << "A is deleted." << std::endl;
	}
};

class B : public A {
public:
	B() {
		std::cout << "B is created." << std::endl;
	}
	~B() {
		std::cout << "B is deleted." << std::endl;
	}
};

int main(int argc, char* argv[])
{
	A* pA = new B();
	delete pA;
	return 0;
}
//
// 答案：输出三行，分别是：A is created. B is created. A is deleted。
//
// 用new创建B时，回调用B的构造函数。在调用B的构造函数的时候，会先调用A的构造函数。因此先输出A is created. B is created.
// 接下来运行delete语句时，会调用析构函数。由于pA被声明成类型A的指针，同时基类A的析构函数没有标上virtual，
// 因此只有A的析构函数被调用到，而不会调用B的析构函数。
// 由于pA实际上是指向一个B的实例的指针，但在析构的时候只调用了基类A的析构函数，却没有调用B的析构函数。
// 这就是一个问题。如果在类型B中创建了一些资源，比如文件句柄、内存等，在这种情况下都得不到释放，从而导致资源泄漏。