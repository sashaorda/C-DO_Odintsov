#include <stdio.h>

int main(void)
{
    char buf[512];

    while (fgets(buf, sizeof(buf), stdin) != NULL)
    {
        printf(">> %s", buf);
        fflush(stdout);
    }

    return 0;
}