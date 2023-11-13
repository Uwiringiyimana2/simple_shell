#include "main.h"
/**
 * handle_builtin_cmd - handles all builtin commands
 * @args: Arguments to the built in commands
 * @num_args: Number of argument
 * @input: The input command
 * @env: The environment variables
 *
 * Return: 1 if successful
 */

int handle_builtin_cmd(char **args, char *input, char **env)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (exit_shell(args, input));
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_env(env);
		return (1);
	}

	return (0);
}
