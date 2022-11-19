#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

int main(void)
{

	pid_t pid;

	//	create a child process to run the shell
	pid = fork();

	// if fork fails
	if (pid == -1)
	{
		perror("Unsuccessful\n");
		return 1;
	}

	//	If we are in child process
	if (pid == 0)
	{
		printf("\n> > > > > Shell < < < < <\n");
		printf("----------------------------\n");
		if(shell_run() == 1)
		{
			return(0);
		}
	}
	//	Else if we are in parent process
	else
	{
		wait(NULL);
		printf("Exiting . . .\n");
		sleep(2);
	}
	 
	
}	