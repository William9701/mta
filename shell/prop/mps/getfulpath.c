#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

char *get_full_path(char *command) {
    char *path = strchr(command, '/');
    if (path != NULL) {
        // Extract the directory path and command
        char *directory = strtok(command, "/");
        char *command_name = strtok(NULL, "/");
        
        // Check if the command is accessible within the directory path
        char full_path[1024]; // Adjust the size as needed
        snprintf(full_path, sizeof(full_path), "%s/%s", directory, command_name);
        if (access(full_path, X_OK) == 0) {
            return strdup(full_path);
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

