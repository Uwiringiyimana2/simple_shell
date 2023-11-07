#include "main.h"

int main(int ac, char **argv)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t read;
	char *prompt = {"Eric&BenShell$ "};

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
			return (1);
		}

		/*tokenize the user input*/


		printf("%s\n", line);

	}
	free(line);
	return (0);
}
