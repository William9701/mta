#include <stdio.h>
#include "main.h"

void jack_bauer(void)
{
	int i;
	int j;

	for (i = 00; i < 24; i++)
	{
		for (j = 00; j < 60; j++)
		{
			putchar(i / 10 + '0');
			putchar(i % 10 + '0');
			putchar(':');
			putchar(j / 10 + '0');
			putchar(j % 10 + '0');
			putchar('\n');
		}
	}
}
