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
	int ret;
	(void)argc;

	ret = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			exit(ret);
		}
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		args = split_line(line);
		if (args != NULL && args[0] != NULL)
			ret = execute(args, argv[0]);
		free_args(args);
		free(line);
	}
	return (ret);
}
