#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[50];
	int age;
	char state[100];
}student;

int main()
{
	int i;
	 student obi = { "Obi William", 27, "Anambra"};
	 student kosi = { "Obi Kosisochukwu", 26, "Abia"};
	 student ada = { "Okocha ada", 26, "Delta"};
	 student chika = { "alison chika", 45, "Kogi"};



	//printf("On behalf of the school, we want to welcome our own person Mr %s, and his beloved wife Mrs %s. You are both welcome, knowing you hail from %s, and your wife from %s, we are glad to have you both here. You are quite young sir, you are %d, and your wife is %d. welcome again sir\n", obi.name, ada.name, obi.state, ada.state, obi.age, ada.age);
	student students[] = {obi, kosi, ada, chika};
	for (i = 0; i < sizeof(students) / sizeof(students[0]); i++)
		printf("%s\t%d\t%s\n", students[i].name, students[i].age, students[i].state);
	 
	 return 0;
}
