#include <gtest/gtest.h>
#include "test_api.h"
#include <sort_algo.h>
TEST(SortAlgo, heapsort)
{
    const size_t n = 16;
	std::vector<int> random_data = test::generate_int_array(n+1, 200);
    int arr[101];
    memcpy(arr, random_data.data(), (n+1)*sizeof(int));
    heap_sort(arr, n);
    ASSERT_TRUE(std::is_sorted(arr+1, arr+n+1));
    test::printArr(&random_data[1], n);
    test::printArr(&arr[1], n);
}