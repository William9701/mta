#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include <unistd.h>
#include <string.h>

/**
 * main - main
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	int i;

	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			execute_command(argv[i], NULL);
			return (0);
		}
	}
	else
	{
		run_shell();
	}
	return (0);
}

/**
 * print_prompt - print_prompt
 */
void print_prompt(void)
{
	if (isatty(fileno(stdin)))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}

/**
 * read_line - read_line
 * Return: char
 */
char *read_line(void)
{
	char *line = NULL;
	size_t buffer = 0;

	ssize_t get = _GetLine(&line, &buffer, stdin);

	if (get == -1)
	{
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 2);
			free(line);
			return (NULL);
		}
		else
		{
			perror("getline");
			free(line);
			return (NULL);
		}
	}
	line[_strcspn(line, "\n")] = '\0';
	return (line);
}


/**
 * process_line - process_line
 * @line: line
 */
void process_line(char *line)
{
	if (_strstr(line, ";"))
	{
		pprocess(line);
	}
	else if (_strstr(line, "exit"))
	{
		int exit_code = get_exit_code(line);

		exit(exit_code);
	}
	else if (_strstr(line, "cd"))
	{
		change(line);
	}
	else if (_strstr(line, "&&"))
	{
		arrange(line);
	}
	else if (_strstr(line, "||"))
	{
		parrange(line);
	}
	else if (_strncmp(line, "setenv", 6) == 0)
	{
		set(line);
	}
	else if (_strncmp(line, "unsetenv", 8) == 0)
	{
		unset(line);
	}
	else if (_strcmp(line, "env") == 0)
	{
		print_environment_variables();
	}
	else
	{
		process(line);
	}
}

/**
 * run_shell - run_shell
 * Return: 0
 */
int run_shell(void)
{
	char *line;

	while (1)
	{
		print_prompt();
		line = read_line();
		if (line == NULL)
		{
			return (0);
		}
		process_line(line);
		free(line);
	}
	return (0);
}
