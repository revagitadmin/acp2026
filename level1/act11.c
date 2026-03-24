#include <stdio.h>

void inputMatrix(int r, int c, int mat[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int r, int c, int mat[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int r, int c, int a[r][c], int b[r][c], int res[r][c]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] + b[i][j];
}

void subtractMatrix(int r, int c, int a[r][c], int b[r][c], int res[r][c]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] - b[i][j];
}

void multiplyMatrix(int r1, int c1, int r2, int c2, int a[r1][c1], int b[r2][c2], int res[r1][c2]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int r = 2, c = 2;
    int a[2][2], b[2][2], res[2][2];

    printf("Enter elements of Matrix A:\n");
    inputMatrix(r, c, a);
    printf("Enter elements of Matrix B:\n");
    inputMatrix(r, c, b);

    addMatrix(r, c, a, b, res);
    printf("\nAddition:\n");
    printMatrix(r, c, res);

    subtractMatrix(r, c, a, b, res);
    printf("\nSubtraction:\n");
    printMatrix(r, c, res);

    multiplyMatrix(r, c, r, c, a, b, res);
    printf("\nMultiplication:\n");
    printMatrix(r, c, res);

    return 0;
}