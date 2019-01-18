#ifndef ALGORITHM_TIME_HELPER_H_
#define ALGORITHM_TIME_HELPER_H_
#ifndef CC_DISABLE_TIMING
#include <ctime>
#include <cstdio>

#ifdef _MSC_VER
#include <windows.h>
#include <WinSock.h>
static int gettimeofday(struct timeval *tp, void *tzp)
{
    time_t clock;
    struct tm tm;
    SYSTEMTIME wtm;
    GetLocalTime(&wtm);
    tm.tm_year = wtm.wYear - 1900;
    tm.tm_mon = wtm.wMonth - 1;
    tm.tm_mday = wtm.wDay;
    tm.tm_hour = wtm.wHour;
    tm.tm_min = wtm.wMinute;
    tm.tm_sec = wtm.wSecond;
    tm.tm_isdst = -1;
    clock = mktime(&tm);
    tp->tv_sec = clock;
    tp->tv_usec = wtm.wMilliseconds * 1000;
    return (0);
}
#else
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#endif

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

#endif
#endif