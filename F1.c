/*Find the GCD of two numbers recursively by Euclids algorithm which states

      GCD (a,b) = b       if b divides a
                = GCD (b, a mod b), otherwise
*/

#include <stdio.h>
int gcd (int a, int b);

int main ()
{
  int a, b, res;
  printf("Provide two numbers : ");
  scanf ("%d %d", &a, &b);
  res = gcd(a, b);
  printf("GCD : %d\n", res);
}

int gcd (int a, int b) {
  int r, k;
  r = a%b;
  if (r == 0) {
    return (b);
  }
  else {
    k = gcd(b, r);
    return (k);
  }
}
