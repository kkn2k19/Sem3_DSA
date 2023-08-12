/*
Single Linked List ---
*/

NOT COMPLETE YET!!!!

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
  scanf("%d", &temp);
}
