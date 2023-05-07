#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int aza;
	char q[1000];
	char name[100];

	printf("Enter name\n");
	scanf("%s", name);
	
		if (strcmp(name, "ifeoma") == 0)
		{
			printf("Welcome ify\nWhat can i do for you today?\n");
			scanf("%s", q);
			if (strcmp(q, "money") == 0)
			{
				printf("%s drop your aza\n", name);
				scanf("%d", &aza);
				printf("No worry you go recieve block soon\n");
			}
			else
			{
				printf("Am sorry but all our agencies are currently offline, please check back later\n");
			}
		}
		else
			printf("i dont know you\n");

	return 0;
}
