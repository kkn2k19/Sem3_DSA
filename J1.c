/*
1. Write a program to implement Binary Search Tree and do the following operations
    a. Creation
    b. Insertion
    c. Traversing (IN, PRE, POST Order)
    d. Searching
*/

#include <stdio.h>
#include <stdlib.h>

struct ABC
{
    int data;
    struct ABC *lc;
    struct ABC *rc;
};

typedef struct ABC node;

node* create_BinaryTree(node* root, int item);
void traverse_InOrder(node* root);
void traverse_PreOrder(node* root);
void traverse_PostOrder(node* root);
node* Searching(node* root, int item);

int main()
{
    node *root = NULL; // Initialize the root node

    int option;
    int item;
    int se;
    do {
        printf("Press 1 for Insertion.\n");
        printf("2 for Traversing (IN Order)\n");
        printf("3 for Traversing (PRE Order)\n");
        printf("4 for Traversing (POST Order)\n");
        printf("5 for Searching\n");
        printf("0 to exit\n");
        printf("Enter your choice : ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                printf("Enter element to insert : ");
                scanf("%d", &item);
                root = create_BinaryTree(root, item);
                break;
            case 2:
                printf("In-order traversal: ");
                traverse_InOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order traversal: ");
                traverse_PreOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal: ");
                traverse_PostOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter element to search : ");
                scanf("%d", &se);
                node* foundNode = Searching(root, se);
                if (foundNode != NULL) {
                    printf("Element found: %d\n", foundNode->data);
                } else {
                    printf("Element not found.\n");
                }
                break;
        }
    } while (option != 0);
    return 0;
}

node* create_BinaryTree(node *root, int item)
{
    if (root == NULL) {
        root = (node*)malloc(sizeof(node));
        root->data = item;
        root->lc = NULL;
        root->rc = NULL;
        return root;
    }
    if (item < root->data) {
        root->lc = create_BinaryTree(root->lc, item);
    } else {
        root->rc = create_BinaryTree(root->rc, item);
    }
    return root;
}

void traverse_InOrder(node *root)
{
    if (root != NULL) {
        traverse_InOrder(root->lc);
        printf("%d ", root->data);
        traverse_InOrder(root->rc);
    }
}

void traverse_PreOrder(node *root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        traverse_PreOrder(root->lc);
        traverse_PreOrder(root->rc);
    }
}

void traverse_PostOrder(node *root)
{
    if (root != NULL) {
        traverse_PostOrder(root->lc);
        traverse_PostOrder(root->rc);
        printf("%d ", root->data);
    }
}

node* Searching(node *root, int item)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->data == item) {
        return root;
    } else if (item < root->data) {
        return Searching(root->lc, item);
    } else {
        return Searching(root->rc, item);
    }
}