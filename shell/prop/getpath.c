#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

char *get_full_path(char *command) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return NULL;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return NULL;
    }

    if (pid == 0) {
        // Child process
        close(pipefd[0]); // Close the read end of the pipe
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to the pipe

        char *which_args[] = {"which", command, NULL};
        execvp("which", which_args);
        perror("execvp");
        exit(1);
    } else {
        // Parent process
        close(pipefd[1]); // Close the write end of the pipe

        const int BUFFER_SIZE = 1024;
        char buffer[BUFFER_SIZE];
        ssize_t read_size = read(pipefd[0], buffer, BUFFER_SIZE - 1);
        if (read_size == -1) {
            perror("read");
            return NULL;
        }
        buffer[read_size] = '\0';

        wait(NULL);

        // Trim the trailing newline character from the result
        char *newline_ptr = strchr(buffer, '\n');
        if (newline_ptr != NULL) {
            *newline_ptr = '\0';
        }

        // Return a dynamically allocated copy of the result
        return strdup(buffer);
    }
}
