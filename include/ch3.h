#ifndef ALGORITHM_CH3_H_
#define ALGORITHM_CH3_H_
#include <util.h>
// 求数列的最大子数列
// params:
//      arr [in]  数组
//      size [in]  数组元素个数
//      start,end [out]  最大子数列的起始index
// return: 最大子数列的和
//
int maximum_subarray(int* arr, const int size, int* start, int* end);
#endif