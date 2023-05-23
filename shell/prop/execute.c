#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * execute_command - execute_command
 * @command: command
 * @arguments: arguments
 */


void execute_command(char *command, char **arguments)
{

	execve(command, arguments, environ);
	perror("");
}


/**
 * _execvp - Execute a program with arguments
 * @file: The path to the program to be executed
 * @argv: The array of arguments to pass to the program
 * Return: -1 on failure, does not return on success
 */
int _execvp(char *file, char *const argv[])
{
	char slash;
	char *const envp[] = {NULL};
	char *path_env = getenv("PATH");
	char *path = _strtok(path_env, ":");

	while (path != NULL)
	{
		size_t path_len = _strlen(path);
		size_t file_len = _strlen(file);
		size_t total_len = path_len + file_len + 2;
		char *path_file = (char *)malloc(total_len * sizeof(char));

		if (path_file == NULL)
		{
			return (-1);
		}
		slash = '/';
		write(1, path, path_len);
		write(1, &slash, 1);
		write(1, file, file_len);
		path_file[total_len - 1] = '\0';
		execve(path_file, argv, envp);
		free(path_file);
		path = _strtok(NULL, ":");
	}
	return (-1);
}

/**
 * unset - unset
 * @line: input
 * Return: 0 on success
 */
int unset(char *line)
{
	char *extractedWord = extractWord(line);

	if (extractedWord != NULL)
	{
		_unsetenv(extractedWord);
	}
	else
	{
		perror("failed");
	}
	return (0);
}
