// Write a program to convert Infix Expression to Postfix Expression.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

char stack[MAX];
int top;

void push(char ch);
char pop();
int operator_check(char ch);
int operator_precedence(char ch);
void conversion(char infix[], char postfix[]);

int main()
{
    top = -1;
    char infix[20];
    printf("Provide Infix Expression : ");
    fgets(infix, sizeof(infix), stdin);
    size_t len = strlen(infix);
    if(len > 0 && infix[len - 1] == '\n')
        infix[len - 1] = '\0';
    char postfix[20];
    conversion (infix, postfix);
    printf("Postfix Expression : %s\n", postfix);
    return 0;
}

int operator_check(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int operator_precedence(char ch) {
    if (ch == '^') {
        return 3;
}
    else if (ch == '*' || ch == '/')
        {
            return 2;
        }
    else if (ch == '+' || ch == '-')
        {
            return 1;
        }
    return 0;
}

void conversion(char infix[], char postfix[])
{
    int i = 0;
    int j = 0;
    char k;
    char ch;

    push('(');
    strcat(infix, ")");

    ch = infix[i];
    while (ch != '\0') {
        if (ch == '(') {
            push(ch);
        }
        else if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            postfix[j++] = ch;
        }
        else if (operator_check(ch) == 1) {
            k = pop();
            while(operator_check(k) && operator_precedence(k) >= operator_precedence(ch)) {
                postfix[j++] = k;
                k = pop();
            }
            push(k);
            push(ch);
        }
        else if (ch == ')') {
            k = pop();
            while (k != '(') {
                postfix[j++] = k;
                k = pop();
            }
        }
        else {
            printf("Invalid Expression.\n");
            return;
        }
        ch = infix[++i];
    }
    postfix[j] = '\0';
}

void push (char ch) {
    if (top == MAX-1) {
        printf("Overflow.\n");
    }
    else {
        top = top +1;
        stack[top] = ch;
    }
}

char pop() {
    char ch = ' ';
    if (top == -1){
        printf("Underflow.\n");
    }
    else {
        ch = stack[top];
        top = top-1;
    }
    return ch;
}
