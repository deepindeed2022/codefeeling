#include <gtest/gtest.h>
#include <string/multi.h>
#include <cassert>
#include <string/utf8.h>
TEST(StringOp, Multi) {
	std::vector<std::string> nums = {"123", "3", "56", "25", "567"};
	std::string result = string_multi_op(nums[0], nums[1]);
	ASSERT_EQ("369", result);
	result = string_multi_op(nums[0], nums[2]);
	ASSERT_EQ("6888", result);
	result = string_multi_op(nums[3], nums[4]);
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

TEST(StringOp, delete_punct) {
	std::string input = "hello, i am cao." ;
	ASSERT_EQ("hello i am cao", delete_punct(input));
	std::wstring w_text = L"你好，我是小草。";
	std::wstring w_text_punct = delete_punct(w_text);
	std::string s_text;
	utf8::utf16to8(w_text_punct.begin(), w_text_punct.end(), s_text.begin());
	std::cout << s_text << std::endl;
}