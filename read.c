#include "shell.h"

/**
 * read_line - reads a line from stdin
 * Return: the line read, or NULL on EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	if (line[n - 1] == '\n')
		line[n - 1] = '\0';
	return (line);
}
