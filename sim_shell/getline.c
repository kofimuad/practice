#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t n = 10;

	/* char *buf = malloc(sizeof(char) * n); */

	/**
	 * if we do not allocate memory to  the buffer using malloc
	 * getline does it for us and then we have to free
	 * the memory at the end.
	 */

	char *buf = NULL;

	printf("Enter Name: ");

	getline(&buf, &n, stdin);

	printf("Name is %s Buffer size is %ld\n", buf, n);

	free(buf);

	return (0);
}
