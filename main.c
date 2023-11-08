#include "main.h"

int main(int ac, char **argv)
{
	char *line = NULL, *linecopy = NULL;
	size_t n = 0;
	ssize_t read;
	char *prompt = {"Eric&BenShell$ "};
	char *delim = '\0';
	int num_token;
	char *token;

	/*declaring void variables*/
	(void)ac; (void)argv;

	while (1)
	{
		printf("%s", prompt);
	
		read = getline(&line, &n, stdin);

		/* check getline fail or reaches EOF*/
		if (read == -1)
		{
			perror("getline error");
			return (-1);
		}
		linecopy = malloc(sizeof(char) * read);
		if (linecopy = NULL)
		{
			ptintf("menory is empty errror in copy");
			return(-1);
		}
		strcpy (linecopy,line);

		token = strtok(line,delim);
		while (token != NULL)
		{
			num_token++;
			strtok(NULL,delim);
		}num_token++;
		argv[] = malloc (sizeof(char*) * num_token);
		/*storing each token in it arry of argv*/
		for (i = 0; token == NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		execmd(argv);
	}
	free(linecopy);
	free(line);
	return(0);
