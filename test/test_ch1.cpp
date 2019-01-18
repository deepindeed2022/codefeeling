#include <gtest/gtest.h>
#include <util.h>
#include <ch1.h>
TEST(Chapter1, InsertSort)
{
    int aa[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // printArr(aa, 10);
    insert_sort(aa, 10);
    // printArr(aa, 10);
}