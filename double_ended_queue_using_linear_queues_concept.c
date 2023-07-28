//double ended queue using linear queues concept

#include <stdio.h>
#define MAX 10
int DENQ[MAX];
int F1, F2, R1, R2;
void insert_at_left_side(int item);
void insert_at_right_side(int item);
int delete_from_left_side();
int delete_from_right_side();
//void display();

int main()
{
    int option, item;
    F1 = -1;
    R1 = -1;
    F2 = MAX;
    R2 = MAX;
    while (option != 6){
        printf("Press 1 for insertion at left side,\n2 for insertion at right side,\n3 for deletion from left side\n4 for deletion from right side\n5 for displaying the queue\n6 for Exit. : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: printf("Enter the number to insert at left side : ");
                    scanf("%d", &item);
                    insert_at_left_side(item);
                    break;
            case 2: printf("Enter the number to insert at right side : ");
                    scanf("%d", &item);
                    insert_at_right_side(item);
                    break;
            case 3: int d1 = delete_from_left_side();
                    printf("Deleted Item : %d\n", d1);
                    break;
            case 4: int d2 = delete_from_right_side();
                    printf("Deleted Item : %d\n", d2);
                    break;
            case 5: 
                    //display();
                    break;
            case 6: 
                    printf("Exiting.");
        }
    }
    return 0;
}

void insert_at_left_side(int item)
{
    if ((R1+1)==R2) {
        printf("overflow.\n");
    }
    else {
        R1 = R1 + 1;
        DENQ[R1] = item;
    }
}

void insert_at_right_side(int item){
    if ((R2-1)==R1) {
        printf("overflow.\n");
    }
    else {
        R2 = R2 - 1;
        DENQ[R2] = item;
    }
}

int delete_from_left_side(){
    int item;
    if (F1 == -1){
        printf("underflow.\n");
    }
    else {
        item = DENQ[F1];
        if (F1 == R1){
            F1 = -1;
            R1 = -1;
        }
        else{
            F1 = F1+1;
        }
        return item;
    }
}

int delete_from_right_side(){
    int item;
    if (F2 == MAX){
        printf("Underflow.\n");
    }
    else {
        item = DENQ[F2];
        if (F2 == R2){
            F2 = MAX;
            R2 = MAX;
        }
        else {
            F2 = F2-1;
        }
        return item;
    }
}
