#include <stdio.h>
#include "main.h"

void more_numbers(void)
{
	int i;
	int j;
	
	for (j = 0; j < 10; j++)
	{

	for (i = 0; i <= 14; i++)
	{
		if (i > 9)
		{
			putchar(i / 10 + '0');
		}
			putchar(i % 10 + '0');
	}
	putchar('\n');
	}
}
