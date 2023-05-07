#include <stdio.h>
#include <string.h>

int main(void)
{
	int i = 6;
	int *ptr = &i;
	char c[60] = {"good"};
	char *p = c;


	printf("value of i is %d\n", i);
	printf("value of ptr is  %p\n", ptr);

	*ptr = 5;
	printf("value of ptr is  %d\n", *ptr);
	printf("value of c is  %s\n", c);
	printf("value of p is  %p\n", p);

	strcpy(p,"boy");
	printf("value of p is  %s\n", p);
	return 0;
}

