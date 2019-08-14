#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <cf_util.h>

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

float IoU(const cf_rect_t& A, const cf_rect_t& B) {
	float xx1 = std::max(A.left, B.left);
	float yy1 = std::max(A.top, B.top);
	float xx2 = std::min(A.right, B.right);
	float yy2 = std::min(A.bottom, B.bottom);

	float inter  = std::max(0.0f, xx2 - xx1) * std::max(0.0f, yy2 - yy1);
	float a_area = std::abs(A.right - A.left) * std::abs(A.bottom - A.top);
	float b_area = std::abs(B.right - B.left) * std::abs(B.bottom - B.top);
	return inter / (a_area + b_area - inter);
}