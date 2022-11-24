#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <unistd.h>

int main(void)
{
    char *input = "ls -la";
    char *str = malloc(sizeof(char) * strlen(input));
    strcpy(str, input);
    char *token;
    char *delim = " ";

    int size = countSpaces(str);

    char *argv[size];

    token = strtok(str, delim);

    char *temp = malloc(sizeof(char) * strlen(token));

    strcpy(temp, token);

    for(int i = 0; token != NULL; i++)
    {
        printf("Token: %s\n", argv[i]);
        token = strtok(NULL, delim);
    }

    argv[size-1] = NULL;

    argv[0] = filenameFormat(temp);

    for(int i = 0; i < size; i++)
    {
        printf("Argument[%d]: %s\n", i+1, argv[i]);
    }

    execve(argv[0], argv, NULL);

    return EXIT_SUCCESS;
    
}