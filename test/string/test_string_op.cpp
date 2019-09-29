#include <gtest/gtest.h>
#include <string/multi.h>
#include <cassert>

TEST(StringOp, Multi) {
	std::vector<std::string> nums = {"123", "3", "56", "25", "567"};
	// std::string result = string_multi_op(nums[0], nums[1]);
	// ASSERT_EQ("369", result);
	// result = string_multi_op(nums[0], nums[2]);
	// ASSERT_EQ("6888", result);
	std::string result = string_multi_op(nums[3], nums[4]);
	ASSERT_EQ("14175", result);
}


TEST(StringOp, Split) {
	std::vector<std::string> result = split("hello , i am cao", ',');
	ASSERT_EQ("hello ", result[0]);
	ASSERT_EQ("hello", rstrip(result[0]));
	ASSERT_EQ(" i am cao", result[1]);
	ASSERT_EQ("i am cao", lstrip(result[1]));
	std::string l = " hello ";
	ASSERT_EQ("hello", strip(l));
}