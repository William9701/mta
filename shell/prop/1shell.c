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
 */
void run_shell(void)
{
	char *line = NULL;
	size_t buffer = 0;
	ssize_t get;

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		get = getline(&line, &buffer, stdin);
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
		line[strcspn(line, "\n")] = '\0';
		if (strcmp(line, "exit") == 0)
		{
			break;
		}
		if (strcmp(line, "env") == 0)
		{
			print_environment_variables();
			continue;
		}
		process(line);
	}
	free(line);
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

