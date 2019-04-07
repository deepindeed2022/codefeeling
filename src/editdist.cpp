#include "editdist.h"
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

int editDistance(char* src, char*dst) {
    if(strlen(src) == 0 || strlen(dst) == 0) {
        return abs((int)strlen(src) - (int)strlen(dst));
    }
    if(src[0] == dst[0]) {
        return editDistance(src+1, dst+1);
    }
    int edIns = editDistance(src, dst+1) + 1;
    int edDel = editDistance(src+1, dst) + 1;
    int edRep = editDistance(src+1, dst+1) + 1;
    return std::min(std::min(edIns, edDel), edRep);
}