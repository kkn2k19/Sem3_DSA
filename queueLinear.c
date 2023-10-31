//Write a menu-driven program to implement a Queue (ENQUE, DEQUE, and DISPLAY) using Array.

#include <stdio.h>
#define MAX 10
int LQ[MAX];          //Linear Queue
int F, R;
void ENQUE(int item);
int DEQUE();
void DISPLAY();

int main ()
{
  int item;
  int option;
  int k;
  F = -1;
  R = -1;
  while (option != 4) {
    printf("Press 1 for ENQUE,\n2 for DEQUE,\n3 for DISPLAY,\n4 for EXIT. : ");
    scanf("%d", &option);
    switch(option) {
      case 1 :
             printf("Enter number to ENQUE : ");
             scanf("%d", &item);
             ENQUE(item);
             break;
      case 2 :
             k = DEQUE();
             printf("DEQUED item : %d\n", k);
             break;
      case 3 :
             DISPLAY();
             break;
      case 4 :
             printf("Exiting.\n");
    }
  }
  return 0;
}

void ENQUE(int item) {
  if (R == MAX-1) {
    printf("Overflow.\n");
  }
  else {
    if (R == -1) {
      R = R+1;
      F = F+1;
    }
    else {
      R = R+1;
    }
    LQ[R] = item;
  }
}

int DEQUE() {
  int item;
  if (F == -1) {
    printf("Underflow.\n");
  }
  else {
    item = LQ[F];
    if (F == R) {
      F = -1;
      R = -1;
    }
    else {
      F = F+1;
    }
    return item;
  }
}

void DISPLAY() {
  int i;
  for (i = F; i <= R; i++) {
    printf("%d ", LQ[i]);
  }
  printf("\n");
}
