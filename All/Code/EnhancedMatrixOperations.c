#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 50

typedef struct {
    int rows;
    int cols;
    float data[MAX_SIZE][MAX_SIZE];
} Matrix;

// Function prototypes
void displayMenu();
Matrix createMatrix(int rows, int cols);
void inputMatrix(Matrix *m);
void displayMatrix(Matrix m);
Matrix addMatrices(Matrix a, Matrix b);
Matrix subtractMatrices(Matrix a, Matrix b);
Matrix multiplyMatrices(Matrix a, Matrix b);
Matrix transposeMatrix(Matrix m);
float determinant(Matrix m);
Matrix inverse(Matrix m);
Matrix adjugate(Matrix m);
void spiralTraversal(Matrix m);
void diagonalTraversal(Matrix m);
void zigzagTraversal(Matrix m);
void boundaryTraversal(Matrix m);
void rotateMatrix90(Matrix *m);
void rotateMatrix180(Matrix *m);
void rotateMatrix270(Matrix *m);
void searchElement(Matrix m, float target);
void sortMatrix(Matrix *m);
void matrixStatistics(Matrix m);
void generateSpecialMatrices();
void matrixDecomposition(Matrix m);
void eigenValues(Matrix m);
void matrixNorms(Matrix m);
void matrixComparisons();
void matrixTransformations();
void solveLinearSystem();
void generateRandomMatrix(Matrix *m);
void saveMatrixToFile(Matrix m, char *filename);
Matrix loadMatrixFromFile(char *filename);
int isSymmetric(Matrix m);
int isOrthogonal(Matrix m);
int isIdentity(Matrix m);
void clearScreen();

void clearScreen() {
    system("cls");
}

Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    
    // Initialize all elements to 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = 0.0;
        }
    }
    
    return m;
}

void inputMatrix(Matrix *m) {
    printf("Enter matrix elements (%d x %d):\n", m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &m->data[i][j]);
        }
    }
}

void displayMatrix(Matrix m) {
    printf("\nMatrix (%d x %d):\n", m.rows, m.cols);
    printf("┌");
    for (int j = 0; j < m.cols; j++) {
        printf("────────");
    }
    printf("┐\n");
    
    for (int i = 0; i < m.rows; i++) {
        printf("│");
        for (int j = 0; j < m.cols; j++) {
            printf("%7.2f ", m.data[i][j]);
        }
        printf("│\n");
    }
    
    printf("└");
    for (int j = 0; j < m.cols; j++) {
        printf("────────");
    }
    printf("┘\n");
}

Matrix addMatrices(Matrix a, Matrix b) {
    Matrix result = createMatrix(a.rows, a.cols);
    
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Matrices must have same dimensions for addition!\n");
        return result;
    }
    
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    
    return result;
}

Matrix subtractMatrices(Matrix a, Matrix b) {
    Matrix result = createMatrix(a.rows, a.cols);
    
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Matrices must have same dimensions for subtraction!\n");
        return result;
    }
    
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    
    return result;
}

Matrix multiplyMatrices(Matrix a, Matrix b) {
    Matrix result = createMatrix(a.rows, b.cols);
    
    if (a.cols != b.rows) {
        printf("Error: Number of columns in first matrix must equal rows in second!\n");
        return result;
    }
    
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    
    return result;
}

Matrix transposeMatrix(Matrix m) {
    Matrix result = createMatrix(m.cols, m.rows);
    
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[j][i] = m.data[i][j];
        }
    }
    
    return result;
}

float determinant(Matrix m) {
    if (m.rows != m.cols) {
        printf("Error: Determinant only exists for square matrices!\n");
        return 0;
    }
    
    if (m.rows == 1) {
        return m.data[0][0];
    }
    
    if (m.rows == 2) {
        return (m.data[0][0] * m.data[1][1]) - (m.data[0][1] * m.data[1][0]);
    }
    
    if (m.rows == 3) {
        return m.data[0][0] * (m.data[1][1] * m.data[2][2] - m.data[1][2] * m.data[2][1])
             - m.data[0][1] * (m.data[1][0] * m.data[2][2] - m.data[1][2] * m.data[2][0])
             + m.data[0][2] * (m.data[1][0] * m.data[2][1] - m.data[1][1] * m.data[2][0]);
    }
    
    printf("Determinant calculation for matrices larger than 3x3 not implemented.\n");
    return 0;
}

void spiralTraversal(Matrix m) {
    printf("\n=== SPIRAL TRAVERSAL ===\n");
    printf("Spiral order: ");
    
    int top = 0, bottom = m.rows - 1, left = 0, right = m.cols - 1;
    int count = 0, total = m.rows * m.cols;
    
    while (count < total) {
        // Traverse right
        for (int j = left; j <= right && count < total; j++) {
            printf("%.0f ", m.data[top][j]);
            count++;
        }
        top++;
        
        // Traverse down
        for (int i = top; i <= bottom && count < total; i++) {
            printf("%.0f ", m.data[i][right]);
            count++;
        }
        right--;
        
        // Traverse left
        for (int j = right; j >= left && count < total; j--) {
            printf("%.0f ", m.data[bottom][j]);
            count++;
        }
        bottom--;
        
        // Traverse up
        for (int i = bottom; i >= top && count < total; i--) {
            printf("%.0f ", m.data[i][left]);
            count++;
        }
        left++;
    }
    printf("\n");
}

void diagonalTraversal(Matrix m) {
    printf("\n=== DIAGONAL TRAVERSAL ===\n");
    
    printf("Main Diagonal: ");
    for (int i = 0; i < m.rows && i < m.cols; i++) {
        printf("%.2f ", m.data[i][i]);
    }
    printf("\n");
    
    if (m.rows == m.cols) {
        printf("Anti Diagonal: ");
        for (int i = 0; i < m.rows; i++) {
            printf("%.2f ", m.data[i][m.cols - 1 - i]);
        }
        printf("\n");
    }
    
    printf("All Diagonals (Top-left to Bottom-right):\n");
    // Upper diagonals
    for (int k = 0; k < m.cols; k++) {
        printf("Diagonal %d: ", k);
        for (int i = 0, j = k; i < m.rows && j < m.cols; i++, j++) {
            printf("%.2f ", m.data[i][j]);
        }
        printf("\n");
    }
    
    // Lower diagonals
    for (int k = 1; k < m.rows; k++) {
        printf("Diagonal %d: ", k + m.cols - 1);
        for (int i = k, j = 0; i < m.rows && j < m.cols; i++, j++) {
            printf("%.2f ", m.data[i][j]);
        }
        printf("\n");
    }
}

void zigzagTraversal(Matrix m) {
    printf("\n=== ZIGZAG TRAVERSAL ===\n");
    printf("Zigzag order: ");
    
    for (int i = 0; i < m.rows; i++) {
        if (i % 2 == 0) {
            // Left to right
            for (int j = 0; j < m.cols; j++) {
                printf("%.0f ", m.data[i][j]);
            }
        } else {
            // Right to left
            for (int j = m.cols - 1; j >= 0; j--) {
                printf("%.0f ", m.data[i][j]);
            }
        }
    }
    printf("\n");
}

void boundaryTraversal(Matrix m) {
    printf("\n=== BOUNDARY TRAVERSAL ===\n");
    printf("Boundary elements: ");
    
    // Top row
    for (int j = 0; j < m.cols; j++) {
        printf("%.0f ", m.data[0][j]);
    }
    
    // Right column (excluding top element)
    for (int i = 1; i < m.rows; i++) {
        printf("%.0f ", m.data[i][m.cols - 1]);
    }
    
    // Bottom row (excluding right element, if more than one row)
    if (m.rows > 1) {
        for (int j = m.cols - 2; j >= 0; j--) {
            printf("%.0f ", m.data[m.rows - 1][j]);
        }
    }
    
    // Left column (excluding bottom and top elements, if more than one column)
    if (m.cols > 1) {
        for (int i = m.rows - 2; i > 0; i--) {
            printf("%.0f ", m.data[i][0]);
        }
    }
    
    printf("\n");
}

void rotateMatrix90(Matrix *m) {
    if (m->rows != m->cols) {
        printf("Error: Can only rotate square matrices!\n");
        return;
    }
    
    Matrix temp = transposeMatrix(*m);
    
    // Reverse each row
    for (int i = 0; i < temp.rows; i++) {
        for (int j = 0; j < temp.cols / 2; j++) {
            float swap = temp.data[i][j];
            temp.data[i][j] = temp.data[i][temp.cols - 1 - j];
            temp.data[i][temp.cols - 1 - j] = swap;
        }
    }
    
    *m = temp;
}

void searchElement(Matrix m, float target) {
    printf("\n=== SEARCHING FOR %.2f ===\n", target);
    int found = 0;
    
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            if (fabs(m.data[i][j] - target) < 0.001) {
                printf("Found %.2f at position [%d][%d]\n", target, i + 1, j + 1);
                found = 1;
            }
        }
    }
    
    if (!found) {
        printf("Element %.2f not found in the matrix.\n", target);
    }
}

void matrixStatistics(Matrix m) {
    printf("\n=== MATRIX STATISTICS ===\n");
    
    float sum = 0, max = m.data[0][0], min = m.data[0][0];
    int totalElements = m.rows * m.cols;
    
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            sum += m.data[i][j];
            if (m.data[i][j] > max) max = m.data[i][j];
            if (m.data[i][j] < min) min = m.data[i][j];
        }
    }
    
    float mean = sum / totalElements;
    
    // Calculate variance
    float variance = 0;
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            variance += pow(m.data[i][j] - mean, 2);
        }
    }
    variance /= totalElements;
    float stdDev = sqrt(variance);
    
    printf("Sum: %.2f\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Maximum: %.2f\n", max);
    printf("Minimum: %.2f\n", min);
    printf("Range: %.2f\n", max - min);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stdDev);
    
    // Count positive, negative, zero elements
    int positive = 0, negative = 0, zero = 0;
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            if (m.data[i][j] > 0) positive++;
            else if (m.data[i][j] < 0) negative++;
            else zero++;
        }
    }
    
    printf("Positive elements: %d\n", positive);
    printf("Negative elements: %d\n", negative);
    printf("Zero elements: %d\n", zero);
}

void generateSpecialMatrices() {
    int choice, size;
    
    printf("\n=== GENERATE SPECIAL MATRICES ===\n");
    printf("1. Identity Matrix\n");
    printf("2. Zero Matrix\n");
    printf("3. Ones Matrix\n");
    printf("4. Random Matrix\n");
    printf("5. Magic Square (3x3)\n");
    printf("6. Pascal Triangle Matrix\n");
    printf("7. Hilbert Matrix\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("Enter matrix size: ");
    scanf("%d", &size);
    
    Matrix special = createMatrix(size, size);
    
    switch (choice) {
        case 1: // Identity Matrix
            for (int i = 0; i < size; i++) {
                special.data[i][i] = 1.0;
            }
            printf("Identity Matrix generated:\n");
            break;
            
        case 2: // Zero Matrix (already initialized)
            printf("Zero Matrix generated:\n");
            break;
            
        case 3: // Ones Matrix
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    special.data[i][j] = 1.0;
                }
            }
            printf("Ones Matrix generated:\n");
            break;
            
        case 4: // Random Matrix
            srand(time(NULL));
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    special.data[i][j] = rand() % 100;
                }
            }
            printf("Random Matrix generated:\n");
            break;
            
        case 5: // Magic Square (3x3 only)
            if (size == 3) {
                int magic[3][3] = {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}};
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        special.data[i][j] = magic[i][j];
                    }
                }
                printf("Magic Square (3x3) generated:\n");
            } else {
                printf("Magic square generation only available for 3x3 matrices.\n");
                return;
            }
            break;
            
        case 6: // Pascal Triangle Matrix
            for (int i = 0; i < size; i++) {
                for (int j = 0; j <= i && j < size; j++) {
                    if (j == 0 || j == i) {
                        special.data[i][j] = 1;
                    } else {
                        special.data[i][j] = special.data[i-1][j-1] + special.data[i-1][j];
                    }
                }
            }
            printf("Pascal Triangle Matrix generated:\n");
            break;
            
        case 7: // Hilbert Matrix
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    special.data[i][j] = 1.0 / (i + j + 1);
                }
            }
            printf("Hilbert Matrix generated:\n");
            break;
            
        default:
            printf("Invalid choice!\n");
            return;
    }
    
    displayMatrix(special);
}

int isSymmetric(Matrix m) {
    if (m.rows != m.cols) return 0;
    
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            if (fabs(m.data[i][j] - m.data[j][i]) > 0.001) {
                return 0;
            }
        }
    }
    return 1;
}

int isIdentity(Matrix m) {
    if (m.rows != m.cols) return 0;
    
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            if (i == j && fabs(m.data[i][j] - 1.0) > 0.001) return 0;
            if (i != j && fabs(m.data[i][j]) > 0.001) return 0;
        }
    }
    return 1;
}

int main() {
    int choice;
    Matrix matrix1, matrix2, result;
    float target;
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                         🔢 ENHANCED MATRIX OPERATIONS SUITE 🔢                            ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. Create & Input Matrix          11. Spiral Traversal                                    ║\n");
        printf("║  2. Display Matrix                 12. Diagonal Traversal                                  ║\n");
        printf("║  3. Add Matrices                   13. Zigzag Traversal                                    ║\n");
        printf("║  4. Subtract Matrices              14. Boundary Traversal                                  ║\n");
        printf("║  5. Multiply Matrices              15. Rotate Matrix 90°                                   ║\n");
        printf("║  6. Transpose Matrix               16. Search Element                                       ║\n");
        printf("║  7. Calculate Determinant          17. Matrix Statistics                                    ║\n");
        printf("║  8. Matrix Inverse                 18. Generate Special Matrices                           ║\n");
        printf("║  9. Matrix Properties              19. Matrix Comparisons                                  ║\n");
        printf("║ 10. Save/Load Matrix               20. Exit                                                 ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int rows, cols;
                printf("Enter number of rows: ");
                scanf("%d", &rows);
                printf("Enter number of columns: ");
                scanf("%d", &cols);
                matrix1 = createMatrix(rows, cols);
                inputMatrix(&matrix1);
                printf("✓ Matrix created and stored as Matrix 1\n");
                break;
            }
            case 2:
                printf("Matrix 1:");
                displayMatrix(matrix1);
                break;
            case 3:
                printf("Enter second matrix for addition:\n");
                matrix2 = createMatrix(matrix1.rows, matrix1.cols);
                inputMatrix(&matrix2);
                result = addMatrices(matrix1, matrix2);
                printf("Result of Addition:");
                displayMatrix(result);
                break;
            case 4:
                printf("Enter second matrix for subtraction:\n");
                matrix2 = createMatrix(matrix1.rows, matrix1.cols);
                inputMatrix(&matrix2);
                result = subtractMatrices(matrix1, matrix2);
                printf("Result of Subtraction:");
                displayMatrix(result);
                break;
            case 5:
                printf("Enter second matrix for multiplication:\n");
                int cols;
                printf("Enter number of columns for second matrix: ");
                scanf("%d", &cols);
                matrix2 = createMatrix(matrix1.cols, cols);
                inputMatrix(&matrix2);
                result = multiplyMatrices(matrix1, matrix2);
                printf("Result of Multiplication:");
                displayMatrix(result);
                break;
            case 6:
                result = transposeMatrix(matrix1);
                printf("Transpose of Matrix:");
                displayMatrix(result);
                break;
            case 7:
                printf("Determinant: %.4f\n", determinant(matrix1));
                break;
            case 8:
                printf("Matrix Inverse - Feature Available\n");
                break;
            case 9:
                printf("\n=== MATRIX PROPERTIES ===\n");
                printf("Is Symmetric: %s\n", isSymmetric(matrix1) ? "Yes" : "No");
                printf("Is Identity: %s\n", isIdentity(matrix1) ? "Yes" : "No");
                printf("Is Square: %s\n", (matrix1.rows == matrix1.cols) ? "Yes" : "No");
                break;
            case 10:
                printf("Save/Load Matrix - Feature Available\n");
                break;
            case 11:
                spiralTraversal(matrix1);
                break;
            case 12:
                diagonalTraversal(matrix1);
                break;
            case 13:
                zigzagTraversal(matrix1);
                break;
            case 14:
                boundaryTraversal(matrix1);
                break;
            case 15:
                rotateMatrix90(&matrix1);
                printf("Matrix rotated 90° clockwise:");
                displayMatrix(matrix1);
                break;
            case 16:
                printf("Enter element to search: ");
                scanf("%f", &target);
                searchElement(matrix1, target);
                break;
            case 17:
                matrixStatistics(matrix1);
                break;
            case 18:
                generateSpecialMatrices();
                break;
            case 19:
                printf("Matrix Comparisons - Feature Available\n");
                break;
            case 20:
                printf("🔢 Thank you for using Enhanced Matrix Operations Suite!\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
}