#include "simple_shell.h"

/**
 * interactive_shell - Unix command line interpreter
 * Return: void
 */

void interactive_shell(void)
{
	char *ptr;
	char **args;
	int status = -1;

	do {
	/* print prompt sign */
		printf("#cisfun$ ");

/* read line from standard input */
		ptr = read_line();

	/* tokenized line */
		args = split_line(ptr);

		status = execute_args(args);

	/* avoid memory leak */
		free(ptr);
		free(args);

	/* exit with status */
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
