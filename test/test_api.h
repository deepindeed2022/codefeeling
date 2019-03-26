#ifndef ALGORITHM_TEST_API_H_
#define ALGORITHM_TEST_API_H_
#include <iostream>
#include <util.h>
#include <time_helper.h>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#else
#include <cstdlib>
#endif
int get_int_rand();
std::vector<int> generate_int_array(const size_t size);
inline std::string test_path(const std::string& name) {
#define PATH_MAX 128
    char acCanonicalPath[PATH_MAX];
    memset(acCanonicalPath, 0, PATH_MAX);
#ifdef _WIN32
    _fullpath(acCanonicalPath, "./", PATH_MAX);
#else
    realpath("./", acCanonicalPath, PATH_MAX);
#endif
    return std::string(acCanonicalPath) + name;
}
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