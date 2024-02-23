#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", NULL};

	pid = fork();
	
	if (pid == -1)
	{
		perror("Unsuccesful\n");
		return (1);
	}
	if (pid == 0)
	{
		int val = execve(argv[0], argv, NULL);
		if (val == -1)
			perror("Error\n");
	}
	else
	{
		wait(NULL); /*This waits for the child to be done executing before it returns to the parent*/
		printf("Done with execve\n");
	}

	/* Intially without the child process the statement above  would not get executed no success*/
	/* Because on success execve returns nothing*/
	/**
	 * But now we have created a child process to take care
	 * of the execve and the printf would run in the parent process
	 */

	return (0);
}
