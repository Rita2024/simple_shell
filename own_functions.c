#include "simple_shell.h"

/**
 * own_exit - exit or terminate the shell
 * @args: command
 * Return: result
 */

int own_exit(char **args)
{
	if (args[1] != NULL)
	{
		int exitcode = atoi(args[1]);

		exit(exitcode);
	}
	exit(0);
}

/**
 * own_env - environment variable
 * @args: command
 * Return: result
 */

int own_env(char **args)
{
	int x = 0;
	char *env_var;

	while ((env_var = getenv(args[x])) != NULL)
	{
		printf("%s\n", env_var);
		x++;
	}

	return (0);
}

/**
 * own_help - display help message
 * @args: command
 * Return: result
 */

int own_help(char **args)
{
	args(void);

	printf("=== Custom Shell Help ===\n");
	printf("Available commands:\n");
	printf("cd [directory] - Change the current directory\n");
	printf("exit - Terminate the shell\n");
	printf("env - Display environment variables\n");
	printf("help - Display this help message\n");
	return (1);
}
