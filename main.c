#include "shell.h"

/**
 * main - entry point of the shell
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *line;
	char **args;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			exit(0);
		}
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		args = split_line(line);
		if (args != NULL && args[0] != NULL)
			execute(args, argv[0]);
		free_args(args);
		free(line);
	}
	return (0);
}
