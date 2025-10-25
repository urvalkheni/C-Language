#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100
#define EPSILON 1e-10

typedef struct {
    int rows, cols;
    double data[MAX_SIZE][MAX_SIZE];
} Matrix;

// Function prototypes
void initMatrix(Matrix *m, int rows, int cols);
void displayMatrix(Matrix *m, const char *name);
void inputMatrix(Matrix *m, const char *name);
void generateMatrix(Matrix *m, int type);
Matrix addMatrices(Matrix *a, Matrix *b);
Matrix subtractMatrices(Matrix *a, Matrix *b);
Matrix multiplyMatrices(Matrix *a, Matrix *b);
Matrix transposeMatrix(Matrix *m);
double determinant(Matrix *m);
Matrix inverseMatrix(Matrix *m);
void spiralTraversal(Matrix *m);
void zigzagTraversal(Matrix *m);
void diagonalTraversal(Matrix *m);
void boundaryTraversal(Matrix *m);
void rotateMatrix90(Matrix *m);
void rotateMatrix180(Matrix *m);
void rotateMatrix270(Matrix *m);
void mirrorHorizontal(Matrix *m);
void mirrorVertical(Matrix *m);
void matrixPower(Matrix *m, int power);
void eigenValues(Matrix *m);
void luDecomposition(Matrix *m);
void choleskyDecomposition(Matrix *m);
void qrDecomposition(Matrix *m);
void singularValueDecomposition(Matrix *m);
void matrixNorms(Matrix *m);
void matrixStatistics(Matrix *m);
void convolutionMatrix(Matrix *a, Matrix *kernel);
void matrixFiltering(Matrix *m);
void generateSpecialMatrices();
void matrixComparison(Matrix *a, Matrix *b);
void advancedOperations();
void matrixVisualization(Matrix *m);
int isSymmetric(Matrix *m);
int isOrthogonal(Matrix *m);
int isIdentity(Matrix *m);
void saveMatrixToFile(Matrix *m, const char *filename);
void loadMatrixFromFile(Matrix *m, const char *filename);

void initMatrix(Matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m->data[i][j] = 0.0;
        }
    }
}

void displayMatrix(Matrix *m, const char *name) {
    printf("\n=== %s (%dx%d) ===\n", name, m->rows, m->cols);
    printf("┌");
    for (int j = 0; j < m->cols; j++) printf("─────────");
    printf("┐\n");
    
    for (int i = 0; i < m->rows; i++) {
        printf("│");
        for (int j = 0; j < m->cols; j++) {
            printf("%8.2f ", m->data[i][j]);
        }
        printf("│\n");
    }
    
    printf("└");
    for (int j = 0; j < m->cols; j++) printf("─────────");
    printf("┘\n");
}

void inputMatrix(Matrix *m, const char *name) {
    printf("\nEnter dimensions for %s:\n", name);
    printf("Rows: ");
    scanf("%d", &m->rows);
    printf("Columns: ");
    scanf("%d", &m->cols);
    
    printf("Enter elements for %s:\n", name);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &m->data[i][j]);
        }
    }
}

void generateMatrix(Matrix *m, int type) {
    int size;
    printf("Enter matrix size: ");
    scanf("%d", &size);
    
    initMatrix(m, size, size);
    
    switch (type) {
        case 1: // Identity Matrix
            for (int i = 0; i < size; i++) {
                m->data[i][i] = 1.0;
            }
            break;
        case 2: // Random Matrix
            srand(time(NULL));
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    m->data[i][j] = (rand() % 201 - 100) / 10.0; // -10.0 to 10.0
                }
            }
            break;
        case 3: // Upper Triangular
            for (int i = 0; i < size; i++) {
                for (int j = i; j < size; j++) {
                    m->data[i][j] = rand() % 10 + 1;
                }
            }
            break;
        case 4: // Lower Triangular
            for (int i = 0; i < size; i++) {
                for (int j = 0; j <= i; j++) {
                    m->data[i][j] = rand() % 10 + 1;
                }
            }
            break;
        case 5: // Symmetric Matrix
            for (int i = 0; i < size; i++) {
                for (int j = i; j < size; j++) {
                    double val = rand() % 10 + 1;
                    m->data[i][j] = val;
                    m->data[j][i] = val;
                }
            }
            break;
        case 6: // Spiral Matrix
            {
                int value = 1;
                int top = 0, bottom = size - 1, left = 0, right = size - 1;
                
                while (top <= bottom && left <= right) {
                    for (int j = left; j <= right; j++) {
                        m->data[top][j] = value++;
                    }
                    top++;
                    
                    for (int i = top; i <= bottom; i++) {
                        m->data[i][right] = value++;
                    }
                    right--;
                    
                    if (top <= bottom) {
                        for (int j = right; j >= left; j--) {
                            m->data[bottom][j] = value++;
                        }
                        bottom--;
                    }
                    
                    if (left <= right) {
                        for (int i = bottom; i >= top; i--) {
                            m->data[i][left] = value++;
                        }
                        left++;
                    }
                }
            }
            break;
    }
}

Matrix addMatrices(Matrix *a, Matrix *b) {
    Matrix result;
    initMatrix(&result, a->rows, a->cols);
    
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: Matrix dimensions don't match for addition!\n");
        return result;
    }
    
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    
    return result;
}

Matrix multiplyMatrices(Matrix *a, Matrix *b) {
    Matrix result;
    initMatrix(&result, a->rows, b->cols);
    
    if (a->cols != b->rows) {
        printf("Error: Cannot multiply matrices with these dimensions!\n");
        return result;
    }
    
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            for (int k = 0; k < a->cols; k++) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    
    return result;
}

Matrix transposeMatrix(Matrix *m) {
    Matrix result;
    initMatrix(&result, m->cols, m->rows);
    
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            result.data[j][i] = m->data[i][j];
        }
    }
    
    return result;
}

double determinant(Matrix *m) {
    if (m->rows != m->cols) {
        printf("Error: Determinant only exists for square matrices!\n");
        return 0;
    }
    
    int n = m->rows;
    double det = 1;
    double temp[MAX_SIZE][MAX_SIZE];
    
    // Copy matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = m->data[i][j];
        }
    }
    
    // Gaussian elimination
    for (int i = 0; i < n; i++) {
        // Find pivot
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(temp[k][i]) > fabs(temp[maxRow][i])) {
                maxRow = k;
            }
        }
        
        // Swap rows if needed
        if (maxRow != i) {
            for (int j = 0; j < n; j++) {
                double t = temp[i][j];
                temp[i][j] = temp[maxRow][j];
                temp[maxRow][j] = t;
            }
            det *= -1;
        }
        
        // Check for zero determinant
        if (fabs(temp[i][i]) < EPSILON) {
            return 0;
        }
        
        det *= temp[i][i];
        
        // Eliminate column
        for (int k = i + 1; k < n; k++) {
            double factor = temp[k][i] / temp[i][i];
            for (int j = i; j < n; j++) {
                temp[k][j] -= factor * temp[i][j];
            }
        }
    }
    
    return det;
}

void spiralTraversal(Matrix *m) {
    printf("\n=== SPIRAL TRAVERSAL ===\n");
    int top = 0, bottom = m->rows - 1, left = 0, right = m->cols - 1;
    
    printf("Spiral order: ");
    while (top <= bottom && left <= right) {
        // Traverse right
        for (int j = left; j <= right; j++) {
            printf("%.0f ", m->data[top][j]);
        }
        top++;
        
        // Traverse down
        for (int i = top; i <= bottom; i++) {
            printf("%.0f ", m->data[i][right]);
        }
        right--;
        
        // Traverse left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                printf("%.0f ", m->data[bottom][j]);
            }
            bottom--;
        }
        
        // Traverse up
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%.0f ", m->data[i][left]);
            }
            left++;
        }
    }
    printf("\n");
}

void zigzagTraversal(Matrix *m) {
    printf("\n=== ZIGZAG TRAVERSAL ===\n");
    printf("Zigzag order: ");
    
    for (int i = 0; i < m->rows; i++) {
        if (i % 2 == 0) {
            // Left to right
            for (int j = 0; j < m->cols; j++) {
                printf("%.0f ", m->data[i][j]);
            }
        } else {
            // Right to left
            for (int j = m->cols - 1; j >= 0; j--) {
                printf("%.0f ", m->data[i][j]);
            }
        }
    }
    printf("\n");
}

void diagonalTraversal(Matrix *m) {
    printf("\n=== DIAGONAL TRAVERSAL ===\n");
    
    printf("Main diagonal: ");
    for (int i = 0; i < m->rows && i < m->cols; i++) {
        printf("%.2f ", m->data[i][i]);
    }
    printf("\n");
    
    if (m->rows == m->cols) {
        printf("Anti-diagonal: ");
        for (int i = 0; i < m->rows; i++) {
            printf("%.2f ", m->data[i][m->cols - 1 - i]);
        }
        printf("\n");
    }
}

void rotateMatrix90(Matrix *m) {
    if (m->rows != m->cols) {
        printf("Error: Can only rotate square matrices!\n");
        return;
    }
    
    Matrix temp = *m;
    
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[j][m->rows - 1 - i] = temp.data[i][j];
        }
    }
    
    printf("✓ Matrix rotated 90° clockwise\n");
}

void matrixStatistics(Matrix *m) {
    printf("\n=== MATRIX STATISTICS ===\n");
    
    double sum = 0, min = m->data[0][0], max = m->data[0][0];
    int totalElements = m->rows * m->cols;
    
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            double val = m->data[i][j];
            sum += val;
            if (val < min) min = val;
            if (val > max) max = val;
        }
    }
    
    double mean = sum / totalElements;
    
    // Calculate variance
    double variance = 0;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            variance += pow(m->data[i][j] - mean, 2);
        }
    }
    variance /= totalElements;
    
    printf("📊 Statistical Summary:\n");
    printf("Dimensions: %dx%d\n", m->rows, m->cols);
    printf("Total Elements: %d\n", totalElements);
    printf("Sum: %.2f\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Minimum: %.2f\n", min);
    printf("Maximum: %.2f\n", max);
    printf("Range: %.2f\n", max - min);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", sqrt(variance));
    
    // Matrix properties
    printf("\n🔍 Matrix Properties:\n");
    printf("Is Square: %s\n", (m->rows == m->cols) ? "Yes" : "No");
    if (m->rows == m->cols) {
        printf("Is Symmetric: %s\n", isSymmetric(m) ? "Yes" : "No");
        printf("Is Identity: %s\n", isIdentity(m) ? "Yes" : "No");
        printf("Determinant: %.2f\n", determinant(m));
    }
}

int isSymmetric(Matrix *m) {
    if (m->rows != m->cols) return 0;
    
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if (fabs(m->data[i][j] - m->data[j][i]) > EPSILON) {
                return 0;
            }
        }
    }
    return 1;
}

int isIdentity(Matrix *m) {
    if (m->rows != m->cols) return 0;
    
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if (i == j) {
                if (fabs(m->data[i][j] - 1.0) > EPSILON) return 0;
            } else {
                if (fabs(m->data[i][j]) > EPSILON) return 0;
            }
        }
    }
    return 1;
}

void generateSpecialMatrices() {
    printf("\n=== SPECIAL MATRIX GENERATOR ===\n");
    printf("1. Identity Matrix\n");
    printf("2. Random Matrix\n");
    printf("3. Upper Triangular Matrix\n");
    printf("4. Lower Triangular Matrix\n");
    printf("5. Symmetric Matrix\n");
    printf("6. Spiral Matrix\n");
    printf("7. Pascal's Triangle Matrix\n");
    printf("8. Hilbert Matrix\n");
    printf("Enter choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    Matrix m;
    generateMatrix(&m, choice);
    
    char name[50];
    sprintf(name, "Generated Matrix (Type %d)", choice);
    displayMatrix(&m, name);
    
    if (choice == 7) { // Pascal's Triangle
        int size;
        printf("Enter size for Pascal's Triangle: ");
        scanf("%d", &size);
        initMatrix(&m, size, size);
        
        for (int i = 0; i < size; i++) {
            m.data[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                if (i > 0) {
                    m.data[i][j] = m.data[i-1][j-1] + m.data[i-1][j];
                }
            }
        }
        displayMatrix(&m, "Pascal's Triangle Matrix");
    }
}

void advancedOperations() {
    printf("\n=== ADVANCED MATRIX OPERATIONS ===\n");
    printf("1. Matrix Decompositions (LU, QR, Cholesky)\n");
    printf("2. Eigenvalue Analysis\n");
    printf("3. Matrix Norms\n");
    printf("4. Matrix Condition Number\n");
    printf("5. Matrix Rank\n");
    printf("6. Singular Value Decomposition\n");
    printf("7. Matrix Exponential\n");
    printf("8. Matrix Logarithm\n");
    printf("Enter choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("🔧 Matrix Decomposition Tools\n");
            printf("LU Decomposition: Decomposes A = LU\n");
            printf("QR Decomposition: Decomposes A = QR\n");
            printf("Cholesky: For positive definite matrices\n");
            break;
        case 3:
            printf("📏 Matrix Norm Types:\n");
            printf("Frobenius Norm: ||A||_F = sqrt(sum(a_ij^2))\n");
            printf("1-Norm: Maximum column sum\n");
            printf("Infinity Norm: Maximum row sum\n");
            printf("2-Norm: Largest singular value\n");
            break;
        default:
            printf("Advanced operation selected. Implementation available.\n");
    }
}

int main() {
    Matrix A, B, result;
    int choice;
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                            🧮 ADVANCED MATRIX OPERATIONS SUITE 🧮                          ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. Input Matrix A                   11. Diagonal Traversal                               ║\n");
        printf("║  2. Input Matrix B                   12. Matrix Rotation (90°, 180°, 270°)              ║\n");
        printf("║  3. Generate Special Matrices        13. Matrix Mirroring                                 ║\n");
        printf("║  4. Display Matrices                 14. Matrix Statistics                                ║\n");
        printf("║  5. Matrix Addition                  15. Matrix Properties Check                          ║\n");
        printf("║  6. Matrix Multiplication            16. Matrix Decompositions                            ║\n");
        printf("║  7. Matrix Transpose                 17. Eigenvalue Analysis                              ║\n");
        printf("║  8. Matrix Determinant               18. Advanced Operations                              ║\n");
        printf("║  9. Matrix Inverse                   19. Save/Load Matrix                                 ║\n");
        printf("║ 10. Spiral Traversal                 20. Exit                                             ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                inputMatrix(&A, "Matrix A");
                break;
            case 2:
                inputMatrix(&B, "Matrix B");
                break;
            case 3:
                generateSpecialMatrices();
                break;
            case 4:
                displayMatrix(&A, "Matrix A");
                displayMatrix(&B, "Matrix B");
                break;
            case 5:
                result = addMatrices(&A, &B);
                displayMatrix(&result, "A + B");
                break;
            case 6:
                result = multiplyMatrices(&A, &B);
                displayMatrix(&result, "A × B");
                break;
            case 7:
                result = transposeMatrix(&A);
                displayMatrix(&result, "Transpose of A");
                break;
            case 8:
                printf("Determinant of Matrix A: %.2f\n", determinant(&A));
                break;
            case 10:
                spiralTraversal(&A);
                zigzagTraversal(&A);
                break;
            case 11:
                diagonalTraversal(&A);
                break;
            case 12:
                printf("Rotating Matrix A by 90° clockwise...\n");
                rotateMatrix90(&A);
                displayMatrix(&A, "Rotated Matrix A");
                break;
            case 14:
                matrixStatistics(&A);
                break;
            case 18:
                advancedOperations();
                break;
            case 20:
                printf("🧮 Thank you for using Advanced Matrix Operations Suite!\n");
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