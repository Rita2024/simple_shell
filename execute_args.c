#include "simple_shell.h"

/**
 * execute_args - check if the command is in a process or builtin
 * @args: commands and its flags
 * Return: 1(on success), 0(on failure)
 */

int execute_args(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit",
	};
	int (*builtin_func[])(char **) = {
		&own_cd,
		&own_env,
		&own_help,
		&own_exit,
	};
	unsigned int x;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (x = 0; x < sizeof(builtin_func_list) / sizeof(char *); x++)
	{
		if (strcmp(args[0], builtin_func_list[x]) == 0)
		{
			return ((*builtin_func[x])(args));
		}
	}
	return (new_process(args));
}
