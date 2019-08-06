#include <iostream>
#include <ch2.h>
#include <cstring>
#include <limits>
#include <algorithm>
bool find_target_sum(int *arr, const int size, int t_sum) {
	std::sort(arr, arr+size);
	int curr_sum = 0;
	int i = 0; int j = size - 1;
	while(i < j) {
		curr_sum = arr[i] + arr[j];
		if(curr_sum > t_sum) {
			j--;
		} else if(curr_sum < t_sum) {
			i++;
		} else {
			return true;
		}
	}
	return false;
}
static int combiled_inversion(int *arr, const int start, const int mid, const int end)
{
	int *tmp = new int[end - start];
	int k = 0;
	int i = start, j = mid;
	int count = 0;
	for (; i < mid && j < end;) {
		if(arr[i] < arr[j]){
			tmp[k++] = arr[i++];
		} else {
			count += mid - i;
			tmp[k++] = arr[j++];
		}
	}
	for (; i < mid; tmp[k++] = arr[i++])
		;
	for (; j < end; tmp[k++] = arr[j++])
		;
	for (k = 0, i = start; i < end;)
		arr[i++] = tmp[k++];
	delete[] tmp;
	return count;
}

static int count_inversion(int *arr, const int start, const int end)
{
	if (nullptr == arr)
		return CF_E_INVALIDARG;
	else if (end - start < 2)
		return CF_OK;
	int mid = (start + end) >> 1;
	int a = count_inversion(arr, start, mid);
	int b = count_inversion(arr, mid, end);
	return combiled_inversion(arr, start, mid, end) + a + b;
}
int count_inversion(int *arr, const int size) {
	return count_inversion(arr, 0, size);
}