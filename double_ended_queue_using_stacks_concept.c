// double ended queue using stacks concept

#include <stdio.h>
#define MAX 10
int DENQ[MAX];
int R, F;
void insert_from_rear_side(int item);
void insert_from_front_side(int item);
int delete_from_rear_side();
int delete_from_front_side();
void display_double_ended_queue();

int main ()
{
    int option, item;
    F = -1;
    R = MAX;
    while (option != 6){
        printf("Press 1 for insertion at rear side,\n2 for insertion at front side,\n3 for deletion at rear side\n4 for deletion at front side\n5 for displaying the queue\n6 for Exit. : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: printf("Enter the number to insert at rear side : ");
                    scanf("%d", &item);
                    insert_from_rear_side(item);
                    break;
            case 2: printf("Enter the number to insert at front side : ");
                    scanf("%d", &item);
                    insert_from_front_side(item);
                    break;
            case 3: int d1 = delete_from_rear_side();
                    printf("Deleted Item : %d\n", d1);
                    break;
            case 4: int d2 = delete_from_front_side();
                    printf("Deleted Item : %d\n", d2);
                    break;
            case 5: 
                    display_double_ended_queue();
                    break;
            case 6: 
                    printf("Exiting.");
        }
    }
    return 0;
}

void insert_from_rear_side(int item)
{
    if ((R-1)==F) {
        printf("Overflow at Rear Side.\n");
    }
    else {
        R=R-1;
        DENQ[R] = item;
    }
}

void insert_from_front_side(int item)
{
    if ((F+1)==R) {
        printf("Overflow at Front side.\n");
    }
    else {
        F = F+1;
        DENQ[F] = item;
    }
}

int delete_from_rear_side()
{
    int item;
    if (R == MAX){
        printf("Underflow at Rear Side.\n");
    }
    else {
        item = DENQ[R];
        R = R+1;
        return item;
    }
}

int delete_from_front_side()
{
    int item;
    if (F == -1) {
        printf("Underflow at front side.\n");
    }
    else {
        item = DENQ[F];
        F = F-1;
        return item;
    }
}

void display_double_ended_queue()
{
    int i;
    if (F!=-1 || R!=MAX){
        for (i=F; i<=R; i++){
            printf("%d ", DENQ[i]);
        }
        printf("%d ", DENQ[R]);
    }
    else {
        printf("Circular Queue is empty.");
    }
}
