//Write a program to implement a Circular Queue Using Array.

#include <stdio.h>
#define MAX 10
int CQ[MAX];
int R, F, flag;
void insertion (int item);
int deletion ();
void display ();

int main ()
{
  int option;
  int item;
  int k;
  F = MAX-1;
  R = MAX-1;
  flag = 0;
  while (option != 4) {
    printf("Press 1 for insertion,\n2 for deletion,\n3 for display,\n4 for exit.\n");
    scanf("%d", &option);
    switch(option) {
      case 1 :
             printf("Enter number to insert : ");
             scanf("%d", &item);
             insertion (item);
             break;
      case 2 :
             k = deletion();
             printf("Deleted item : %d\n", k);
             break;
      case 3 :
             display ();
             break;
      case 4 :
             printf("Exiting.\n");
    }
  }
  return 0;
}

void insertion (int item) {
  if (F == R && flag == 1) {
    printf("Overflow.\n");
  }
  else {
    R = (R+1)%MAX;
    CQ[R] = item;
    flag = 1;
  }
}

int deletion () {
  int item;
  if (F == R && flag == 0) {
    printf("Underflow.\n");
  }
  else {
    F = (F+1)%MAX;
    item = CQ[F];
    flag = 0;
    F = F+1;
    return (item);
  }
}

void display () {
  int i;
  if (F != -1) {
    printf("Circular Queue.\n");
    for (i = F; i != R; i++) {
      printf("%d ", CQ[i]);
    }
    printf("%d ", CQ[i]);
  }
  else {
    printf("Circular Queue is empty.\n");
  }
}
