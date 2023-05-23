#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * extractSubstrings -extractSubstrings
 * @lne: line
 * @searchStr: searchStr
 * @subs1: substring1
 * @subs2: substring2
 */
void extractSubstrings(char *lne, char *searchStr, char **subs1, char **subs2)
{
	char *substring;
	char *token;

	substring = _strstr(lne, searchStr);
	if (substring != NULL)
	{
		substring += _strlen(searchStr);
		while (*substring == ' ')
		{
			substring++;
		}
		token = _strtok(substring, " ");
		if (token != NULL)
		{
			*subs1 = token;
		}
		token = _strtok(NULL, " ");
		if (token != NULL)
		{
			*subs2 = token;
		}
	}
}


/**
 * _setenv - _setenv
 * @name: name of the variable to set
 * @value: valuse to set the variable to
 * @overwrite: to over write if it exists
 * Return: 0 on success
 */
int _setenv(char *name, char *value, int overwrite)
{
	size_t nameLength;
	size_t valueLength;
	size_t bufferSize;
	char *buffer;
	int result;

	if (name == NULL || value == NULL)
	{
		return (-1);
	}
	if (!overwrite && _getenv(name) != NULL)
	{
		return (0);
	}
	nameLength = _strlen(name);
	valueLength = _strlen(value);
	bufferSize = nameLength + valueLength + 2;
	buffer = malloc(bufferSize);
	if (buffer == NULL)
	{
		return (-1);
	}
	snprintf(buffer, bufferSize, "%s=%s", name, value);
	result = _putenv(buffer);
	if (result != 0)
	{
		return (-1);
	}
	return (0);
}



/**
 * _getenv - _getenv
 * @name: name
 * Return: a pointer to the env
 */
char *_getenv(char *name)
{
	size_t nameLength;
	char **env;

	if (name == NULL)
	{
		return (NULL);
	}
	nameLength = _strlen(name);
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, nameLength) == 0)
		{
			if ((*env)[nameLength] == '=')
			{
				return (&(*env)[nameLength + 1]);
			}
		}
	}
	return (NULL);
}



/**
 * _putenv - _putenv
 * @string: string
 * Return: 0 on success
 */
int _putenv(char *string)
{
	char *nameValueSeparator;
	size_t nameLength;
	char *name;
	int result;

	if (string == NULL || string[0] == '\0' || _strchr(string, '=') == NULL)
	{
		return (-1);
	}
	nameValueSeparator = _strchr(string, '=');
	nameLength = nameValueSeparator - string;
	name = malloc(nameLength + 1);
	_strncpy(name, string, nameLength);
	name[nameLength] = '\0';
	result = setenv(name, nameValueSeparator + 1, 1);
	free(name);

	if (result == -1)
	{
		return (-1);
	}
	return (0);
}


/**
 * _unsetenv - _unsetenv
 * @name: name
 * Return: 0 on success
 */
int _unsetenv(char *name)
{
	size_t nameLength;
	char **envp;
	char *equalSign;
	size_t varLength;
	char **nextEnvp;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
	{
		return (-1);
	}
	nameLength = _strlen(name);
	envp = environ;
	while (*envp != NULL)
	{
		equalSign = _strchr(*envp, '=');
		if (equalSign != NULL)
		{
			varLength = equalSign - *envp;
			if (varLength == nameLength && _strncmp(*envp, name, varLength) == 0)
			{
				nextEnvp = envp + 1;
				while (*envp != NULL)
				{
					*envp = *nextEnvp;
					envp++;
					nextEnvp++;
				}
				return (0);
			}
		}
		envp++;
	}
	return (0);
}

