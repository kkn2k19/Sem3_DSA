/*
Write a menu-driven program to implement the Circular Link List and perform the following operations.
a. Creation
b. Insertion
   i.  After a Specific Node
   ii. Before a Specific Node
c. Searching
d. Traversing
e. Deletion of a particular node
*/

#include <stdio.h>
#include <stdlib.h>

struct box
{
    int data;
    struct box *next;
};

typedef struct box node;

node *head = NULL;
node *last_node = NULL;

void insert_at_last(int item);
void insert_before(int item, int se);
void insert_after(int item, int se);
void traverse();
int searching(int se);
void delete_node(int se);

int main()
{
    int option;
    int item;
    int se;
    while (option != 7)
    {
        printf("\nMenu : \n");
        printf("1. Insert at last\n");
        printf("2. Insert before a specific node\n");
        printf("3. Insert after a specific node\n");
        printf("4. Traversing\n");
        printf("5. Searching\n");
        printf("6. Deletion of a particular node\n");
        printf("7. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                printf("Enter element to insert at last : ");
                scanf("%d", &item);
                insert_at_last(item);
                break;
            case 2:
                printf("Enter value before which to insert : ");
                scanf("%d", &se);
                printf("Enter element to insert : ");
                scanf("%d", &item);
                insert_before(item, se);
                break;
            case 3:
                printf("Enter value after which to insert : ");
                scanf("%d", &se);
                printf("Enter element to insert : ");
                scanf("%d", &item);
                insert_after(item, se);
                break;
            case 4:
                traverse();
                break;
            case 5:
                printf("Enter value to search : ");
                scanf("%d", &se);
                if (searching(se)) {
                    printf("Found\n");
                }
                else {
                    printf("Not Found\n");
                }
                break;
            case 6:
                printf("Enter value to delete : ");
                scanf("%d", &se);
                delete_node(se);
                break;
            case 7:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid option. Please choose a number between 1 and 7.\n");
        }
    }
    return 0;
}

void insert_at_last(int item) {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp -> data = item;
    if (head == NULL) {
        head = temp;
        last_node = temp;
        last_node->next = head;
        return;
    }
    else {
        last_node -> next = temp;
        last_node = temp;
        last_node->next = head;
    }
}

void insert_before(int item, int se) {
   node *dh = head;
   node *temp;
   temp = (node*)malloc(sizeof(node));
   int flag = 0;
   if (head == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }
    if (head->data == se) {
        temp->data = item;
        temp->next = head;
        head = temp;
        last_node->next = head;
        return;
    }
    do {
        if (dh->next->data == se) {
            flag = 1;
            break;
        }
        dh = dh->next;
    } while (dh != head);
    if (flag == 0) {
        printf("Node %d not found.\n", se);
        return;
    }
    temp->data = item;
    temp->next = dh->next;
    dh->next = temp;
}

void insert_after(int item, int se)
{
    node *dh=head;
    node *temp;
    temp=(node *)malloc(sizeof(node));
    int flag=0;
    do {
        if (dh->data == se) {
            flag = 1;
            break;
        }
        dh=dh->next;
    } while(dh != head);
    if (flag == 0) {
        printf("Node %d not found.\n", se);
        return;
    }
    temp->data=item;
    temp->next=dh->next;
    dh->next=temp;
    if (temp->next==head) {
        last_node=temp;
    }
}

void traverse()
{
    node *dh = head;
    if (head == NULL) {
        printf("Empty.\n");
        return;
    }
    do {
        printf("%d\n", dh->data);
        dh = dh->next;
    } while (dh != head);
    printf("\n");
}

int searching(int se) {
    node *dh=head;
    int flag = 0;
    do {
        if (se == dh->data) {
            flag = 1;
            break;
        }
        dh=dh->next;
    } while (dh != head);
    return flag;
}

void delete_node(int se) {
    node *dh=head;
    node *temp;
    temp=(node *)malloc(sizeof(node));
    int flag = 0;
    if (head->data==se) {
        temp=head;
        head=head->next;
        if (head==last_node) {
            head = NULL;
            last_node = NULL;
        }
        else {
            last_node->next=head;
        }
        free(temp);
        return;
    }
    do {
        if (dh->next->data == se) {
            flag = 1;
            break;
        }
        dh=dh->next;
    } while(dh != head);
    if (flag == 0) {
        printf("Node %d not found.\n", se);
        return;
    }
    temp=dh->next;
    dh->next=temp->next;
    if (temp->next == head) {
        last_node = dh;
    }
    free(temp);
}
