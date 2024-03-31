#include <stdio.h>

void createMatrix(int matrix[10][10], int rows, int cols) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void strassenMatrixMultiply(int A[10][10], int B[10][10], int C[10][10], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int A11[10][10], A12[10][10], A21[10][10], A22[10][10];
    int B11[10][10], B12[10][10], B21[10][10], B22[10][10];
    int C11[10][10], C12[10][10], C21[10][10], C22[10][10];
    int M1[10][10], M2[10][10], M3[10][10], M4[10][10], M5[10][10], M6[10][10], M7[10][10];
    int temp1[10][10], temp2[10][10];

    int i, j;

 
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n / 2];
            A21[i][j] = A[i + n / 2][j];
            A22[i][j] = A[i + n / 2][j + n / 2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + n / 2];
            B21[i][j] = B[i + n / 2][j];
            B22[i][j] = B[i + n / 2][j + n / 2];
        }
    }

    strassenMatrixMultiply(A11, B11, temp1, n / 2);
    strassenMatrixMultiply(A12, B21, temp2, n / 2);
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            M1[i][j] = temp1[i][j] + temp2[i][j];
        }
    }

    strassenMatrixMultiply(A11, B12, temp1, n / 2);
    strassenMatrixMultiply(A12, B22, temp2, n / 2);
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            M2[i][j] = temp1[i][j] + temp2[i][j];
        }
    }

    strassenMatrixMultiply(A21, B11, temp1, n / 2);
    strassenMatrixMultiply(A22, B21, temp2, n / 2);
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            M3[i][j] = temp1[i][j] + temp2[i][j];
        }
    }

    strassenMatrixMultiply(A21, B12, temp1, n / 2);
    strassenMatrixMultiply(A22, B22, temp2, n / 2);
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            M4[i][j] = temp1[i][j] + temp2[i][j];
        }
    }

    strassenMatrixMultiply(A11, B11, temp1, n / 2);
    strassenMatrixMultiply(A12, B12, temp2, n / 2);
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            M5[i][j] = temp1[i][j] + temp2[i][j];
        }
    }

    strassenMatrixMultiply(A21, B21, temp1, n / 2);
    strassenMatrixMultiply(A22, B22, temp2, n / 2);
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            M6[i][j] = temp1[i][j] + temp2[i][j];
        }
    }

    strassenMatrixMultiply(A11, B12, temp1, n / 2);
    strassenMatrixMultiply(A12, B22, temp2, n / 2);
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            M7[i][j] = temp1[i][j] + temp2[i][j];
        }
    }

    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C12[i][j] = M3[i][j] + M5[i][j];
            C21[i][j] = M2[i][j] + M4[i][j];
            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

 
    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n / 2; j++) {
            C[i][j] = C11[i][j];
            C[i][j + n / 2] = C12[i][j];
            C[i + n / 2][j] = C21[i][j];
            C[i + n / 2][j + n / 2] = C22[i][j];
        }
    }
}

int main() {
    int A[10][10], B[10][10], C[10][10];
    int n;

    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);

    createMatrix(A, n, n);
    createMatrix(B, n, n);

    printf("\nMatrix A:\n");
    printMatrix(A, n, n);
    printf("\nMatrix B:\n");
    printMatrix(B, n, n);

    strassenMatrixMultiply(A, B, C, n);

    printf("\nResult Matrix:\n");
    printMatrix(C, n, n);

    return 0;
}
