#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>

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
 * run_shell - shell main program
 * Return: 0
 */
int run_shell()
{
	char *line = NULL;
	size_t buffer = 0;
	ssize_t get;
	char *searchStr;
	char* extractedWord;
	char *substring1;
	char *substring2;
	char *directory;
	int exit_code;

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		get = _GetLine(&line, &buffer, stdin);
		if (get == -1)
		{
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 2);
			break;
		}
		else
		{
			perror("getline");
			continue;
		}
		}
		line[_strcspn(line, "\n")] = '\0';
		if (strstr(line, "exit"))
		{
				exit_code = get_exit_code(line);
				exit(exit_code);
		
		}
		if (strstr(line, "cd"))
		{
			directory = NULL;
			directory = cdextractWord(line);
			if (directory != NULL)
			{
				 if (change_directory(directory) != 0)
				 {
					 perror("cant change");
					 continue;
				 }
			}
			continue;
		}

		if (strncmp(line, "setenv", 6) == 0)
		{
			searchStr = "setenv";
			substring1 = NULL;
			substring2 = NULL;
			extractSubstrings(line, searchStr, &substring1, &substring2);
			if (substring1 != NULL && substring2 != NULL)
			{
				if(_setenv(substring1, substring2, 1) != 0)
				{
					perror("failed to set");
					continue;
				}
			}
			continue;
		}
		if (strncmp(line, "unsetenv", 8) == 0)
		{
			extractedWord= extractWord(line);
			if (extractedWord != NULL)
			{
				_unsetenv(extractedWord);
				continue;
			}
			perror("failed");
			continue;
		}

		if (_strcmp(line, "env") == 0)
		{
			print_environment_variables();
			continue;
		}
		process(line);
	}
	free(line);
	return (0);
}

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
 * @str: string
 * @charset: string to check with
 * Return: piosition
 */

size_t _strcspn(char *string, const char *charset)
{
    const char* p;
    const char* s;
    for (s = string; *s != '\0'; ++s) {
        for (p = charset; *p != '\0'; ++p) {
            if (*s == *p) {
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

	command = strtok(line, " ");
	arguments = NULL;
	while (command != NULL)
	{
		arguments = realloc(arguments, sizeof(char *) * (arg_count + 1));
		arguments[arg_count] = command;
		arg_count++;
		command = strtok(NULL, " ");
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

