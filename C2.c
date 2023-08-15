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
  printf("Enter infix expression: ");
  fgets(infix, sizeof(infix), stdin);
  char postfix[20];
  convertion(infix, postfix);
  printf("Postfix Expression: %s\n", postfix);
  return 0;
}

int operator_check(char ch)
{
  switch(ch)
  {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      return 1;
    default:
      return 0;
  }
}

int operator_precedence(char ch)
{
  switch(ch)
  {
    case '^':
      return 3;
    case '*':
    case '/':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
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
  
  while(item != '\0')
  {
    if(item == '(')
      push(item);
    else if(isalnum(item))  // Alphanumeric characters
    {
      postfix[j++] = item;
    }
    else if(operator_check(item) == 1)
    {
      x = pop();
      while(operator_check(x) && operator_precedence(x) >= operator_precedence(item))
      {
        postfix[j++] = x;
        x = pop();
      }
      push(x);  // Push back the last popped item which does not satisfy the condition.
      push(item);
    }
    else if(item == ')')
    {
      x = pop();
      while(x != '(')
      {
        postfix[j++] = x;
        x = pop();
      }
    }
    else
    {
      printf("Invalid expression.\n");
      return;
    }
    i++;
    item = infix[i];
  }
  postfix[j] = '\0';
}

void push(char ch)
{
  if(top == MAX-1)
    printf("Overflow.\n");
  else
    stack[++top] = ch; 
}

char pop()
{
  if(top == -1)
  {
    printf("Underflow.\n");
    return '\0';  // Return a null character to indicate underflow
  }
  else
    return stack[top--];
}
