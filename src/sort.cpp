#include <iostream>
#include <ch1.h>
#include <cstring>
#include <limits>
errcode_t insert_sort(int *arr, const int size)
{
    if(arr == nullptr || size <= 0) return CF_E_INVALIDARG;
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
    return CF_OK;
}
/***********************************************************
void MERGET(int*A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = new int[n1];
    int* R = new int[n2];
    for(int i = 0; i < n1-1; i++) L[i] = A[p+i-1];
    for(int j = 0; j < n2-1; j++) R[j] = A[q + j];
    L[n1] = std::numeric_limits<int>::max();
    L[n1] = std::numeric_limits<int>::max();
    int i = 0;
    int j = 0;
    for(int k = p; k < r; k++)
        A[k] = L[i] < R[j] ? L[i++]: R[j++];
    delete []L;
    delete []R;
}
*************************************************************/
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
		return CF_E_INVALIDARG;
	else if(end - start < 2) 
		return CF_OK;
    int mid = (start + end) >> 1;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid, end);
    combiled_two_part(arr, start, mid, end);
	return CF_OK;
}

