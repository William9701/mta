#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	int mul = 1;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	if (isdigit(*argv[1]) && isdigit(*argv[2]))
	{
			for (i=1;i<argc;i++)
				mul *= atoi(argv[i]);
			printf("%d\n", mul);
			printf("%s\n", argv[1]);
			printf("%s\n", argv[2]);
	}
	else
		printf("error\n");
		
		return 0;
}


