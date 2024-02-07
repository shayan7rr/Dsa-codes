#include <stdio.h>

void selectionsort(int arr[],int n){
    int i,j,min;
    for (i = 0; i < n;i++){
        min = i;
        for (j = i + 1; j < n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
            }
            if(min!=i){
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
    }
}
void createarray(int arr[],int n){
    printf("Enter the array elements\n ");
    for (int i = 0; i < n;i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);

    }
}
void printarray(int arr[], int n){
    printf("\nThe entered array is:\n");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
        printf("\n");
    }
}

int main(){
    int arr[100], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    createarray(arr, n);
    printf("\nBefore sorting\n");
    printarray(arr, n);
    printf("\nAfter sorting\n");
    selectionsort(arr, n);
    printarray(arr, n);

    return 0;
}