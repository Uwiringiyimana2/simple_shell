#include "main.h"

/**
 * exec_cmd - executes command
 * @args: Arguments to execute
 * @env: environment variables
 * @input: Arguments read
 *
 * Return: -1 unsuccessfully
 */
int exec_cmd(char *input, char **args, char **env)
{
	char *path;
	int status;
	pid_t child_pid;
	size_t arg_count;

	arg_count = tokenize(input, " \n");

	if (handle_builtin_cmd(args, arg_count, args[0], env))
		return (0);

	path = get_file_path(args[0]);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(path, args, NULL) == -1)
		{
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
