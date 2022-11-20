#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <unistd.h>

int main(void)
{
   char *val = "ls -la";
   char *token;
   char *delim = " ";
   char *command;
   char *str = malloc(sizeof(char) * strlen(val));

   strcpy(str, val);

   int size = countSpaces(str);

   char *argv[size];

   token = strtok(str, delim);

   char *temp = token;

   argv[0] = filenameFormat(temp);

   
   int i = 1;

   while(token != NULL)
   {
      token = strtok(NULL, delim);
      argv[i] = token;
      i += 1;
   }
   argv[size-1] = NULL;

   for(int i = 0; i < size; i++)
   {
      printf("Argument[%d]: %s\n", i+1, argv[i]);
   }

   return(0);
}