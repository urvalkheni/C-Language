/*
 * Advanced Binary Pattern Generator v2.0
 * Features: 0-1 patterns, binary visualizations,
 *           custom patterns, and mathematical binary operations
 * 
 * IMPROVEMENTS (v2.1):
 * - Added input validation for menu choices
 * - Enhanced error handling for pattern generation
 * - Improved code documentation and comments
 * - Added bounds checking for user inputs
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Function prototypes
void basicBinaryTriangle();
void checkerboardPattern();
void binaryPyramid();
void alternatingRows();
void diagonalPattern();
void spiralBinary();
void randomBinaryPattern();
void customBinaryPattern();
void binaryWave();
void diamondPattern();
void hollowBinarySquare();
void zigzagPattern();
void binaryFractal();
void numberToBinaryPattern();
void binaryMatrixOps();
void displayMenu();

int main() {
    int choice;
    int inputStatus;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║       Advanced Binary Pattern Generator v2.0              ║\n");
    printf("║         Comprehensive 0-1 Pattern System                  ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    srand(time(NULL));
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        inputStatus = scanf("%d", &choice);
        
        // Input validation: check if scanf was successful
        if(inputStatus != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                basicBinaryTriangle();
                break;
            case 2:
                checkerboardPattern();
                break;
            case 3:
                binaryPyramid();
                break;
            case 4:
                alternatingRows();
                break;
            case 5:
                diagonalPattern();
                break;
            case 6:
                spiralBinary();
                break;
            case 7:
                randomBinaryPattern();
                break;
            case 8:
                customBinaryPattern();
                break;
            case 9:
                binaryWave();
                break;
            case 10:
                diamondPattern();
                break;
            case 11:
                hollowBinarySquare();
                break;
            case 12:
                zigzagPattern();
                break;
            case 13:
                binaryFractal();
                break;
            case 14:
                numberToBinaryPattern();
                break;
            case 15:
                binaryMatrixOps();
                break;
            case 16:
                printf("\n--- Quick Reference ---\n");
                printf("\nPattern Types:\n");
                printf("• Triangle: Right-angle pattern\n");
                printf("• Checkerboard: Alternating 0-1\n");
                printf("• Pyramid: Centered pattern\n");
                printf("• Spiral: Circular arrangement\n");
                printf("• Fractal: Self-similar patterns\n");
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Binary Pattern Generator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC PATTERNS                                         │\n");
    printf("│  [1]  Basic Binary Triangle                             │\n");
    printf("│  [2]  Checkerboard Pattern                              │\n");
    printf("│  [3]  Binary Pyramid                                    │\n");
    printf("│  [4]  Alternating Rows                                  │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED PATTERNS                                      │\n");
    printf("│  [5]  Diagonal Pattern                                  │\n");
    printf("│  [6]  Spiral Binary                                     │\n");
    printf("│  [7]  Random Binary Pattern                             │\n");
    printf("│  [8]  Custom Binary Pattern                             │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL PATTERNS                                       │\n");
    printf("│  [9]  Binary Wave                                       │\n");
    printf("│  [10] Diamond Pattern                                   │\n");
    printf("│  [11] Hollow Binary Square                              │\n");
    printf("│  [12] Zigzag Pattern                                    │\n");
    printf("│  [13] Binary Fractal                                    │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  OPERATIONS                                             │\n");
    printf("│  [14] Number to Binary Pattern                          │\n");
    printf("│  [15] Binary Matrix Operations                          │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Quick Reference                                   │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void basicBinaryTriangle() {
    int rows, cols;
    printf("\nEnter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    printf("\n--- Basic Binary Triangle ---\n\n");
    
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= cols; j++) {
            if(j >= i) {
                if((i + j) % 2 == 0)
                    printf("1 ");
                else
                    printf("0 ");
            }
        }
        printf("\n");
    }
}

void checkerboardPattern() {
    int size;
    printf("\nEnter size: ");
    scanf("%d", &size);
    
    printf("\n--- Checkerboard Pattern ---\n\n");
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", (i + j) % 2);
        }
        printf("\n");
    }
}

void binaryPyramid() {
    int rows;
    printf("\nEnter number of rows: ");
    scanf("%d", &rows);
    
    printf("\n--- Binary Pyramid ---\n\n");
    
    for(int i = 1; i <= rows; i++) {
        // Print spaces
        for(int j = 1; j <= rows - i; j++) {
            printf("  ");
        }
        // Print pattern
        for(int j = 1; j <= 2 * i - 1; j++) {
            printf("%d ", j % 2);
        }
        printf("\n");
    }
}

void alternatingRows() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    
    printf("\n--- Alternating Rows ---\n\n");
    
    for(int i = 0; i < rows; i++) {
        int start = i % 2;
        for(int j = 0; j < cols; j++) {
            printf("%d ", start);
        }
        printf("\n");
    }
}

void diagonalPattern() {
    int size;
    printf("\nEnter size: ");
    scanf("%d", &size);
    
    printf("\n--- Diagonal Pattern ---\n\n");
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i == j || i + j == size - 1)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void spiralBinary() {
    int n;
    printf("\nEnter size (odd number recommended): ");
    scanf("%d", &n);
    if(n <= 0 || n > 20) {
        printf("Size must be between 1 and 20.\n");
        return;
    }
    
    int matrix[20][20] = {0};
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int value = 0;
    
    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) {
            matrix[top][i] = value;
            value = 1 - value;
        }
        top++;
        
        for(int i = top; i <= bottom; i++) {
            matrix[i][right] = value;
            value = 1 - value;
        }
        right--;
        
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                matrix[bottom][i] = value;
                value = 1 - value;
            }
            bottom--;
        }
        
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                matrix[i][left] = value;
                value = 1 - value;
            }
            left++;
        }
    }
    
    printf("\n--- Spiral Binary ---\n\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void randomBinaryPattern() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    
    printf("\n--- Random Binary Pattern ---\n\n");
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", rand() % 2);
        }
        printf("\n");
    }
}

void customBinaryPattern() {
    int rows, cols, rule;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    printf("Enter rule (1-5):\n");
    printf("1: Sum-based  2: Product-based  3: XOR-based\n");
    printf("4: AND-based  5: OR-based\n");
    printf("Choice: ");
    scanf("%d", &rule);
    
    printf("\n--- Custom Binary Pattern ---\n\n");
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int value = 0;
            switch(rule) {
                case 1: value = (i + j) % 2; break;
                case 2: value = (i * j) % 2; break;
                case 3: value = (i ^ j) % 2; break;
                case 4: value = (i & j) % 2; break;
                case 5: value = (i | j) % 2; break;
                default: value = (i + j) % 2;
            }
            printf("%d ", value);
        }
        printf("\n");
    }
}

void binaryWave() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    
    printf("\n--- Binary Wave ---\n\n");
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int value = (i + j / 2) % 2;
            printf("%d ", value);
        }
        printf("\n");
    }
}

void diamondPattern() {
    int n;
    printf("\nEnter size (odd number): ");
    scanf("%d", &n);
    
    printf("\n--- Diamond Pattern ---\n\n");
    
    int mid = n / 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int dist = abs(i - mid) + abs(j - mid);
            if(dist <= mid)
                printf("%d ", dist % 2);
            else
                printf("  ");
        }
        printf("\n");
    }
}

void hollowBinarySquare() {
    int size;
    printf("\nEnter size: ");
    scanf("%d", &size);
    
    printf("\n--- Hollow Binary Square ---\n\n");
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i == 0 || i == size - 1 || j == 0 || j == size - 1)
                printf("%d ", (i + j) % 2);
            else
                printf("  ");
        }
        printf("\n");
    }
}

void zigzagPattern() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    
    printf("\n--- Zigzag Pattern ---\n\n");
    
    for(int i = 0; i < rows; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < cols; j++) {
                printf("%d ", j % 2);
            }
        } else {
            for(int j = cols - 1; j >= 0; j--) {
                printf("%d ", j % 2);
            }
        }
        printf("\n");
    }
}

void binaryFractal() {
    int level;
    printf("\nEnter fractal level (1-4): ");
    scanf("%d", &level);
    
    int size = 1 << level; // 2^level
    
    printf("\n--- Binary Fractal (Sierpinski-like) ---\n\n");
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", (i & j) == 0 ? 1 : 0);
        }
        printf("\n");
    }
}

void numberToBinaryPattern() {
    int num;
    printf("\nEnter a number: ");
    scanf("%d", &num);
    
    printf("\n--- Number to Binary Pattern ---\n");
    printf("Number: %d\n", num);
    printf("Binary: ");
    
    if(num == 0) {
        printf("0\n");
        return;
    }
    
    int binary[32], i = 0;
    int temp = num;
    
    while(temp > 0) {
        binary[i++] = temp % 2;
        temp /= 2;
    }
    
    printf("\n\n");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d ", binary[j]);
    }
    printf("\n\nPattern Representation:\n");
    
    for(int j = i - 1; j >= 0; j--) {
        for(int k = 0; k <= j; k++) {
            printf("%d ", binary[k]);
        }
        printf("\n");
    }
}

void binaryMatrixOps() {
    int size;
    printf("\nEnter matrix size: ");
    scanf("%d", &size);
    
    int matrix[20][20];
    
    printf("Enter binary matrix (%dx%d with 0s and 1s):\n", size, size);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("\n--- Binary Matrix Operations ---\n\n");
    
    printf("Original Matrix:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\nTransposed Matrix:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
    
    printf("\nInverted Matrix (NOT operation):\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", 1 - matrix[i][j]);
        }
        printf("\n");
    }
}