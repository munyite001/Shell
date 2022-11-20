#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    char *command = "ls";
    int size = countSpaces(command);
    if (size == 2)
    {
        printf("Matches\n");
    }
    else
    {
        printf("Doesn't match\n");
    }

    printf("Size: %d\n", size);
}