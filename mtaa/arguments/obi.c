#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("argc = %d\n", argc);
	if (argc > 1)
	{
	printf("Everything inside argc\n");

	int i;

	for (i=0;i<argc;i++)
		printf("argc[%d] value is %s\n", i, argv[i]);
	}
	return 0;
}
