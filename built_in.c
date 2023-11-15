#include "main.h"
/**
 * handle_builtin_cmd - handles all builtin commands
 * @args: Arguments to the built in commands
 * @input: The input command
 * @env: The environment variables
 * @argc: arguments count
 *
 * Return: 1 if successful
 */

int handle_builtin_cmd(char **args, int argc, char *input, char **env)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		return (exit_shell(args, input));
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		change_dir(args, argc, env);
		return (1);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		print_env(env);
		return (1);
	}

	return (0);
}

/**
 * change_dir - changes directory
 * @argv: Array of commands
 * @argc: Arguments count
 * @env: environment lists
 *
 * Return: Nothing
 */
void change_dir(char **argv, int argc, char **env)
{
	const char *home_dir, *prev_dir;

	home_dir = _getenv(env, "HOME");
	prev_dir = _getenv(env, "OLDPWD");

	if (argc == 1 || (_strcmp(argv[1], "~")) == 0)
	{
		if (!home_dir)
		{
			perror("HOME environment not set");
			return;
		}
		if (chdir(home_dir) != 0)
			perror("cd");
	}
	else  if (argc == 2 || (_strcmp(argv[1], "-")) == 0)
	{
		if (!prev_dir)
		{
			perror("OLDPWD environment not set");
			return;
		}
		if (chdir(prev_dir) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(argv[1]) != 0)
			perror("cd");
	}
}
