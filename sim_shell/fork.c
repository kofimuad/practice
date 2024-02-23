#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	pid_t ppid;

	pid = fork();

	if (pid == -1)
	{
		perror("fork did not work\n");
		return (0);
	}

	if (pid == 0)
	{
		sleep(40);
		printf("I am the child process\n");
	}
	else
	{
		ppid = getpid();
		printf("PID of the parent process is: %u\n", ppid);
	}

	return (0);
}

