#include "main.h"

/*handle_exit - handles exit functionality
 * @input: Input to handle
 * @status: exit status
 *
 * Return: Nothing
 */
void handle_exit(char *input, int exit_status)
{
	free(input);
	exit(exit_status);
}

/**
 * exit_shell - handles shell exit
 * @args: arguments to function
 * @input: checks the status of exit
 *
 * Return: status of exit, 1 if otherwise
 */
int exit_shell(char **args, char *input)
{
	char *status_str;
	int exit_status, i;

	if (args[1] != NULL)
	{
		exit_status = 0;
		status_str = args[1];

		for (i = 0; status_str[i] != '\0'; i++)
		{
			if (status_str[i] < '0' || status_str[i] > '9')
			{
				handle_exit(input, 2);
				return (1);
			}
			exit_status = exit_status * 10 + (status_str[i] - '0');
		}
		handle_exit(input, exit_status);
	}
	else
	{
		handle_exit(input, 98);
	}
	return (1);
}
