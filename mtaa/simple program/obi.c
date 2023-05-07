#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_name();
void display_age();
int main()
{
	char *name;
	char *surname;
	int age;

	int l = strlen(name);
	int k = strlen(surname);

	name = malloc(l * (sizeof(char)));
	if (name == 0)
	{
		return 1;
	}
	surname = malloc(k * (sizeof(char)));
	if (surname == 0)
	{
		exit(98);
	}
	display_name();
	scanf("%s %s", name, surname);

	display_age();
	scanf("%d", &age);

	if (age > 18)
	{
	printf("Hello %s %s, nice to meet you. i am %dyears old too\t you be like person wa go like fuck oh.\n", name, surname, age);
	}
	else
		printf("%s %s,get the fuck out\n", name, surname);

	free(name);
	free(surname);
	return 0;
}
void display_name()
{
	printf("What is your name (Surname and Name)\n");
}
void display_age()
{
	printf("how old are you?\n");
}
