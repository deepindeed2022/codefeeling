#include<time.h>
#include <iostream>

template<typename T, int i=1>
class someComputing {
public:
    typedef volatile T* retType; // 类型计算
    enum { retValume = i + someComputing<T, i-1>::retValume }; // 数值计算，递归
    static void f() { std::cout << "someComputing: i=" << i << '\n'; }
};
template<typename T> // 模板特例，递归终止条件
class someComputing<T, 0> {
public:
    enum { retValume = 0 };
};

template<typename T>
class codeComputing {
public:
    static void f() { T::f(); } // 根据类型调用函数，代码计算
};
int main(){
    clock_t start,finish;
    double totaltime;

    someComputing<int>::retType a = 0;
    std::cout << sizeof(a) << '\n'; // 64-bit 程序指针
    // VS2013 默认最大递归深度500，GCC6.3 默认最大递归深度900（-ftemplate-depth=n）
    codeComputing<someComputing<int, 99>>::f();
    
    int total = 0;
    start=clock();
    for(int i = 0; i < 10000; i++) {
        // total = someComputing<int, 500>::retValume; // 1+2+...+500
        total = 0;
        for(int j = 1; j <= 500; j++) {
            total += j;
        }
    }
    finish=clock();

    totaltime=(double)(finish-start);
    std::cout << "total clock:"<< totaltime << " total:" << total << std::endl;
    return 0;
}
