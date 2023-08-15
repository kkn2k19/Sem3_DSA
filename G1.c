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

NOT COMPLETE !!!!!

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
    int option, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Creation\n");
        printf("2. Insertion\n");
        printf("3. Insert after a specific node\n");
        printf("4. Insert before a specific node\n");
        printf("5. Traversing\n");
        printf("6. Searching\n");
        printf("7. Reversing the list\n");
        printf("8. Deletion of a particular node\n");
        printf("9. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) 
        {
            case 1:
                insertion();
                break;
            case 2:
                insertion();
                break;
            case 3: 
                printf("Enter the value after which to insert: ");
                scanf("%d", &value);
                insert_after(value);
                break;
            case 4: 
                printf("Enter the value before which to insert: ");
                scanf("%d", &value);
                insert_before(value);
                break;
            case 5:
                traverse();
                break;
            case 6: 
                printf("Enter the number to search: ");
                if(searching())
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;
            case 7:
                reverse_list();
                break;
            case 8:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &value);
                delete_node(value);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please choose a number between 1 and 9.\n");
        }
    } while(option != 9);

    return 0;
}

void insertion() 
{
    node *temp = (node*)malloc(sizeof(node));
    if (!temp) 
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Input data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (!head) 
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

void traverse() 
{
    node *dh = head;
    while (dh) 
    {
        printf("%d ", dh->data);
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
    while (dh) 
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
    while (dh) 
    {
        if (se == dh->data) 
            break;
        dh = dh->next;
    }
    if (!dh) 
    {
        printf("Not Found: %d\n", se);
        return;
    }
    temp = (node *)malloc(sizeof(node));
    if (!temp) 
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert after %d: ", se);
    scanf("%d", &temp->data);
    temp->next = dh->next;
    dh->next = temp;
    if (!temp->next) 
        last_node = temp;
}

void insert_before(int se) 
{
    if (!head) 
    {
        printf("List is empty.\n");
        return;
    }
    
    if (head->data == se) 
    {
        node *temp = (node *)malloc(sizeof(node));
        if (!temp) 
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
    node *temp;
    while (dh->next && dh->next->data != se) 
        dh = dh->next;

    if (!dh->next) 
    {
        printf("Not Found: %d\n", se);
        return;
    }
    
    temp = (node *)malloc(sizeof(node));
    if (!temp) 
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert before %d: ", se);
    scanf("%d", &temp->data);
    temp->next = dh->next;
    dh->next = temp;
}

void reverse_list() 
{
    node *prev = NULL, *current = head, *next = NULL;
    while (current) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void delete_node(int se) 
{
    node *temp, *prev;
    if (!head) 
    {
        printf("List is empty.\n");
        return;
    }

    if (head->data == se) 
    {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;
    while (temp && temp->data != se) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) 
    {
        printf("Node not found: %d\n", se);
        return;
    }

    prev->next = temp->next;
    if (!temp->next) 
        last_node = prev;
    free(temp);
}
