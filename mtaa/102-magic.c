#include <stdio.h>

int main(void)
{
  int n;
  int a[6];
  int *p;

  a[1] = 1024;
  p = &n;
  /*
   * write your line of code here...
   * Remember:
   * - you are not allowed to use a
   * - you are not allowed to modify p
   * - only one statement
   * - you are not allowed to code anything else than this line of code
   */
  *(p+3)=98;
  /* ...so that this prints 98\n */
  printf("a[2] = %d\n", a[1]);
  printf("value of p is %d\n", *p);
  printf("%p and for p %p\n", &a[1], p);
  return (0);
}
