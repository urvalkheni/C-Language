/*
 * Advanced Matrix Operations Calculator v2.0
 * Features: Matrix arithmetic, transformations,
 *           determinants, transpose, and advanced operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void addMatrices(int a[][MAX_SIZE], int b[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols);
void subtractMatrices(int a[][MAX_SIZE], int b[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int a[][MAX_SIZE], int b[][MAX_SIZE], int result[][MAX_SIZE], int r1, int c1, int r2, int c2);
void transposeMatrix(int matrix[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols);
void scalarMultiply(int matrix[][MAX_SIZE], int scalar, int result[][MAX_SIZE], int rows, int cols);
int determinant2x2(int matrix[][MAX_SIZE]);
int determinant3x3(int matrix[][MAX_SIZE]);
void identityMatrix(int matrix[][MAX_SIZE], int size);
void zeroMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void randomMatrix(int matrix[][MAX_SIZE], int rows, int cols, int max);
bool isSymmetric(int matrix[][MAX_SIZE], int size);
bool isIdentity(int matrix[][MAX_SIZE], int size);
int traceMatrix(int matrix[][MAX_SIZE], int size);
void spiralTraversal(int matrix[][MAX_SIZE], int rows, int cols);
void diagonalSum(int matrix[][MAX_SIZE], int size);
void rotateMatrix90(int matrix[][MAX_SIZE], int result[][MAX_SIZE], int size);
void displayMenu();

// Main function
int main() {
    int choice, rows, cols, r1, c1, r2, c2, scalar, size;
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    
    srand(time(NULL));
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║      Advanced Matrix Operations Calculator v2.0           ║\n");
    printf("║         Comprehensive Matrix Computation Tool             ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-18): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n--- Matrix Addition ---\n");
                printf("Enter rows and columns: ");
                scanf("%d %d", &rows, &cols);
                printf("Enter first matrix:\n");
                inputMatrix(matrix1, rows, cols);
                printf("Enter second matrix:\n");
                inputMatrix(matrix2, rows, cols);
                addMatrices(matrix1, matrix2, result, rows, cols);
                printf("\nResult:\n");
                displayMatrix(result, rows, cols);
                break;
                
            case 2:
                printf("\n--- Matrix Subtraction ---\n");
                printf("Enter rows and columns: ");
                scanf("%d %d", &rows, &cols);
                printf("Enter first matrix:\n");
                inputMatrix(matrix1, rows, cols);
                printf("Enter second matrix:\n");
                inputMatrix(matrix2, rows, cols);
                subtractMatrices(matrix1, matrix2, result, rows, cols);
                printf("\nResult:\n");
                displayMatrix(result, rows, cols);
                break;
                
            case 3:
                printf("\n--- Matrix Multiplication ---\n");
                printf("Enter rows and cols of first matrix: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and cols of second matrix: ");
                scanf("%d %d", &r2, &c2);
                if(c1 != r2) {
                    printf("Error: Incompatible dimensions!\n");
                    break;
                }
                printf("Enter first matrix:\n");
                inputMatrix(matrix1, r1, c1);
                printf("Enter second matrix:\n");
                inputMatrix(matrix2, r2, c2);
                multiplyMatrices(matrix1, matrix2, result, r1, c1, r2, c2);
                printf("\nResult:\n");
                displayMatrix(result, r1, c2);
                break;
                
            case 4:
                printf("\n--- Matrix Transpose ---\n");
                printf("Enter rows and columns: ");
                scanf("%d %d", &rows, &cols);
                printf("Enter matrix:\n");
                inputMatrix(matrix1, rows, cols);
                transposeMatrix(matrix1, result, rows, cols);
                printf("\nTranspose:\n");
                displayMatrix(result, cols, rows);
                break;
                
            case 5:
                printf("\n--- Scalar Multiplication ---\n");
                printf("Enter rows and columns: ");
                scanf("%d %d", &rows, &cols);
                printf("Enter scalar value: ");
                scanf("%d", &scalar);
                printf("Enter matrix:\n");
                inputMatrix(matrix1, rows, cols);
                scalarMultiply(matrix1, scalar, result, rows, cols);
                printf("\nResult:\n");
                displayMatrix(result, rows, cols);
                break;
                
            case 6:
                printf("\n--- Determinant (2×2) ---\n");
                printf("Enter 2×2 matrix:\n");
                inputMatrix(matrix1, 2, 2);
                printf("Determinant = %d\n", determinant2x2(matrix1));
                break;
                
            case 7:
                printf("\n--- Determinant (3×3) ---\n");
                printf("Enter 3×3 matrix:\n");
                inputMatrix(matrix1, 3, 3);
                printf("Determinant = %d\n", determinant3x3(matrix1));
                break;
                
            case 8:
                printf("\n--- Generate Identity Matrix ---\n");
                printf("Enter size: ");
                scanf("%d", &size);
                identityMatrix(matrix1, size);
                displayMatrix(matrix1, size, size);
                break;
                
            case 9:
                printf("\n--- Generate Zero Matrix ---\n");
                printf("Enter rows and columns: ");
                scanf("%d %d", &rows, &cols);
                zeroMatrix(matrix1, rows, cols);
                displayMatrix(matrix1, rows, cols);
                break;
                
            case 10:
                printf("\n--- Generate Random Matrix ---\n");
                printf("Enter rows and columns: ");
                scanf("%d %d", &rows, &cols);
                printf("Enter max value: ");
                scanf("%d", &scalar);
                randomMatrix(matrix1, rows, cols, scalar);
                displayMatrix(matrix1, rows, cols);
                break;
                
            case 11:
                printf("\n--- Check Symmetric Matrix ---\n");
                printf("Enter size: ");
                scanf("%d", &size);
                printf("Enter matrix:\n");
                inputMatrix(matrix1, size, size);
                if(isSymmetric(matrix1, size))
                    printf("Matrix is SYMMETRIC ✓\n");
                else
                    printf("Matrix is NOT symmetric\n");
                break;
                
            case 12:
                printf("\n--- Check Identity Matrix ---\n");
                printf("Enter size: ");
                scanf("%d", &size);
                printf("Enter matrix:\n");
                inputMatrix(matrix1, size, size);
                if(isIdentity(matrix1, size))
                    printf("Matrix is IDENTITY ✓\n");
                else
                    printf("Matrix is NOT identity\n");
                break;
                
            case 13:
                printf("\n--- Matrix Trace ---\n");
                printf("Enter size: ");
                scanf("%d", &size);
                printf("Enter matrix:\n");
                inputMatrix(matrix1, size, size);
                printf("Trace = %d\n", traceMatrix(matrix1, size));
                break;
                
            case 14:
                printf("\n--- Spiral Traversal ---\n");
                printf("Enter rows and columns: ");
                scanf("%d %d", &rows, &cols);
                printf("Enter matrix:\n");
                inputMatrix(matrix1, rows, cols);
                printf("\nSpiral order: ");
                spiralTraversal(matrix1, rows, cols);
                printf("\n");
                break;
                
            case 15:
                printf("\n--- Diagonal Sum ---\n");
                printf("Enter size: ");
                scanf("%d", &size);
                printf("Enter matrix:\n");
                inputMatrix(matrix1, size, size);
                diagonalSum(matrix1, size);
                break;
                
            case 16:
                printf("\n--- Rotate Matrix 90° ---\n");
                printf("Enter size: ");
                scanf("%d", &size);
                printf("Enter matrix:\n");
                inputMatrix(matrix1, size, size);
                rotateMatrix90(matrix1, result, size);
                printf("\nRotated matrix:\n");
                displayMatrix(result, size, size);
                break;
                
            case 17:
                printf("\n--- Fill Matrix with Pattern ---\n");
                printf("Enter size: ");
                scanf("%d", &size);
                for(int i = 0; i < size; i++) {
                    for(int j = 0; j < size; j++) {
                        matrix1[i][j] = 10;
                    }
                }
                displayMatrix(matrix1, size, size);
                break;
                
            case 18: {
                printf("\n--- Matrix Quick Reference ---\n");
                printf("\nOperations:\n");
                printf("Addition: Same dimensions required\n");
                printf("Multiplication: cols(A) = rows(B)\n");
                printf("Transpose: Flip rows ↔ columns\n");
                printf("Determinant: Square matrices only\n");
                printf("Trace: Sum of main diagonal\n");
                break;
            }
                
            case 0:
                printf("\n✓ Thank you for using Matrix Calculator!\n");
                break;
                
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
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
    printf("│  [4]  Matrix Transpose                                  │\n");
    printf("│  [5]  Scalar Multiplication                             │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  DETERMINANT & PROPERTIES                               │\n");
    printf("│  [6]  Determinant (2×2)                                 │\n");
    printf("│  [7]  Determinant (3×3)                                 │\n");
    printf("│  [8]  Generate Identity Matrix                          │\n");
    printf("│  [9]  Generate Zero Matrix                              │\n");
    printf("│  [10] Generate Random Matrix                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  MATRIX CHECKS                                          │\n");
    printf("│  [11] Check if Symmetric                                │\n");
    printf("│  [12] Check if Identity                                 │\n");
    printf("│  [13] Calculate Trace                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED OPERATIONS                                    │\n");
    printf("│  [14] Spiral Traversal                                  │\n");
    printf("│  [15] Diagonal Sum (Primary & Secondary)                │\n");
    printf("│  [16] Rotate Matrix 90°                                 │\n");
    printf("│  [17] Fill with Pattern (All 10s)                       │\n");
    printf("│  [18] Quick Reference                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[][MAX_SIZE], int b[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[][MAX_SIZE], int b[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[][MAX_SIZE], int b[][MAX_SIZE], int result[][MAX_SIZE], int r1, int c1, int r2, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void scalarMultiply(int matrix[][MAX_SIZE], int scalar, int result[][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

int determinant2x2(int matrix[][MAX_SIZE]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

int determinant3x3(int matrix[][MAX_SIZE]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
         - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
         + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

void identityMatrix(int matrix[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }
}

void zeroMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
}

void randomMatrix(int matrix[][MAX_SIZE], int rows, int cols, int max) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % max + 1;
        }
    }
}

bool isSymmetric(int matrix[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(matrix[i][j] != matrix[j][i]) return false;
        }
    }
    return true;
}

bool isIdentity(int matrix[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
                return false;
        }
    }
    return true;
}

int traceMatrix(int matrix[][MAX_SIZE], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

void spiralTraversal(int matrix[][MAX_SIZE], int rows, int cols) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    
    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) printf("%d ", matrix[top][i]);
        top++;
        
        for(int i = top; i <= bottom; i++) printf("%d ", matrix[i][right]);
        right--;
        
        if(top <= bottom) {
            for(int i = right; i >= left; i--) printf("%d ", matrix[bottom][i]);
            bottom--;
        }
        
        if(left <= right) {
            for(int i = bottom; i >= top; i--) printf("%d ", matrix[i][left]);
            left++;
        }
    }
}

void diagonalSum(int matrix[][MAX_SIZE], int size) {
    int primary = 0, secondary = 0;
    for(int i = 0; i < size; i++) {
        primary += matrix[i][i];
        secondary += matrix[i][size - 1 - i];
    }
    printf("Primary diagonal sum: %d\n", primary);
    printf("Secondary diagonal sum: %d\n", secondary);
}

void rotateMatrix90(int matrix[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            result[j][size - 1 - i] = matrix[i][j];
        }
    }
}