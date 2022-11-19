#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   char *argv[] = {"/bin/ls", NULL};
    int n = sizeof(argv)/sizeof(char *);
    printf("%lu\n", sizeof(argv)/sizeof(char *));
    argv[n] = "Test";
    printf("%s\n", argv[n]);
    printf("%lu\n", sizeof(argv)/sizeof(char *));
}