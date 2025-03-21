#include <stdio.h>

// Function to calculate the determinant of a matrix
int determinant(int matrix[10][10], int n) {
    int det = 0;
    int subMatrix[10][10];
    
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    
    for (int x = 0; x < n; x++) {
        int subI = 0;
        for (int i = 1; i < n; i++) {
            int subJ = 0;
            for (int j = 0; j < n; j++) {
                if (j == x)
                    continue;
                subMatrix[subI][subJ] = matrix[i][j];
                subJ++;
            }
            subI++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(subMatrix, n - 1);
    }
    
    return det;
}

int main() {
    int matrix[10][10], n;
    
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);
    
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int result = determinant(matrix, n);
    printf("The determinant of the matrix is: %d\n", result);
    
    return 0;
}
