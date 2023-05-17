#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int i;
    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            execute_command(argv[i]);
        }
    } else {
        run_shell();
    }
    return 0;
}

void run_shell() {
    char *line = NULL;
    size_t buffer = 0;
    ssize_t get;
    pid_t pid;

    while (1) {
        if (isatty(fileno(stdin))) {
            // Interactive Mode
            write(STDOUT_FILENO, "$ ", 2);
        }

        get = getline(&line, &buffer, stdin);
        if (get == -1) {
            if (feof(stdin)) {
                write(STDOUT_FILENO, "\n", 2); // Print a newline before exiting on Ctrl+D (end of file).
                break;
            } else {
                perror("getline");
                continue;
            }
        }
        line[get - 1] = '\0';

        // Check if the command exists by attempting to resolve its full path
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
            pid = fork();
            if (pid == -1) {
                perror("fork");
                free(full_path);
                continue;
            }

            if (pid == 0) {
                // Child process
                execute_command(full_path);
                free(full_path); // Free full_path in the child process
                exit(1);
            } else {
                // Parent process
                wait(NULL);
            }
        } else {
            // Failed to resolve the full path, command does not exist
            fprintf(stderr, "Command not found: %s\n", command);
        }
    }

    free(line);
}
