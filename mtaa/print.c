#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(int *a, int n);

int main()
{

	char *b = "1001101";
	int i, j;
	j = strlen(b);
	int binary = 0;
	int a[j];
	int n = 1;
	memset(a, 0, sizeof(a));

	a[0] = n;
	for (i = 0; i < 7; i++)
	{
		n *= 2;
		a[i+1] = n;
	}
	for (i = 0; i < 7; i++)
	{
	printf("%d\n", a[i]);
	}

	for (i = 0; i <= j; i++)
	{
		printf("%c\n", b[i]);
	}
	
	//binary += (a[0]) * (b[0]);
	printf("binary is %d\n", b[1]);


	return 0;
}
