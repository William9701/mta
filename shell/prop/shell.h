#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
int run_shell(void);
void execute_command(char *command, char **args);
void _fork(char *line);
char *get_full_path(char *command);
void print_environment_variables(void);
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
void extractSubstrings(char *lne, char *searchStr, char **subs1, char **subs2);
int _unsetenv(char *name);
char *extractWord(char *line);
char *cdextractWord(char *line);
int change_directory(char *path);
void cut(char *line);
void pprocess(char *line);
void split_and_process(char *line);
int execute(char *command);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
char *_strstr(const char *haystack, const char *needle);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
int _execvp(char *file, char *const argv[]);
char *_strdup(const char *str);
char *_strtok(char *str, const char *delim);
char *read_line(void);
void process_line(char *line);
void print_prompt(void);
int change(char *line);
int set(char *line);
int unset(char *line);


#endif

