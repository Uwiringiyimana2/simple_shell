#include "main.h"
/**
 * main - prints prompt and read user input
 * @ac: number of arguments
 * @argv: array of arguments
 * @env: environment variables
 *
 * Return: Always 0
 */
int main(int ac, char **argv, char **env)
{
	char *lineptr = NULL;
	ssize_t read;
	size_t n = 0;
	char *delim = " \n";

	/* unused parameters*/
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "E&Bshell$  ", 10);

		read = getline(&lineptr, &n, stdin);
		if (read == -1)
		{
			write(2, "\n", 1);
			return (-1);
		}

		argv = word_list(lineptr, delim, read);

		exec_cmd(lineptr, argv, env);
	}

	free(lineptr);
	free(argv);
	return (0);
}
