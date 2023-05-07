#include <stdio.h>

int main()
{
	int i;
	int k;

	for (i = 9; i > 0; i--)
	{
		for (k=0; k < i; k--)
		{
			printf("%d", k);
		
		}
		printf("\n");
		k--;
	}
	return 0;
}
