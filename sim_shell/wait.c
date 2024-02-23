#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}

	if (pid == 0)
	{
		printf("Child process created\n");
	}
	else
	{
		wait(NULL);
		sleep(30);
		printf("This is the parent process\n");
	}
	return (0);
}
