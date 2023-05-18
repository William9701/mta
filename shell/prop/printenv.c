#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

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
