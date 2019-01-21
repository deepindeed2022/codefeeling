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