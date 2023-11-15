#include "main.h"

/**
 * _strchr - function to locate a character
 * @s: string to search through
 * @c: character to search
 * Return: Always 0.
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
	}
	if (c == '\0')
		return (&s[i]);
	return (NULL);
}
