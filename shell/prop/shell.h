#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
extern char **environ;
int run_shell();
void execute_command(char *command, char **args);
void _fork(char *line);
char *get_full_path(char *command);
void print_environment_variables();
void process(char *line);
ssize_t _GetLine(char **lineptr, size_t *n, FILE *stream);
size_t _strcspn(char *string, const char *charset);
int _strcmp(char *str1, const char *str2);
int _atoi(char *s);
int is_exit_command(char *line);
int get_exit_code(char *line);
void my_exit(int exit_code);
int _putenv(char *string);
int _setenv(char *name, char *value, int overwrite);
char *_getenv(char *name);
void extractSubstrings(char *line, char *searchStr, char **substring1, char **substring2);
int _unsetenv(char *name);
char *extractWord(char *line);
char *cdextractWord(char *line);
int change_directory(char *path);

#endif

