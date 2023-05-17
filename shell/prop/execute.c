#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

void execute_command(char *command, char** arguments) {
    //char *token;
     extern char** environ;
    execve(command,arguments, environ); // Execute the command
    perror("");
    exit(1);
}

