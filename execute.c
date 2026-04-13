#include "shell.h"

/**
 * find_path - finds full path of a command
 * @cmd: the command to find
 * Return: full path or NULL
 */
char *find_path(char *cmd)
{
	char *path;
	char *path_copy;
	char *dir;
	char *full;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (strdup(cmd));
	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full = malloc(strlen(dir) + strlen(cmd) + 2);
		if (full == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full, "%s/%s", dir, cmd);
		if (stat(full, &st) == 0)
		{
			free(path_copy);
			return (full);
		}
		free(full);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * execute - executes a command
 * @args: array of arguments
 * @progname: name of the shell
 * Return: 1 to continue, 0 to stop
 */
int execute(char **args, char *progname)
{
	pid_t pid;
	int status;
	char *path;

	if (strcmp(args[0], "exit") == 0)
		exit(0);
	path = find_path(args[0]);
	if (path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", progname, args[0]);
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror(progname);
			free(path);
			exit(1);
		}
	}
	else if (pid > 0)
		waitpid(pid, &status, 0);
	free(path);
	return (1);
}
