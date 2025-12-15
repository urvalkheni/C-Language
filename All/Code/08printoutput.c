/*
 * Advanced Number Pattern Generator v2.1
 * Features: Numeric patterns, sequences, visualizations,
 *           custom number arrangements, and mathematical designs
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void incrementingTriangle();
void numberPyramid();
void pascalTriangle();
void numberDiamond();
void squareNumbersPattern();
void fibonacciPattern();
void primePattern();
void evenOddPattern();
void multiplicationTable();
void numberSpiral();
void floydTriangle();
void hollowNumberSquare();
void diagonalPattern();
void zigzagNumbers();
void customIncrement();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║      Advanced Number Pattern Generator v2.1               ║\n");
    printf("║         Comprehensive Numeric Pattern System               ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                incrementingTriangle();
                break;
            case 2:
                numberPyramid();
                break;
            case 3:
                pascalTriangle();
                break;
            case 4:
                numberDiamond();
                break;
            case 5:
                squareNumbersPattern();
                break;
            case 6:
                fibonacciPattern();
                break;
            case 7:
                primePattern();
                break;
            case 8:
                evenOddPattern();
                break;
            case 9:
                multiplicationTable();
                break;
            case 10:
                numberSpiral();
                break;
            case 11:
                floydTriangle();
                break;
            case 12:
                hollowNumberSquare();
                break;
            case 13:
                diagonalPattern();
                break;
            case 14:
                zigzagNumbers();
                break;
            case 15:
                customIncrement();
                break;
            case 16:
                printf("\n--- Pattern Types ---\n");
                printf("\n• Incrementing: Sequential numbering\n");
                printf("• Floyd: Continuous number fill\n");
                printf("• Pascal: Binomial coefficients\n");
                printf("• Spiral: Circular arrangement\n");
                printf("• Prime: Only prime numbers\n");
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Number Pattern Generator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC PATTERNS                                         │\n");
    printf("│  [1]  Incrementing Triangle                             │\n");
    printf("│  [2]  Number Pyramid                                    │\n");
    printf("│  [3]  Pascal Triangle                                   │\n");
    printf("│  [4]  Number Diamond                                    │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SEQUENCE PATTERNS                                      │\n");
    printf("│  [5]  Square Numbers Pattern                            │\n");
    printf("│  [6]  Fibonacci Pattern                                 │\n");
    printf("│  [7]  Prime Pattern                                     │\n");
    printf("│  [8]  Even-Odd Pattern                                  │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED PATTERNS                                      │\n");
    printf("│  [9]  Multiplication Table                              │\n");
    printf("│  [10] Number Spiral                                     │\n");
    printf("│  [11] Floyd Triangle                                    │\n");
    printf("│  [12] Hollow Number Square                              │\n");
    printf("│  [13] Diagonal Pattern                                  │\n");
    printf("│  [14] Zigzag Numbers                                    │\n");
    printf("│  [15] Custom Increment Pattern                          │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Pattern Types Reference                           │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void incrementingTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Incrementing Triangle ---\n\n");
    
    int a = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", a);
            a++;
        }
        printf("\n");
    }
}

void numberPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Number Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= 2 * i - 1; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
}

void pascalTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Pascal Triangle ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            printf("  ");
        }
        
        int val = 1;
        for(int j = 0; j <= i; j++) {
            printf("%4d ", val);
            val = val * (i - j) / (j + 1);
        }
        printf("\n");
    }
}

void numberDiamond() {
    int n;
    printf("\nEnter size (odd number): ");
    scanf("%d", &n);
    
    printf("\n--- Number Diamond ---\n\n");
    
    int mid = n / 2 + 1;
    
    for(int i = 1; i <= n; i++) {
        if(i <= mid) {
            for(int j = 1; j <= mid - i; j++)
                printf("  ");
            for(int k = 1; k <= i; k++)
                printf("%d ", k);
        } else {
            for(int j = 1; j <= i - mid; j++)
                printf("  ");
            for(int k = 1; k <= n - i + 1; k++)
                printf("%d ", k);
        }
        printf("\n");
    }
}

void squareNumbersPattern() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Square Numbers Pattern ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", j * j);
        }
        printf("\n");
    }
}

void fibonacciPattern() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Fibonacci Pattern ---\n\n");
    
    long long a = 0, b = 1;
    
    for(int i = 1; i <= n; i++) {
        a = 0; b = 1;
        for(int j = 1; j <= i; j++) {
            printf("%lld ", a);
            long long next = a + b;
            a = b;
            b = next;
        }
        printf("\n");
    }
}

void primePattern() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Prime Pattern ---\n\n");
    
    int num = 2, count;
    
    for(int i = 1; i <= n; i++) {
        count = 0;
        while(count < i) {
            bool isPrime = true;
            for(int j = 2; j * j <= num; j++) {
                if(num % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) {
                printf("%d ", num);
                count++;
            }
            num++;
        }
        printf("\n");
    }
}

void evenOddPattern() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Even-Odd Pattern ---\n\n");
    
    printf("Even numbers:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", 2 * ((i - 1) * i / 2 + j));
        }
        printf("\n");
    }
    
    printf("\nOdd numbers:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", 2 * ((i - 1) * i / 2 + j) - 1);
        }
        printf("\n");
    }
}

void multiplicationTable() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Multiplication Table ---\n\n");
    
    printf("    ");
    for(int i = 1; i <= n; i++) {
        printf("%4d", i);
    }
    printf("\n");
    printf("    ");
    for(int i = 1; i <= n; i++) {
        printf("----");
    }
    printf("\n");
    
    for(int i = 1; i <= n; i++) {
        printf("%2d |", i);
        for(int j = 1; j <= n; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
}

void numberSpiral() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);

    if(n <= 0 || n > 20) {
        printf("Size must be between 1 and 20 to fit the buffer.\n");
        return;
    }
    
    int matrix[20][20] = {0};
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;
    
    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;
        
        for(int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;
        
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }
        
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    
    printf("\n--- Number Spiral ---\n\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void floydTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Floyd Triangle ---\n\n");
    
    int num = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
}

void hollowNumberSquare() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Hollow Number Square ---\n\n");
    
    int num = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || i == n || j == 1 || j == n) {
                printf("%3d ", num);
                num++;
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
}

void diagonalPattern() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Diagonal Pattern ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || i + j == n + 1) {
                printf("%d ", i);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void zigzagNumbers() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    
    printf("\n--- Zigzag Numbers ---\n\n");
    
    int num = 1;
    for(int i = 0; i < rows; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < cols; j++) {
                printf("%3d ", num);
                num++;
            }
        } else {
            int temp[100];
            for(int j = 0; j < cols; j++) {
                temp[j] = num;
                num++;
            }
            for(int j = cols - 1; j >= 0; j--) {
                printf("%3d ", temp[j]);
            }
        }
        printf("\n");
    }
}

void customIncrement() {
    int n, start, step;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    printf("Enter starting number: ");
    scanf("%d", &start);
    printf("Enter increment step: ");
    scanf("%d", &step);
    
    printf("\n--- Custom Increment Pattern ---\n\n");
    
    int num = start;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", num);
            num += step;
        }
        printf("\n");
    }
}
}