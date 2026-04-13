#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

/* Prototypes */
char *read_line(void);
char **split_line(char *line);
int execute(char **args, char *progname);
char *find_path(char *cmd);
void free_args(char **args);

#endif /* SHELL_H */
