//Write a program to evaluate a postfix expression.

#include <stdio.h>
#define MAX 10
float stack[MAX];
int top;
void push (float item);
float pop();
float evaluate (float L, float R, char op);

int main () 
{
  int item;
  int i;
  char ch;
  top = -1;
  char postfix[30];
  printf("Enter a Postfix Expression : ");
  gets(postfix);
  int n = strlen(postfix);
  for (i = 0; i < n; i++) {
    ch = postfix[i];
    if (ch >= '0' && ch <= '9') {
      item = ch-48;
      push (item);
    }
    else {
      R = pop();
      L = pop();
      UR = evaluate (L, R, ch);
      push (UR);
    }
  }
  return 0;
}

void push (float item) {
  if (top == MAX-1) {
    printf("Overflow.\n");
  }
  else {
    top = top + 1;
    stack[i] = item;
  }
}
