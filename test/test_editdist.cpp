#include <gtest/gtest.h>
#include "test_api.h"
#include <editdist.h>
#include <cstdio>
TEST(EDITDIST, editdistO3){
    char src[] = "hello";
    char dst[] = "heool";
    fprintf(stderr, "edit distance:%d\n", editDistance(src, dst));
}