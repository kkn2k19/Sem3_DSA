/*
1. Write a program to implement a Linear Search Algorithm.
*/

#include <stdio.h>

int LinearSearch(int arr[], int n, int se) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == se) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {4, 3, 2, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int se = 7;
    int index = LinearSearch(arr, n, se);
    if (index == -1) {
        printf("Not Found\n");
    } else {
        printf("Found at index: %d\n", index);
    }

    return 0;
}
