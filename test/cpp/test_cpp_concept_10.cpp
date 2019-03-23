#include <cstdio>
#include <gtest/gtest.h>
TEST(cpp_concept, chararr_and_string_compare)
{
    char str1[] = "hello world";
    char str2[] = "hello world";

    const char *str3 = "hello world";
    const char *str4 = "hello world";

    if (str1 == str2)
        printf("str1(%p) and str2(%p) are same.\n", str1, str2);
    else
        printf("str1(%p) and str2(%p) are not same.\n", str1, str2);

    if (str3 == str4)
        printf("str3(%p) and str4(%p) are same.\n", str3, str4);
    else
        printf("str3(%p) and str4(%p) are not same.\n", str3, str4);

}
//
// 答案：输出两行。第一行是str1 and str2 are not same，第二行是str3 and str4 are same。
//
// str1和str2是两个字符串数组。我们会为它们分配两个长度为12个字节的空间，并把"hello world"的内容分别拷贝到数组中去。
// 这是两个初始地址不同的数组，因此比较str1和str2的值，会不相同。str3和str4是两个指针，我们无需为它们分配内存以存储字符串的内容，
// 而只需要把它们指向"hello world"在内存中的地址就可以了。由于"hello world"是常量字符串，它在内存中只有一个拷贝，
// 因此str3和str4指向的是同一个地址。因此比较str3和str4的值，会是相同的。
// 更多关于内存: https://blog.csdn.net/daiyutage/article/details/8605580
// int a = 0; // 全局初始化区  
// char *p1;  // 全局未初始化区  
// #include <cstdio>
// #include <cstring>
// #include <memory>
// int main(int argc, char* argv[]) {
// 	int b; // 栈  
// 	char s[] = "abc"; // 栈  
// 	char *p2; // 栈  
// 	const char *p3 = "123456"; // 123456\0在常量区，p3在栈上。  
// 	static int c = 0; // 全局（静态）初始化区  
// 	p1 = (char *)malloc(10);  
// 	p2 = (char *)malloc(20);  
// 	printf("p1(%p) and p2(%p) are not same.\n", p1, p2);
// 	// 分配得来得10和20字节的区域就在堆区。  
// 	strcpy(p1, "123456"); // 123456\0放在常量区，编译器可能会将它与p3所指向的"123456"优化成一个地方.
// 	printf("a(%p)\nb(%p)\ns(%p)\nc(%p)\np1(%p)\n", &a, &b, &s, &c, &p1);
// 	printf("p2(%p)\n", &p2);
// 	printf("p1(%p) p3(%p)\n", &(p1[0]), &(p3[0]));
// 	return 0; 
// }