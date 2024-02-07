#include <stdio.h>


void merge(int arr[], int low, int mid, int high){
    int newarr[100];
    int i,j,k;
    i = low;
    j = mid + 1;
    k = low;
    while(i<=mid && j<= high){
        if(arr[i]<=arr[j]){
            newarr[k] = arr[i];
            i++;
        }
        else{
            newarr[k] = arr[j];
            j++ ;
        }
        k++;
    }
    if(i>mid){
        while(j<=high){
            newarr[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            newarr[k]=arr[i];
            i++;
            k++;
        }
    }
    for (i = low; i <= high;i++){
        arr[i] = newarr[i];

    }
}

void mergesort(int arr[], int low, int high){
    if(low<high){

    int mid = (low + high) / 2;
    mergesort(arr , low , mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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
   mergesort(arr, 0, n);
    printarray(arr, n);

    return 0;
}