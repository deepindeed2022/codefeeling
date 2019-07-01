// #include "sort_algo.h"
#include <iostream>
#include <algorithm>
void heap_sort(int* arr, const int size) {
	std::vector<int> v(arr, arr+size);
	std::sort_heap (v.begin(),v.end());
	memcpy(arr, v.data(), size*sizeof(int));
}
