#include <gtest/gtest.h>
#include <iostream>
class A
{
private:
	int n1;
	int n2;
public:
	A(): n2(0), n1(n2 + 2) {}
	void Print(){
	    std::cout << "n1: " << n1 << ", n2: " << n2 << std::endl;
	}
	int get_n1() { return n1; }
	int get_n2() { return n2; }
};
TEST(cpp_concept, init_class_param)
{
	A a;
	// a.Print();
	ASSERT_NE(2, a.get_n1());
	ASSERT_EQ(0, a.get_n2());
	
}
/*****************************************************************************
	答案：输出n1是一个随机的数字，n2为0。
	在C++中，成员变量的初始化顺序与变量在类型中的申明顺序相同，而与它们在构造函数的初始化列表中的顺序无关。
	因此在这道题中，会首先初始化n1，而初始n1的参数n2还没有初始化，是一个随机值，因此n1就是一个随机值。
	初始化n2时，根据参数0对其初始化，故n2=0。
 *****************************************************************************/