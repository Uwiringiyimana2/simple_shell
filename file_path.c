#include "main.h"

/**
 * get_file_path - get full path of a file
 * @filename: Argument name
 *
 * Return: pointer to the full path to argument
 */

char *get_file_path(char *filename)
{
	char *path;
	char *full_path;

	path = getenv("PATH");

	if (forward_slash(filename) && access(filename, X_OK) == 0)
		return (strdup(filename));

	if (!path)
	{
		perror("Not found");
		return (NULL);
	}

	full_path = get_file_loc(path, filename);

	if (full_path == NULL)
	{
		write(2, filename, strlen(filename));
		write(2, ": Command not found\n", 19);
		return (NULL);
	}

	return (full_path);
}
