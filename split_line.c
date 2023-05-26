#include "simple_shell.h"

/**
 * split_line - split a string into multiple strings
 * @ptr: the string to be slited.
 * Return: result
 */

char **split_line(char *ptr)
{
	int bufsize = 64;
	int x = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *str;

	if (!tokens)
	{
		fprintf(stderr, "allocate error in split_line: tokens\n");
		exit(EXIT_FAILURE);
	}
	str = strtok(ptr, TOK_DELIM);
	while (str != NULL)
	{
		if (str[0] == '#')
		{
			break;
		}
		tokens[x] = str;
		x++;
		if (x >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char));
			if (!tokens)
			{
				fprintf(stderr, "reallocation error in split_line: tokensn");
				exit(EXIT_FAILURE);
			}
		}
		str = strtok(NULL, TOK_DELIM);
	}
	tokens[x] = NULL;
	return (tokens);
}
