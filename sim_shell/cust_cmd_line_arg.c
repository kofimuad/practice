#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char *cmd = NULL;
    char *cmd_cpy = NULL;
    char *token = NULL;
    char *delim = " \n";
    size_t n = 0; /* store the size of buffer */
    int argc = 0;
    int i = 0;
    char **argv = NULL;

    printf("$ ");
    if (getline(&cmd, &n, stdin) == -1)
        return (-1);

    cmd_cpy = strdup(cmd);

    token = strtok(cmd, delim);

    while (token)
    {
        token = strtok(NULL, delim);
        argc++;
    }

    printf("%d\n", argc);

    argv = malloc(sizeof(char *) * argc);

    token = strtok(cmd_cpy, delim);

    while (token)
    {
        argv[i] = token;
        token = strtok(NULL, delim);
        i++;
    }

    argv[i] = NULL;

    i = 0;

    while (argv[i])
    {
        printf("%s\n", argv[i++]);
    }
    return (0);
}