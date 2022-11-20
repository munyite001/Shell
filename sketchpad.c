#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *t = "ls";
    char *command;
    command = malloc(5 + strlen(t));
    strcpy(command, "/bin/");
    strcat(command, t);

    return (command);
}