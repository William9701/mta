#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"
#include <stddef.h>

/**
 * get_exit_code - get_exit_code
 * @line: line
 * Return: the next number
 */
int get_exit_code(char *line)
{

	int number = 0;
	int i;

	for (i = 0; i < _strlen(line); i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			number = number * 10 + (line[i] - '0');
		}
	}
	return (number);

}

/**
 * _strtok - Tokenize a string
 * @str: The string to tokenize
 * @delim: The delimiter characters
 * Return: Pointer to the next token in the string, or NULL if no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	char *token_start;
	const char *d;
	static char *next_token = NULL;
	bool found_delim = false;

	if (str != NULL)
	{
		next_token = str;
	}
	if (next_token == NULL || *next_token == '\0')
	{
		return (NULL);
	}
	token_start = next_token;
	while (*next_token)
	{
	{
		d = delim;
	}
	while (*d)
	{
		if (*next_token == *d)
		{
			*next_token = '\0';
			next_token++;
			found_delim = true;
			break;
		}
		d++;
	}
	if (found_delim)
	{
		break;
	}
	next_token++;
	}

	return (token_start);
}

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 * Return: Pointer
 */
char *_strdup(const char *str)
{
	size_t len;
	const char *s;
	char *duplicate;
	char *dup_iter;

	if (str == NULL)
	{
		return (NULL);
	}
	len = 0;
	s = str;
	while (*s++)
		len++;

	duplicate = (char *) malloc((len + 1) * sizeof(char));

	if (duplicate == NULL)
	{
		return (NULL);
	}
	dup_iter = duplicate;

	while (*str)
		*dup_iter++ = *str++;

	*dup_iter = '\0';

	return (duplicate);
}

