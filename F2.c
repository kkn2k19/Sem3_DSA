/*
Find X^y
 EXP (X,Y)    =    1, if Y = 0
              = X*EXP(X, Y-1), otherwise
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int k;
    int x;
    int y;
    printf("Enter no. and its exponential power : ");
    scanf("%d %d", &x, &y);
    k = exponent(x, y);
    printf("Result : %d\n", k);
    return 0;
}

int exponent(int x, int y){
    int k;
    if (y == 0) {
        return 1;
    }
    else {
        k = x*exponent(x, y-1);
        return k;
    }
}
