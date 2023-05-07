#include <stdio.h>
#include "main.h"

void times_table(void)
{
	int i;
	int j;
	int k;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			k = i * j;

			{
				putchar(k / 10 + '0');
				putchar(k % 10 + '0');
				k++;
			}
			putchar(',');
			putchar(' ');
			putchar(' ');
			putchar('\n');
		}
		putchar('\n');
	}
}

