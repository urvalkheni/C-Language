#include <stdio.h>

#define MAX 10

// Function to input matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose matrix
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], 
                     int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// Function to check if matrix is symmetric
int isSymmetric(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i])
                return 0;
        }
    }
    return 1;
}

// Function to add two matrices
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], 
                 int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

int main() {
    int matrix[MAX][MAX], transpose[MAX][MAX];
    int rows, cols, choice;
    
    printf("=== Matrix Operations ===\n\n");
    printf("1. Transpose a Matrix\n");
    printf("2. Check if Matrix is Symmetric\n");
    printf("3. Add Two Matrices\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\nEnter number of rows: ");
            scanf("%d", &rows);
            printf("Enter number of columns: ");
            scanf("%d", &cols);
            
            inputMatrix(matrix, rows, cols);
            
            printf("\nOriginal Matrix (%dx%d):\n", rows, cols);
            displayMatrix(matrix, rows, cols);
            
            transposeMatrix(matrix, transpose, rows, cols);
            
            printf("\nTransposed Matrix (%dx%d):\n", cols, rows);
            displayMatrix(transpose, cols, rows);
            break;
            
        case 2:
            printf("\nEnter size of square matrix: ");
            scanf("%d", &rows);
            cols = rows;
            
            inputMatrix(matrix, rows, cols);
            
            printf("\nMatrix:\n");
            displayMatrix(matrix, rows, cols);
            
            if (isSymmetric(matrix, rows))
                printf("\nThe matrix IS symmetric!\n");
            else
                printf("\nThe matrix is NOT symmetric.\n");
            break;
            
        case 3: {
            int matrix2[MAX][MAX], result[MAX][MAX];
            
            printf("\nEnter number of rows: ");
            scanf("%d", &rows);
            printf("Enter number of columns: ");
            scanf("%d", &cols);
            
            printf("\nFirst Matrix:\n");
            inputMatrix(matrix, rows, cols);
            
            printf("\nSecond Matrix:\n");
            inputMatrix(matrix2, rows, cols);
            
            addMatrices(matrix, matrix2, result, rows, cols);
            
            printf("\nFirst Matrix:\n");
            displayMatrix(matrix, rows, cols);
            
            printf("\nSecond Matrix:\n");
            displayMatrix(matrix2, rows, cols);
            
            printf("\nSum of Matrices:\n");
            displayMatrix(result, rows, cols);
            break;
        }
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}
