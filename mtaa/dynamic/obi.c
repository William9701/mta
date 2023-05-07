#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;
	char *ptr;
	printf("nigga how many letters you wanna type\n");
	scanf("%d",&n);

	ptr = (char*)malloc(n*sizeof(int));

	printf("\nenter your values:");
	for(i=0;i<n;i++)
	{
		scanf("%s", (ptr+i));
	}
	printf("\nthe values you entered are:");
	for(i=0;i<n;i++)
	{
		printf("\n%s\n", ptr);
	}

	free(ptr);
}

