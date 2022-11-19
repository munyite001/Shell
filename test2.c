#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   char val[] = "ls";
   int v = strcmp("ls", val);
   printf("The value is: %d\n", v);
   return(0);
}