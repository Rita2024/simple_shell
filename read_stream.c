#include "simple_shell.h"

/**
 * read_stream - read a line from the stram
 * Return: result
 */

char *read_stream(void)
{
	int bufsize = 1024;
	char *ptr = malloc(sizeof(char *) * bufsize);
	int nchar, x = 0;

	if (ptr == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		nchar = getchar();
		if (nchar == EOF)
		{
			free(ptr);
			exit(EXIT_SUCCESS);
		}
		else if (nchar == '\n')
		{
			ptr[x] = '\0';
			return (ptr);
		}
		else
		{
			ptr[x] = nchar;
		}
		x++;
		if (x >= bufsize)
		{
			bufsize += bufsize;
			ptr = realloc(ptr, bufsize);
			if (ptr == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
