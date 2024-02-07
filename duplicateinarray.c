#include <stdio.h>

#define ROWS 2
#define COLS 2

void createArray(int matrix[ROWS][COLS]) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printArray(int matrix[ROWS][COLS]) {
    printf("Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[ROWS][COLS], mat2[ROWS][COLS], result[ROWS][COLS];

    printf("Enter elements for first matrix:\n");
    createArray(mat1);

    printf("Enter elements for second matrix:\n");
    createArray(mat2);

    multiplyMatrix(mat1, mat2, result);

    printf("Resultant matrix after multiplication:\n");
    printArray(result);

    return 0;
}
