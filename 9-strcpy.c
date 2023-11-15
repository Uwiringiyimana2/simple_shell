#include "main.h"
/**
 ** _strcpy - copy the string pointed to by src to dest
 ** @dest: char to check
 ** @src: char to check
 ** Return: 0 is success
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: copy of str
 */
char *_strdup(char *str)
{
	char *dup;

	if (str == NULL)
		return NULL;

	dup = malloc(_strlen(str) + 1);

	if (dup != NULL)
	{
		_strcpy(dup, str);
	}

	return (dup);
}

