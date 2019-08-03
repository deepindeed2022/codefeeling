#include <cstdio>
#include <cstring>
int main(int argc, char const *argv[])
{
	// for(int i = 0; i < 10; i++) {
	// 	fprintf(stderr, "%d %d\n", i, i & (i -1));
	// }
	char a[] = "12345";

	fprintf(stderr, "%d\n", sizeof(a));
	fprintf(stderr, "%d\n", strlen(a));
	return 0;
}
