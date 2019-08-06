#include <gtest/gtest.h>
#include "test_api.h"
#include "time_helper.h"

TEST(COMMON, clock_gettime) {
    long spend;
    struct timespec start, end;

    clock_gettime(0, &start);
    for(int i = 0; i < 10; i++) {
    	int count = 0;
    	for(int j = 0; j < 10000; j++) {
    		count *= j;
    		if (count > 0x7ffff) {
    			count >>= 8;
    		}
    	}
    }
    clock_gettime(0, &end);
    spend = (end.tv_sec - start.tv_sec) * 1000 * 1000 + (end.tv_nsec - start.tv_nsec) / 1000;
    printf("[Forward]===== TIME SPEND: %ldms, %ldus =====\n\n", spend/1000, spend);
#ifndef CF_DISABLE_TIMING
    time_print(&start, "start");
    time_print(&end, "end");
    time_spendMs(&start, &end, "common test clock_gettime");
#endif
}
