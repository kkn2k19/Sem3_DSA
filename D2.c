//Write a program to implement a Circular Queue Using Array/.

#include <stdio.h>
#define MAX 10

int CQ[MAX];
int R, F;

void insertion(int item);
int deletion();
void display();

int main()
{
    int option;
    int item;
    int k;
    F = MAX-1;
    R = MAX-1;
    do {
        printf("Press 1 for insertion,\n2 for deletion,\n3 for display,\n4 for exit. : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &item);
                insertion(item);
                break;
            case 2:
                k = deletion();
                if (k != -1)
                    printf("Deleted item: %d\n", k);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid option. Please choose between 1-4.\n");
        }
    } while(option != 4);
    return 0;
}

void insertion(int item)
{
    if ((R + 1)%MAX == F)
    {
        printf("Overflow.\n");
        return;
    }
    if (F == MAX-1) {
        F = 0;
    }
    R = (R + 1) % MAX;
    CQ[R] = item;
}

int deletion()
{
    if (F == MAX-1 && R == MAX-1)
    {
        printf("Underflow.\n");
        return -1;
    }
    int item = CQ[F];
    if (F == R)
    {
        F = MAX-1;
        R = MAX-1;
    }
    else
    {
        F = (F+1)%MAX;
    }
    return item;
}

void display()
{
    if (F == MAX-1 &&  R == MAX-1)
    {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue: ");
    int i = F;
    do {
        printf("%d ", CQ[i]);
        i = (i + 1) % MAX;
    } while(i != (R+1)%MAX);
   printf("\n");
}
