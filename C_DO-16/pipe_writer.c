#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[512];

    while (fgets(buf, sizeof(buf), stdin) != NULL)
    {
        if (strncmp(buf, "exit", 4) == 0 && buf[4] == '\n')
        {
            break;
        }

        fputs(buf, stdout);
        fflush(stdout);
    }

    return 0;
}