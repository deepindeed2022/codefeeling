#include <gtest/gtest.h>
#include "test_api.h"
#include <ch3.h>
TEST(Chapter3, maximum_subarray)
{
	int aa[] = {-2,1,-3,4,-1,2,1,-5,4,1};
	printArr(aa, 10);
	int start = 0;
	int end = 0;
	__TIC__();
	ASSERT_EQ(6, maximum_subarray(aa, 10, &start, &end));
	__TOC__();
	ASSERT_EQ(start, 3);
	ASSERT_EQ(end, 6);
}