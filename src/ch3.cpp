#include <iostream>
#include <ch3.h>
#include <cstring>
#include <limits>
#include <algorithm>

int maximum_subarray(int* arr, const int size, int* start, int* end) {
    if(size == 0) {
        return 0;
    }
    int* dp = new int[size];
    dp[0] = arr[0];
    for(int i = 1; i < size; i++) {
        dp[i] = std::max(dp[i-1] + arr[i], arr[i]);
    }
    int res = dp[0];
    for(int i = 1; i < size; i++) {
        if(res < dp[i]) {
            *end = i;
            res = dp[i];
        }
    }
    delete[] dp;
    int tmp = 0;
    for(int i = *end; i >=0; i--) {
        tmp += arr[i];
        if(res == tmp) {
            *start = i;
            break;
        }
    }
    return res;
}