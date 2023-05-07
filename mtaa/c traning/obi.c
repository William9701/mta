#include <stdio.h>

int main(void)
{
	int i;
	int j;
	

	
			for (i = 0; i < 10; i++)
	{
		printf("%d This is the outer loop\n", i);
		for (j = 1; j < 10; j++)
		{
			if (j == 7)
			{
				continue;
			}
			printf("%d      This is the inner loop\n", j);
		}
	}
	return (0);
}
