#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes for basic patterns
void upperRightTriangle(int n, char symbol);
void upperLeftTriangle(int n, char symbol);
void lowerRightTriangle(int n, char symbol);
void lowerLeftTriangle(int n, char symbol);
void hollowUpperRightTriangle(int n, char symbol);
void hollowUpperLeftTriangle(int n, char symbol);
void hollowLowerRightTriangle(int n, char symbol);
void hollowLowerLeftTriangle(int n, char symbol);

// Advanced pattern functions
void diamondPattern(int n, char symbol);
void butterflyPattern(int n, char symbol);
void spiralPattern(int n);
void pascalTriangle(int n);
void floydTriangle(int n);
void heartPattern(int n);
void christmasTree(int n);
void wavePattern(int rows, int cols);
void zigzagPattern(int rows, int cols);
void checkerboardPattern(int n);
void mandalaPattern(int n);
void fibonacciSpiral(int n);
void numberDiamond(int n);
void alphabetPyramid(int n);
void hollowDiamond(int n, char symbol);
void crossPattern(int n, char symbol);
void starBurst(int n);
void hexagonPattern(int n);
void octagonPattern(int n);
void infinityPattern(int n);

// Utility functions
void printSpaces(int count);
void printChar(char c, int count);
void clearScreen();
void setColor(int color);
void resetColor();

void clearScreen() {
    system("cls");
}

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printChar(char c, int count) {
    for (int i = 0; i < count; i++) {
        printf("%c", c);
    }
}

void upperRightTriangle(int n, char symbol) {
    printf("\n=== Upper Right Triangle ===\n");
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);
        printChar(symbol, i);
        printf("\n");
    }
}

void upperLeftTriangle(int n, char symbol) {
    printf("\n=== Upper Left Triangle ===\n");
    for (int i = 1; i <= n; i++) {
        printChar(symbol, i);
        printf("\n");
    }
}

void lowerRightTriangle(int n, char symbol) {
    printf("\n=== Lower Right Triangle ===\n");
    for (int i = n; i >= 1; i--) {
        printSpaces(n - i);
        printChar(symbol, i);
        printf("\n");
    }
}

void lowerLeftTriangle(int n, char symbol) {
    printf("\n=== Lower Left Triangle ===\n");
    for (int i = n; i >= 1; i--) {
        printChar(symbol, i);
        printf("\n");
    }
}

void hollowUpperRightTriangle(int n, char symbol) {
    printf("\n=== Hollow Upper Right Triangle ===\n");
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == n) {
                printf("%c", symbol);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void diamondPattern(int n, char symbol) {
    printf("\n=== Diamond Pattern ===\n");
    // Upper half
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);
        printChar(symbol, 2 * i - 1);
        printf("\n");
    }
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        printSpaces(n - i);
        printChar(symbol, 2 * i - 1);
        printf("\n");
    }
}

void hollowDiamond(int n, char symbol) {
    printf("\n=== Hollow Diamond Pattern ===\n");
    // Upper half
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                printf("%c", symbol);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        printSpaces(n - i);
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                printf("%c", symbol);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void butterflyPattern(int n, char symbol) {
    printf("\n=== Butterfly Pattern ===\n");
    // Upper half
    for (int i = 1; i <= n; i++) {
        printChar(symbol, i);
        printSpaces(2 * (n - i));
        printChar(symbol, i);
        printf("\n");
    }
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        printChar(symbol, i);
        printSpaces(2 * (n - i));
        printChar(symbol, i);
        printf("\n");
    }
}

void spiralPattern(int n) {
    printf("\n=== Spiral Pattern ===\n");
    int matrix[20][20];
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int value = 1;
    
    while (top <= bottom && left <= right) {
        // Fill top row
        for (int i = left; i <= right; i++) {
            matrix[top][i] = value++;
        }
        top++;
        
        // Fill right column
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = value++;
        }
        right--;
        
        // Fill bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }
        
        // Fill left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }
    
    // Print matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void pascalTriangle(int n) {
    printf("\n=== Pascal's Triangle ===\n");
    for (int i = 0; i < n; i++) {
        printSpaces(n - i - 1);
        int value = 1;
        for (int j = 0; j <= i; j++) {
            printf("%3d ", value);
            value = value * (i - j) / (j + 1);
        }
        printf("\n");
    }
}

void floydTriangle(int n) {
    printf("\n=== Floyd's Triangle ===\n");
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%3d ", num++);
        }
        printf("\n");
    }
}

void heartPattern(int n) {
    printf("\n=== Heart Pattern ===\n");
    // Upper part of heart
    for (int i = n/2; i <= n; i += 2) {
        // Left spaces
        for (int j = 1; j < n - i; j += 2) {
            printf(" ");
        }
        // Left part of heart
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        // Middle spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Right part of heart
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Lower part of heart
    for (int i = n; i >= 1; i--) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        for (int j = 1; j <= (i * 2) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void christmasTree(int n) {
    printf("\n=== Christmas Tree ===\n");
    // Tree layers
    for (int layer = 0; layer < 3; layer++) {
        for (int i = 1; i <= n - layer; i++) {
            printSpaces(n - i + layer);
            printChar('*', 2 * i - 1);
            printf("\n");
        }
    }
    
    // Tree trunk
    for (int i = 0; i < 2; i++) {
        printSpaces(n - 1);
        printf("|\n");
    }
}

void wavePattern(int rows, int cols) {
    printf("\n=== Wave Pattern ===\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i + j) % 4 == 0 || (i + j) % 4 == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void zigzagPattern(int rows, int cols) {
    printf("\n=== Zigzag Pattern ===\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i + j) % 2 == 0) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void checkerboardPattern(int n) {
    printf("\n=== Checkerboard Pattern ===\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void numberDiamond(int n) {
    printf("\n=== Number Diamond ===\n");
    // Upper half
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        for (int j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        printSpaces(n - i);
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        for (int j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void alphabetPyramid(int n) {
    printf("\n=== Alphabet Pyramid ===\n");
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);
        char ch = 'A';
        for (int j = 1; j <= i; j++) {
            printf("%c ", ch++);
        }
        ch -= 2;
        for (int j = 1; j < i; j++) {
            printf("%c ", ch--);
        }
        printf("\n");
    }
}

void crossPattern(int n, char symbol) {
    printf("\n=== Cross Pattern ===\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n/2 || j == n/2 || i == j || i + j == n - 1) {
                printf("%c ", symbol);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void starBurst(int n) {
    printf("\n=== Star Burst Pattern ===\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n/2 || j == n/2 || i == j || i + j == n - 1 || 
                abs(i - n/2) == abs(j - n/2)) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void showBasicPatterns() {
    int size;
    char symbol;
    
    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter symbol: ");
    scanf(" %c", &symbol);
    
    upperRightTriangle(size, symbol);
    upperLeftTriangle(size, symbol);
    lowerRightTriangle(size, symbol);
    lowerLeftTriangle(size, symbol);
    hollowUpperRightTriangle(size, symbol);
    diamondPattern(size, symbol);
    hollowDiamond(size, symbol);
}

void showAdvancedPatterns() {
    int choice, size;
    char symbol;
    
    printf("\n=== ADVANCED PATTERNS ===\n");
    printf("1. Butterfly Pattern\n");
    printf("2. Spiral Pattern\n");
    printf("3. Pascal's Triangle\n");
    printf("4. Floyd's Triangle\n");
    printf("5. Heart Pattern\n");
    printf("6. Christmas Tree\n");
    printf("7. Wave Pattern\n");
    printf("8. Checkerboard\n");
    printf("9. Number Diamond\n");
    printf("10. Alphabet Pyramid\n");
    printf("11. Cross Pattern\n");
    printf("12. Star Burst\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    switch (choice) {
        case 1:
            printf("Enter symbol: ");
            scanf(" %c", &symbol);
            butterflyPattern(size, symbol);
            break;
        case 2:
            spiralPattern(size);
            break;
        case 3:
            pascalTriangle(size);
            break;
        case 4:
            floydTriangle(size);
            break;
        case 5:
            heartPattern(size);
            break;
        case 6:
            christmasTree(size);
            break;
        case 7:
            wavePattern(size, size * 2);
            break;
        case 8:
            checkerboardPattern(size);
            break;
        case 9:
            numberDiamond(size);
            break;
        case 10:
            alphabetPyramid(size);
            break;
        case 11:
            printf("Enter symbol: ");
            scanf(" %c", &symbol);
            crossPattern(size, symbol);
            break;
        case 12:
            starBurst(size);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\n======= ADVANCED PATTERN GENERATOR =======\n");
        printf("1. Basic Triangle Patterns\n");
        printf("2. Advanced Patterns\n");
        printf("3. Custom Pattern Creator\n");
        printf("4. Pattern Animation\n");
        printf("5. Export Pattern to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                showBasicPatterns();
                break;
            case 2:
                showAdvancedPatterns();
                break;
            case 3:
                printf("Custom Pattern Creator - Feature coming soon!\n");
                break;
            case 4:
                printf("Pattern Animation - Feature coming soon!\n");
                break;
            case 5:
                printf("Export to File - Feature coming soon!\n");
                break;
            case 6:
                printf("Thank you for using Advanced Pattern Generator!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
}