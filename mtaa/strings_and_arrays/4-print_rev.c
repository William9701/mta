#include "main.h"

void print_rev(char *s)
{
	int i;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
		count++;
	for (i = count; i >= 0; i--)
	{
		putchar(s[i]);
	}
	putchar('\n');
}
