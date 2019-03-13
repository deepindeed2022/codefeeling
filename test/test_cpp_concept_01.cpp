#include <iostream>
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

int main()
{
    B b;
    A &a = b;
    a.Fun();
}