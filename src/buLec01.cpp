#include <buLec01.h>
int gcd(int a, int b) {
    if(a < b) 
        return gcd(b, a);
    else if(b == 0) 
        return 1;
    int c = a % b;
    while(c != 0) {
        b = a;
        a = c;
        c = a % b;
    }
    return b; 
}