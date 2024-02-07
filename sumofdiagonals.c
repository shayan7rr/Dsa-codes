#include <stdio.h>

void sumDiagonals(int mat[][3], int size) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < size; i++) {
        sum1 += mat[i][i];
        sum2 += mat[i][size - i - 1];
    }
    printf("Sum of diagonal 1: %d\n", sum1);
    printf("Sum of diagonal 2: %d\n", sum2);
}

int main() {
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int size = 3;

    sumDiagonals(mat, size);

    return 0;
}
