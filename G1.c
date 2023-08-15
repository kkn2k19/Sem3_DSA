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

struct box 
{
  int data;
  int box*next;
};

typedef struct box node;

node*head;
node*last_node;

int main () 
{
  head = NULL;
  last_node = NULL;
  int option;
  while (option != 4) {
    printf("Enter 1 for insertion,\n2 for traversing,\n3 for searching,\n4 for Exiting. : ");
    scanf("%d", &option);
    switch(option) {
      case 1 :
             insertion();
             break;
      case 2 :
             traversing();
             break;
      case 3 : 
             searching();
             break;
      case 4 : 
             printf("Exiting.\n");
      default:
             printf("Give input from 1 to 4.\n");
    }
  }
  return 0;
}

void insertion () {
  node*temp;
  temp = (node*)malloc(sizeof(node));
  printf("Input data : ");
  scanf("%d", &temp -> data);
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

void traverse () {
   node *dh = head;
   while (dh != NULL) {
      printf("%d\n", dh->data);
      dh = dh -> next;
   }
}

int searching () {
   int se;
   int flag = 0;
   node *dh = head;
   scanf("%d", &se);
   while (dh != NULL) {
      if (se == dh -> data) {
         flag = 1;
         break;
      }
      dh = dh -> next;
   }
   return (flag);
}

void insert_after (int se) {
   node *dh = head;
   node *temp;
   int flag = 0;
   while (dh != NULL) {
      if (se = dh -> data) {
         flag = 1;
         break;
      }
      dh = dh -> next;
   }
   if (flag == 0) {
      printf("Not Found : %d\n", se);
      return;
   }
   temp = (node *)malloc(sizeof(node));
   scanf("%d", &temp -> data);
   temp -> next = dh -> next;
   dh -> next = temp;
   if (temp -> next == NULL) {
      last_node = temp;
   }
}

void insert_before (int se) {
   node *dh = head;
   if (head -> data == se) {
      temp = (node *)malloc(sizeof(node));
      scanf("%d", &temp -> data);
      temp -> next = head;
      head = temp;
      return;
   }
   flag = 0;
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
   temp = (node *)malloc(sizeof(node));
   scanf("%d", &temp -> data);
   temp -> next = dh -> next;
   dh -> next = temp;
}
