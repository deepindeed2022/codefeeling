#include <iostream>
#include <ch1.h>

errcode_t insert_sort(int *arr, const int size)
{
    if(arr == nullptr || size <= 0) return CC_E_INVALIDARG;
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // 为什么是j+1? 因为while循环结束有两种条件: 1: j < 0 2.arr[j] < key
        arr[j + 1] = key;
    }
    return CC_OK;
}