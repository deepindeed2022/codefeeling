#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdint>
using namespace std;

#define FAST_MALLOC_ALIGN 16

template<typename _Tp> 
static inline _Tp* alignPtr(_Tp* ptr, int n=(int)sizeof(_Tp))
{
    return (_Tp*)(((size_t)ptr + n-1) & -n);
}

void fastFree(void* ptr) {
    if(ptr) {
        uint8_t* udata = ((uint8_t**)ptr)[-1];
        assert(udata < (uint8_t*)ptr &&
               ((uint8_t*)ptr - udata) <= (ptrdiff_t)(sizeof(void*)+FAST_MALLOC_ALIGN));
        free(udata);
    }
}
void* fastAlloc(size_t size) {
    // alloc the size include
    //      size
    //      pointer size
    //      aligen 

    uint8_t* udata = (uint8_t*)malloc(size + sizeof(void*) + FAST_MALLOC_ALIGN);
    if(!udata) {
        std::cerr << "Alloc memory Failed"<< std::endl;
        return NULL;
    }
    uint8_t** adata = alignPtr((uint8_t**)udata + 1, FAST_MALLOC_ALIGN);
    adata[-1] = udata;
    return adata;
}