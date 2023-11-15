#include "main.h"

/**
 * tokenize - tokenizes the user input
 * @str: user's arguments
 * @delim: delimiters
 *
 * Return: number of tokens
 */
size_t tokenize(char *str, char *delim)
{
	size_t words_count = 0;

	if (strtok(str, delim))
		words_count++;
	while (strtok(NULL, delim))
		words_count++;

	return (words_count);
}

/**
 * word_list - tokenizes str and returns array of tokens
 * @str: strings to tokenize
 * @delim: delimiters
 * @read: numbers of characters in str
 *
 * Return: array of tokens
 */
char **word_list(char *str, char *delim, ssize_t read)
{
	size_t i, words_count = 0;
	char **args = NULL;
	char *token, *str_copy = NULL;

	str_copy = malloc(sizeof(char) * read);
	if (str_copy == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}
	_strcpy(str_copy, str);

	words_count = tokenize(str_copy, delim);

	if (words_count > 0)
		args = malloc(sizeof(char *) * (words_count + 1));

	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
	{
		args[i] = malloc(sizeof(char) * _strlen(token));
		args[i] = token;
		token = strtok(NULL, delim);
	}
	args[i] = NULL;

	free(str_copy);

	return (args);
}
