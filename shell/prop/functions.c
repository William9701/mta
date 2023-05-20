#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

char *extractWord(char *line) 
{
    const char* delimiter = " ";
    char* extractedWord = NULL;
    
    char* lineCopy = strdup(line);
    char* token = strtok(lineCopy, delimiter);
    
    while (token != NULL) {
        if (strcmp(token, "unsetenv") == 0) {
            token = strtok(NULL, delimiter);
            if (token != NULL) {
                extractedWord = strdup(token);
            }
            break;
        }
        token = strtok(NULL, delimiter);
    }
    
    free(lineCopy);
    
    return extractedWord;
}

char *cdextractWord(char *line)
{
    const char* delimiter = " ";
    char* extractedWord = NULL;
    
    char* lineCopy = strdup(line);
    char* token = strtok(lineCopy, delimiter);
    
    while (token != NULL) {
        if (strcmp(token, "cd") == 0) {
            extractedWord = strdup(token);
            break;
        }
        token = strtok(NULL, delimiter);
    }
    
    free(lineCopy);
    
    return extractedWord;
}


int change_directory(char *path)
{
	char *home;
	char *previousDir;
	int result;
	char *cwd;
    
    if (path == NULL || path[0] == '\0') {
        home = _getenv("HOME");
        if (home == NULL) {
            fprintf(stderr, "Unable to get HOME environment variable.\n");
            return -1;
        }
        path = home;
    }

    
    if (path[0] == '-' && path[1] == '\0') {
        previousDir = _getenv("OLDPWD");
        if (previousDir == NULL) {
            fprintf(stderr, "Unable to get OLDPWD environment variable.\n");
            return -1;
        }
        path = previousDir;
    }

    result = chdir(path);
    if (result != 0) {
        perror("Error changing directory");
        return -1;
    }

    
    cwd = getcwd(NULL, 0);
    if (cwd != NULL) {
        _setenv("OLDPWD", _getenv("PWD"), 1);
        _setenv("PWD", cwd, 1);
        free(cwd);
    }

    return 0;
}
