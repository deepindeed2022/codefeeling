#include <iostream>
// 计算 N 的阶乘 N!

#ifdef LAZY_TEST_FAILURE
template<int N>
class aTMP{
public:
    enum { ret = N==0 ? 1 : N * aTMP<N-1>::ret }; // Lazy Instantiation，将产生无限递归!
};
#else
template<int N>
class aTMP{
public:
    enum { ret = N * aTMP<N-1>::ret }; // Lazy Instantiation，将产生无限递归!
};
template<>
class aTMP<0>{
public:
    enum { ret = 1 };
};
#endif

int main(){
    std::cout << aTMP<10>::ret << '\n';
    return 0;
}
/*
D:\Repo\codefeeling\cpp\cpp_template_05.cpp: In instantiation of 'class aTMP<-889>':
D:\Repo\codefeeling\cpp\cpp_template_05.cpp:7:31:   recursively required from 'class aTMP<9>'
D:\Repo\codefeeling\cpp\cpp_template_05.cpp:7:31:   required from 'class aTMP<10>'
D:\Repo\codefeeling\cpp\cpp_template_05.cpp:11:26:   required from here
D:\Repo\codefeeling\cpp\cpp_template_05.cpp:7:31: fatal error: template instantiation depth exceeds maximum of 900 (use -ftemplate-depth= to increase the maximum)
     enum { ret = N==0 ? 1 : N * aTMP<N-1>::ret };
上面的错误是因为，当编译 aTMP<N> 时，并不判断 N==0，而仅仅知道其依赖 aTMP<N-1>（lazy instantiation），从而产生无限递归
*/

