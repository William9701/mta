#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int j;
	int mul;

	for (j = 1; j<8;j++)
	{
	for (i = 1; i<9;i++)
	{
		mul = i * j;
		if (i == 8)
		{
		printf("%d", mul);
		}
		else
		printf("%d, ", mul);
	}
	printf("\n");
	}
	return 0;
}

