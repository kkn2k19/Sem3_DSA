//Write a program  to display all unique elements of an array. 

#include <stdio.h>
int unique(int array[], int n);                    //unique - it is the function created to check for unique elements in the array.

int main()
{
   int arr[30], n, i;
   printf("Enter size of Array : ");
   scanf("%d",&n);
   printf("Enter the array elements : ");
   for(i = 0; i < n; i++){
      scanf("%d", &arr[i]);
   }
   unique(arr, n);
   return 0;
}

int unique(int arr[], int n){
   int i, j, c=0;
  printf("unique elements in array is : ");
   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         if(arr[i] == arr[j] && i != j)
         break;
      }
      if(j == n ){
         printf("%d ", arr[i]);
         c++;
      }
   }
   return -1;
}
