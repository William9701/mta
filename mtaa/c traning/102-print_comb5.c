#include <stdio.h>

int main(void)
{
	int i;
	int j;

	for (i = 0; i <= 99; i++)
	{
		for (j = 1; j <= 99; j++)
		{
			if (i < j && i != j)
			{
				putchar(i / 10 + '0');
				putchar(i % 10 + '0');
				putchar(' ');
				putchar(j / 10+ '0');
				putchar(j % 10 + '0');
				if (i + j != 197)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return 0;
}


