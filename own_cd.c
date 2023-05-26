#include "simple_shell.h"

/**
 * own_cd - change directory
 * @args: command
 * Return: result
 */

int own_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "own_cd: expected argument to \"cd\"\n");
		return (1);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("own_cd");
			return (1);
		}
	}
	return (0);
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
