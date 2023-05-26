#include "simple_shell.h"

/**
 * new_process - func that create a new process
 * @args: arrays of strings
 * Return: 1 (success) , 0(fails)
 */

int new_process(char **args)
{
	pid_t cpid;
	int status;

	cpid = fork();
	if (cpid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error in new_process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (cpid < 0)
	{
		perror("error in new_process: forking");
	}
	else
	{
		do {
			waitpid(cpid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
