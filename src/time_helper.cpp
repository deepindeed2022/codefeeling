#ifndef CC_DISABLE_TIMING
#include "time_helper.h"
#include <ctime>
#include <cstdio>

#ifdef _MSC_VER
static BOOL g_first_time = 1;
static LARGE_INTEGER g_counts_per_sec;

#define BILLION                             (1E9)

int clock_gettime(int type, struct timespec* ct) {
    LARGE_INTEGER count;
    if (g_first_time) {
        g_first_time = 0;
        if (0 == QueryPerformanceFrequency(&g_counts_per_sec)) {
            g_counts_per_sec.QuadPart = 0;
        }
    }
    if ((NULL == ct) || (g_counts_per_sec.QuadPart <= 0) ||
        (0 == QueryPerformanceCounter(&count))) {
        return -1;
    }
    ct->tv_sec = count.QuadPart / g_counts_per_sec.QuadPart;
    ct->tv_nsec = (long)(((count.QuadPart % g_counts_per_sec.QuadPart) * BILLION) / g_counts_per_sec.QuadPart);
    return 0;
}

int gettimeofday(struct timeval *tp, void *tzp) {
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
#endif


void time_spendMs(struct timespec* ptime1, struct timespec* ptime2, char* des) {
    long spend;
    spend = ((ptime2->tv_sec - ptime1->tv_sec) * 1000 + (ptime2->tv_nsec - ptime1->tv_nsec) / 1000000);
    fprintf(stderr, "[%s]===== TIME SPEND: %ld ms =====\n", des, spend);
}

void time_print(struct timespec* ptime, char* des) {
    fprintf(stderr, "[%s]===== TIME NOW: %ld s, %ld us =====\n", des, (ptime->tv_sec), (ptime->tv_nsec / 1000));
}

#endif