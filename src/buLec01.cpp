#include <buLec01.h>
// Euclidean algorithm
// more efficent algorithm: https://en.wikipedia.org/wiki/Binary_GCD_algorithm
int gcd(int a, int b) {
    if(a < b) 
        return gcd(b, a);
    else if(b == 0) 
        return 1;
    int c = a % b;
    while(c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b; 
}
