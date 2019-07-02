#include <gtest/gtest.h>
#include "test_api.h"
#include <sort_algo.h>
TEST(SortAlgo, heapsort)
{
    std::cout << "test heap sort" << std::endl;
	std::vector<int> random_data = generate_int_array(100);
	std::cout << std::endl;
    ASSERT_FALSE(std::is_sorted(random_data.begin(), random_data.end()));
    int b[100];
    memcpy(random_data.data(), b, 100*sizeof(int));
    std::sort(b, b+100);
    ASSERT_TRUE(std::is_sorted(b, b+100));
}