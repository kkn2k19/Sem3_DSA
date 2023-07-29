//write a program to display the duplicate element of the array.

#include <stdio.h>

int main()
{
    int arr[30], i, j, n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("Enter the elements of the array : ");
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Duplicate elements in the array : ");
    for (i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if (arr[i] == arr[j]){
                printf("%d ", arr[i]);
                break;
            }
        }
    }
    return 0;
}
