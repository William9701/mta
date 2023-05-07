#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/* betty style doc for function main goes there */
int main(void)
{
		int n;

			srand(time(0));
				n = rand() - RAND_MAX / 2;
					/* your code goes there */
				if (n % 10 > 5)
				{
					printf(" the last digit of %d is %d and is greater than 5\n", n, n % 10);
				}
				if (n % 10 == 0)
				{
					printf("The last digit of %d is %d and is 0\n", n, n % 10);
				}
				if (n < 6)
				{
					printf("The last digit of %d is %d and is less than 6 and not 0\n", n, n % 10);
				}
					return (0);
}

