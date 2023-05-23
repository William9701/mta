#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * extractWord - extractWord
 * @line: line
 * Return: extracted word
 */
char *extractWord(char *line)
{
	const char *delimiter = " ";
	char *extractedWord = NULL;

	char *lineCopy = _strdup(line);
	char *token = _strtok(lineCopy, delimiter);

	while (token != NULL)
	{
		if (_strcmp(token, "unsetenv") == 0)
		{
			token = _strtok(NULL, delimiter);
			if (token != NULL)
			{
				extractedWord = _strdup(token);
			}
			break;
		}
		token = _strtok(NULL, delimiter);
	}
	free(lineCopy);
	return (extractedWord);
}

/**
 * cdextractWord - cdextractWord
 * @line: line
 * Return: extracted word
 */
char *cdextractWord(char *line)
{
	const char *delimiter = " ";
	char *extractedWord = NULL;

	char *lineCopy = _strdup(line);
	char *token = _strtok(lineCopy, delimiter);

	while (token != NULL)
	{
		if (_strcmp(token, "cd") == 0)
		{
			token = _strtok(NULL, delimiter);
			if (token != NULL)
			{
				extractedWord = _strdup(token);
			}
			break;
		}
		token = _strtok(NULL, delimiter);
	}
	free(lineCopy);
	return (extractedWord);
}

/**
 * change_directory - change_directory
 * @path: path
 * Return: 0
 */
int change_directory(char *path)
{
	char *home;
	char *previousDir;
	int result;
	char *cwd;

	if (path == NULL || path[0] == '\0')
	{
		home = _getenv("HOME");
		if (home == NULL)
		{
			perror("Unable to get HOME environment variable");
			return (-1);
		}
		path = home;
	}
	if (path[0] == '-' && path[1] == '\0')
	{
		previousDir = _getenv("OLDPWD");
		if (previousDir == NULL)
		{
			perror("Unable to get OLDPWD environment variable");
			return (-1);
		}
		path = previousDir;
	}
	result = chdir(path);
	if (result != 0)
	{
		perror("Error changing directory");
		return (-1);
	}
	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		_setenv("OLDPWD", _getenv("PWD"), 1);
		_setenv("PWD", cwd, 1);
		free(cwd);
	}
	return (0);
}


/**
 * pprocess - pprocess
 * @line: line
 */
void pprocess(char *line)
{
	char *command;

	command = _strtok(line, ";");
	while (command != NULL)
	{
		execute(command);
		command = _strtok(NULL, ";");
	}
}


/**
 * execute - execute
 * @command: comand
 * Return: 0
 */
int execute(char *command)
{
	pid_t pid;
	int status;
	char *argv[] = {"/bin/sh", "-c", NULL, NULL};

	argv[2] = (char *)command;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		perror("execve");
		exit(1);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (-1);
		}
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status))
		{
			return (WTERMSIG(status));
		}
		else
		{
			return (-1);
		}
	}
}
