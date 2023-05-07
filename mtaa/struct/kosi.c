#include <stdio.h>
#define loop 4
int sum(int a, int b);
int sub(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main()
{
	int (*ptr[loop])(int, int)={sum, sub, multiply, divide};
	int choice;
	int num1, num2;

	printf("Good day sir,what do you want to do today\n0 for addition\n1 for subtraction\n2 for multiplication\n3 for division\n");
	scanf("%d", &choice);

	if (choice < 4)
	{
	printf("Enter the two numbers Sir\n");
	scanf("%d %d", &num1, &num2);

	printf("The result sir is %d\n", (*ptr[choice])(num1, num2));
	}
	else
		printf("Wrong input!!\n");

	return 0;
}

int sum(int a, int b)
{
	return a+b;
}
int sub(int a, int b)
{
	return a-b;
}
int multiply(int a, int b)
{
	return a*b;
}
int divide(int a, int b)
{
	return a/b;
}
