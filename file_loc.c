#include "main.h"

/**
 * get_file_loc - finds the full path of a file
 * @path: path variavles
 * @filename: executable file
 *
 * Return: character pointer to full path
 */

char *get_file_loc(char *path, char *filename)
{
	char *path_cpy, *token;
	struct stat st;
	char *buf = NULL;

	path_cpy = strdup(path);
	token = strtok(path_cpy, ":");

	while (token)
	{
		if (buf)
		{
			free(buf);
			buf = NULL;
		}
		buf = malloc(strlen(token) + strlen(filename) + 2);
		if (!buf)
		{
			perror("Error: malloc failed");
			return (NULL);
		}

		strcpy(buf, token);
		strcat(buf, "/");
		strcat(buf, filename);
		strcat(buf, "\0");

		if (stat(buf, &st) == 0 && access(buf, X_OK) == 0)
		{
			free(path_cpy);
			return (buf);
		}
		
		token = strtok(NULL, ":");
	}
	free(path_cpy);
	if (buf)
		free(buf);
	return (NULL);
}
