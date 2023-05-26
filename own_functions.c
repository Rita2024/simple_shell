#include "simple_shell.h"

/**
 * own_exit - exit shell
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
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (1);
}

/**
 * own_help - help
 * @args: command
 * Return: result
 */

int own_help(char **args)
{
	printf("=== Custom Shell Help ===\n");
	printf("Available commands:\n");
	printf("cd [directory] - Change the current directory\n");
	printf("exit - Terminate the shell\n");
	printf("env - Display environment variables\n");
	printf("help - Display this help message\n");
	return (1);
}

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
			fprintf(stderr, "Expected argument to \"cd\"\n");
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("chdir");
			}
		}
		return (1);
	}
}
