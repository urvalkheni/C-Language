/*
 * Advanced Number Sequence Generator v2.0
 * Features: Multiple patterns, customizable ranges,
 *           arithmetic/geometric sequences, visualizations
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
void printRange(int start, int end, int step);
void printEvenNumbers(int start, int end);
void printOddNumbers(int start, int end);
void printPrimes(int start, int end);
void printFibonacci(int n);
void printArithmeticSequence(int a, int d, int n);
void printGeometricSequence(int a, int r, int n);
void printSquares(int n);
void printCubes(int n);
void printFactorials(int n);
void printPerfectNumbers(int limit);
void printArmstrong(int start, int end);
void printPalindrome(int start, int end);
void visualizePattern(int n);
void printGrid(int rows, int cols);
bool isPrime(int n);
bool isPerfect(int n);
bool isArmstrong(int n);
bool isPalindrome(int n);
void displayMenu();

// Main function
int main() {
    int choice, start, end, step, n, a, d, r, rows, cols;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║      Advanced Number Sequence Generator v2.0              ║\n");
    printf("║           Patterns, Sequences & Visualizations            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-17): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n--- Print Number Range ---\n");
                printf("Enter start: ");
                scanf("%d", &start);
                printf("Enter end: ");
                scanf("%d", &end);
                printf("Enter step: ");
                scanf("%d", &step);
                printRange(start, end, step);
                break;
                
            case 2:
                printf("\n--- Even Numbers ---\n");
                printf("Enter start: ");
                scanf("%d", &start);
                printf("Enter end: ");
                scanf("%d", &end);
                printEvenNumbers(start, end);
                break;
                
            case 3:
                printf("\n--- Odd Numbers ---\n");
                printf("Enter start: ");
                scanf("%d", &start);
                printf("Enter end: ");
                scanf("%d", &end);
                printOddNumbers(start, end);
                break;
                
            case 4:
                printf("\n--- Prime Numbers ---\n");
                printf("Enter start: ");
                scanf("%d", &start);
                printf("Enter end: ");
                scanf("%d", &end);
                printPrimes(start, end);
                break;
                
            case 5:
                printf("\n--- Fibonacci Sequence ---\n");
                printf("How many terms? ");
                scanf("%d", &n);
                printFibonacci(n);
                break;
                
            case 6:
                printf("\n--- Arithmetic Sequence ---\n");
                printf("Enter first term (a): ");
                scanf("%d", &a);
                printf("Enter common difference (d): ");
                scanf("%d", &d);
                printf("Enter number of terms: ");
                scanf("%d", &n);
                printArithmeticSequence(a, d, n);
                break;
                
            case 7:
                printf("\n--- Geometric Sequence ---\n");
                printf("Enter first term (a): ");
                scanf("%d", &a);
                printf("Enter common ratio (r): ");
                scanf("%d", &r);
                printf("Enter number of terms: ");
                scanf("%d", &n);
                printGeometricSequence(a, r, n);
                break;
                
            case 8:
                printf("\n--- Square Numbers ---\n");
                printf("How many terms? ");
                scanf("%d", &n);
                printSquares(n);
                break;
                
            case 9:
                printf("\n--- Cube Numbers ---\n");
                printf("How many terms? ");
                scanf("%d", &n);
                printCubes(n);
                break;
                
            case 10:
                printf("\n--- Factorial Sequence ---\n");
                printf("How many terms? ");
                scanf("%d", &n);
                printFactorials(n);
                break;
                
            case 11:
                printf("\n--- Perfect Numbers ---\n");
                printf("Enter limit: ");
                scanf("%d", &n);
                printPerfectNumbers(n);
                break;
                
            case 12:
                printf("\n--- Armstrong Numbers ---\n");
                printf("Enter start: ");
                scanf("%d", &start);
                printf("Enter end: ");
                scanf("%d", &end);
                printArmstrong(start, end);
                break;
                
            case 13:
                printf("\n--- Palindrome Numbers ---\n");
                printf("Enter start: ");
                scanf("%d", &start);
                printf("Enter end: ");
                scanf("%d", &end);
                printPalindrome(start, end);
                break;
                
            case 14:
                printf("\n--- Pattern Visualization ---\n");
                printf("Enter size: ");
                scanf("%d", &n);
                visualizePattern(n);
                break;
                
            case 15:
                printf("\n--- Number Grid ---\n");
                printf("Enter rows: ");
                scanf("%d", &rows);
                printf("Enter columns: ");
                scanf("%d", &cols);
                printGrid(rows, cols);
                break;
                
            case 16:
                printf("\n--- Classic: 1 to 100 ---\n");
                printRange(1, 100, 1);
                break;
                
            case 17:
                printf("\n--- Quick Stats (1-100) ---\n");
                int primeCount = 0, evenCount = 0, oddCount = 0;
                for(int i = 1; i <= 100; i++) {
                    if(isPrime(i)) primeCount++;
                    if(i % 2 == 0) evenCount++;
                    else oddCount++;
                }
                printf("Primes: %d\n", primeCount);
                printf("Evens: %d\n", evenCount);
                printf("Odds: %d\n", oddCount);
                printf("Sum: %d\n", (100 * 101) / 2);
                break;
                
            case 0:
                printf("\n✓ Thank you for using Number Generator!\n");
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
    printf("│  BASIC SEQUENCES                                        │\n");
    printf("│  [1]  Custom Range (start, end, step)                   │\n");
    printf("│  [2]  Even Numbers                                      │\n");
    printf("│  [3]  Odd Numbers                                       │\n");
    printf("│  [4]  Prime Numbers                                     │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  MATHEMATICAL SEQUENCES                                 │\n");
    printf("│  [5]  Fibonacci Sequence                                │\n");
    printf("│  [6]  Arithmetic Sequence (a, a+d, a+2d...)             │\n");
    printf("│  [7]  Geometric Sequence (a, ar, ar²...)                │\n");
    printf("│  [8]  Square Numbers (1², 2², 3²...)                    │\n");
    printf("│  [9]  Cube Numbers (1³, 2³, 3³...)                      │\n");
    printf("│  [10] Factorial Sequence (1!, 2!, 3!...)                │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL NUMBERS                                        │\n");
    printf("│  [11] Perfect Numbers                                   │\n");
    printf("│  [12] Armstrong Numbers                                 │\n");
    printf("│  [13] Palindrome Numbers                                │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  VISUALIZATIONS                                         │\n");
    printf("│  [14] Pattern Visualization                             │\n");
    printf("│  [15] Number Grid                                       │\n");
    printf("│  [16] Classic 1 to 100                                  │\n");
    printf("│  [17] Quick Statistics (1-100)                          │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void printRange(int start, int end, int step) {
    int count = 0;
    if(step > 0) {
        for(int i = start; i <= end; i += step) {
            printf("%d ", i);
            count++;
            if(count % 10 == 0) printf("\n");
        }
    } else if(step < 0) {
        for(int i = start; i >= end; i += step) {
            printf("%d ", i);
            count++;
            if(count % 10 == 0) printf("\n");
        }
    }
    printf("\n");
}

void printEvenNumbers(int start, int end) {
    if(start % 2 != 0) start++;
    int count = 0;
    for(int i = start; i <= end; i += 2) {
        printf("%d ", i);
        count++;
        if(count % 10 == 0) printf("\n");
    }
    printf("\n");
}

void printOddNumbers(int start, int end) {
    if(start % 2 == 0) start++;
    int count = 0;
    for(int i = start; i <= end; i += 2) {
        printf("%d ", i);
        count++;
        if(count % 10 == 0) printf("\n");
    }
    printf("\n");
}

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void printPrimes(int start, int end) {
    int count = 0;
    for(int i = start; i <= end; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
            count++;
            if(count % 10 == 0) printf("\n");
        }
    }
    printf("\n");
}

void printFibonacci(int n) {
    long long a = 0, b = 1, next;
    for(int i = 0; i < n; i++) {
        printf("%lld ", a);
        next = a + b;
        a = b;
        b = next;
        if((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");
}

void printArithmeticSequence(int a, int d, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a + i * d);
        if((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");
}

void printGeometricSequence(int a, int r, int n) {
    long long term = a;
    for(int i = 0; i < n; i++) {
        printf("%lld ", term);
        term *= r;
        if((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");
}

void printSquares(int n) {
    for(int i = 1; i <= n; i++) {
        printf("%d² = %d\n", i, i * i);
    }
}

void printCubes(int n) {
    for(int i = 1; i <= n; i++) {
        printf("%d³ = %d\n", i, i * i * i);
    }
}

void printFactorials(int n) {
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
        printf("%d! = %lld\n", i, fact);
    }
}

bool isPerfect(int n) {
    int sum = 1;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            sum += i;
            if(i * i != n) sum += n / i;
        }
    }
    return sum == n && n != 1;
}

void printPerfectNumbers(int limit) {
    for(int i = 2; i <= limit; i++) {
        if(isPerfect(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

bool isArmstrong(int n) {
    int original = n, sum = 0, digits = 0;
    int temp = n;
    while(temp != 0) {
        digits++;
        temp /= 10;
    }
    temp = n;
    while(temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }
    return sum == original;
}

void printArmstrong(int start, int end) {
    for(int i = start; i <= end; i++) {
        if(isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

bool isPalindrome(int n) {
    int original = n, reversed = 0;
    while(n != 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return original == reversed;
}

void printPalindrome(int start, int end) {
    for(int i = start; i <= end; i++) {
        if(isPalindrome(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void visualizePattern(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printGrid(int rows, int cols) {
    int num = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%4d ", num++);
        }
        printf("\n");
    }
}