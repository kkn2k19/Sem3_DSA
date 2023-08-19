/*
The famous car manufacturing company, NavaVista, launching their Battery Operated subsidized 6-seater Car this 1st December.
For that NavaVista had opened the booking for 100 customers only.
Your job is to maintain the booking details on a First book First get basis.
You have to accept the following details from the customers : (Name, Aadhar No, MobileNo, City).
Write a menu-driven program to accept a booking, show the customers details, and
sequence in which booking will be served on 1st December.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct car {
    char name[20];
    char aadhaar[20];
    char mobile[20];
    char city[20];
    char temp[5];
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
    printf("\nPress 1 for Book,\n2 for Serving,\n3 for Display,\n4 for EXIT. : ");
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
    fgets(LQ[R].temp, sizeof(LQ[R].temp), stdin);
    printf("Customer Name : ");
    fgets(LQ[R].name, sizeof(LQ[R].name), stdin);
    printf("Aadhaar No. : ");
    fgets(LQ[R].aadhaar, sizeof(LQ[R].aadhaar), stdin);
    printf("Mobile No. : ");
    fgets(LQ[R].mobile, sizeof(LQ[R].mobile), stdin);
    printf("City : ");
    fgets(LQ[R].city, sizeof(LQ[R].city), stdin);
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
    strcpy(a, LQ[F].name);
    strcpy(b, LQ[F].aadhaar);
    strcpy(c, LQ[F].mobile);
    strcpy(d, LQ[F].city);
    if (F == R) {
      F = -1;
      R = -1;
    }
    else {
      F = F+1;
    }
    printf("Served Booking : --- \n");
    printf("Booking Number : %d\n", F);
    printf("Customer Name : %s", a);
    printf("Aadhaar No. : %s", b);
    printf("Mobile No. : %s", c);
    printf("City : %s", d);
  }
}

void display() {
  int i;
  for (i = F; i <= R; i++) {
    printf("\nBooking Number : %d\n", i+1);
    printf("Customer Name : %s", LQ[i].name);
    printf("Aadhaar No. : %s", LQ[i].aadhaar);
    printf("Mobile No. : %s", LQ[i].mobile);
    printf("City : %s", LQ[i].city);
  }
}
