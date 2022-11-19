#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

//  FUnction to run the shell program
int shell_run()
{
    char *command;

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
            run_command(command);
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

    command = malloc(strlen(argv[0]) + strlen(val));
    strcpy(command, argv[0]);
    strcat(command, token); //  TO fix get rid of new line character
    argv[0] = strtok(command, '\n');

            /*Debug*/
    // printf("%s\n", argv[0]);
    // printf("Size: %lu\n", sizeof(argv[0]));
    // printf("comparison: %d\n", strcmp("ls", token));
    // printf("size of token: %lu\n", strlen(token));

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

        printf("v: %d\n", v);

        if(v == -1)
        {
            printf("Undefined command: %s", argv[0]);
            return(-1);
        }
    }
    else
    {
        wait(NULL);
    }

    return (0);
}