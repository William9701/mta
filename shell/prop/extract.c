#include <stdlib.h>
#include <string.h>
#include "shell.h"


void extractSubstrings(char *line, char *searchStr, char **substring1, char **substring2)
{
    char *substring;
    char *token;

    substring = strstr(line, searchStr);
    if (substring != NULL) {
        substring += strlen(searchStr);

        while (*substring == ' ')
	{
            substring++;
        }
        token = strtok(substring, " ");
        if (token != NULL)
	{
            *substring1 = token;
        }
	token = strtok(NULL, " ");
        if (token != NULL)
	{
            *substring2 = token;
        }
    }
}



int _setenv(char *name, char *value, int overwrite) 
{
	size_t nameLength;
	size_t valueLength;
	size_t bufferSize;
	char *buffer;
	int result;
    if (name == NULL || value == NULL)
        return -1;

    if (!overwrite && _getenv(name) != NULL)
        return 0;

    nameLength = strlen(name);
    valueLength = strlen(value);
    bufferSize = nameLength + valueLength + 2;
    buffer = malloc(bufferSize);

    if (buffer == NULL)
        return -1;

    snprintf(buffer, bufferSize, "%s=%s", name, value);

    result = _putenv(buffer);
    if (result != 0)
    {
        return -1;
    }

    return 0;
}




char *_getenv(char *name)
{
	size_t nameLength;
	char **env;
    if (name == NULL)
        return NULL;

    nameLength = strlen(name);

    for (env = environ; *env != NULL; env++) 
    {
        if (strncmp(*env, name, nameLength) == 0) 
	{
            
            if ((*env)[nameLength] == '=')
	    {
                return &(*env)[nameLength + 1];
            }
        }
    }

    return NULL;
}



int _putenv(char *string)
{
	char *nameValueSeparator;
	size_t nameLength;
	char *name;
	int result;

    if (string == NULL || string[0] == '\0' || strchr(string, '=') == NULL)
        return -1;

    nameValueSeparator = strchr(string, '=');
    nameLength = nameValueSeparator - string;
    name = malloc(nameLength + 1);
    strncpy(name, string, nameLength);
    name[nameLength] = '\0';

    result = setenv(name, nameValueSeparator + 1, 1);

    free(name);

    if (result == -1)
        return -1;

    return 0;
}


int _unsetenv(char *name)
{
	size_t nameLength;
	char **envp;
	char *equalSign;
	size_t varLength;
	char **nextEnvp;

    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
        return -1;

    nameLength = strlen(name);

    envp = environ;


    while (*envp != NULL) {
        
        equalSign = strchr(*envp, '=');
        if (equalSign != NULL) {
            varLength = equalSign - *envp;
            if (varLength == nameLength && strncmp(*envp, name, varLength) == 0) {
                
                nextEnvp = envp + 1;

                
                while (*envp != NULL) {
                    *envp = *nextEnvp;
                    envp++;
                    nextEnvp++;
                }

                return 0;
            }
        }

        envp++;
    }

    return 0;
}

