/*
The famous car manufacturing compary, NavaVista, launching their Battery Operated subsidized 6-seater Car this 1st December.
For that NavaVista had opened the booking for 100 customers only.
Your job is to maintain the booking details on a First book First get basis.
You have to accept the foolowing details from the customers : (Name, AadharNo, MobileNo, City).
Write a menu-driven program to accept a booking, show the customers details, and sequence in which booking will be served on 1st December.
*/

NOT COMPLETE YET!!!!!


#include <stdio.h>
#define MAX 10
char LQ_name[MAX];
int LQ_aadhar[MAX];
int LQ_mobile[MAX];
char LQ_city[MAX];          
int F, R;
void Book(char name[], int aadhar, int mobile, char city[]);
char serving();
void display();

int main ()
{
  char name[15];
  int mobile;
  int aadhar;
  char city[10];
  int option;
  char n;
  int a;
  int m;
  char c;
  F = -1;
  R = -1;
  while (option != 4) {
    printf("Press 1 for Book,\n2 for Serving,\n3 for Display,\n4 for EXIT. : ");
    scanf("%d", &option);
    switch(option) {
      case 1 :
             printf("Enter required details to Book : ");
             printf("Customer name : ");
             gets(name);
             printf("Aadhar Number : ");
             scanf("%d", &aadhar);
             printf("Mobile Number : ");
             scanf("%d", &mobile);
             printf("City : ");
             gets(city);
             Book(char name[], int aadhar, int mobile, char city[]);
             break;
      case 2 :
             k = book();
             printf("booked item : %d\n", k);
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

void Book(char name[], int aadhar, int mobile, char city[]) {
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
    LQ_name[R] = name;
    LQ_aadhar[R] = aadhar;
    LQ_mobile[R] = mobile;
    LQ_city[R] = city;
  }
}

char serving() {
  int item;
  if (F == -1) {
    printf("Zero Booking.\n");
  }
  else {
    item = LQ[F];
    if (F == R) {
      F = -1;
      R = -1;
    }
    else {
      F = F+1;
    }
    return item;
  }
}

void display() {
  int i;
  for (i = F; i <= R; i++) {
    printf("%d ", LQ[i]);
  }
  printf("\n");
}
