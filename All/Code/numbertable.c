/*
 * Advanced Number Table & Pattern Generator v2.0
 * Features: Multiple table patterns, visualizations,
 *           custom sequences, and comprehensive number patterns
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
void standardMultiplicationTable(int n, int range);
void additionTable(int n, int range);
void squareTable(int n);
void cubeTable(int n);
void powerTable(int base, int maxPower);
void factorialTable(int n);
void fibonacciTable(int n);
void primeTable(int n);
void numberPyramid(int n);
void numberGrid(int rows, int cols);
void pascalTriangle(int n);
void multiplicationGrid(int size);
void customSequenceTable(int start, int step, int count);
void arithmeticTable(int a, int d, int n);
void geometricTable(int a, int r, int n);
void displayMenu();

int main() {
    int choice, n, range, rows, cols, base, start, step;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║   Advanced Number Table & Pattern Generator v2.0          ║\n");
    printf("║        Comprehensive Mathematical Table System            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &n);
                printf("Enter range (default 10): ");
                scanf("%d", &range);
                standardMultiplicationTable(n, range);
                break;
                
            case 2:
                printf("\nEnter number: ");
                scanf("%d", &n);
                printf("Enter range (default 10): ");
                scanf("%d", &range);
                additionTable(n, range);
                break;
                
            case 3:
                printf("\nEnter limit: ");
                scanf("%d", &n);
                squareTable(n);
                break;
                
            case 4:
                printf("\nEnter limit: ");
                scanf("%d", &n);
                cubeTable(n);
                break;
                
            case 5:
                printf("\nEnter base: ");
                scanf("%d", &base);
                printf("Enter max power: ");
                scanf("%d", &n);
                powerTable(base, n);
                break;
                
            case 6:
                printf("\nEnter limit: ");
                scanf("%d", &n);
                factorialTable(n);
                break;
                
            case 7:
                printf("\nEnter count: ");
                scanf("%d", &n);
                fibonacciTable(n);
                break;
                
            case 8:
                printf("\nEnter count: ");
                scanf("%d", &n);
                primeTable(n);
                break;
                
            case 9:
                printf("\nEnter height: ");
                scanf("%d", &n);
                numberPyramid(n);
                break;
                
            case 10:
                printf("\nEnter rows: ");
                scanf("%d", &rows);
                printf("Enter columns: ");
                scanf("%d", &cols);
                numberGrid(rows, cols);
                break;
                
            case 11:
                printf("\nEnter rows: ");
                scanf("%d", &n);
                pascalTriangle(n);
                break;
                
            case 12:
                printf("\nEnter size: ");
                scanf("%d", &n);
                multiplicationGrid(n);
                break;
                
            case 13:
                printf("\nEnter starting number: ");
                scanf("%d", &start);
                printf("Enter step: ");
                scanf("%d", &step);
                printf("Enter count: ");
                scanf("%d", &n);
                customSequenceTable(start, step, n);
                break;
                
            case 14:
                printf("\nEnter first term (a): ");
                scanf("%d", &n);
                printf("Enter common difference (d): ");
                scanf("%d", &range);
                printf("Enter count: ");
                scanf("%d", &base);
                arithmeticTable(n, range, base);
                break;
                
            case 15:
                printf("\nEnter first term (a): ");
                scanf("%d", &n);
                printf("Enter common ratio (r): ");
                scanf("%d", &range);
                printf("Enter count: ");
                scanf("%d", &base);
                geometricTable(n, range, base);
                break;
                
            case 16:
                printf("\n--- Quick Reference ---\n");
                printf("\nTable Types:\n");
                printf("• Multiplication: n × i format\n");
                printf("• Addition: n + i format\n");
                printf("• Power: base^i format\n");
                printf("• Factorial: n! values\n");
                printf("• Arithmetic: a, a+d, a+2d, ...\n");
                printf("• Geometric: a, ar, ar², ...\n");
                break;
                
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Table Generator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC TABLES                                           │\n");
    printf("│  [1]  Multiplication Table                              │\n");
    printf("│  [2]  Addition Table                                    │\n");
    printf("│  [3]  Square Table                                      │\n");
    printf("│  [4]  Cube Table                                        │\n");
    printf("│  [5]  Power Table                                       │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SEQUENCE TABLES                                        │\n");
    printf("│  [6]  Factorial Table                                   │\n");
    printf("│  [7]  Fibonacci Table                                   │\n");
    printf("│  [8]  Prime Number Table                                │\n");
    printf("│  [13] Custom Sequence Table                             │\n");
    printf("│  [14] Arithmetic Progression Table                      │\n");
    printf("│  [15] Geometric Progression Table                       │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  PATTERNS & GRIDS                                       │\n");
    printf("│  [9]  Number Pyramid                                    │\n");
    printf("│  [10] Number Grid                                       │\n");
    printf("│  [11] Pascal's Triangle                                 │\n");
    printf("│  [12] Multiplication Grid                               │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Quick Reference                                   │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void standardMultiplicationTable(int n, int range) {
    printf("\n--- Multiplication Table of %d ---\n\n", n);
    for(int i = 1; i <= range; i++) {
        printf("%4d × %2d = %5d\n", n, i, n * i);
    }
}

void additionTable(int n, int range) {
    printf("\n--- Addition Table of %d ---\n\n", n);
    for(int i = 1; i <= range; i++) {
        printf("%4d + %2d = %5d\n", n, i, n + i);
    }
}

void squareTable(int n) {
    printf("\n--- Square Table (1 to %d) ---\n\n", n);
    printf("  Number  |  Square\n");
    printf("----------+----------\n");
    for(int i = 1; i <= n; i++) {
        printf("%6d    |  %6d\n", i, i * i);
    }
}

void cubeTable(int n) {
    printf("\n--- Cube Table (1 to %d) ---\n\n", n);
    printf("  Number  |   Cube\n");
    printf("----------+----------\n");
    for(int i = 1; i <= n; i++) {
        printf("%6d    |  %6d\n", i, i * i * i);
    }
}

void powerTable(int base, int maxPower) {
    printf("\n--- Power Table: %d^n ---\n\n", base);
    printf("  Power   |   Result\n");
    printf("----------+-------------\n");
    
    long long result = 1;
    for(int i = 0; i <= maxPower; i++) {
        printf("%4d^%-2d   |  %10lld\n", base, i, result);
        result *= base;
    }
}

void factorialTable(int n) {
    printf("\n--- Factorial Table (1! to %d!) ---\n\n", n);
    printf("    n     |     n!\n");
    printf("----------+-------------\n");
    
    long long factorial = 1;
    for(int i = 1; i <= n; i++) {
        factorial *= i;
        printf("%6d    |  %10lld\n", i, factorial);
        if(factorial < 0) {
            printf("\n(Overflow detected at %d!)\n", i);
            break;
        }
    }
}

void fibonacciTable(int n) {
    printf("\n--- Fibonacci Table (First %d numbers) ---\n\n", n);
    printf("  Index   |  Fibonacci\n");
    printf("----------+-------------\n");
    
    long long a = 0, b = 1;
    for(int i = 1; i <= n; i++) {
        printf("%6d    |  %10lld\n", i, a);
        long long temp = a + b;
        a = b;
        b = temp;
    }
}

bool isPrime(int num) {
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

void primeTable(int n) {
    printf("\n--- Prime Number Table (First %d primes) ---\n\n", n);
    printf("  Index   |   Prime\n");
    printf("----------+----------\n");
    
    int count = 0, num = 2;
    while(count < n) {
        if(isPrime(num)) {
            count++;
            printf("%6d    |  %6d\n", count, num);
        }
        num++;
    }
}

void numberPyramid(int n) {
    printf("\n--- Number Pyramid (Height: %d) ---\n\n", n);
    
    for(int i = 1; i <= n; i++) {
        // Print spaces
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        // Print numbers
        for(int j = 1; j <= i; j++) {
            printf("%3d ", j);
        }
        printf("\n");
    }
}

void numberGrid(int rows, int cols) {
    printf("\n--- Number Grid (%d × %d) ---\n\n", rows, cols);
    
    int num = 1;
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= cols; j++) {
            printf("%4d ", num++);
        }
        printf("\n");
    }
}

void pascalTriangle(int n) {
    printf("\n--- Pascal's Triangle (Rows: %d) ---\n\n", n);
    
    for(int i = 0; i < n; i++) {
        // Print spaces
        for(int j = 0; j < n - i - 1; j++) {
            printf("   ");
        }
        
        int val = 1;
        for(int j = 0; j <= i; j++) {
            printf("%5d ", val);
            val = val * (i - j) / (j + 1);
        }
        printf("\n");
    }
}

void multiplicationGrid(int size) {
    printf("\n--- Multiplication Grid (%d × %d) ---\n\n", size, size);
    
    // Print header
    printf("    × |");
    for(int i = 1; i <= size; i++) {
        printf("%4d", i);
    }
    printf("\n");
    
    printf("------+");
    for(int i = 1; i <= size; i++) {
        printf("----");
    }
    printf("\n");
    
    // Print table
    for(int i = 1; i <= size; i++) {
        printf("%5d |", i);
        for(int j = 1; j <= size; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
}

void customSequenceTable(int start, int step, int count) {
    printf("\n--- Custom Sequence Table ---\n");
    printf("Start: %d, Step: %d, Count: %d\n\n", start, step, count);
    printf("  Index   |   Value\n");
    printf("----------+----------\n");
    
    for(int i = 1; i <= count; i++) {
        printf("%6d    |  %6d\n", i, start);
        start += step;
    }
}

void arithmeticTable(int a, int d, int n) {
    printf("\n--- Arithmetic Progression Table ---\n");
    printf("First term (a): %d, Common difference (d): %d\n\n", a, d);
    printf("  Index   |   Term   |   Sum\n");
    printf("----------+----------+----------\n");
    
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        int term = a + (i - 1) * d;
        sum += term;
        printf("%6d    |  %6d  |  %6d\n", i, term, sum);
    }
}

void geometricTable(int a, int r, int n) {
    printf("\n--- Geometric Progression Table ---\n");
    printf("First term (a): %d, Common ratio (r): %d\n\n", a, r);
    printf("  Index   |   Term\n");
    printf("----------+-------------\n");
    
    long long term = a;
    for(int i = 1; i <= n; i++) {
        printf("%6d    |  %10lld\n", i, term);
        term *= r;
    }
}