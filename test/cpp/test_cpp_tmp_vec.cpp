#include <gtest/gtest.h>
#include <vector>
#include <iostream>
std::vector<int> get_tmp() {
	std::vector<int> tmp = {1, 2, 3, 4};
	return tmp;
}

TEST(cpp_concept, TmpVectorDoubleCall) {
	std::vector<int> shape0 = get_tmp();
	std::vector<int> shape2 = std::vector<int>(shape0.begin(), shape0.end());
	ASSERT_EQ(shape2.size(), 4uL);
	ASSERT_EQ(shape2[0], 1);
	ASSERT_EQ(shape2[1], 2);
	ASSERT_EQ(shape2[2], 3);
	ASSERT_EQ(shape2[3], 4);

#if !(defined(_WIN32) || defined(__linux__))
	// 由于返回的是临时变量，因此如下初始化中的begin和end对应并不是同一个vec， 这个在vs 2015中会抛出异常
	// ubuntu16 g++-4.9会抛出异常
	// unknown file: Failure
	// C++ exception with description "std::bad_alloc" thrown in the test body.
	std::vector<int> shape1 = std::vector<int>(get_tmp().begin(), get_tmp().end());
	ASSERT_NE(shape1.size(), 4);
#endif
}