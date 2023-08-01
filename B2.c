//Write a program to reverse a String Using the Stack Data structure.

#include <stdio.h>
#define MAX 20
int stack[MAX];                                 //char used instead of int as this case is for a string (i.e. character array)
int top;
char ch;                                          //ch used to get each character of the string during reversing.
void push(char ch);
char pop();

int main() {
  int i;
  char string[30];
  top = -1;
  printf("Provide a String : ");
  gets(string);
  int n = strlen(string);                            //used to check length of the string entered.
  for (i=0; i < n; i++)                               //pushing all character in the stack named string[]
    {
      ch = string[i];
      push(ch);
    }
  for (i = 0; i < n; i++)                           //reverse as pop is LIFO
  {
    ch = pop();
    string[i] = ch;
  }
  puts(string);                                   //string will be printed after all character poped.
  return 0;
}

void push (char ch)
{
  if (top == MAX-1) {
    printf("Overflow.\n");
  }
  else {
    top = top + 1;
    stack[top] = ch;
  }
}

char pop()
{
  char item;
  if (top == -1) {
    printf("Underflow.\n");
  }
  else {
    item = stack[top];
    top = top - 1;
    return (item);
  }
}
