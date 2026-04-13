#include "shell.h"

/**
 * split_line - splits a line into tokens
 * @line: the line to split
 * Return: array of tokens
 */
char **split_line(char *line)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (tokens == NULL)
		return (NULL);
	token = strtok(line, " \t\r\n");
	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * free_args - frees an array of strings
 * @args: the array to free
 */
void free_args(char **args)
{
	if (args != NULL)
		free(args);
}
