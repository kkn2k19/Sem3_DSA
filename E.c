/*
The famous car manufacturing company, NavaVista, launching their Battery Operated subsidized 6-seater Car this 1st December.
For that NavaVista had opened the booking for 100 customers only.
Your job is to maintain the booking details on a First book First get basis.
You have to accept the following details from the customers : (Name, Aadhar No, MobileNo, City).
Write a menu-driven program to accept a booking, show the customers details, and
sequence in which booking will be served on 1st December.
*/

#include <stdio.h>
#define MAX 100
struct car {
    char name[20];
    char aadhar[20];
    char mobile[20];
    char city[20];
};
struct car LQ[MAX];
int F, R;
void booking();
void serving();
void display();

int main ()
{
  int option;
  F = -1;
  R = -1;
  while (option != 4) {
    printf("Press 1 for Book,\n2 for Serving,\n3 for Display,\n4 for EXIT. : ");
    scanf("%d", &option);
    switch(option) {
      case 1 :
             booking();
             break;
      case 2 :
             serving();
             break;
      case 3 :
             display();
             break;
      case 4 :
             printf("Exiting.\n");
    }
  }
  return 0;
}

void booking() {
  if (R == MAX-1) {
    printf("Fully Booked.\n");
  }
  else {
    if (R == -1) {
      R = R+1;
      F = F+1;
    }
    else {
      R = R+1;
    }
    printf("Customer Name : ");
    gets(LQ[R].name);
    printf("Aadhar No. : ");
    gets(LQ[R].aadhar);
    printf("Mobile No. : ");
    gets(LQ[R].mobile);
    printf("City : ");
    gets(LQ[R].city);
  }
}

void serving() {
  char a[20];
  char b[20];
  char c[20];
  char d[20];
  if (F == -1) {
    printf("Zero Booking.\n");
  }
  else {
    strcpy(a, LQ[R].name);
    strcpy(b, LQ[R].aadhar);
    strcpy(c, LQ[R].mobile);
    strcpy(d, LQ[R].city);
    if (F == R) {
      F = -1;
      R = -1;
    }
    else {
      F = F+1;                  //
    }
    printf("Served Booking : ---");
    printf("\nBooking Number : %d", i+1);
    printf("\nCustomer Name : ");
    puts(a[20]);
    printf("\nAadhar No. : ");
    puts(b[20]);
    printf("\nMobile No. : ");
    puts(c[20]);
    printf("\nCity : ");
    puts(d[20]);
  }
}

void display() {
  int i;
  for (i = F; i <= R; i++) {
    printf("\nBooking Number : %d", i+1);
    printf("\nCustomer Name : ");
    puts(LQ[R].name);
    printf("\nAadhar No. : ");
    puts(LQ[R].aadhar);
    printf("\nMobile No. : ");
    puts(LQ[R].mobile);
    printf("\nCity : ");
    puts(LQ[R].city);
  }
    printf("\nBooking Number : %d", i+1);
    printf("\nCustomer Name : ");
    puts(LQ[R].name);
    printf("\nAadhar No. : ");
    puts(LQ[R].aadhar);
    printf("\nMobile No. : ");
    puts(LQ[R].mobile);
    printf("\nCity : ");
    puts(LQ[R].city);
}
