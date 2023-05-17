#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

char *get_full_path(char *command) {
    int fd[2];
    if (pipe2(fd, 0) == -1) {
        perror("pipe2");
        return NULL;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return NULL;
    }

    if (pid == 0) {
        // Child process
        close(fd[0]); // Close the read end of the pipe

        if (fd[1] != STDOUT_FILENO) {
            dup2(fd[1], STDOUT_FILENO);
            close(fd[1]);
        }

        char *which_args[] = {"/usr/bin/which", command, NULL};
        execv(which_args[0], which_args);
        perror("execv");
        _exit(1);
    } else {
        // Parent process
        close(fd[1]); // Close the write end of the pipe

        const int BUFFER_SIZE = 1024;
        char buffer[BUFFER_SIZE];
        ssize_t read_size = read(fd[0], buffer, BUFFER_SIZE - 1);
        if (read_size == -1) {
            perror("read");
            return NULL;
        }
        buffer[read_size] = '\0';

        close(fd[0]); // Close the read end of the pipe

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

