#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include <stdlib.h>

/**
 * print_environment_variables - print_environment_variables
 */
void print_environment_variables(void)
{
	int i;
	size_t lenght;

	for (i = 0; environ[i] != NULL; i++)
	{
		lenght = strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], lenght);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * arrange - arrange
 * @line: line
 */
void arrange(char *line)
{
	char *commands[10];
	char *token;
	int num_commands = 0;
	int i;

	token = strtok(line, "&&");
	while (token != NULL)
	{
		commands[num_commands++] = token;
		token = strtok(NULL, "&&");
	}
	for (i = 0; i < num_commands; i++)
	{
		if (execute(commands[i]) != 0)
		{
			break;
		}
	}
}


/**
 * parrange - parrange
 * @line: line
 */
void parrange(char *line)
{
	char *commands[10];
	char *token;
	int num_commands = 0;
	int i;

	token = strtok(line, "&&");
	while (token != NULL)
	{
		commands[num_commands++] = token;
		token = strtok(NULL, "&&");
	}
	for (i = 0; i < num_commands; i++)
	{
		if (execute(commands[i]) == 0)
		{
			break;
		}
	}
}
