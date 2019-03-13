// #include <cstdio>
// int SizeOf(char pString[]) {
// 	return sizeof(pString);
// }
// int main(int argc, char* argv[]) {
// 	const char* pString1 = "google";
// 	int size1 = sizeof(pString1);
// 	int size2 = sizeof(*pString1);
// 	char pString2[100] = "google";
// 	int size3 = sizeof(pString2);
// 	int size4 = SizeOf(pString2);
// 	printf("%d, %d, %d, %d\n", size1, size2, size3, size4);
// 	return 0;
// }

// 8, 1, 100, 8
// pString1是一个指针。在64位机器上，任意指针都占8个字节的空间。
// *pString1是字符串pString1的第一个字符。一个字符占一个字节。
// pString2是一个数组，sizeof(pString2)是求数组的大小。这个数组包含100个字符，因此大小是100个字节。
// 而在函数SizeOf中，虽然传入的参数是一个字符数组，当数组作为函数的参数进行传递时，数组就自动退化为同类型的指针。
// 因此size4也是一个指针的大小，为8.