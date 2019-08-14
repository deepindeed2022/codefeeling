/**
 * 测试cpp中的class在内存中所占空间大小
 */
#include <cstdio>
#include <gtest/gtest.h>
class A {};
class B {
public:
    B() {}
    ~B() {}
};
class C {
public:
    C() {}
    virtual ~C() {}
};
TEST(cpp_concept, sizeof_class)
{
    // printf("%ld, %ld, %ld\n", sizeof(A), sizeof(B), sizeof(C));
    ASSERT_EQ(1uL, sizeof(A));
    ASSERT_EQ(1uL, sizeof(B));
#if defined(_WIN32) || defined(__x86__)
    ASSERT_EQ(4, sizeof(C));
#else
    ASSERT_EQ(8, sizeof(C));
#endif
}
/**************************************************************************
分析：答案是1, 1, 8。

class A是一个空类型，它的实例不包含任何信息，本来求sizeof应该是0。
但当我们声明该类型的实例的时候，它必须在内存中占有一定的空间，否则无法使用这些实例。
至于占用多少内存，由编译器决定。gcc 4.9中每个空类型的实例占用一个byte的空间。

class B在class A的基础上添加了构造函数和析构函数。
由于构造函数和析构函数的调用与类型的实例无关（调用它们只需要知道函数地址即可），在它的实例中不需要增加任何信息。
所以sizeof(B)和sizeof(A)一样，在gcc 4.9中都是1。

class C在class B的基础上把析构函数标注为虚拟函数。
C++的编译器一旦发现一个类型中有虚拟函数，就会为该类型生成虚函数表，并在该类型的每一个实例中添加一个指向虚函数表的指针。
在64位的机器上，一个指针占8个字节的空间，因此sizeof(C)是8。
**************************************************************************/