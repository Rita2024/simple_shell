#include "simple_shell.h"

/**
 * own_cd - change directory
 * @args: command
 * Return: result
 */

int own_cd(char **args)
{
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "expected argument to \"cd\"\n");
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("error");
			}
		}
		return (1);
	}
}

/**
 * main - main function
 * Return: 0
 */

int main(void)
{
	char *args[] = {"cd", "/path/to/directory", NULL};

	own_cd(args);

	return (0);
}
