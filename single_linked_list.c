/*
Single Linked List ---
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
void reverse();

int main()
{
    int option;
    int item;
    int se;
    while(option != 8)
    {
        printf("\nMenu:\n");
        printf("1. Insert at last\n");
        printf("2. Insert before a specific node\n");
        printf("3. Insert after a specific node\n");
        printf("4. Traversing\n");
        printf("5. Searching\n");
        printf("6. Deletion of a particular node\n");
        printf("7. Reversing\n");
        printf("8. Exit\n");
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
                if(searching(se))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &se);
                delete_node(se);
                break;
            case 7:
                reverse();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please choose a number between 1 and 8.\n");
        }
    }
    return 0;
}

void insert_at_last(int item) {
    node *temp;
    temp = (node*)malloc(sizeof(node));
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

void insert_after(int item, int se) {
    node *dh = head;
    node *temp;
    int flag = 0;
    while (dh != NULL) {
        if (se == dh->data) {
            flag = 1;
            break;
        }
        dh = dh->next;
    }
    if (flag == 0) {
        printf("Node %d not found.\n", se);
        return;
    }
    temp = (node*)malloc(sizeof(node));
    temp->data = item;
    temp->next = dh->next;
    dh->next = temp;
    if (temp->next == NULL) {
        last_node = temp;
    }
}

void insert_before(int item, int se) {
    node *dh = head;
    node *temp;
    int flag = 0;
    temp = (node*)malloc(sizeof(node));
    if (head == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }
    if (head->data == se) {
        temp->data = item;
        temp->next = head;
        head = temp;
        return;
    }
    while (dh->next != NULL) {
        if (dh->next->data == se) {
            flag = 1;
            break;
        }
        dh = dh->next;
    }
    if (flag == 0) {
        printf("Node %d not found.\n", se);
        return;
    }
    temp->data = item;
    temp->next = dh->next;
    dh->next = temp;
}

void traverse()
{
    node *dh = head;
    while (dh != NULL) {
        printf("%d\n", dh->data);
        dh = dh->next;
    }
    printf("\n");
}

int searching(int se) {
    node *dh = head;
    int flag = 0;
    while (dh != NULL) {
        if (se == dh->data) {
            flag = 1;
            break;
        }
        dh = dh->next;
    }
    return flag;
}

void delete_node (int se) {
    node *dh = head;
    node *temp;
    int flag = 0;
    if (head->data == se) {
        temp = head;
        head = head->next;
        if (head == NULL) {
            last_node = NULL;
        }
        free(temp);
        return;
    }
    while (dh->next != NULL) {
        if (dh->next->data == se) {
            flag = 1;
            break;
        }
        dh = dh->next;
    }
    if (flag == 0)
    {
        printf("Node %d not found.\n", se);
        return;
    }
    temp = dh->next;
    dh->next = dh->next->next;
    if (dh->next == NULL) {
        last_node = dh;
    }
    free(temp);
}

void reverse () {
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
