#include <stdio.h>

void add_print(int n, int b);

void main()
{
	add_print(5, 7);
	printf("\n");
}
void add_print(int n, int b)
{
	int j = 0;
	j += n + j;

	printf("%d",j);
	j--;

	if (j > 0)
		n=n-1;
	b=n-1;
		add_print(n, b);
}

