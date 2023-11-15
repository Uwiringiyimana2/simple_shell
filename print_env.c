#include "main.h"

/**
 * print_env - prints the environment
 * @env: enviroments
 *
 * Return: Nothing
 */
void print_env(char **env)
{
	while (*env != NULL)
	{
		write(1, *env, _strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}

/**
 * _getenv - gets environment variable
 * @name: environment variable to search
 *
 * Return: pointer to environment variable
 */

extern char **environ;

char *_getenv(char *name)
{
	char **env = environ;
	char *equal_s;
	int name_len;

	while (*env != NULL)
	{
		equal_s = strchr(*env, '=');
		if (equal_s != NULL)
		{
			name_len = equal_s - *env;

			if (_strlen(name) == name_len && _strcmp(*env, name) == 0)
			{
				return (equal_s + 1);
			}
		}
		env++;
	}
	return (NULL);
}
