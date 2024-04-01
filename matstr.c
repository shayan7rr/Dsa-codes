#include <stdio.h>

void add(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiply(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int mid = n / 2;
    int A11[mid][mid], A12[mid][mid], A21[mid][mid], A22[mid][mid];
    int B11[mid][mid], B12[mid][mid], B21[mid][mid], B22[mid][mid];
    int C11[mid][mid], C12[mid][mid], C21[mid][mid], C22[mid][mid];
    int P1[mid][mid], P2[mid][mid], P3[mid][mid], P4[mid][mid], P5[mid][mid], P6[mid][mid], P7[mid][mid];
    int temp1[mid][mid], temp2[mid][mid];

   
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    
    add(mid, A11, A22, temp1);
    add(mid, B11, B22, temp2);
    multiply(mid, temp1, temp2, P1);

    add(mid, A21, A22, temp1);
    multiply(mid, temp1, B11, P2);

    subtract(mid, B12, B22, temp1);
    multiply(mid, A11, temp1, P3);

    subtract(mid, B21, B11, temp1);
    multiply(mid, A22, temp1, P4);

    add(mid, A11, A12, temp1);
    multiply(mid, temp1, B22, P5);

    subtract(mid, A21, A11, temp1);
    add(mid, B11, B12, temp2);
    multiply(mid, temp1, temp2, P6);

    subtract(mid, A12, A22, temp1);
    add(mid, B21, B22, temp2);
    multiply(mid, temp1, temp2, P7);

   
    add(mid, P1, P4, temp1);
    subtract(mid, temp1, P5, temp2);
    add(mid, temp2, P7, C11);

    add(mid, P3, P5, C12);

    add(mid, P2, P4, C21);

    add(mid, P1, P3, temp1);
    subtract(mid, temp1, P2, temp2);
    add(mid, temp2, P6, C22);

   
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
}

void printMatrix(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void inputMatrix(int n, int matrix[][n]) {
    printf("Enter %dx%d matrix elements:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int n;

    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter matrix A:\n");
    inputMatrix(n, A);
    printf("\n");

    printf("Enter matrix B:\n");
    inputMatrix(n, B);
    printf("\n");

    multiply(n, A, B, C);

    printf("Matrix A:\n");
    printMatrix(n, A);
    printf("\n");

    printf("Matrix B:\n");
    printMatrix(n, B);
    printf("\n");

    printf("Resultant Matrix C:\n");
    printMatrix(n, C);

    return 0;
}

