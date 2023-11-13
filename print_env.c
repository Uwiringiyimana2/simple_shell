#include "main.h"

/**
 * print_env - prints the environment
 * @env - enviroments
 * Return: Nothing
 */
void print_env(char **env)
{
	while (*env != NULL)
	{
		write(1, *env, strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}
