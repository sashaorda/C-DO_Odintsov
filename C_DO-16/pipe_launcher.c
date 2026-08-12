#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int fd[2];

    pipe(fd);

    /* писатель */
    if (fork() == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("./pipe_writer", "./pipe_writer", (char *) NULL);
    }

    /* читатель */
    if (fork() == 0)
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execlp("./pipe_reader", "./pipe_reader", (char *) NULL);
    }

    close(fd[0]);
    close(fd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}