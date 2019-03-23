#include <iostream>
#include <gtest/gtest.h>
class A {
public:
    virtual void Fun(int number = 10) {
        std::cout << "A::Fun with number " << number<< std::endl;
    }
};
class B: public A
{
public:
    virtual void Fun(int number = 20) {
        std::cout << "B::Fun with number " << number << std::endl;
    }
};

TEST(cpp_concept, default_value)
{
    B b;
    A &a = b;
    a.Fun();
}

// 答案：输出B::Fun with number 10
// 由于a是一个指向B实例的引用，因此在运行的时候会调用B::Fun
// 但缺省参数是在编译期决定的。在编译的时候，编译器只知道a是一个类型a的引用，具体指向什么类型在编译期是不能确定的，
// 因此会按照A::Fun的声明把缺省参数number设为10
// 这一题的关键在于理解确定缺省参数的值是在编译的时候，但确定引用、指针的虚函数调用哪个类型的函数是在运行的时候。
