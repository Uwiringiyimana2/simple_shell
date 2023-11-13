#include "main.h"

/**
 * exec_cmd - executes command
 * @args: Arguments to execute
 *
 * Return: -1 unsuccessfully
 */
int exec_cmd(char **args, char **env)
{
	char *path;
	int status;
	pid_t child_pid;

	if (handle_builtin_cmd(args, args[0], env))
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
			perror("Execution Failed");
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
