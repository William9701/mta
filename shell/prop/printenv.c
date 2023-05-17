#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

extern char **environ;

void print_environment_variables()
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
