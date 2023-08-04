/*
Find X^y
 EXP (X,Y)    =    1, if Y = 0
              = X*EXP(X, Y-1), otherwise
*/

#include <stdio.h>
#include <math.h>

int main()
{
    float k;
    int x;
    int y;
    printf("Enter no. and its exponential power : ");
    scanf("%d %d", &x, &y);
    k = expo(x, y);
    printf("Result : %f\n", k);
    return 0;
}

int expo(int x, int y){
    float k;
    if (y == 0) {
            return 1.0;
    }
    else {
            k = x*expo(x, y-1);
            return k;
    }
}
