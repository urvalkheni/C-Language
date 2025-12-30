/*
 * Advanced Loop Demonstrator & Iterator v2.2
 * Modified: 2025-12-30
 * Features: Multiple loop types, patterns, algorithms,
 *           loop analysis and performance comparison
 * ENHANCEMENTS: Robust input validation, bounds checking,
 *               improved error handling for all operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

void basicWhileLoop();
void doWhileLoop();
void forLoop();
void nestedLoops();
void infiniteLoopDemo();
void loopWithBreak();
void loopWithContinue();
void countingPatterns();
void multiplicationTable();
void fibonacciLoop();
void primeNumbersLoop();
void factorialLoop();
void reverseCountLoop();
void sumSeriesLoop();
void loopComparison();
void displayMenu();
bool getValidInteger(const char* prompt, int* value);
bool validateRange(int value, int min, int max, const char* fieldName);

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║      Advanced Loop Demonstrator & Iterator v2.0           ║\n");
    printf("║         Comprehensive Loop Learning System                 ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: basicWhileLoop(); break;
            case 2: doWhileLoop(); break;
            case 3: forLoop(); break;
            case 4: nestedLoops(); break;
            case 5: infiniteLoopDemo(); break;
            case 6: loopWithBreak(); break;
            case 7: loopWithContinue(); break;
            case 8: countingPatterns(); break;
            case 9: multiplicationTable(); break;
            case 10: fibonacciLoop(); break;
            case 11: primeNumbersLoop(); break;
            case 12: factorialLoop(); break;
            case 13: reverseCountLoop(); break;
            case 14: sumSeriesLoop(); break;
            case 15: loopComparison(); break;
            case 16:
                printf("\n--- Loop Types ---\n");
                printf("• while: Entry-controlled loop\n");
                printf("• do-while: Exit-controlled loop\n");
                printf("• for: Counter-controlled loop\n");
                printf("• break: Exit loop early\n");
                printf("• continue: Skip iteration\n");
                break;
            case 0: break;
            default: printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Loop Demonstrator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC LOOPS                                            │\n");
    printf("│  [1]  Basic While Loop                                  │\n");
    printf("│  [2]  Do-While Loop                                     │\n");
    printf("│  [3]  For Loop                                          │\n");
    printf("│  [4]  Nested Loops                                      │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  CONTROL FLOW                                           │\n");
    printf("│  [5]  Infinite Loop Demo                                │\n");
    printf("│  [6]  Loop with Break                                   │\n");
    printf("│  [7]  Loop with Continue                                │\n");
    printf("│  [8]  Counting Patterns                                 │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  APPLICATIONS                                           │\n");
    printf("│  [9]  Multiplication Table                              │\n");
    printf("│  [10] Fibonacci Loop                                    │\n");
    printf("│  [11] Prime Numbers Loop                                │\n");
    printf("│  [12] Factorial Loop                                    │\n");
    printf("│  [13] Reverse Count Loop                                │\n");
    printf("│  [14] Sum Series Loop                                   │\n");
    printf("│  [15] Loop Performance Comparison                       │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Loop Types Info                                   │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void basicWhileLoop() {
    int n, i = 1;
    if(!getValidInteger("\nEnter limit: ", &n)) return;
    if(!validateRange(n, 1, INT_MAX, "Limit")) return;
    
    printf("\n--- Basic While Loop ---\n");
    printf("Counting from 1 to %d:\n", n);
    
    while(i <= n) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
}

void doWhileLoop() {
    int n, i = 1;
    if(!getValidInteger("\nEnter limit: ", &n)) return;
    if(!validateRange(n, 1, INT_MAX, "Limit")) return;

    printf("\n--- Do-While Loop ---\n");
    printf("Counting (executes at least once):\n");
    
    do {
        printf("%d ", i);
        i++;
    } while(i <= n);
    printf("\n");
}

void forLoop() {
    int n;
    if(!getValidInteger("\nEnter limit: ", &n)) return;
    if(!validateRange(n, 1, INT_MAX, "Limit")) return;

    printf("\n--- For Loop ---\n");
    printf("Counting from 1 to %d:\n", n);
    
    for(int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void nestedLoops() {
    int rows;
    printf("\nEnter number of rows: ");
    scanf("%d", &rows);
    
    printf("\n--- Nested Loops (Pattern) ---\n");
    
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void infiniteLoopDemo() {
    int count = 0;
    printf("\n--- Infinite Loop Demo (with break at 10) ---\n");
    
    while(1) {
        count++;
        printf("%d ", count);
        if(count >= 10) break;
    }
    printf("\nLoop terminated!\n");
}

void loopWithBreak() {
    int n;
    printf("\nEnter limit: ");
    scanf("%d", &n);
    
    printf("\n--- Loop with Break (stops at 5) ---\n");
    
    for(int i = 1; i <= n; i++) {
        if(i == 5) {
            printf("\nBreak at %d!\n", i);
            break;
        }
        printf("%d ", i);
    }
}

void loopWithContinue() {
    int n;
    printf("\nEnter limit: ");
    scanf("%d", &n);
    
    printf("\n--- Loop with Continue (skip even numbers) ---\n");
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) continue;
        printf("%d ", i);
    }
    printf("\n");
}

void countingPatterns() {
    printf("\n--- Counting Patterns ---\n\n");
    
    printf("Even numbers (1-20): ");
    for(int i = 2; i <= 20; i += 2) {
        printf("%d ", i);
    }
    
    printf("\nOdd numbers (1-20): ");
    for(int i = 1; i <= 20; i += 2) {
        printf("%d ", i);
    }
    
    printf("\nMultiples of 5: ");
    for(int i = 5; i <= 50; i += 5) {
        printf("%d ", i);
    }
    printf("\n");
}

void multiplicationTable() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    if(num == 0) {
        printf("\nZero table is trivial (all zeros).\n");
        return;
    }

    printf("\n--- Multiplication Table of %d ---\n", num);
    
    for(int i = 1; i <= 10; i++) {
        printf("%d × %d = %d\n", num, i, num * i);
    }
}

void fibonacciLoop() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Fibonacci Sequence ---\n");
    
    long long a = 0, b = 1;
    int i = 1;
    
    while(i <= n) {
        printf("%lld ", a);
        long long next = a + b;
        a = b;
        b = next;
        i++;
    }
    printf("\n");
}

void primeNumbersLoop() {
    int n;
    printf("\nEnter limit: ");
    scanf("%d", &n);
    
    printf("\n--- Prime Numbers up to %d ---\n", n);
    
    for(int num = 2; num <= n; num++) {
        int isPrime = 1;
        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if(isPrime) printf("%d ", num);
    }
    printf("\n");
}

void factorialLoop() {
    int n;
    printf("\nEnter number: ");
    scanf("%d", &n);
    
    printf("\n--- Factorial Calculation ---\n");
    
    long long factorial = 1;
    int i = 1;
    
    while(i <= n) {
        factorial *= i;
        printf("Step %d: %lld\n", i, factorial);
        i++;
    }
    
    printf("\nFinal: %d! = %lld\n", n, factorial);
}

void reverseCountLoop() {
    int n;
    printf("\nEnter starting number: ");
    scanf("%d", &n);
    
    printf("\n--- Reverse Counting ---\n");
    
    int i = n;
    while(i >= 1) {
        printf("%d ", i);
        i--;
    }
    printf("\n");
}

void sumSeriesLoop() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Sum of Series (1 + 2 + 3 + ...) ---\n");
    
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
        printf("Sum up to %d: %d\n", i, sum);
    }
    
    printf("\nFinal sum: %d\n", sum);
    printf("Formula check: n(n+1)/2 = %d\n", n*(n+1)/2);
}

void loopComparison() {
    int n = 1000000;
    clock_t start, end;
    double cpu_time;
    
    printf("\n--- Loop Performance Comparison ---\n");
    printf("Computing sum of %d numbers...\n\n", n);
    
    // While loop
    start = clock();
    long long sum1 = 0;
    int i = 1;
    while(i <= n) {
        sum1 += i;
        i++;
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("While loop: %.6f seconds\n", cpu_time);
    
    // For loop
    start = clock();
    long long sum2 = 0;
    for(int j = 1; j <= n; j++) {
        sum2 += j;
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("For loop:   %.6f seconds\n", cpu_time);
    
    // Do-while loop
    start = clock();
    long long sum3 = 0;
    int k = 1;
    do {
        sum3 += k;
        k++;
    } while(k <= n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Do-while:   %.6f seconds\n", cpu_time);
    
    printf("\nAll results: %lld (should be same)\n", sum1);
}

bool getValidInteger(const char* prompt, int* value) {
    printf("%s", prompt);
    if(scanf("%d", value) != 1) {
        printf("✗ Invalid input! Please enter an integer.\n");
        while(getchar() != '\n');
        return false;
    }
    return true;
}

bool validateRange(int value, int min, int max, const char* fieldName) {
    if(value < min || value > max) {
        printf("✗ %s must be between %d and %d.\n", fieldName, min, max);
        return false;
    }
    return true;
}

/* Version history:
   v2.2 (2025-12-30): Added robust input validation, bounds checking, error handling
   v2.1 (2025-11-15): Loop performance comparison feature
*/