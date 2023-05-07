#include <stdio.h>

int _strlen(char *s)
{
	int i;
	int count = 0;

	for (i = 0; s[i] != '\0'; s++)
		count++;
	return count;
}
