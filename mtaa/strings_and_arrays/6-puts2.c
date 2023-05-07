#include "main.h"

void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
	{
		putchar(str[i]);
		i++;
	}
	putchar('\n');
}
