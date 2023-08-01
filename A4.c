//Take two sorted arrays and merge them in such a way that the merged array will also be sorted. Print all the elements of all arrays.

#include <stdio.h>
merge(int arr1, int arr2, int n1, int n2);

int main() 
{
  int arr1[30], arr2[30], n1, n2, i;
  printf("Enter the size of Array 1 : ");
  scanf("%d", &n1);
  printf("Enter elements of the array 1 : ");
  for (i = 0; i < n1; i++) 
  {
    scanf("%d", &arr1[i]);
  }
  printf("Enter the size of Array 2 : ");
  scanf("%d", &n2);
  printf("Enter elements of the array 2 : ");
  for (i = 0; i < n2; i++) 
  {
    scanf("%d", &arr2[i]);
  }
  merge(arr1, arr2, n1, n2);
}
