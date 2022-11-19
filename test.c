#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

//  FUnction to run the shell program
int shell_run(char *command)
{
    size_t n = 0;
    char *buffer = NULL;
    int v;

    while(true)
    {
        printf("($) ");
        getline(&buffer, &n, stdin);
        v = strncmp("exit", buffer, strlen("exit"));
        if(v == 0)
        {
            return(1);
        }
        else
        {
            command = malloc(sizeof(char) * strlen(buffer));
            strcpy(command, buffer);
            if(run_command(command) == 0)
            {
                continue;
            }
        }
    }

    free(buffer);
    return(0);
}


int run_command(char *val)
{
    pid_t pid;

    char *token;
    char *delim = " ";
    char *command;

    char *argv[] = {"/bin/", NULL};

    //  Tokenize the passed in arguments
    token = strtok(val, delim);

    command = malloc(sizeof(char) * 7);

    strcpy(command, argv[0]);
    strcat(command, token);
    argv[0] = command;

    // for(int i = 1; token != NULL; i++)
    // {
    //     argv[i] = token;
    //     token = strtok(NULL, delim);
    // }
    // argv[sizeof(argv)] = NULL;

    
    //  We create a child process to prevent our existing process from being overwritten after 
    //  execve runs
    pid = fork();

    if (pid == -1)
    {
        perror("Error");
        return(-1);
    }

    if (pid == 0)
    {
        int v = execve(argv[0], argv, NULL);

        if(v == -1)
        {
            perror("Undefined");
            return(-1);
        }
    }
    else
    {
        wait(NULL);
    }

    return (0);
}

int main(void)
{
    char *command = "ls";
    run_command(command);
    return(0);
}