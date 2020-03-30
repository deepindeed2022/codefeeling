#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// #define TEST_ITIMER_SIGNAL
#define TEST_FORK

#ifdef TEST_ITIMER_SIGNAL
#include <signal.h>
// typedef void (*sighandler_t)(int);
// sighandler_t signal(int signum, sighandler_t handler);
#include <sys/time.h>
// struct itimerval {
//    struct timeval it_interval; /* next value */
//    struct timeval it_value;    /* current value */
// };
// struct timeval {
//     time_t      tv_sec;         /* seconds */
//     suseconds_t tv_usec;        /* microseconds */
// };
// int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);
void SigAction(int signal)
{
    fprintf(stderr, "Get signal:%d\n", signal);
}
#endif
int main(int argc, char const *argv[]) {
    char* paths = getenv("PATH");
    fprintf(stderr, "PATH:=%s\n", paths);

#ifdef TEST_FORK
    pid_t a = fork();
    pid_t b = fork();
    fprintf(stderr, "p%d : %d  %d\n", getpid(), a, b);
#endif

#ifdef TEST_ITIMER_SIGNAL
    struct itimerval itimer = {{3,0},{5,0}};
    struct itimerval itimer_new = {{5,0},{4,0}};
    setitimer(ITIMER_REAL, &itimer, &itimer_new);
    signal(SIGALRM, SigAction);
    while(1)
    {
      fprintf(stderr,"come to get a signal!\n");
      sleep(1);
    }
#endif
    return 0;
}