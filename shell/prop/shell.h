#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>

void run_shell();
void execute_command(char *command, char **args);
void _fork(char *line);
char *get_full_path(char *command);
void print_environment_variables();
void process(char *line);

#endif

