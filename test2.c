#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(void)
{
   char *val = "ls -la";
   char *token;
   char *delim = " ";
   char *command;
   char *str = malloc(sizeof(char) * strlen(val));

   strcpy(str, val);

   int size = countSpaces(val);

   token = strtok(str, delim);
   char *argv[size];
   char *temp = token;
   argv[0] = filenameFormat(temp);

   int i = 0;

   while(token != NULL)
   {
      printf("Argument[%d]: %s\n", i, argv[i]);
      token = strtok(NULL, delim);
      i += 1;
      argv[i] = token;
   }
   argv[size-1] = NULL;
   printf("Argument[%d]: %s\n", size, argv[2]);

   

   return(0);
}