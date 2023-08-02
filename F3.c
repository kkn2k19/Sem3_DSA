/*
Print the Fibonacci Series up to nth term
FIB(n) = 0, if n = 0
       = 1, if n = 1
       = FIB(n-1) + FIB(n-2), Otherwise
*/

#include <stdio.h>
int fib(int n);

int main ()
{
  int n, k;
  printf("Enter no. of terms : ");
  scanf("%d", &n);
  for (k = 0; k < n; k++) {
         printf("%d ", fib(k));
  }
  return 0;
}

int fib (int n)
{
       if (n ==0 || n == 1) {
              return n;
       }
       else {
              return (fib(n-1) + fib(n-2));
       }
}
