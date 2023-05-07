#include "main.h"

void puts_half(char *str)
{
	int i;
	int n;
	int lent = 0;

	for (i = 0; str[i] != '\0'; i++)
		lent++;
	if (lent % 2 == 0)
	{
		n = lent / 2;

			for (i = n; str[i] != '\0'; i++)
			{
				putchar(str[i]);
			}
	}
	else if (lent % 2 != 0)
	{
		n = (lent - 1) / 2;

	for (i = n; str[i] != '\0'; i++)
	{
		putchar(str[i]);
	}
	}
	putchar('\n');
}
