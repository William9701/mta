#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _strcmp - _strcmp
 * @str1: string one
 * @str2: strring to check with
 * Return: count
 */
int _strcmp(char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (str1[i] - str2[i]);
}

/**
 * _strcspn - _strcspn
 * @string: string
 * @charset: string to check with
 * Return: piosition
 */

size_t _strcspn(char *string, const char *charset)
{
	const char *p;
	const char *s;

	for (s = string; *s != '\0'; ++s)
	{
		for (p = charset; *p != '\0'; ++p)
		{
			if (*s == *p)
			{
				return (s - string);
			}
		}
	}
	return (s - string);
}

/**
 * process - process the files
 * @line: line of input
 */
void process(char *line)
{
	char *command, *full_path, **arguments;
	int arg_count = 0;
	pid_t pid;

	command = _strtok(line, " ");
	arguments = NULL;
	while (command != NULL)
	{
		arguments = realloc(arguments, sizeof(char *) * (arg_count + 1));
		arguments[arg_count] = command;
		arg_count++;
		command = _strtok(NULL, " ");
	}
	arguments = realloc(arguments, sizeof(char *) * (arg_count + 1));
	arguments[arg_count] = NULL;
	full_path = get_full_path(arguments[0]);
	if (access(full_path, X_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
		perror("fork");
		}
		if (pid == 0)
		{
		execute_command(full_path, arguments);
		free(full_path);
		free(arguments);
		free(line);
		exit(1);
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
	perror("Command not found");
	}
}

