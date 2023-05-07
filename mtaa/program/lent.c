#include <stdio.h>

int main()
{
	int n, i;
	printf("Enter number to check scores\n");
	scanf("%d", &n);
	
	int array[n];
	printf("Enter nubers of array\n");
	for (i=0;i<n;i++)
	scanf("%d", &array[i]);

	for (i=1;i<n;i++)
	{
		if (array[i] > array[0])
		{
			array[0] = array[i];
		}
	}
	printf("\nThe largest number is %d\n", array[0]);
	return 0;
}

