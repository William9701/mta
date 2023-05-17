#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int i;
    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            execute_command(argv[i], NULL);
        }
    } else {
        run_shell();
    }
    return 0;
}
void run_shell()
{
    char *line = NULL;
    size_t buffer = 0;
    char *file;
    char *arg;
    char* command;
    char** arguments;
    int arg_count;
    char* full_path;
    ssize_t get;
    pid_t pid;

    while (1) 
    {
	if (isatty(fileno(stdin))) 
	{
		write(STDOUT_FILENO, "$ ", 2);
		get = getline(&line, &buffer, stdin);
			if (get == -1) 
			{
				if (feof(stdin)) 
				{
				write(STDOUT_FILENO, "\n", 2); // Print a newline before exiting on Ctrl+D (end of file).
				break;
			}
			else
			{
			perror("getline");
			continue;
			}
			}
		line[get - 1] = '\0';
	}
	else
	{
		if (getline(&line, &buffer, stdin) == -1)
		{
		break;
		}
		line[strcspn(line, "\n")] = '\0';
	}

	if (strcmp(line, "exit") == 0)
	{
		break;
	}

	if (strcmp(line, "env") == 0)
	{
		print_environment_variables();
		continue;
	}

 if (access(line, X_OK) == 0 || strchr(line, '/') != NULL) {
            // Command is accessible or has an absolute path, execute it
            command = line;
            arguments = NULL;
            arg_count = 0;

            if (strchr(line, '/') != NULL) {
                // Command has an absolute path, extract the command and arguments
                command = strtok(line, " ");
                arguments = realloc(arguments, sizeof(char*) * (arg_count + 1));
                arguments[0] = command;
                arg_count = 1;

                while ((arg = strtok(NULL, " ")) != NULL) {
                    arguments[arg_count] = arg;
                    arg_count++;
                }
                arguments[arg_count] = NULL;
            }

            pid_t pid = fork();
            if (pid == -1) {
                 perror("fork");
                continue;
            }

            if (pid == 0) {
                // Child process
                execute_command(command, arguments);
                if (arguments != NULL) {
                    free(arguments);
                }
                exit(1);
            } else {
                // Parent process
                wait(NULL);
            }
        else {
            perror("Command cannot be found");
        }

	
        } else {
            if (strchr(line, ' ') == NULL) {
                file = get_full_path(line);
                if (file != NULL) {
                    pid = fork();
                    if (pid == -1) {
                        perror("fork");
                        continue;
                    }
                    if (pid == 0) {
                        execute_command(file, NULL);
                        free(file);
                        exit(1);
                    } else {
                        // Parent process
                        wait(NULL);
                    }
                } else {
                    perror("Command cannot be found");
                }
            } else {
                command = strtok(line, " /");
                arguments = NULL;
                arg_count = 0;

                while (command != NULL) {
                    arguments = realloc(arguments, sizeof(char*) * (arg_count + 1));
                    arguments[arg_count] = command;
                    arg_count++;

                    command = strtok(NULL, " /");
                }

                arguments = realloc(arguments, sizeof(char*) * (arg_count + 1));
                arguments[arg_count] = NULL;

                full_path = get_full_path(arguments[0]);

                if (full_path == NULL) {
                    perror("Error:");
                    free(line);
                    free(arguments);
                    exit(1);
                } else {
                    pid = fork();
                    if (pid == -1) {
                        perror("fork");
                        continue;
                    }
                    if (pid == 0) {
                        execute_command(full_path, arguments);
                        free(full_path);
                        free(arguments);
                        free(line);
                        exit(1);
                    } else {
                        // Parent process
                        wait(NULL);
                    }
                }
            }
        }
    }
}
       
