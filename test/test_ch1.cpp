#include <gtest/gtest.h>
#include "test_api.h"
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

TEST(Chapter1, InsertSortSMOKE) {
    int size = 10000;
    if(size > 1) {
        std::vector<int> random_data = generate_int_array(size);
        ASSERT_FALSE(std::is_sorted(random_data.begin(), random_data.end()));
        __TIC__();
        ASSERT_EQ(CC_OK, insert_sort(random_data.data(), random_data.size()));
        __TOC__();
        ASSERT_TRUE(std::is_sorted(random_data.begin(), random_data.end()));
    }
}

TEST(Chapter1, MergeSort)
{
    int aa[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	ASSERT_EQ(CC_OK, merge_sort(aa, 0, 10));
    int expect_aa[] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < 10; i++) ASSERT_EQ(expect_aa[i], aa[i]);
    ASSERT_EQ(CC_E_INVALIDARG, merge_sort(nullptr, 0, 10));
    int size = 10000;
    if(size > 1) {
        std::vector<int> random_data = generate_int_array(size);
        ASSERT_FALSE(std::is_sorted(random_data.begin(), random_data.end()));
        __TIC__();
        ASSERT_EQ(CC_OK, merge_sort(random_data.data(), 0, random_data.size()));
        __TOC__();
        ASSERT_TRUE(std::is_sorted(random_data.begin(), random_data.end()));
    }
}
