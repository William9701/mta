#include <stdio.h>
#include "main.h"

void print_line(int n)
{
	int i;

	if (n <= 0)
	{
		putchar('\n');
		return ;
	}
	
	for (i = 0; i <= n; i++)
	{
		putchar('_');
	}
	putchar('\n');
}

