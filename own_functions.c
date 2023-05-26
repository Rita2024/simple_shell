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
	char **env = environ;

	if (strcmp(args[0], "env") == 0)
	{
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (1);
}

/**
 * own_help - display help message
 * @args: command
 * Return: result
 */

int own_help(char **args)
{
	char *args[] = {NULL};

	if (args[0] == NULL)
	{
		printf("=== Custom Shell Help ===\n");
		printf("Available commands:\n");
		printf("cd [directory] - Change the current directory\n");
		printf("exit - Terminate the shell\n");
		printf("env - Display environment variables\n");
		printf("help - Display this help message\n");
		return (1);
	}
	else if (strcmp(args[0], "help") == 0)
	{
		own_help(args);
		return (1);
	}
	else
		return (1);
}
