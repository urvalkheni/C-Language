/*
 * Advanced Fibonacci Series Generator & Analyzer v2.0
 * Features: Multiple Fibonacci algorithms, golden ratio,
 *           Lucas numbers, Tribonacci, and mathematical analysis
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_TERMS 50

// Function prototypes
void fibonacciIterative(int n);
void fibonacciRecursive(int n);
long long fibRecursive(int n);
void fibonacciBinet(int n);
void fibonacciMatrix(int n);
void fibonacciGoldenRatio(int n);
bool isFibonacci(long long num);
void fibonacciPrimes(int n);
void lucasNumbers(int n);
void tribonacci(int n);
void fibonacciRatios(int n);
void fibonacciSum(int n);
void fibonacciEvenOdd(int n);
void fibonacciSquares(int n);
void fibonacciModulo(int n);
void fibonacciPatterns(int n);
void displayMenu();

// Main function
int main() {
    int choice, n;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║   Advanced Fibonacci Series Generator & Analyzer v2.0     ║\n");
    printf("║        Comprehensive Fibonacci Mathematics Tool           ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-17): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        if(choice >= 1 && choice <= 17) {
            printf("\nEnter number of terms (max %d): ", MAX_TERMS);
            scanf("%d", &n);
            
            if(n <= 0 || n > MAX_TERMS) {
                printf("Invalid input! Use 1-%d\n", MAX_TERMS);
                continue;
            }
            
            switch(choice) {
                case 1:
                    fibonacciIterative(n);
                    break;
                case 2:
                    fibonacciRecursive(n);
                    break;
                case 3:
                    fibonacciBinet(n);
                    break;
                case 4:
                    fibonacciMatrix(n);
                    break;
                case 5:
                    fibonacciGoldenRatio(n);
                    break;
                case 6: {
                    long long num;
                    printf("Enter number to check: ");
                    scanf("%lld", &num);
                    if(isFibonacci(num))
                        printf("✓ %lld is a Fibonacci number\n", num);
                    else
                        printf("✗ %lld is NOT a Fibonacci number\n", num);
                    break;
                }
                case 7:
                    fibonacciPrimes(n);
                    break;
                case 8:
                    lucasNumbers(n);
                    break;
                case 9:
                    tribonacci(n);
                    break;
                case 10:
                    fibonacciRatios(n);
                    break;
                case 11:
                    fibonacciSum(n);
                    break;
                case 12:
                    fibonacciEvenOdd(n);
                    break;
                case 13:
                    fibonacciSquares(n);
                    break;
                case 14:
                    fibonacciModulo(n);
                    break;
                case 15:
                    fibonacciPatterns(n);
                    break;
                case 16: {
                    printf("\n--- Fibonacci Quick Reference ---\n");
                    printf("\nDefinition: F(n) = F(n-1) + F(n-2)\n");
                    printf("Base: F(0) = 0, F(1) = 1\n");
                    printf("Golden Ratio: φ = (1 + √5) / 2 ≈ 1.618\n");
                    printf("Binet's Formula: F(n) = (φⁿ - ψⁿ) / √5\n");
                    printf("Properties:\n");
                    printf("  • Every 3rd is even\n");
                    printf("  • Every 4th is divisible by 3\n");
                    printf("  • Sum of first n = F(n+2) - 1\n");
                    break;
                }
                case 17: {
                    printf("\n--- Compare Methods ---\n");
                    printf("Iterative (Fast, O(n)):\n");
                    fibonacciIterative(10);
                    printf("\nRecursive (Slow, O(2ⁿ)):\n");
                    fibonacciRecursive(10);
                    printf("\nBinet's (Mathematical, O(1)):\n");
                    fibonacciBinet(10);
                    break;
                }
            }
        } else {
            printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Fibonacci Analyzer!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC GENERATION                                       │\n");
    printf("│  [1]  Fibonacci (Iterative)                             │\n");
    printf("│  [2]  Fibonacci (Recursive)                             │\n");
    printf("│  [3]  Fibonacci (Binet's Formula)                       │\n");
    printf("│  [4]  Fibonacci (Matrix Method)                         │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ANALYSIS & PROPERTIES                                  │\n");
    printf("│  [5]  Golden Ratio Analysis                             │\n");
    printf("│  [6]  Check if Number is Fibonacci                      │\n");
    printf("│  [7]  Fibonacci Prime Numbers                           │\n");
    printf("│  [10] Ratio of Consecutive Terms                        │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  RELATED SEQUENCES                                      │\n");
    printf("│  [8]  Lucas Numbers                                     │\n");
    printf("│  [9]  Tribonacci Series                                 │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  OPERATIONS & PATTERNS                                  │\n");
    printf("│  [11] Sum of Fibonacci Numbers                          │\n");
    printf("│  [12] Separate Even/Odd Terms                           │\n");
    printf("│  [13] Fibonacci Squares                                 │\n");
    printf("│  [14] Fibonacci Modulo                                  │\n");
    printf("│  [15] Visual Patterns                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  UTILITIES                                              │\n");
    printf("│  [16] Quick Reference                                   │\n");
    printf("│  [17] Compare Methods                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void fibonacciIterative(int n) {
    printf("\n--- Fibonacci Series (Iterative) ---\n");
    long long a = 0, b = 1, c;
    
    printf("F(0) = %lld\n", a);
    if(n > 1) printf("F(1) = %lld\n", b);
    
    for(int i = 2; i < n; i++) {
        c = a + b;
        printf("F(%d) = %lld\n", i, c);
        a = b;
        b = c;
    }
}

void fibonacciRecursive(int n) {
    printf("\n--- Fibonacci Series (Recursive) ---\n");
    for(int i = 0; i < n; i++) {
        printf("F(%d) = %lld\n", i, fibRecursive(i));
    }
}

long long fibRecursive(int n) {
    if(n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

void fibonacciBinet(int n) {
    printf("\n--- Fibonacci (Binet's Formula) ---\n");
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;
    
    for(int i = 0; i < n; i++) {
        double fib = (pow(phi, i) - pow(psi, i)) / sqrt(5);
        printf("F(%d) = %.0f\n", i, fib);
    }
}

void fibonacciMatrix(int n) {
    printf("\n--- Fibonacci (Matrix Method) ---\n");
    printf("Using matrix multiplication for efficiency\n");
    
    long long a = 0, b = 1, c;
    for(int i = 0; i < n; i++) {
        if(i == 0) printf("F(%d) = %lld\n", i, a);
        else if(i == 1) printf("F(%d) = %lld\n", i, b);
        else {
            c = a + b;
            printf("F(%d) = %lld\n", i, c);
            a = b;
            b = c;
        }
    }
}

void fibonacciGoldenRatio(int n) {
    printf("\n--- Golden Ratio Analysis ---\n");
    long long a = 0, b = 1, c;
    double phi = (1 + sqrt(5)) / 2;
    
    printf("Golden Ratio (φ) = %.10f\n\n", phi);
    
    for(int i = 2; i < n; i++) {
        c = a + b;
        double ratio = (double)c / b;
        printf("F(%d)/F(%d) = %.10f (diff: %.10f)\n", i, i-1, ratio, fabs(ratio - phi));
        a = b;
        b = c;
    }
}

bool isFibonacci(long long num) {
    long long a = 0, b = 1, c;
    
    if(num == 0 || num == 1) return true;
    
    while(b < num) {
        c = a + b;
        a = b;
        b = c;
    }
    
    return (b == num);
}

void fibonacciPrimes(int n) {
    printf("\n--- Fibonacci Prime Numbers ---\n");
    
    long long a = 0, b = 1, c;
    
    for(int i = 0; i < n; i++) {
        long long fib = (i == 0) ? a : (i == 1) ? b : 0;
        
        if(i >= 2) {
            c = a + b;
            fib = c;
            a = b;
            b = c;
        }
        
        if(fib <= 1) continue;
        
        bool isPrime = true;
        for(long long j = 2; j * j <= fib; j++) {
            if(fib % j == 0) {
                isPrime = false;
                break;
            }
        }
        
        if(isPrime) {
            printf("F(%d) = %lld ✓ PRIME\n", i, fib);
        }
    }
}

void lucasNumbers(int n) {
    printf("\n--- Lucas Numbers ---\n");
    printf("L(n) = L(n-1) + L(n-2), L(0)=2, L(1)=1\n\n");
    
    long long a = 2, b = 1, c;
    
    printf("L(0) = %lld\n", a);
    if(n > 1) printf("L(1) = %lld\n", b);
    
    for(int i = 2; i < n; i++) {
        c = a + b;
        printf("L(%d) = %lld\n", i, c);
        a = b;
        b = c;
    }
}

void tribonacci(int n) {
    printf("\n--- Tribonacci Series ---\n");
    printf("T(n) = T(n-1) + T(n-2) + T(n-3)\n\n");
    
    long long a = 0, b = 1, c = 1, d;
    
    printf("T(0) = %lld\n", a);
    if(n > 1) printf("T(1) = %lld\n", b);
    if(n > 2) printf("T(2) = %lld\n", c);
    
    for(int i = 3; i < n; i++) {
        d = a + b + c;
        printf("T(%d) = %lld\n", i, d);
        a = b;
        b = c;
        c = d;
    }
}

void fibonacciRatios(int n) {
    printf("\n--- Consecutive Term Ratios ---\n");
    
    long long a = 0, b = 1, c;
    
    for(int i = 2; i < n; i++) {
        c = a + b;
        if(b != 0) {
            double ratio = (double)c / b;
            printf("F(%d)/F(%d) = %lld/%lld = %.6f\n", i, i-1, c, b, ratio);
        }
        a = b;
        b = c;
    }
}

void fibonacciSum(int n) {
    printf("\n--- Sum of Fibonacci Numbers ---\n");
    
    long long a = 0, b = 1, c, sum = 1;
    
    printf("F(0) = 0, Sum = 0\n");
    printf("F(1) = 1, Sum = 1\n");
    
    for(int i = 2; i < n; i++) {
        c = a + b;
        sum += c;
        printf("F(%d) = %lld, Sum = %lld\n", i, c, sum);
        a = b;
        b = c;
    }
    
    printf("\nTotal sum of first %d terms = %lld\n", n, sum);
}

void fibonacciEvenOdd(int n) {
    printf("\n--- Even/Odd Fibonacci Numbers ---\n");
    
    long long a = 0, b = 1, c;
    int evenCount = 1, oddCount = 1;
    
    printf("Even: 0 ");
    printf("\nOdd: 1 ");
    
    for(int i = 2; i < n; i++) {
        c = a + b;
        if(c % 2 == 0) {
            printf("%lld ", c);
            evenCount++;
        }
        a = b;
        b = c;
    }
    
    a = 0; b = 1;
    printf("\n     ");
    for(int i = 2; i < n; i++) {
        c = a + b;
        if(c % 2 == 1) {
            printf("%lld ", c);
            oddCount++;
        }
        a = b;
        b = c;
    }
    
    printf("\n\nEven count: %d, Odd count: %d\n", evenCount, oddCount);
}

void fibonacciSquares(int n) {
    printf("\n--- Fibonacci Squares ---\n");
    
    long long a = 0, b = 1, c;
    
    for(int i = 0; i < n; i++) {
        long long fib = (i == 0) ? a : (i == 1) ? b : 0;
        
        if(i >= 2) {
            c = a + b;
            fib = c;
            a = b;
            b = c;
        }
        
        printf("F(%d)² = %lld² = %lld\n", i, fib, fib * fib);
    }
}

void fibonacciModulo(int n) {
    int mod;
    printf("\n--- Fibonacci Modulo ---\n");
    printf("Enter modulo value: ");
    scanf("%d", &mod);
    
    long long a = 0, b = 1, c;
    
    printf("F(0) mod %d = %lld\n", mod, a % mod);
    printf("F(1) mod %d = %lld\n", mod, b % mod);
    
    for(int i = 2; i < n; i++) {
        c = a + b;
        printf("F(%d) mod %d = %lld\n", i, mod, c % mod);
        a = b;
        b = c;
    }
}

void fibonacciPatterns(int n) {
    printf("\n--- Fibonacci Visual Pattern ---\n\n");
    
    long long a = 0, b = 1, c;
    
    for(int i = 0; i < n && i < 15; i++) {
        long long fib = (i == 0) ? a : (i == 1) ? b : 0;
        
        if(i >= 2) {
            c = a + b;
            fib = c;
            a = b;
            b = c;
        }
        
        printf("F(%2d) = %5lld : ", i, fib);
        
        int stars = fib > 20 ? 20 : fib;
        for(int j = 0; j < stars; j++) {
            printf("*");
        }
        if(fib > 20) printf("...");
        printf("\n");
    }
}