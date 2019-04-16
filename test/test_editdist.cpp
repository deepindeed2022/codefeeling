#include <gtest/gtest.h>
#include <cstdio>
#include "editdist.h"
#include "test_api.h"
#include <string>

TEST(EDITDIST, editdistO3){
    const char* src = "hello";
    const char* dst = "heool";
    ASSERT_EQ(3, editDistance(src, dst));
    ASSERT_EQ(3, minEditDistance(src, dst));
}