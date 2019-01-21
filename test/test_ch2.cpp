#include <gtest/gtest.h>
#include "test_api.h"
#include <ch2.h>
TEST(Chapter2, FindTargetSum)
{
	int aa[] = {10, 0, 22, 7, 16, 5, 14, 3, 2, 10};
	printArr(aa, 10);
	ASSERT_TRUE(find_target_sum(aa, 10, 7));
	ASSERT_FALSE(find_target_sum(aa, 10, 11));
	printArr(aa, 10);
}

TEST(Chapter2, CountInversion)
{
	int aa[] = {1,2,3,4,5,6,7,8,9,10};
	ASSERT_EQ(count_inversion(aa, 10), 0);
	int aa2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	ASSERT_EQ(count_inversion(aa2, 10), 9);
	int aa3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	ASSERT_EQ(count_inversion(aa3, 10), 45);
}