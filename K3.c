/*
Write a program to implement an Interpolation search algorithm.
*/

#include <stdio.h>

int InterpolationSearch(int arr[], int n, int se)
{
    int low = 0;
    int high = n - 1;
    while (low <= high && se >= arr[low] && se <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == se) {
                return low;
            }
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (se - arr[low]));
        if (arr[pos] == se) {
            return pos;
        }
        if (arr[pos] < se) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int se = 7;
    int index = InterpolationSearch(arr, n, se);
    if (index != -1)
    {
        printf("Element %d found at index %d\n", se, index);
    }
    else
    {
        printf("Element %d not found in the array\n", se);
    }
    return 0;
}
