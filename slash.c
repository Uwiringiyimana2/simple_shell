#include "main.h"

/**
 * forward_slash - checks if starts with "/"
 * @str: filename to be checked
 *
 * Return: 0 if yes and 1 if no
 */

int forward_slash(const char *str)
{
	if (str != NULL || str[0] == '/')
		return (1);

	return (0);
}
