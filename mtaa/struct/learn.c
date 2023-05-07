#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char *name;
	char *id;
	int age;
	int grade[7];
}students;

void print_student(students student);
typedef struct
{
	int x;
	int y;
}pionts;
int main()
{

	students mark;
	strcpy(mark.name, "mark odioin");
	strcpy(mark.id, "odion456");
	mark.age = 50;
       	students kevin;
	kevin.age = 40;
	strcpy(kevin.name, "kevin akpan");
	strcpy(kevin.id, "9701665");
	kevin.grade[0] = 19;
	kevin.grade[1] = 24;
	kevin.grade[2] = 37;
	kevin.grade[3] = 34;
	kevin.grade[4] = 95;
	kevin.grade[5] = 36;
	kevin.grade[6] = 57;
	students clinton = {"clinton abigial", "cd453678", 45, {23,56,78,34,56,78,67}};

	print_student(kevin);
	printf("\n");
	print_student(mark);
	printf("\n");
	print_student(clinton);
	printf("\n");

	

	pionts p1 = {5, 10};
	pionts p2 = { .y = 56, .x = 34};
	printf("p1.x: %d\n", p1.x);
	printf("p1.y: %d\n", p1.y);
	 printf("p2.x: %d\n", p2.x);
	  printf("p2.y: %d\n", p2.y);



	return 0;
}
void print_student(students student)
{
	students *y = malloc(sizeof(students));
	        int j = strlen(y->name);
		        int k = strlen(y->id);
			        y->name = malloc(sizeof(char)*j +1);
				        y->id = malloc(sizeof(char)*k +1);
	int i;
	printf("Age: %d\nName: %s\nId: %s\nGrades: ", student.age, student.name, student.id);
	for (i=0;i<7;i++)
		printf("%d ", student.grade[i]);
	printf("\n");
}
