/*
Write a menu-driven program to implement the Single Link List and perform the following operations.
a. Creation
b. Insertion
   i.  After a Specific Node
   ii. Before a Specific Node
c. Searching
d. Traversing
e. Reversing the list
f. Deletion of a particular node
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

void insertion();
void traverse();
int searching();
void insert_after(int se);
void insert_before(int se);
void reverse_list();
void delete_node(int se);

int main()
{
    int option;
    int value;
    while(option != 8)
    {
        printf("Menu:\n");
        printf("1. Insertion at last\n");
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
                insertion();
                break;
            case 2:
                printf("Enter the value before which to insert: ");
                scanf("%d", &value);
                insert_before(value);
                break;
            case 3:
                printf("Enter the value after which to insert: ");
                scanf("%d", &value);
                insert_after(value);
                break;
            case 4:
                traverse();
                break;
            case 5:
                printf("Enter the number to search: ");
                if(searching())
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;
            case 6:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &value);
                delete_node(value);
                break;
            case 7:
                reverse_list();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please choose a number between 1 and 9.\n");
        }
    }
    return 0;
}

void insertion()                            //insertion at last
{
    node *temp;
    temp = (node*)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Input data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        last_node = temp;
    }
    else
    {
        last_node->next = temp;
        last_node = temp;
    }
}

void insert_before(int se)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (head->data == se)
    {
        node *temp;
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }
        printf("Enter data to insert before %d: ", se);
        scanf("%d", &temp->data);
        temp->next = head;
        head = temp;
        return;
    }
    node *dh = head;

    int flag = 0;
    while (dh -> next != NULL) {
        if (dh -> next -> data == se) {
            flag = 1;
            break;
        }
        dh = dh -> next;
    }
    if (flag == 0) {
        printf("Not Found.\n");
        return;
    }
    node *temp;
    temp = (node *)malloc(sizeof(node));
    scanf ("%d", &temp -> data);
    temp -> next = dh -> next;
    dh -> next = temp;
}

void traverse()
{
    node *dh = head;
    while (dh != NULL)
    {
        printf("%d\n", dh->data);
        dh = dh->next;
    }
    printf("\n");
}

int searching()
{
    int se;
    int flag = 0;
    node *dh = head;
    scanf("%d", &se);
    while (dh != NULL)
    {
        if (se == dh->data)
        {
            flag = 1;
            break;
        }
        dh = dh->next;
    }
    return flag;
}

void insert_after(int se)
{
    node *dh = head;
    node *temp;
    int flag = 0;
    while (dh != NULL)
    {
        if (se == dh->data) {
            flag = 1;
            break;
        }
        dh = dh->next;
    }

    if (flag == 0)
    {
        printf("Not Found: %d\n", se);
        return;
    }
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert after %d: ", se);
    scanf("%d", &temp->data);
    temp->next = dh->next;
    dh->next = temp;
    if (!temp->next) {
        last_node = temp;
    }
}

void reverse_list()
{
    node *temp;
    node *dh;
    node *Rh;          //Reverse Head
    Rh = NULL;
    while (head != NULL) {
        temp = head;
        head = head -> next;
        temp -> next = Rh;
        Rh = temp;
    }
    head = Rh;
    traverse();      //printing after reversing completed
}

void delete_node(int se)
{
    node *temp;
    node *dh;
    if (head -> data == se)
    {
        temp = head;
        head = head -> next;
        if (head == NULL)
        {
            last_node = NULL;
        }
        free(temp);
        return;
    }
    dh = head;
    int flag = 0;
    while (dh -> next != NULL)
    {
        if (dh -> next -> data == se)
        {
            flag = 1;
            break;
        }
        dh = dh -> next;
    }
    if (flag == 0)
    {
        printf("Not Found.\n");
        return;
    }
    temp = dh -> next;
    dh -> next = temp -> next;
    if (dh -> next == NULL)
    {
        last_node = dh;
    }
    free(temp);
    traverse();
}
