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
	extern char **environ;

	execve(command, arguments, environ);
	perror("");
	exit(1);
}

