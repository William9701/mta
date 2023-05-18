#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * get_full_path - get_full_path
 * @command: commandi
 * Return: full path
 */
char *get_full_path(char *command)
{
	int pipefd[2];
	const int BUFFER_SIZE = 1024;
	char buffer[1024];
	ssize_t read_size;
	char *which_args[3];
	char *newline_ptr;
	pid_t pid;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (NULL);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (NULL);
	}
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		which_args[0] = "which";
		which_args[1] = command;
		which_args[2] = NULL;
		execvp("which", which_args);
		perror("execvp");
		exit(1);
	}
	else
	{
		close(pipefd[1]);
		read_size = read(pipefd[0], buffer, BUFFER_SIZE - 1);
		if (read_size == -1)
		{
			perror("read");
			return (NULL);
		}
		buffer[read_size] = '\0';
		wait(NULL);
		newline_ptr = strchr(buffer, '\n');
		if (newline_ptr != NULL)
		{
			*newline_ptr = '\0';
		}
		return (strdup(buffer));
	}
}
