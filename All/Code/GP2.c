/*
 * Advanced Progression & Series Calculator v2.1
 * Modified: 2025-11-15
 * Features: GP, AP, HP, special series,
 *           convergence analysis, sum calculations
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void geometricProgression();
void arithmeticProgression();
void harmonicProgression();
void gpWithSum();
void apWithSum();
void infiniteGPSum();
void fibonacciSeries();
void squaresSeries();
void cubesSeries();
void primeSeries();
void factorialSeries();
void seriesComparison();
void customSeries();
void seriesAnalysis();
void geometricMean();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║   Advanced Progression & Series Calculator v2.0           ║\n");
    printf("║        Professional Mathematical Series System            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: geometricProgression(); break;
            case 2: arithmeticProgression(); break;
            case 3: harmonicProgression(); break;
            case 4: gpWithSum(); break;
            case 5: apWithSum(); break;
            case 6: infiniteGPSum(); break;
            case 7: fibonacciSeries(); break;
            case 8: squaresSeries(); break;
            case 9: cubesSeries(); break;
            case 10: primeSeries(); break;
            case 11: factorialSeries(); break;
            case 12: seriesComparison(); break;
            case 13: customSeries(); break;
            case 14: seriesAnalysis(); break;
            case 15: geometricMean(); break;
            case 16:
                printf("\n--- Series Calculator Info ---\n");
                printf("• GP: a, ar, ar², ar³...\n");
                printf("• AP: a, a+d, a+2d...\n");
                printf("• HP: 1/a, 1/(a+d), 1/(a+2d)...\n");
                printf("• Various special series\n");
                break;
            case 0: break;
            default: printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Series Calculator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC PROGRESSIONS                                     │\n");
    printf("│  [1]  Geometric Progression (GP)                        │\n");
    printf("│  [2]  Arithmetic Progression (AP)                       │\n");
    printf("│  [3]  Harmonic Progression (HP)                         │\n");
    printf("│  [4]  GP with Sum                                       │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SUM CALCULATIONS                                       │\n");
    printf("│  [5]  AP with Sum                                       │\n");
    printf("│  [6]  Infinite GP Sum                                   │\n");
    printf("│  [7]  Fibonacci Series                                  │\n");
    printf("│  [8]  Squares Series                                    │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL SERIES                                         │\n");
    printf("│  [9]  Cubes Series                                      │\n");
    printf("│  [10] Prime Number Series                               │\n");
    printf("│  [11] Factorial Series                                  │\n");
    printf("│  [12] Series Comparison                                 │\n");
    printf("│  [13] Custom Series Generator                           │\n");
    printf("│  [14] Series Analysis                                   │\n");
    printf("│  [15] Geometric Mean                                    │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Series Calculator Info                            │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void geometricProgression() {
    int i, n;
    
    printf("\nEnter The term Number :: ");
    scanf("%d", &n);
    if(n <= 0) {
        printf("Invalid number of terms (must be > 0).\n");
        return;
    }
    if(n > 100) {
        printf("Limiting terms to 100 to avoid overflow/display issues.\n");
        n = 100;
    }

    printf("\n--- Geometric Progression (3, 12, 48...) ---\n\n");
    
    int a = 3;
    for(i = 1; i <= n; i++) {
        printf("%d ", a);
        /* guard against overflow for large n */
        if(a > INT_MAX / 4) break;
        a *= 4;
    }
    printf("\n");
}

void arithmeticProgression() {
    int a, d, n;
    printf("\nEnter first term: ");
    scanf("%d", &a);
    printf("Enter common difference: ");
    scanf("%d", &d);
    printf("Enter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Arithmetic Progression ---\n\n");
    
    for(int i = 0; i < n; i++) {
        printf("%d ", a + i * d);
    }
    printf("\n\nNth term = %d\n", a + (n - 1) * d);
}

void harmonicProgression() {
    int a, d, n;
    printf("\nEnter first term: ");
    scanf("%d", &a);
    printf("Enter common difference: ");
    scanf("%d", &d);
    printf("Enter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Harmonic Progression ---\n\n");
    
    for(int i = 0; i < n; i++) {
        printf("1/%d ", a + i * d);
    }
    printf("\n\nDecimal values:\n");
    for(int i = 0; i < n; i++) {
        printf("%.4f ", 1.0 / (a + i * d));
    }
    printf("\n");
}

void gpWithSum() {
    double a, r;
    int n;
    printf("\nEnter first term: ");
    scanf("%lf", &a);
    printf("Enter common ratio: ");
    scanf("%lf", &r);
    printf("Enter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- GP with Sum ---\n\n");
    
    double sum = 0;
    double term = a;
    
    for(int i = 0; i < n; i++) {
        printf("%.2f ", term);
        sum += term;
        term *= r;
    }
    
    printf("\n\nSum = %.2f\n", sum);
    
    if(r != 1) {
        double formulaSum = a * (pow(r, n) - 1) / (r - 1);
        printf("Sum (formula) = %.2f\n", formulaSum);
    }
}

void apWithSum() {
    int a, d, n;
    printf("\nEnter first term: ");
    scanf("%d", &a);
    printf("Enter common difference: ");
    scanf("%d", &d);
    printf("Enter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- AP with Sum ---\n\n");
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int term = a + i * d;
        printf("%d ", term);
        sum += term;
    }
    
    printf("\n\nSum = %d\n", sum);
    printf("Sum (formula) = %d\n", n * (2 * a + (n - 1) * d) / 2);
}

void infiniteGPSum() {
    double a, r;
    printf("\nEnter first term: ");
    scanf("%lf", &a);
    printf("Enter common ratio (-1 < r < 1): ");
    scanf("%lf", &r);
    
    printf("\n--- Infinite GP Sum ---\n\n");
    
    if(fabs(r) >= 1) {
        printf("Series diverges (|r| >= 1)\n");
        return;
    }
    
    double sum = a / (1 - r);
    printf("Sum to infinity = %.4f\n", sum);
    
    printf("\nPartial sums:\n");
    double partial = 0, term = a;
    for(int i = 1; i <= 10; i++) {
        partial += term;
        printf("S%d = %.4f\n", i, partial);
        term *= r;
    }
}

void fibonacciSeries() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Fibonacci Series ---\n\n");
    
    long long a = 0, b = 1;
    long long sum = 0;
    
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            printf("%lld ", a);
            sum += a;
        } else if(i == 1) {
            printf("%lld ", b);
            sum += b;
        } else {
            long long next = a + b;
            printf("%lld ", next);
            sum += next;
            a = b;
            b = next;
        }
    }
    printf("\n\nSum = %lld\n", sum);
}

void squaresSeries() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Squares Series (1², 2², 3²...) ---\n\n");
    
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        printf("%d ", i * i);
        sum += i * i;
    }
    
    printf("\n\nSum = %lld\n", sum);
    printf("Sum (formula) = %lld\n", (long long)n * (n + 1) * (2 * n + 1) / 6);
}

void cubesSeries() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Cubes Series (1³, 2³, 3³...) ---\n\n");
    
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        printf("%d ", i * i * i);
        sum += i * i * i;
    }
    
    long long formulaSum = n * n * (n + 1) * (n + 1) / 4;
    printf("\n\nSum = %lld\n", sum);
    printf("Sum (formula) = %lld\n", formulaSum);
}

bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

void primeSeries() {
    int n;
    printf("\nEnter number of primes: ");
    scanf("%d", &n);
    
    printf("\n--- Prime Number Series ---\n\n");
    
    int count = 0, num = 2;
    long long sum = 0;
    
    while(count < n) {
        if(isPrime(num)) {
            printf("%d ", num);
            sum += num;
            count++;
        }
        num++;
    }
    
    printf("\n\nSum = %lld\n", sum);
}

void factorialSeries() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Factorial Series (1!, 2!, 3!...) ---\n\n");
    
    long long factorial = 1;
    long long sum = 0;
    
    for(int i = 1; i <= n; i++) {
        factorial *= i;
        printf("%lld ", factorial);
        sum += factorial;
    }
    
    printf("\n\nSum = %lld\n", sum);
}

void seriesComparison() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Series Comparison ---\n\n");
    
    printf("Term\tNatural\tSquares\tCubes\tPowers of 2\n");
    printf("─────────────────────────────────────────────────\n");
    
    for(int i = 1; i <= n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", 
               i, i, i*i, i*i*i, (int)pow(2, i));
    }
}

void customSeries() {
    int n, choice;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    printf("\n1. Even numbers\n2. Odd numbers\n3. Multiples of a number\n");
    printf("Choose pattern: ");
    scanf("%d", &choice);
    
    printf("\n--- Custom Series ---\n\n");
    
    if(choice == 1) {
        for(int i = 1; i <= n; i++)
            printf("%d ", 2 * i);
    } else if(choice == 2) {
        for(int i = 1; i <= n; i++)
            printf("%d ", 2 * i - 1);
    } else if(choice == 3) {
        int m;
        printf("Enter multiple: ");
        scanf("%d", &m);
        for(int i = 1; i <= n; i++)
            printf("%d ", m * i);
    }
    printf("\n");
}

void seriesAnalysis() {
    double a, r;
    int n;
    printf("\nEnter first term: ");
    scanf("%lf", &a);
    printf("Enter common ratio: ");
    scanf("%lf", &r);
    printf("Enter terms to analyze: ");
    scanf("%d", &n);
    
    printf("\n--- Series Analysis ---\n\n");
    
    if(fabs(r) < 1)
        printf("Series: CONVERGENT\n");
    else if(fabs(r) > 1)
        printf("Series: DIVERGENT\n");
    else
        printf("Series: OSCILLATING\n");
    
    printf("\nFirst %d terms:\n", n);
    double term = a;
    for(int i = 0; i < n; i++) {
        printf("%.2f ", term);
        term *= r;
    }
    printf("\n");
}

void geometricMean() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    double nums[100];
    double product = 1.0;
    
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &nums[i]);
        product *= nums[i];
    }
    
    double gm = pow(product, 1.0 / n);
    
    printf("\n--- Geometric Mean ---\n\n");
    printf("Numbers: ");
    for(int i = 0; i < n; i++)
        printf("%.2f ", nums[i]);
    printf("\n\nGeometric Mean = %.4f\n", gm);
}