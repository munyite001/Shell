#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;

    char *argv[] = {"/bin/ls", "-l", NULL};

    pid = fork();

    if (pid == -1)
    {
        perror("Undefined");
        return(-1);
    }
    
    if (pid == 0)
    {
        int v = execve(argv[0], argv, NULL);
        if(v == -1)
        {
            perror("Undefined");
        }
    }
    else
    {
        wait(NULL);
        printf("\nBack to Parent\n");
    }
    return(0);
}