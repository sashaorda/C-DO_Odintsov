#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t running = 1;

void handle_sigint(int signum)
{
    (void) signum;
    running = 0;
}

int main(void)
{
    struct timeval tv;
    struct tm *tm_info;
    char buf[32];
    clock_t start;
    clock_t end;

    signal(SIGINT, handle_sigint);
    printf("Для завершения нажмите Ctrl+C.\n\n");

    start = clock();

    while (running)
    {
        gettimeofday(&tv, NULL);

        tm_info = localtime(&tv.tv_sec);
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tm_info);

        printf("Текущее время: %s.%ld\n", buf, (long) tv.tv_usec);

        sleep(1);
    }

    end = clock();
    printf("\nПроцессорное время: %f сек\n", (double) (end - start) / CLOCKS_PER_SEC);

    return 0;
}