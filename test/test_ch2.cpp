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
