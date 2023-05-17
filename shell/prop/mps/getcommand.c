#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* get_command_path(const char* command) 
{
    char* full_path = NULL;
    char* path_env = getenv("PATH");

    if (path_env == NULL) {
        printf("Error: PATH environment variable not set.\n");
        return NULL;
    }

    char* path_env_copy = strdup(path_env);
    char* token = strtok(path_env_copy, ":");

    while (token != NULL) {
        char* potential_path = (char*)malloc(strlen(token) + strlen(command) + 2);
        sprintf(potential_path, "%s/%s", token, command);

        if (access(potential_path, X_OK) == 0) {
            full_path = potential_path;
            break;
        }

        free(potential_path);
        token = strtok(NULL, ":");
    }

    free(path_env_copy);

    return full_path;
}
