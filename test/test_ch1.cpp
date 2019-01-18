#include <gtest/gtest.h>
#include <util.h>
#include <ch1.h>
TEST(Chapter1, InsertSort)
{
    int aa[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    ASSERT_EQ(CC_OK, insert_sort(aa, 10));
    int expect_aa[] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < 10; i++) ASSERT_EQ(expect_aa[i], aa[i]);
    ASSERT_EQ(CC_E_INVALIDARG, insert_sort(nullptr, 0));
    printArr(aa, 10);
}