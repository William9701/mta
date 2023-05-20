#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"

/**
 * _atoi - covert
 * @s: the pointer
 * Return: a integer
 */

int _atoi(char *s)
{

	int c = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (s[c])
	{
		if (s[c] == 45)
		{
			min *= -1;
		}
		while (s[c] >= 48 && s[c] <= 57)
		{
			isi = 1;
			ni = (ni * 10) + (s[c] - '0');
			c++;
		}
		if (isi == 1)
		{
			break;
		}
		c++;
	}
	ni *= min;
	return (ni);
}


/**
 * is_exit_command - is_exit_command
 * @line: line
 * Return: true/false
 */
int is_exit_command(char *line)
{
	char *token;

    token = strtok(line, " ");

    
    if (token != NULL && strcmp(token, "exit") == 0) {
        return 1;
    } else {
        return 0; 
    }
}


/**
 * get_next_argument_as_integer - get_next_argument_as_integer
 * @line: line
 * Return: the next number
 */
int get_exit_code(char *line) 
{

	int number = 0;
	size_t i;

	for (i = 0; i < strlen(line); i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			number = number * 10 + (line[i] - '0');
		}
	}
	return number;

}


/**
 * my_exit - my_exit
 * @exit_code: exit code
 */
void my_exit(int exit_code)
{
       	exit(exit_code);
}
