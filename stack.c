
//Write a menu driven program for Stack implementation (PUSH, POP, DISPLAY) using array.

#include <stdio.h>
#define MAX 10

int Stack[MAX];
int top;
void push(int item);
void pop();
void display();

int main ()
{
  int item, ch;
  top = -1;
  while(ch != 4) {
    printf("Press 1 for PUSH,\n2 for POP,\n3 for DISPLAY,\n4 for EXIT. \n : ");
    scanf("%d", &ch);
    switch (ch) {
      case 1 :
              printf("Enter number for Push. : ");
              scanf("%d", &item);
              push(item);
              break;
      case 2 :
              pop();
              break;
      case 3 :
              display();
              break;
      case 4 :
              printf("Exiting.\n");
    }
  }
}

void push (int item) {
  if (top == MAX-1) {
    printf("Overflow.\n");
  }
  else {
    top = top+1;
    Stack[top] = item;
  }
}

void pop()
{
  int item;
  if(top == -1) {
    printf("Underflow.\n");
  }
  else {
    item = Stack[top];
    top = top - 1;
    printf("%d \n", item);
  }
}

void display ()
{
  int i;
  for (i = top; i>=0; i--) {
    printf("%d \n", Stack[i]);
  }
}
