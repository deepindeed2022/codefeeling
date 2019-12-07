#include <iostream>
class A
{
public:
	A(){
		std::cout << "A DefaultCtor called\n";
	}
	A(const A& rhs) {
		std::cout << "A CopyCtor called\n";
	}
	~A(){}
	
};

// class B
// {
// public:
// 	B(){
// 		std::cout << "B DefaultCtor called\n";
// 	}
// 	B(const B& rhs) {
// 		std::cout << "B CopyCtor called\n";
// 	}
// 	~B(){}
	
// };


class DevideA: public A
{
public:
	DevideA() {
		std::cout << "DevideA DefaultCtor called\n";
	}
	DevideA(const DevideA& rhs) {
		std::cout << "DevideA CopyCtor called\n";
	}
	~DevideA(){}
	
};

TEST(cpp_concept, copy_ctor)
{
	std::cout << "-- init da1" << std::endl;
	DevideA da1;
	std::cout << "-- init da2" << std::endl;
	DevideA da2 = da1;
}
/*********************************************
expect output as following:
-- init da1
A DefaultCtor called
B DefaultCtor called
DevideA DefaultCtor called
-- init da2
A DefaultCtor called
B DefaultCtor called
DevideA CopyCtor called
*********************************************/