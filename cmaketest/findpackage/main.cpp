/**
 * The test for cmake to findpackage() 
 * author: caowenlong92@gmail.com
 **/
#include <iostream>
// include a package header as following
#include <climbingstats.h>

int main(int argc, char const *argv[]) {
	int a = climbing(100);
    std::cout << "result " << a << std::endl;
    return 0;
}