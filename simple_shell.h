#ifndef _SIMPLE_SHELL_H_
#define _SIMPLE_SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

void interactive_shell(void);
void non_interactive_shell(void);
char *read_line(void);
char **split_line(char *ptr);
int execute_args(char **args);
int new_process(char **args);
char *read_stream(void);
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);

#endif
