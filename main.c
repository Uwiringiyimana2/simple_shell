#include "main.h"

int main(int ac, char **argv, char **env)
{
	char *lineptr = NULL, *lineptr_cpy = NULL;
	size_t n = 0;
	ssize_t read;
	int i, count = 0;
	char *token;
	const char *delim = " \n";
	
	/* unused parameters*/
	(void)ac;

	while (1){
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "E&Bshell$  ", 10);

		read = getline(&lineptr, &n, stdin);
		if (read == -1)
		{
			return (-1);
		}

		lineptr_cpy = malloc(sizeof(char) * read);
		if (lineptr_cpy == NULL)
		{
			perror("memory allocation failed");
			return (1);
		}
		strcpy(lineptr_cpy, lineptr);

		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			count++;
			token = strtok(NULL, delim);
		}
		count++;

		argv = malloc(sizeof(char *) * count);

		token = strtok(lineptr_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			argv[i] = token;
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		exec_cmd(argv, env);
	}

	free(lineptr);
	free(lineptr_cpy);
	free(argv);
	return (0);
}
