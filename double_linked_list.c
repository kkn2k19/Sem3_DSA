/*
Write a menu-driven program to implement the Double Link List and perform the following operations :
a. Creation
b. Insertion
   i.  After a Specific Node
   ii. Before a Specific Node
c. Searching
d. Traversing
   i.  Traversing Normal
   ii. Traversing backward
e. Reversing the list
f. Deletion of a particular Node.
*/

//NOT COMPLETE YET!!!!!

#include <stdio.h>
#include <stdlib.h>

struct box
{
    int data;
    struct box *next;
    struct box *prev;
};

typedef struct box node;

node *head=NULL;
node *tail=NULL;

void insert_at_last(int item);
void insert_before(int item, int se);
void insert_after(int item, int se);
void traverse();
int searching(int se);
void delete_node(int se);
void traverse_backward();
void reverse();

int main()
{
    int option;
    int item;
    int se;
    do {
        printf("\nMenu:\n");
        printf("1. Insert at last\n");
        printf("2. Insert before a specific node\n");
        printf("3. Insert after a specific node\n");
        printf("4. Traversing\n");
        printf("5. Searching\n");
        printf("6. Traversing backward\n");
        printf("7. Deletion of a particular node\n");
        printf("8. Reversing\n");
        printf("9. Exit\n");
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
                printf("Enter value to search: ");
                scanf("%d", &se);
                if(searching(se)) {
                    printf("Found\n");
                }
                else {
                    printf("Not Found\n");
                }
                break;
            case 6:
                traverse_backward();
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &se);
                delete_node(se);
                break;
            case 8:
                reverse();
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please choose a number between 1 and 9.\n");
        }
    } while (option != 9);
    return 0;
}

void insert_at_last(int item)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    if (head==NULL) {
        temp->data=item;
        temp->next=NULL;
        temp->prev=NULL;
        head=temp;
        tail=temp;
        return;
    }
    temp->data=item;
    temp->next=NULL;
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insert_after(int item, int se) {
    node *temp;
    temp=(node *)malloc(sizeof(node));
    node *dh=head;
    int flag=0;
    while (dh != NULL){
        if (dh->data==se){
            flag=1;
            break;
        }
        dh=dh->next;
    }
    if (flag==0) {
        printf("node %d not found.\n", se);
        return;
    }
    temp->data=item;
    temp->next=dh->next;
    temp->prev=dh;
    dh->next=temp;
    if (temp->next==NULL) {
        tail=temp;
    }
    else {
        temp->next->prev=temp;
    }
}

void insert_before(int item, int se) {
    node *temp;
    temp=(node *)malloc(sizeof(node));
    node *dh=head;
    int flag=0;
    if (head->data==se) {
        temp->data=item;
        temp->prev=NULL;
        temp->next=head;
        head->prev=temp;
        head=temp;
        return;
    }
    while (dh != NULL) {
        if (dh->data==se) {
            flag=1;
            break;
        }
        dh=dh->next;
    }
    if (flag==0) {
        printf("Node %d not found.\n", se);
        return;
    }
    temp->data=item;
    temp->next=dh;
    temp->prev=dh->prev;
    dh->prev=temp;
    if (temp->prev==NULL){
        head=temp;
    }
    else {
        temp->prev->next=temp;
    }
}

void traverse() {
    node *dh=head;
    while(dh!=NULL) {
        printf("%d ", dh->data);
        dh=dh->next;
    }
    printf("\n");
}

int searching(int se) {
    node *dh=head;
    int flag=0;
    while(dh!=NULL) {
        if (dh->data==se) {
            flag=1;
            break;
        }
        dh=dh->next;
    }
    return flag;
}

void traverse_backward() {
    node *dh=tail;
    while (dh!=NULL) {
        printf("%d ", dh->data);
        dh=dh->prev;
    }
}

void reverse() {
    node *temp;
    node *Rh = NULL;
    while (head != NULL) {
        temp = head;
        head = head->next;
        temp->next = Rh;
        Rh = temp;
    }
    head = Rh;
    traverse();
}

void delete_node(int se) {
    node *dh=head;
    node *temp;
    int flag=0;
    while(dh != NULL)
    {
        if (dh->data == se)
        {
            flag=1;
            break;
        }
        dh=dh->next;
    }
    if(flag==0) {
        printf("Node %d not found.\n", se);
        return;
    }
    else {
        printf("Deleted : %d\n", se);
    }
    temp=dh;
    if (dh->prev==NULL)
    {
        head=head->next;
        if(head==NULL) {
            tail=NULL;
            free(temp);
            return;
        }
        else {
            head->prev=NULL;
        }
    }
    else {
        dh->prev->next=dh->next;
    }
    if(dh->next==NULL) {
        tail=tail->prev;
        if (tail==NULL) {
            head=NULL;
        }
        else {
            tail->next=NULL;
        }
    }
    else {
        dh->next->prev=dh->prev;
    }
}
