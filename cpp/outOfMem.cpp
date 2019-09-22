#include <iostream>
#include <memory>
#include <cstring>
void outOfMem() {
	char* a =  new char[100]; 
	char b[] = "Unable to satifsfy request for memory\n";
	memcpy(a, b, strlen(b) + 1);
    std::cerr << a;
    std::abort();
}
int main() {
    std::set_new_handler(outOfMem);
    int* pBigDataArray = new int [99999999999L];
    return 0;
}