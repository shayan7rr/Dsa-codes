#include <stdio.h>

void findMaxMin(int arr[], int size) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
}

int main() {
    int arr[] = {3, 6, 2, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    findMaxMin(arr, size);

    return 0;
}
