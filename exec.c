#include "main.h"

void exec(char **argv)
{
	char *cmd = NULL;
	
	if (argv)
	{
		cmd = argv[0];
		
		if (execve(cmd, argv, NULL) == -1)
			perror("execve failed");
	}
}
