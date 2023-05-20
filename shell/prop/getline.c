#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _GetLine - _GetLine
 * @lineptr: line
 * @n: size
 * @stream: where its reading from
 * Return: number
 */
ssize_t _GetLine(char **lineptr, size_t *n, FILE *stream)
{
	size_t capacity;
	int current_char;
	char *buffer;
	size_t position;
	char *temp;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	capacity = *n;
	if (*lineptr == NULL || capacity == 0)
	{
		capacity = 128;
		*lineptr = malloc(capacity);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
		buffer = *lineptr;
		position = 0;
		while ((current_char = fgetc(stream)) != EOF)
		{
			if (position >= capacity - 1)
			{
				capacity *= 2;
				temp = realloc(buffer, capacity);
				if (temp == NULL)
				{
					free(buffer);
					*lineptr = NULL;
					return (-1);
				}
				buffer = temp;
				*lineptr = buffer;
				*n = capacity;
			}
			buffer[position++] = current_char;
			if (current_char == '\n')
			{
				break;
			}
		}
		if (position == 0 && current_char == EOF)
		{
			return (-1);
		}
		buffer[position] = '\0';
		return (position);
}

