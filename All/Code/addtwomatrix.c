/*
 * Advanced Matrix Operations Calculator v2.0
 * Features: Matrix arithmetic, transformations,
 *           determinants, inverses, and analysis
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 10

// Function prototypes
void matrixAddition();
void matrixSubtraction();
void matrixMultiplication();
void scalarMultiplication();
void matrixTranspose();
void matrixDeterminant();
void matrixTrace();
void identityMatrix();
void diagonalMatrix();
void symmetricCheck();
void sparseMatrixCheck();
void matrixPower();
void upperTriangular();
void lowerTriangular();
void matrixNorm();
void displayMenu();

// Helper functions
void inputMatrix(int mat[][MAX], int r, int c);
void displayMatrix(int mat[][MAX], int r, int c);
void displayFloatMatrix(float mat[][MAX], int r, int c);

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║      Advanced Matrix Operations Calculator v2.0           ║\n");
    printf("║         Comprehensive Matrix Analysis Tool                 ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                matrixAddition();
                break;
            case 2:
                matrixSubtraction();
                break;
            case 3:
                matrixMultiplication();
                break;
            case 4:
                scalarMultiplication();
                break;
            case 5:
                matrixTranspose();
                break;
            case 6:
                matrixDeterminant();
                break;
            case 7:
                matrixTrace();
                break;
            case 8:
                identityMatrix();
                break;
            case 9:
                diagonalMatrix();
                break;
            case 10:
                symmetricCheck();
                break;
            case 11:
                sparseMatrixCheck();
                break;
            case 12:
                matrixPower();
                break;
            case 13:
                upperTriangular();
                break;
            case 14:
                lowerTriangular();
                break;
            case 15:
                matrixNorm();
                break;
            case 16:
                printf("\n--- Matrix Operations Guide ---\n");
                printf("\n• Addition: Same dimensions required\n");
                printf("• Multiplication: Columns of A = Rows of B\n");
                printf("• Determinant: Square matrix only\n");
                printf("• Transpose: Rows ↔ Columns\n");
                printf("• Trace: Sum of diagonal elements\n");
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Matrix Calculator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC OPERATIONS                                       │\n");
    printf("│  [1]  Matrix Addition                                   │\n");
    printf("│  [2]  Matrix Subtraction                                │\n");
    printf("│  [3]  Matrix Multiplication                             │\n");
    printf("│  [4]  Scalar Multiplication                             │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  MATRIX TRANSFORMATIONS                                 │\n");
    printf("│  [5]  Transpose                                         │\n");
    printf("│  [6]  Determinant                                       │\n");
    printf("│  [7]  Trace                                             │\n");
    printf("│  [8]  Identity Matrix                                   │\n");
    printf("│  [9]  Diagonal Matrix                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  MATRIX ANALYSIS                                        │\n");
    printf("│  [10] Symmetric Check                                   │\n");
    printf("│  [11] Sparse Matrix Check                               │\n");
    printf("│  [12] Matrix Power                                      │\n");
    printf("│  [13] Upper Triangular Form                             │\n");
    printf("│  [14] Lower Triangular Form                             │\n");
    printf("│  [15] Matrix Norm                                       │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Operations Guide                                  │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void inputMatrix(int mat[][MAX], int r, int c) {
    printf("Enter elements:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[][MAX], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}

void displayFloatMatrix(float mat[][MAX], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%8.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

void matrixAddition() {
    int r, c;
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    
    printf("\nEnter rows: ");
    scanf("%d", &r);
    printf("Enter columns: ");
    scanf("%d", &c);
    
    printf("\nMatrix 1:\n");
    inputMatrix(mat1, r, c);
    
    printf("\nMatrix 2:\n");
    inputMatrix(mat2, r, c);
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    
    printf("\n--- Matrix Addition ---\n\n");
    printf("Matrix 1:\n");
    displayMatrix(mat1, r, c);
    printf("\nMatrix 2:\n");
    displayMatrix(mat2, r, c);
    printf("\nResult:\n");
    displayMatrix(result, r, c);
}

void matrixSubtraction() {
    int r, c;
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    
    printf("\nEnter rows: ");
    scanf("%d", &r);
    printf("Enter columns: ");
    scanf("%d", &c);
    
    printf("\nMatrix 1:\n");
    inputMatrix(mat1, r, c);
    
    printf("\nMatrix 2:\n");
    inputMatrix(mat2, r, c);
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    
    printf("\n--- Matrix Subtraction ---\n\n");
    printf("Result:\n");
    displayMatrix(result, r, c);
}

void matrixMultiplication() {
    int r1, c1, r2, c2;
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX] = {0};
    
    printf("\nMatrix 1 rows: ");
    scanf("%d", &r1);
    printf("Matrix 1 columns: ");
    scanf("%d", &c1);
    
    printf("Matrix 2 rows: ");
    scanf("%d", &r2);
    printf("Matrix 2 columns: ");
    scanf("%d", &c2);
    
    if(c1 != r2) {
        printf("\n✗ Multiplication not possible! Columns of Matrix1 ≠ Rows of Matrix2\n");
        return;
    }
    
    printf("\nMatrix 1:\n");
    inputMatrix(mat1, r1, c1);
    
    printf("\nMatrix 2:\n");
    inputMatrix(mat2, r2, c2);
    
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            for(int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    
    printf("\n--- Matrix Multiplication ---\n\n");
    printf("Result (%dx%d):\n", r1, c2);
    displayMatrix(result, r1, c2);
}

void scalarMultiplication() {
    int r, c, scalar;
    int mat[MAX][MAX], result[MAX][MAX];
    
    printf("\nEnter rows: ");
    scanf("%d", &r);
    printf("Enter columns: ");
    scanf("%d", &c);
    
    inputMatrix(mat, r, c);
    
    printf("Enter scalar value: ");
    scanf("%d", &scalar);
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[i][j] = scalar * mat[i][j];
        }
    }
    
    printf("\n--- Scalar Multiplication ---\n\n");
    printf("Original:\n");
    displayMatrix(mat, r, c);
    printf("\nResult (×%d):\n", scalar);
    displayMatrix(result, r, c);
}

void matrixTranspose() {
    int r, c;
    int mat[MAX][MAX], trans[MAX][MAX];
    
    printf("\nEnter rows: ");
    scanf("%d", &r);
    printf("Enter columns: ");
    scanf("%d", &c);
    
    inputMatrix(mat, r, c);
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            trans[j][i] = mat[i][j];
        }
    }
    
    printf("\n--- Matrix Transpose ---\n\n");
    printf("Original (%dx%d):\n", r, c);
    displayMatrix(mat, r, c);
    printf("\nTranspose (%dx%d):\n", c, r);
    displayMatrix(trans, c, r);
}

void matrixDeterminant() {
    int n;
    int mat[MAX][MAX];
    
    printf("\nEnter matrix size (n×n): ");
    scanf("%d", &n);
    
    if(n > 3) {
        printf("\n✗ Currently supports up to 3×3 matrices\n");
        return;
    }
    
    inputMatrix(mat, n, n);
    
    int det = 0;
    
    if(n == 1) {
        det = mat[0][0];
    } else if(n == 2) {
        det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    } else if(n == 3) {
        det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
            - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
            + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    }
    
    printf("\n--- Determinant ---\n\n");
    printf("Matrix:\n");
    displayMatrix(mat, n, n);
    printf("\nDeterminant = %d\n", det);
}

void matrixTrace() {
    int n;
    int mat[MAX][MAX];
    
    printf("\nEnter matrix size (n×n): ");
    scanf("%d", &n);
    
    inputMatrix(mat, n, n);
    
    int trace = 0;
    for(int i = 0; i < n; i++) {
        trace += mat[i][i];
    }
    
    printf("\n--- Matrix Trace ---\n\n");
    printf("Matrix:\n");
    displayMatrix(mat, n, n);
    printf("\nTrace (sum of diagonal) = %d\n", trace);
}

void identityMatrix() {
    int n;
    int mat[MAX][MAX] = {0};
    
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        mat[i][i] = 1;
    }
    
    printf("\n--- Identity Matrix ---\n\n");
    displayMatrix(mat, n, n);
}

void diagonalMatrix() {
    int n;
    int mat[MAX][MAX] = {0};
    
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("Enter %d diagonal elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &mat[i][i]);
    }
    
    printf("\n--- Diagonal Matrix ---\n\n");
    displayMatrix(mat, n, n);
}

void symmetricCheck() {
    int n;
    int mat[MAX][MAX];
    
    printf("\nEnter matrix size (n×n): ");
    scanf("%d", &n);
    
    inputMatrix(mat, n, n);
    
    bool symmetric = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] != mat[j][i]) {
                symmetric = false;
                break;
            }
        }
    }
    
    printf("\n--- Symmetric Check ---\n\n");
    printf("Matrix:\n");
    displayMatrix(mat, n, n);
    printf("\nResult: %s\n", symmetric ? "Symmetric" : "Not Symmetric");
}

void sparseMatrixCheck() {
    int r, c;
    int mat[MAX][MAX];
    
    printf("\nEnter rows: ");
    scanf("%d", &r);
    printf("Enter columns: ");
    scanf("%d", &c);
    
    inputMatrix(mat, r, c);
    
    int zeros = 0, nonZeros = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(mat[i][j] == 0)
                zeros++;
            else
                nonZeros++;
        }
    }
    
    printf("\n--- Sparse Matrix Check ---\n\n");
    printf("Matrix:\n");
    displayMatrix(mat, r, c);
    printf("\nZero elements: %d\n", zeros);
    printf("Non-zero elements: %d\n", nonZeros);
    printf("Sparsity: %.2f%%\n", (zeros * 100.0) / (r * c));
    printf("\nResult: %s\n", zeros > nonZeros ? "Sparse Matrix" : "Not Sparse");
}

void matrixPower() {
    int n, power;
    int mat[MAX][MAX], result[MAX][MAX], temp[MAX][MAX];
    
    printf("\nEnter matrix size (n×n): ");
    scanf("%d", &n);
    
    inputMatrix(mat, n, n);
    
    printf("Enter power: ");
    scanf("%d", &power);
    
    if(power == 0) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                result[i][j] = (i == j) ? 1 : 0;
    } else {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                result[i][j] = mat[i][j];
        
        for(int p = 1; p < power; p++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    temp[i][j] = 0;
                    for(int k = 0; k < n; k++) {
                        temp[i][j] += result[i][k] * mat[k][j];
                    }
                }
            }
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    result[i][j] = temp[i][j];
        }
    }
    
    printf("\n--- Matrix Power ---\n\n");
    printf("Matrix^%d:\n", power);
    displayMatrix(result, n, n);
}

void upperTriangular() {
    int n;
    int mat[MAX][MAX];
    
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    inputMatrix(mat, n, n);
    
    bool isUpper = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(mat[i][j] != 0) {
                isUpper = false;
                break;
            }
        }
    }
    
    printf("\n--- Upper Triangular Check ---\n\n");
    printf("Matrix:\n");
    displayMatrix(mat, n, n);
    printf("\nResult: %s\n", isUpper ? "Upper Triangular" : "Not Upper Triangular");
}

void lowerTriangular() {
    int n;
    int mat[MAX][MAX];
    
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    inputMatrix(mat, n, n);
    
    bool isLower = true;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(mat[i][j] != 0) {
                isLower = false;
                break;
            }
        }
    }
    
    printf("\n--- Lower Triangular Check ---\n\n");
    printf("Matrix:\n");
    displayMatrix(mat, n, n);
    printf("\nResult: %s\n", isLower ? "Lower Triangular" : "Not Lower Triangular");
}

void matrixNorm() {
    int r, c;
    int mat[MAX][MAX];
    
    printf("\nEnter rows: ");
    scanf("%d", &r);
    printf("Enter columns: ");
    scanf("%d", &c);
    
    inputMatrix(mat, r, c);
    
    float frobeniusNorm = 0;
    int maxNorm = 0;
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            frobeniusNorm += mat[i][j] * mat[i][j];
            if(abs(mat[i][j]) > maxNorm)
                maxNorm = abs(mat[i][j]);
        }
    }
    
    frobeniusNorm = sqrt(frobeniusNorm);
    
    printf("\n--- Matrix Norms ---\n\n");
    printf("Matrix:\n");
    displayMatrix(mat, r, c);
    printf("\nFrobenius Norm: %.2f\n", frobeniusNorm);
    printf("Max Norm: %d\n", maxNorm);
}