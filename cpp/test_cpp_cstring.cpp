#include <cstring>
#include <cstdio>

char* GetString1()
{
    char p[] = "Hello World";
    return p;
}
char* GetString2()
{
    char *p = "Hello World";
    return p;
}

int main(int argc, char* argv[])
{
    printf("GetString1 returns: %s. \n", GetString1());
    printf("GetString2 returns: %s. \n", GetString2());
    return 0;
}
/***************************************************************************
答案：输出两行，第一行GetString1 returns: 后面跟的是一串随机的内容，而第二行GetString2 returns: Hello World. 

两个函数的区别在于GetString1中是一个数组，而GetString2中是一个指针。
当运行到GetString1时，p是一个数组，会开辟一块内存，并拷贝"Hello World"初始化该数组。
接着返回数组的首地址并退出该函数。由于p是GetString1内的一个局部变量，当运行到这个函数外面的时候，这个数组的内存会被释放掉。
因此在main函数里再去访问这个数组的内容时，结果是随机的。

当运行到GetString2时，p是一个指针，它指向的是字符串常量区的一个常量字符串。
该常量字符串是一个全局的，并不会因为退出函数GetString2而被释放掉。
因此在_tmain中仍然根据GetString2返回的地址得到字符串"Hello World"。
***************************************************************************/