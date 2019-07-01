#include <gtest/gtest.h>
#include "test_api.h"
#include <sort_algo.h>
TEST(SortAlgo, heapsort)
{
    std::cout << "test heap sort" << std::endl;
	std::vector<int> random_data = generate_int_array(size);
	std::cout << std::endl;
    ASSERT_FALSE(std::is_sorted(random_data.begin(), random_data.end()));
    heap_sort(random_data.data(), random_data.size());
    ASSERT_TRUE(std::is_sorted(random_data.begin(), random_data.end()));
}