#include "main.h"

void swap_int(int *a, int *b)
{
	int j = 0;

	j = *a;
	*a = *b;
	*b = j;
}
