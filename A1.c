//Write a program to delete an element from the array.

#include <stdio.h>

int main()
{
    int arr[30], i, j, n, d;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("Enter the elements of the array : ");
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be deleted : ");
    scanf("%d", &d);
    for (i=0; i<n; i++){
        if (arr[i] == d){
            for (j=i; j<n; j++){
                arr[j]=arr[j+1];
            }
            n--;
            break;
        }
    }
    printf("The array after deletion : \n");
    for (i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
