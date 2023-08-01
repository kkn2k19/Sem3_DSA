//Take two sorted arrays and merge them in such a way that the merged array will also be sorted. Print all the elements of all arrays.

#include <stdio.h>
void merge_array(int arr1[], int arr2[], int n1, int n2, int merge[]);
void print(int merge[], int n3);

int main()
{
  int arr1[30], arr2[30], n1, n2, n3, i, merge[70];
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
  merge_array(arr1, arr2, n1, n2, merge);
  printf("Array after merging : ");
  n3 = n1+n2;
  print(merge, n3);
}

void merge_array(int arr1[], int arr2[], int n1, int n2, int merge[])
{
  int i = 0, j = 0, k = 0;
  while (i < n1 && j < n2)
  {
      if (arr1[i] < arr2[j]) {
        merge[k] = arr1[i];
        i++;
      }
      else {
        merge[k] = arr2[j];
        j++;
      }
      k++;
  }
  while (i < n1) {
    merge[k] = arr1[i];
    i++;
    k++;
  }
  while (j < n2) {
    merge[k] = arr2[j];
    j++;
    k++;
  }
  return merge;
}

void print(int merge[], int n3){
    int i;
    for (i = 0; i < n3; i++)
        {
            printf("%d ", merge[i]);
        }
}
