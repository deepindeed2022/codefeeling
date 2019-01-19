#include <iostream>
#include <ch1.h>
#include <cstring>
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

static void combiled_two_part(int* arr, const int start, const int mid, const int end) {
	int* tmp = new int[end - start]; 
	int k = 0;
    int i = start, j = mid;
    
	for(;i < mid && j < end;) 
		tmp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    
	for(; i < mid; tmp[k++] = arr[i++]);
    for(; j < end; tmp[k++] = arr[j++]);
	for(k=0, i = start; i < end;) arr[i++] = tmp[k++];
    delete[] tmp;
}

errcode_t merge_sort(int*arr, const int start, const int end){
    if(nullptr == arr) 
		return CC_E_INVALIDARG;
	else if(end - start < 2) 
		return CC_OK;
    int mid = (start + end) >> 1;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid, end);
    combiled_two_part(arr, start, mid, end);
	return CC_OK;
}

