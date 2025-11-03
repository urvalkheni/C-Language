/*
 * Advanced Number Comparison & Analysis Tool v2.0
 * Features: Comparison operations, mathematical analysis,
 *           relationship testing, and comprehensive number operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
void basicComparison(int a, int b);
void findMaxMin(int a, int b);
void arithmeticOperations(int a, int b);
void compareAbsoluteValues(int a, int b);
void divisibilityCheck(int a, int b);
void gcdLcm(int a, int b);
void digitComparison(int a, int b);
void evenOddComparison(int a, int b);
void primeComparison(int a, int b);
void perfectSquareCheck(int a, int b);
void rangeCheck(int a, int b, int x);
void betweenCheck(int a, int b);
void distanceCalculation(int a, int b);
void ratioComparison(int a, int b);
void percentageComparison(int a, int b);
void displayMenu();
bool isPrime(int n);
int countDigits(int n);
int gcd(int a, int b);

int main() {
    int choice, a, b, x;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║   Advanced Number Comparison & Analysis Tool v2.0         ║\n");
    printf("║        Comprehensive Number Operations System             ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        if(choice >= 1 && choice <= 15) {
            printf("\nEnter first number: ");
            scanf("%d", &a);
            printf("Enter second number: ");
            scanf("%d", &b);
            
            if(choice == 11) {
                printf("Enter number to check: ");
                scanf("%d", &x);
            }
        }
        
        switch(choice) {
            case 1:
                basicComparison(a, b);
                break;
            case 2:
                findMaxMin(a, b);
                break;
            case 3:
                arithmeticOperations(a, b);
                break;
            case 4:
                compareAbsoluteValues(a, b);
                break;
            case 5:
                divisibilityCheck(a, b);
                break;
            case 6:
                gcdLcm(a, b);
                break;
            case 7:
                digitComparison(a, b);
                break;
            case 8:
                evenOddComparison(a, b);
                break;
            case 9:
                primeComparison(a, b);
                break;
            case 10:
                perfectSquareCheck(a, b);
                break;
            case 11:
                rangeCheck(a, b, x);
                break;
            case 12:
                betweenCheck(a, b);
                break;
            case 13:
                distanceCalculation(a, b);
                break;
            case 14:
                ratioComparison(a, b);
                break;
            case 15:
                percentageComparison(a, b);
                break;
            case 16:
                printf("\n--- Quick Reference ---\n");
                printf("\nComparison Operators:\n");
                printf("• Greater: a > b\n");
                printf("• Less: a < b\n");
                printf("• Equal: a == b\n");
                printf("• GCD: Greatest Common Divisor\n");
                printf("• LCM: Least Common Multiple\n");
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Number Comparison Tool!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC COMPARISON                                       │\n");
    printf("│  [1]  Basic Comparison (>, <, ==)                       │\n");
    printf("│  [2]  Find Maximum/Minimum                              │\n");
    printf("│  [3]  Arithmetic Operations                             │\n");
    printf("│  [4]  Compare Absolute Values                           │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  MATHEMATICAL ANALYSIS                                  │\n");
    printf("│  [5]  Divisibility Check                                │\n");
    printf("│  [6]  GCD & LCM                                         │\n");
    printf("│  [7]  Digit Comparison                                  │\n");
    printf("│  [13] Distance Calculation                              │\n");
    printf("│  [14] Ratio Comparison                                  │\n");
    printf("│  [15] Percentage Comparison                             │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  PROPERTIES                                             │\n");
    printf("│  [8]  Even/Odd Comparison                               │\n");
    printf("│  [9]  Prime Number Comparison                           │\n");
    printf("│  [10] Perfect Square Check                              │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  RANGE & POSITION                                       │\n");
    printf("│  [11] Range Check (x between a & b)                     │\n");
    printf("│  [12] Find Numbers Between a & b                        │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Quick Reference                                   │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void basicComparison(int a, int b) {
    printf("\n--- Basic Comparison ---\n");
    printf("First number:  %d\n", a);
    printf("Second number: %d\n\n", b);
    
    if(a > b) {
        printf("Result: %d is GREATER than %d\n", a, b);
        printf("Difference: %d\n", a - b);
    } else if(a < b) {
        printf("Result: %d is LESS than %d\n", a, b);
        printf("Difference: %d\n", b - a);
    } else {
        printf("Result: %d is EQUAL to %d\n", a, b);
    }
}

void findMaxMin(int a, int b) {
    printf("\n--- Maximum/Minimum ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    printf("Maximum: %d\n", (a > b) ? a : b);
    printf("Minimum: %d\n", (a < b) ? a : b);
    printf("Range: %d\n", abs(a - b));
}

void arithmeticOperations(int a, int b) {
    printf("\n--- Arithmetic Operations ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    printf("Sum:        %d + %d = %d\n", a, b, a + b);
    printf("Difference: %d - %d = %d\n", a, b, a - b);
    printf("Product:    %d × %d = %d\n", a, b, a * b);
    
    if(b != 0) {
        printf("Division:   %d ÷ %d = %.2f\n", a, b, (float)a / b);
        printf("Modulo:     %d %% %d = %d\n", a, b, a % b);
    } else {
        printf("Division:   Cannot divide by zero\n");
    }
    
    printf("Average:    (%.2f)\n", (a + b) / 2.0);
}

void compareAbsoluteValues(int a, int b) {
    printf("\n--- Absolute Value Comparison ---\n");
    printf("Numbers: %d, %d\n", a, b);
    printf("Absolute values: |%d| = %d, |%d| = %d\n\n", a, abs(a), b, abs(b));
    
    if(abs(a) > abs(b)) {
        printf("|%d| is GREATER than |%d|\n", a, b);
    } else if(abs(a) < abs(b)) {
        printf("|%d| is LESS than |%d|\n", a, b);
    } else {
        printf("|%d| is EQUAL to |%d|\n", a, b);
    }
}

void divisibilityCheck(int a, int b) {
    printf("\n--- Divisibility Check ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    
    if(b != 0 && a % b == 0) {
        printf("%d is divisible by %d\n", a, b);
        printf("Quotient: %d\n", a / b);
    } else if(b != 0) {
        printf("%d is NOT divisible by %d\n", a, b);
        printf("Remainder: %d\n", a % b);
    }
    
    if(a != 0 && b % a == 0) {
        printf("%d is divisible by %d\n", b, a);
        printf("Quotient: %d\n", b / a);
    } else if(a != 0) {
        printf("%d is NOT divisible by %d\n", b, a);
        printf("Remainder: %d\n", b % a);
    }
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void gcdLcm(int a, int b) {
    printf("\n--- GCD & LCM ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    
    int g = gcd(a, b);
    printf("GCD (Greatest Common Divisor): %d\n", g);
    
    if(g != 0) {
        long long lcm = (long long)abs(a) * abs(b) / g;
        printf("LCM (Least Common Multiple):  %lld\n", lcm);
    }
}

int countDigits(int n) {
    if(n == 0) return 1;
    int count = 0;
    n = abs(n);
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

void digitComparison(int a, int b) {
    printf("\n--- Digit Comparison ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    
    int digitsA = countDigits(a);
    int digitsB = countDigits(b);
    
    printf("Digits in %d: %d\n", a, digitsA);
    printf("Digits in %d: %d\n\n", b, digitsB);
    
    if(digitsA > digitsB) {
        printf("%d has MORE digits\n", a);
    } else if(digitsA < digitsB) {
        printf("%d has MORE digits\n", b);
    } else {
        printf("Both have SAME number of digits\n");
    }
}

void evenOddComparison(int a, int b) {
    printf("\n--- Even/Odd Comparison ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    
    printf("%d is %s\n", a, (a % 2 == 0) ? "EVEN" : "ODD");
    printf("%d is %s\n\n", b, (b % 2 == 0) ? "EVEN" : "ODD");
    
    if((a % 2 == 0) && (b % 2 == 0)) {
        printf("Both are EVEN numbers\n");
    } else if((a % 2 != 0) && (b % 2 != 0)) {
        printf("Both are ODD numbers\n");
    } else {
        printf("One is EVEN, one is ODD\n");
    }
}

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void primeComparison(int a, int b) {
    printf("\n--- Prime Number Comparison ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    
    bool primeA = isPrime(abs(a));
    bool primeB = isPrime(abs(b));
    
    printf("%d is %s\n", a, primeA ? "PRIME" : "NOT PRIME");
    printf("%d is %s\n\n", b, primeB ? "PRIME" : "NOT PRIME");
    
    if(primeA && primeB) {
        printf("Both are PRIME numbers\n");
    } else if(!primeA && !primeB) {
        printf("Neither is PRIME\n");
    } else {
        printf("One is PRIME, one is NOT\n");
    }
}

void perfectSquareCheck(int a, int b) {
    printf("\n--- Perfect Square Check ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    
    int sqrtA = (int)sqrt(abs(a));
    int sqrtB = (int)sqrt(abs(b));
    
    bool isPerfectA = (sqrtA * sqrtA == abs(a));
    bool isPerfectB = (sqrtB * sqrtB == abs(b));
    
    printf("%d is %s (√%d = %d)\n", a, 
           isPerfectA ? "a PERFECT SQUARE" : "NOT a perfect square", 
           abs(a), sqrtA);
    printf("%d is %s (√%d = %d)\n\n", b, 
           isPerfectB ? "a PERFECT SQUARE" : "NOT a perfect square", 
           abs(b), sqrtB);
    
    if(isPerfectA && isPerfectB) {
        printf("Both are PERFECT SQUARES\n");
    }
}

void rangeCheck(int a, int b, int x) {
    printf("\n--- Range Check ---\n");
    printf("Range: [%d, %d]\n", (a < b) ? a : b, (a > b) ? a : b);
    printf("Number to check: %d\n\n", x);
    
    int min = (a < b) ? a : b;
    int max = (a > b) ? a : b;
    
    if(x >= min && x <= max) {
        printf("%d is WITHIN range [%d, %d]\n", x, min, max);
    } else {
        printf("%d is OUTSIDE range [%d, %d]\n", x, min, max);
    }
}

void betweenCheck(int a, int b) {
    printf("\n--- Numbers Between %d and %d ---\n\n", a, b);
    
    int min = (a < b) ? a : b;
    int max = (a > b) ? a : b;
    
    int count = max - min - 1;
    
    if(count > 0) {
        printf("Count: %d numbers\n", count);
        if(count <= 50) {
            printf("Numbers: ");
            for(int i = min + 1; i < max; i++) {
                printf("%d ", i);
            }
            printf("\n");
        } else {
            printf("(Too many to display)\n");
        }
    } else {
        printf("No numbers between them\n");
    }
}

void distanceCalculation(int a, int b) {
    printf("\n--- Distance Calculation ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    
    int distance = abs(a - b);
    printf("Absolute distance: |%d - %d| = %d\n", a, b, distance);
    printf("Midpoint: %.1f\n", (a + b) / 2.0);
}

void ratioComparison(int a, int b) {
    printf("\n--- Ratio Comparison ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    
    if(b != 0) {
        printf("Ratio a:b = %d:%d\n", a, b);
        printf("Decimal: %.4f\n", (float)a / b);
        
        int g = gcd(a, b);
        printf("Simplified: %d:%d\n", a / g, b / g);
    }
}

void percentageComparison(int a, int b) {
    printf("\n--- Percentage Comparison ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    
    if(b != 0) {
        printf("%d is %.2f%% of %d\n", a, (a * 100.0) / b, b);
    }
    if(a != 0) {
        printf("%d is %.2f%% of %d\n", b, (b * 100.0) / a, a);
    }
    
    if(a != 0 && b != 0) {
        float diff = abs(a - b);
        printf("\nDifference: %.2f%% (relative to %d)\n", 
               (diff * 100.0) / ((a > b) ? a : b), (a > b) ? a : b);
    }
}    