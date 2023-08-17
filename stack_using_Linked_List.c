//Write a program using Single Linked List to implement Stack Data Structure.

#include <stdio.h>

struct stack
{
    int data;
    struct stack *next;
};

typedef struct stack node;

node *head;
node *last_node;

int main ()
{
    head = NULL;
    last_node = NULL;
    int option;
    int item;
    while (option != 4)
    {
        printf("Enter 1 for PUSH, \n2 for POP, \n3 for DISPLAY, \n4 for Exit. : ");
        scanf("%d", &option);
        switch (option) {
        case 1 :
            printf("Enter number for PUSH. : ");
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
    return 0;
}

void push(int item) {
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp -> data = item;
    temp -> next = NULL;
    if (head == NULL) {
        head = temp;
        last_node = temp;
    }
    else {
        last_node -> next = temp;
        last_node = temp;
    }
}

void pop() {
    int item;
    node *temp;
    node *dh;
    node *head;
    if (head == NULL) {
        printf("Underflow.\n");
    }
    else {
        item = temp;
        temp = dh -> next;
        dh -> next = temp -> next;
        if (dh -> next == NULL) {
            last_node = dh;
        }
        free(temp);
        printf("Deleted item : %d\n", item);
    }
}

void display() {
    node *dh = head;
    while (dh != NULL)
    {
        printf("%d\n", dh->data);
        dh = dh->next;
    }
    printf("\n");
}
