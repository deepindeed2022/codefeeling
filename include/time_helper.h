#ifndef ALGORITHM_TIME_HELPER_H_
#define ALGORITHM_TIME_HELPER_H_
#ifndef CC_DISABLE_TIMING
#include <time.h>
#include <cstdio>

#ifdef _MSC_VER
#include <Windows.h>
#include <WinSock.h>
int clock_gettime(int type, struct timespec* ct);
int gettimeofday(struct timeval *tp, void *tzp);
#else // ifdef _WIN32
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#endif

void time_spendMs(struct timespec* ptime1, struct timespec* ptime2, char* des);
void time_print(struct timespec* ptime, char* des);


#define __TIC__()                                \
    struct timeval __timing_start, __timing_end; \
    gettimeofday(&__timing_start, NULL);

#define __TOC__()                                         \
    do                                                    \
    {                                                     \
        gettimeofday(&__timing_end, NULL);                \
        double __timing_gap = (__timing_end.tv_sec -      \
                               __timing_start.tv_sec) *   \
                                  1000.0 +                \
                              (__timing_end.tv_usec -     \
                               __timing_start.tv_usec) /  \
                                  1000.0;                 \
        fprintf(stdout, "TIME(ms): %lf\n", __timing_gap); \
    } while (0)

#endif // CC_DISABLE_TIMING
#endif // ALGORITHM_TIME_HELPER_H_