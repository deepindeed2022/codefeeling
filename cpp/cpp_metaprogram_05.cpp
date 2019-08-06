#include <iostream>

template<int N>
class sumt{
public: 
	static const int ret = sumt<N-1>::ret + N;
};
template<>
class sumt<0>{
public: 
	static const int ret = 0;
};

int main() {
    std::cout << sumt<5>::ret << '\n';
    return 0;
}

// 当编译器遇到 sumt<5> 时，试图实例化之，sumt<5> 引用了 sumt<5-1> 即 sumt<4>，试图实例化 sumt<4>，
// 以此类推，直到 sumt<0>，sumt<0> 匹配模板特例，sumt<0>::ret 为 0，sumt<1>::ret 为 sumt<0>::ret+1 为 1，
// 以此类推，sumt<5>::ret 为 15。值得一提的是，虽然对用户来说程序只是输出了一个编译期常量 sumt<5>::ret，
// 但在背后，编译器其实至少处理了 sumt<0> 到 sumt<5> 共 6 个类型。

// 从这个例子我们也可以窥探 C++ 模板元编程的函数式编程范型，对比结构化求和程序：
// for(i=0,sum=0; i<=N; ++i) sum+=i; 用逐步改变存储（即变量 sum）的方式来对计算过程进行编程，模板元程序
// 没有可变的存储（都是编译期常量，是不可变的变量），要表达求和过程就要用很多个常量：sumt<0>::ret，
// sumt<1>::ret，...，sumt<5>::ret 。函数式编程看上去似乎效率低下（因为它和数学接近，而不是和硬件工作方式接近），
// 但有自己的优势：描述问题更加简洁清晰（前提是熟悉这种方式），没有可变的变量就没有数据依赖，方便进行并行化。