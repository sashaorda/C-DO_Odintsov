#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t running = 1;
volatile sig_atomic_t tick = 0;

void handle_sigint(int signum)
{
    (void) signum;
    running = 0;
}

void handle_sigalrm(int signum)
{
    (void) signum;
    signal(SIGALRM, handle_sigalrm);
    tick = 1;
}

int main(void)
{
    struct timeval tv;
    struct tm *tm_info;
    char buf[32];
    clock_t start;
    clock_t end;
    struct itimerval timer;

    signal(SIGINT, handle_sigint);
    signal(SIGALRM, handle_sigalrm);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    printf("Для завершения нажмите Ctrl+C.\n\n");

    start = clock();

    setitimer(ITIMER_REAL, &timer, NULL);

    while (running)
    {
        pause();

        if (tick)
        {
            tick = 0;

            gettimeofday(&tv, NULL);

            tm_info = localtime(&tv.tv_sec);
            strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm_info);

            printf("Текущее время: %s.%06ld\n", buf, (long) tv.tv_usec);
        }
    }

    end = clock();
    printf("\nПроцессорное время: %f сек\n", (double) (end - start) / CLOCKS_PER_SEC);

    return 0;
}