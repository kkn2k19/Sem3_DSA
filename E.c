/*
The famous car manufacturing compary, NavaVista, launching their Battery Operated subsidized 6-seater Car this 1st December.
For that NavaVista had opened the booking for 100 customers only.
Your job is to maintain the booking details on a First book First get basis.
You have to accept the foolowing details from the customers : (Name, AadharNo, MobileNo, City).
Write a menu-driven program to accept a booking, show the customers details, and sequence in which booking will be served on 1st December.
*/

NOT COMPLETE YET!!!!!


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct customer {
    char name[50];
    char aadharNo[20];
    char mobileNo[15];
    char city[50];
} Customer;

Customer booking[100];
int lastBooking = 0;

void book() {
    if(lastBooking >= 100) {
        printf("Booking full!\n");
        return;
    }
    printf("Enter your name: ");
    scanf(" %[^\n]s", booking[lastBooking].name);
    printf("Enter your Aadhar number: ");
    scanf(" %[^\n]s", booking[lastBooking].aadharNo);
    printf("Enter your mobile number: ");
    scanf(" %[^\n]s", booking[lastBooking].mobileNo);
    printf("Enter your city: ");
    scanf(" %[^\n]s", booking[lastBooking].city);
    lastBooking++;
    printf("Booking successful!\n");
}

void show() {
    int i;
    for(i = 0; i < lastBooking; i++) {
        printf("Booking no: %d\n", i+1);
        printf("Name: %s\n", booking[i].name);
        printf("Aadhar number: %s\n", booking[i].aadharNo);
        printf("Mobile number: %s\n", booking[i].mobileNo);
        printf("City: %s\n", booking[i].city);
        printf("\n");
    }
}

int main() {
    int choice;
    while(choice != 3) {
        printf("1. Book a car\n");
        printf("2. Show booking details\n");
        printf("3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                book();
                break;
            case 2:
                show();
                break;
            case 3:
                printf("Exiting.\n");;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
