#include <gtest/gtest.h>
#include "test_api.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

static int count = 0;
void Combination(const char* s, int number, std::vector<char>& result) {
    // print result
    if(number == 0) {
        std::vector<char>::iterator iter = result.begin();
        for(; iter < result.end(); ++ iter)
            fprintf(stderr, "%c", *iter);
        fprintf(stderr, "\n");
        count++;
        return;
    }
    if(*s == '\0') return;

    result.push_back(*s);
    Combination(s + 1, number - 1, result);
    result.pop_back();
    Combination(s + 1, number, result);
}

void Combination(const char* s) {
    if(s == NULL) return;

    int length = strlen(s);
    std::vector<char> result;
    for(int i = 1; i <= length; ++ i) {
        Combination(s, i, result);
    }
}

TEST(Perm, printall)
{
    std::string s("abc");
    Combination(s.c_str());
    ASSERT_EQ(7, count);
    // fprintf(stderr, "total size:%d\n", count);
}