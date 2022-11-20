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
    int v;  // To store value of comparison to determine if we exit

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
    char *str = malloc(sizeof(char) * strlen(val));

    strcpy(str, val);

    int size = countSpaces(str);    //  To calculate size of argv[] array
    int i = 0;  //  To count extra arguments passed in to the command

    char *argv[size];       // Creating the argv array


    // while(token != NULL)
    // {
    //     token = strtok(NULL, delim);
    //     i += 1;
    //     argv[i] = token;
    // }

    //argv[size-1] = NULL;

    char *argv[] = {"/bin/", NULL};

    //  Tokenize the passed in arguments
    token = strtok(str, delim);

    argv[0] = filenameFormat(token);
    
    //  We create a child process to prevent our existing process from being overwritten after 
    //  execve runs
    pid = fork();

    //  If there was an issue with creating the child process
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
            exit(0);
        }
    }
    else
    {
        wait(NULL);
    }

    return (0);
}

//  Function to count number of spaces
int countSpaces(char *str)
{
    int count;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ' ')
        {
            count += 1;
        }
    }

    return(count+2);    //  1 for num of elemets, 1 for null value at the end of array
}

//  Function to format filename
char *filenameFormat(char *t)
{
    char *command;
    command = malloc(5 + strlen(t));

    strcpy(command, "/bin/");
    strcat(command, t);

    return(strtok(command, "\n"));
}