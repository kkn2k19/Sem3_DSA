// Write a program using Single Linked List to implement Stack Data Structure.

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

typedef struct stack node;

node *head;

int main()
{
    head = NULL;
    int option;
    int item;
    while (option != 4)
    {
        printf("Enter 1 for PUSH, \n2 for POP, \n3 for DISPLAY, \n4 for Exit. : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter number for PUSH. : ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting.\n");
            break;
        default :
            printf("Invalid Option.\n");
        }
    }
    return 0;
}

void push(int item)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = item;
    temp->next = head;
    head = temp;
}

void pop()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Underflow.\n");
    }
    else {
        printf("Deleted item : %d\n", temp -> data);
        head = head -> next;
        free(temp);
    }
}

void display()
{
    node *dh = head;
    while (dh != NULL)
    {
        printf("%d\n", dh->data);
        dh = dh->next;
    }
    printf("\n");
}
