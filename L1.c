/*
Write a menu-driven program to implement the following Sorting Algorithms
    i. Bubble
    ii. Selection
    iii. Insertion

Write input() function to take input in the Array, display() function to show the array elements, and also write a separate function unsort() which will randomize the positions of the elements in the Array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void unsort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void display(int arr[], int n)
{
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    srand(time(NULL));
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    int choice;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    do
    {
        printf("\nMenu:\n");
        printf("1. Display elements\n");
        printf("2. Unsort elements (randomize positions)\n");
        printf("3. Bubble Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Insertion Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(arr, n);
            break;
        case 2:
            unsort(arr, n);
            printf("Array elements have been unsorted (randomized).\n");
            break;
        case 3:
            bubbleSort(arr, n);
            printf("Array sorted using Bubble Sort.\n");
            break;
        case 4:
            selectionSort(arr, n);
            printf("Array sorted using Selection Sort.\n");
            break;
        case 5:
            insertionSort(arr, n);
            printf("Array sorted using Insertion Sort.\n");
            break;
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}