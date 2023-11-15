#include "main.h"

/**
 * get_file_path - get full path of a file
 * @filename: Argument name
 * @env: environment variables
 *
 * Return: pointer to the full path to argument
 */

char *get_file_path(char *filename, char **env)
{
	char *path;
	char *full_path;

	path = _getenv(env, "PATH");

	if (forward_slash(filename) && access(filename, X_OK) == 0)
		return (_strdup(filename));

	if (!path)
	{
		perror("Not found");
		return (NULL);
	}

	full_path = get_file_loc(path, filename);

	if (full_path == NULL)
	{
		write(2, filename, _strlen(filename));
		write(2, ": not found\n", 19);
		return (NULL);
	}

	return (full_path);
}
