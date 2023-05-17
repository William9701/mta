#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

void execute_command(char *command) 
{
    char *argv[] = {command, NULL};
    execvp(command, argv);
    perror("execvp");
    exit(1);
}

