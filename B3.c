//Write a program to check whether brackets have been given properly or not in an expression.

#include <stdio.h>
#define MAX 10
int stack[MAX];
int top;
void push(char ch);
char pop();
int bcheck(char st, char end);

int main()
{
  int i;
  int k;
  char ch1, ch2;
  top = -1;
  printf("Provide an Expression : ");
  char string[30];
  gets(string);
  int n = strlen(string);
  for (i = 0; i < n; i++) {
    ch1 = string[i];
    if (ch1 == '[' || ch1 == '{' || ch1 == '(') {
      push(ch1);
    }
    else {
      ch2 = pop();
      k = bcheck(ch2, ch1);
      if (k == 0) {
        printf("Wrong.\n");
        break;
      }
      if (k == 1) {
            printf("Right.\n");
            break;
      }
    }
  }
  return 0;
}

void push (char ch) {
  if (top == MAX-1) {
    printf("Overflow.\n");
  }
  else {
    top = top + 1;
    stack[top] = ch;
  }
}

char pop() {
  char item;
  if (top == -1) {
    printf("Underflow.\n");
  }
  else {
    item = stack[top];
    top = top-1;
    return (item);
  }
}

int bcheck(char st, char end) {
  if (st == '[' && end == ']') {
    return 1;
  }
  else if (st == '(' && end == ')') {
    return 1;
  }
  else if (st == '{' && end == '}') {
    return 1;
  }
  else {
    return 0;
  }
}
