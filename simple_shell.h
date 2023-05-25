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
int cd_cmd(char **args);
int exit_cmd(char **args);
int env_cmd(char **args);
int help_cmd(char **args);

#endif
