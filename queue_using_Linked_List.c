//Write a program using single Linked List to implement Queue Data Structure.

 #include <stdio.h>
 #include <stdlib.h>

 struct queue
 {
     int data;
     struct queue *next;
 };

 typedef struct queue node;

 node *head;
 node *last_node;

 void ENQUE(int item);
 void DEQUE();
 void DISPLAY();

 int main ()
 {
     head = NULL;
     last_node = NULL;
     int option;
     int item;
     while (option != 4) {
        printf("Enter 1 for ENQUE, \n2 for DEQUE, \n3 for DISPLAY, \n4 for EXIT. : ");
        scanf("%d", &option);
        switch (option) {
        case 1 :
            printf("Enter number to ENQUE : ");
            scanf("%d", &item);
            ENQUE(item);
            break;
        case 2 :
            DEQUE();
            break;
        case 3 :
            DISPLAY();
            break;
        case 4 :
            printf("Exiting.\n");
            break;
        default :
            printf("Invalid Option.\n");
        }
     }
     return 0;
 }

 void ENQUE(int item) {
     node *temp;
     temp = (node *)malloc(sizeof(node));
     temp -> data = item;
     temp -> next = NULL;
     if (head == NULL && last_node == NULL) {
        head = temp;
        last_node = temp;
     } else {
         last_node -> next = temp;
         last_node = temp;
     }
 }

 void DEQUE ()
 {
     node *temp = head;
     if (head == NULL) {
        printf("Underflow.\n");
     }
        printf("Dequeued item : %d\n", head -> data);
        if (head == last_node) {
            head = NULL;
            last_node = NULL;
        }
        else {
            head = head -> next;
        }
    free(temp);
 }

 void DISPLAY () {
    node *dh = head;
    while (dh != NULL)
    {
        printf("%d\n", dh->data);
        dh = dh->next;
    }
    printf("\n");
 }
