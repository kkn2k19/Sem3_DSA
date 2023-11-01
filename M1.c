/*
1. Write the program to implement the Merge Sort Algorithm.
*/

#include <stdio.h>
void merge(int *arr, int low, int mid, int high);

void MergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int *arr, int low, int mid, int high)
{
    int k = -1;
    int i = low;
    int j = mid + 1;
    int temp[high - low + 1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[++k] = arr[i++];
        }
        else
        {
            temp[++k] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[++k] = arr[i++];
    }
    while (j <= high)
    {
        temp[++k] = arr[j++];
    }
    for (i = 0; i <= k; i++)
    {
        arr[low + i] = temp[i];
    }
}

int main()
{
    int arr[] = {5, 4, 3, 9, 8, 7, 3, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = n - 1;
    MergeSort(arr, low, high);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
