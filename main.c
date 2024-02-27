#include "shell.h"

/**
 * main - entry point of program
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t pid;
	char *lineptr = NULL, **argv, *command;
	size_t len = 0;
	ssize_t nread = 0;
	int status;

	printf("#cisfun$ ");
	while ((nread = getline(&lineptr, &len, stdin)) != EOF)
	{
		lineptr[(int)nread - 1] = '\0';

		pid = fork();
		if (pid == -1)
		{
			perror("Unsuccessful!\n");
			return (1);
		}


		if (pid == 0)
		{
			argv = word_list(lineptr, " ");
			strcpy(command, "/usr/bin/");
			strcat(command, argv[0]);
			execve(argv[0], argv, NULL);
		}
		else
			wait(&status);

		printf("#cisfun$ ");

	}

	free(lineptr);

	return (0);
}

