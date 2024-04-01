#include <stdio.h>

#define MAX_SIZE 10

void multiply_matrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int n) {
    int i, j, k;
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int A11[MAX_SIZE][MAX_SIZE], A12[MAX_SIZE][MAX_SIZE], A21[MAX_SIZE][MAX_SIZE], A22[MAX_SIZE][MAX_SIZE];
        int B11[MAX_SIZE][MAX_SIZE], B12[MAX_SIZE][MAX_SIZE], B21[MAX_SIZE][MAX_SIZE], B22[MAX_SIZE][MAX_SIZE];
        int C11[MAX_SIZE][MAX_SIZE], C12[MAX_SIZE][MAX_SIZE], C21[MAX_SIZE][MAX_SIZE], C22[MAX_SIZE][MAX_SIZE];
        int P1[MAX_SIZE][MAX_SIZE], P2[MAX_SIZE][MAX_SIZE], P3[MAX_SIZE][MAX_SIZE], P4[MAX_SIZE][MAX_SIZE], P5[MAX_SIZE][MAX_SIZE], P6[MAX_SIZE][MAX_SIZE], P7[MAX_SIZE][MAX_SIZE];
        int temp1[MAX_SIZE][MAX_SIZE], temp2[MAX_SIZE][MAX_SIZE];
        
        int mid = n / 2;

       
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
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

     
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                temp1[i][j] = B12[i][j] - B22[i][j];
            }
        }
        multiply_matrices(A11, temp1, P1, mid);

      
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                temp1[i][j] = A11[i][j] + A12[i][j];
            }
        }
        multiply_matrices(temp1, B22, P2, mid);

       
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                temp1[i][j] = A21[i][j] + A22[i][j];
            }
        }
        multiply_matrices(temp1, B11, P3, mid);

   
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                temp1[i][j] = B21[i][j] - B11[i][j];
            }
        }
        multiply_matrices(A22, temp1, P4, mid);

       
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                temp1[i][j] = A11[i][j] + A22[i][j];
                temp2[i][j] = B11[i][j] + B22[i][j];
            }
        }
        multiply_matrices(temp1, temp2, P5, mid);

        
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                temp1[i][j] = A12[i][j] - A22[i][j];
                temp2[i][j] = B21[i][j] + B22[i][j];
            }
        }
        multiply_matrices(temp1, temp2, P6, mid);

        
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                temp1[i][j] = A11[i][j] - A21[i][j];
                temp2[i][j] = B11[i][j] + B12[i][j];
            }
        }
        multiply_matrices(temp1, temp2, P7, mid);

      
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                C11[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            }
        }

      
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                C12[i][j] = P1[i][j] + P2[i][j];
            }
        }

     
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                C21[i][j] = P3[i][j] + P4[i][j];
            }
        }

     
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                C22[i][j] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
            }
        }

       
        for (i = 0; i < mid; i++) {
            for (j = 0; j < mid; j++) {
                C[i][j] = C11[i][j];
                C[i][j + mid] = C12[i][j];
                C[i + mid][j] = C21[i][j];
                C[i + mid][j + mid] = C22[i][j];
            }
        }
    }
}

void display_matrix(int matrix[][MAX_SIZE], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int n, i, j;

    printf("Enter the size of matrices (n x n): ");
    scanf("%d", &n);

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    multiply_matrices(A, B, C, n);

    printf("Resultant matrix C:\n");
    display_matrix(C, n);

    return 0;
}

