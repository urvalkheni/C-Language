#include<stdio.h>
int main() {
    int m, n, p, q;

    // Input dimensions for the matrices
    printf("Enter the number of rows of the first matrix: ");
    scanf("%d", &m);
    printf("Enter the number of columns of the first matrix: ");
    scanf("%d", &n);
    printf("Enter the number of rows of the second matrix: ");
    scanf("%d", &p);
    printf("Enter the number of columns of the second matrix: ");
    scanf("%d", &q);

    // Check if matrix multiplication is possible
    if (n != p) {
        printf("Matrix multiplication not possible! Columns of the first matrix must equal rows of the second matrix.\n");
        return 0;
    }

    // Declare matrices
    int a[m][n], b[p][q], res[m][q];

    // Initialize the result matrix to zero
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            res[i][j] = 0;
        }
    }

    // Input for the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    // Input for the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            printf("b[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Display the result matrix
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
