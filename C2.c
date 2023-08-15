//Write a program to convert Infix Expression to Postfix Expression.

NOT COMPLETE!!!!

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>
#define MAX 30
char stack[MAX];
int top;
void push(char ch);
char pop();
int operator_check(char ch);
int operator_precedence(char ch);
void convertion(char infix[], char postfix[]);

int main()
{
  top = -1;
  char infix[20];
  printf("Enter infix expression : ");
  fgets(infix, sizeof(infix), stdin);
  char postfix[20];
  convertion(infix, postfix);
  printf("Postfix Expression : ");
  puts(postfix);
  return 0;
}

int operator_check(char ch)
{
  if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int operator_precedence(char ch)
{
  if (ch == '*' || ch == '/')
  {
    return 2;
  }
  else if (ch == '+' || ch == '-')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void convertion(char infix[], char postfix[])
{
  int i, j;
  char item;
  char x;
  push('(');
  strcat(infix, ")");
  i = 0;
  j = 0;
  item = infix[i];
  while (item != 0)
  {
    if (item == '(')
      push(item);
    else if (isdigit(item))
    {
      postfix[j] = item;
      j++;
    }
    else if (operator_check(item) == 1)
    {
      x = pop();
      while (operator_check(item) == 1 && operator_precedence(x) >= operator_precedence(item))
      {
        postfix[j] = x;
        j++;
        x = pop();
      }
      push(x);
      push(item);
    }
    else if (item == ')')
    {
      x = pop();
      while (x != '(')
      {
        postfix[j] = x;
        j++;
        x = pop();
      }
    }
    else
    {
      printf("invalid expression.\n");
      break;
    }
    i++;
    item = infix[i];
  }
  postfix[j] = '\0';
}

void push (char ch) {
  if (top == MAX-1) {
    printf("Overflow.\n");
  }
  else {
    top = top+1;
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
  }
  return item;
}
