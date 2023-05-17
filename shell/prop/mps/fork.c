#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void _fork(char *line) {
    pid_t pid;

    while (1) {
        if (access(line, X_OK) == 0) {
            // Command is accessible, execute it
            pid = fork();
            if (pid == -1) {
                perror("fork");
                continue;
            }

            if (pid == 0) {
                // Child process
                execute_command(line);
                exit(1);
            } else {
                // Parent process
                wait(NULL);
            }
        } else {
            // Command is not accessible, try to resolve the full path
            char *command = line;
            char *full_path = NULL;

            // Search for the command in the directories listed in the PATH environment variable
            char *path = getenv("PATH");
            if (path != NULL) {
                char *dir = strtok(path, ":");
                while (dir != NULL) {
                    size_t path_length = strlen(dir);
                    size_t command_length = strlen(command);
                    full_path = malloc(path_length + command_length + 2);
                    if (full_path == NULL) {
                        perror("malloc");
                        break;
                    }
                    strcpy(full_path, dir);
                    strcat(full_path, "/");
                    strcat(full_path, command);
                    if (access(full_path, X_OK) == 0) {
                        // Found the command, set the full path
                        break;
                    }
                    free(full_path);
                    dir = strtok(NULL, ":");
                }
            }

            if (full_path != NULL) {
                // Full path resolved successfully, execute the command
                pid = fork();
                if (pid == -1) {
                    perror("fork");
                    free(full_path);
                    continue;
                }

                if (pid == 0) {
                    // Child process
                    execute_command(full_path);
		    free(full_path);
                    exit(1);
                } else {
                    // Parent process
                    wait(NULL);
                }
            } else {
                // Failed to resolve the full path, command does not exist
                perror("command does not exist");
            }
        }
    }

    // Free the line outside the loop
    free(line);
}

