#ifndef ALGORITHM_TEST_API_H_
#define ALGORITHM_TEST_API_H_
#include <iostream>
#include <util.h>
#include <time_helper.h>
#include <vector>
int get_int_rand();
std::vector<int> generate_int_array(const size_t size);

template <typename T>
errcode_t printArr(T *arr, const size_t size)
{
    if (arr == nullptr || size <= 0)
        return CC_E_INVALIDARG;
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return CC_OK;
}

#endif