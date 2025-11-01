/*
 * Advanced Factorial Calculator & Analyzer v2.0
 * Features: Multiple algorithms, approximations, series,
 *           permutations, combinations, and special functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_FACT 20

// Function prototypes
unsigned long long factorialIterative(int n);
unsigned long long factorialRecursive(int n);
double factorialApprox(int n);
double stirlingApproximation(int n);
void printFactorialTable(int n);
unsigned long long permutation(int n, int r);
unsigned long long combination(int n, int r);
unsigned long long derangement(int n);
double subfactorial(int n);
void factorialPrimeFactors(int n);
bool isFactorialNumber(unsigned long long num);
void findFactorialNumbers(int limit);
double doubleFactorial(int n);
void factorialDigitSum(int n);
void compareAlgorithms(int n);
void factorialSeries(int terms);
void catalanNumber(int n);
void bellNumber(int n);
void partitionFunction(int n);
void displayMenu();

// Main function
int main() {
    int choice, n, r;
    unsigned long long num;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║      Advanced Factorial Calculator & Analyzer v2.0         ║\n");
    printf("║         Comprehensive Combinatorial Mathematics            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-18): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n--- Iterative Factorial ---\n");
                printf("Enter a number (0-20): ");
                scanf("%d", &n);
                if(n >= 0 && n <= 20)
                    printf("%d! = %llu\n", n, factorialIterative(n));
                else
                    printf("Number out of range!\n");
                break;
                
            case 2:
                printf("\n--- Recursive Factorial ---\n");
                printf("Enter a number (0-20): ");
                scanf("%d", &n);
                if(n >= 0 && n <= 20)
                    printf("%d! = %llu\n", n, factorialRecursive(n));
                else
                    printf("Number out of range!\n");
                break;
                
            case 3:
                printf("\n--- Stirling's Approximation ---\n");
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Stirling approximation: %.2f\n", stirlingApproximation(n));
                if(n <= 20)
                    printf("Exact factorial:        %llu\n", factorialIterative(n));
                break;
                
            case 4:
                printf("\n--- Factorial Table ---\n");
                printf("Enter maximum n: ");
                scanf("%d", &n);
                printFactorialTable(n);
                break;
                
            case 5:
                printf("\n--- Permutation P(n,r) ---\n");
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Enter r: ");
                scanf("%d", &r);
                if(n >= r && r >= 0)
                    printf("P(%d,%d) = %llu\n", n, r, permutation(n, r));
                else
                    printf("Invalid input!\n");
                break;
                
            case 6:
                printf("\n--- Combination C(n,r) ---\n");
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Enter r: ");
                scanf("%d", &r);
                if(n >= r && r >= 0)
                    printf("C(%d,%d) = %llu\n", n, r, combination(n, r));
                else
                    printf("Invalid input!\n");
                break;
                
            case 7:
                printf("\n--- Derangement (!n) ---\n");
                printf("Enter n: ");
                scanf("%d", &n);
                printf("!%d = %llu\n", n, derangement(n));
                break;
                
            case 8:
                printf("\n--- Double Factorial (n!!) ---\n");
                printf("Enter n: ");
                scanf("%d", &n);
                printf("%d!! = %.0f\n", n, doubleFactorial(n));
                break;
                
            case 9:
                printf("\n--- Factorial Prime Factorization ---\n");
                printf("Enter n: ");
                scanf("%d", &n);
                factorialPrimeFactors(n);
                break;
                
            case 10:
                printf("\n--- Check Factorial Number ---\n");
                printf("Enter a number: ");
                scanf("%llu", &num);
                if(isFactorialNumber(num))
                    printf("%llu is a factorial number! ✓\n", num);
                else
                    printf("%llu is not a factorial number.\n", num);
                break;
                
            case 11:
                printf("\n--- Find Factorial Numbers ---\n");
                printf("Enter limit: ");
                scanf("%d", &n);
                findFactorialNumbers(n);
                break;
                
            case 12:
                printf("\n--- Factorial Digit Sum ---\n");
                printf("Enter n: ");
                scanf("%d", &n);
                factorialDigitSum(n);
                break;
                
            case 13:
                printf("\n--- Algorithm Comparison ---\n");
                printf("Enter n: ");
                scanf("%d", &n);
                compareAlgorithms(n);
                break;
                
            case 14:
                printf("\n--- Factorial Series Sum ---\n");
                printf("Enter number of terms: ");
                scanf("%d", &n);
                factorialSeries(n);
                break;
                
            case 15:
                printf("\n--- Catalan Number ---\n");
                printf("Enter n: ");
                scanf("%d", &n);
                catalanNumber(n);
                break;
                
            case 16:
                printf("\n--- Bell Number ---\n");
                printf("Enter n (0-15): ");
                scanf("%d", &n);
                if(n >= 0 && n <= 15)
                    bellNumber(n);
                else
                    printf("Number out of range!\n");
                break;
                
            case 17:
                printf("\n--- Partition Function ---\n");
                printf("Enter n: ");
                scanf("%d", &n);
                partitionFunction(n);
                break;
                
            case 18: {
                printf("\n--- Factorial Statistics ---\n");
                printf("Enter n (0-20): ");
                scanf("%d", &n);
                if(n >= 0 && n <= 20) {
                    unsigned long long fact = factorialIterative(n);
                    printf("\n═══════════════════════════════════════\n");
                    printf("FACTORIAL STATISTICS FOR %d!\n", n);
                    printf("═══════════════════════════════════════\n");
                    printf("Exact value:          %llu\n", fact);
                    printf("Stirling approx:      %.2f\n", stirlingApproximation(n));
                    printf("Number of digits:     %d\n", (int)log10(fact) + 1);
                    printf("Permutations P(n,n):  %llu\n", fact);
                    printf("Combinations C(n,0):  1\n");
                    printf("Derangements:         %llu\n", derangement(n));
                    printf("═══════════════════════════════════════\n");
                }
                break;
            }
                
            case 0:
                printf("\n✓ Thank you for using Factorial Calculator!\n");
                break;
                
            default:
                printf("\n✗ Invalid choice! Please try again.\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    return 0;
}

// Display menu
void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC FACTORIAL                                        │\n");
    printf("│  [1]  Iterative Factorial                               │\n");
    printf("│  [2]  Recursive Factorial                               │\n");
    printf("│  [3]  Stirling's Approximation                          │\n");
    printf("│  [4]  Factorial Table (0 to n)                          │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  COMBINATORICS                                          │\n");
    printf("│  [5]  Permutation P(n,r) = n!/(n-r)!                    │\n");
    printf("│  [6]  Combination C(n,r) = n!/(r!(n-r)!)                │\n");
    printf("│  [7]  Derangement (!n)                                  │\n");
    printf("│  [8]  Double Factorial (n!!)                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ANALYSIS                                               │\n");
    printf("│  [9]  Prime Factorization of n!                         │\n");
    printf("│  [10] Check if Number is Factorial                      │\n");
    printf("│  [11] Find All Factorial Numbers                        │\n");
    printf("│  [12] Factorial Digit Sum                               │\n");
    printf("│  [13] Algorithm Performance Comparison                  │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL FUNCTIONS                                      │\n");
    printf("│  [14] Factorial Series (1! + 2! + ... + n!)            │\n");
    printf("│  [15] Catalan Numbers                                   │\n");
    printf("│  [16] Bell Numbers                                      │\n");
    printf("│  [17] Partition Function                                │\n");
    printf("│  [18] Factorial Statistics                              │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit Program                                      │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

// Iterative factorial
unsigned long long factorialIterative(int n) {
    unsigned long long result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Recursive factorial
unsigned long long factorialRecursive(int n) {
    if(n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

// Stirling's approximation
double stirlingApproximation(int n) {
    if(n == 0) return 1;
    return sqrt(2 * M_PI * n) * pow(n / M_E, n);
}

// Print factorial table
void printFactorialTable(int n) {
    if(n > 20) n = 20;
    printf("\n═══════════════════════════════════\n");
    printf("    FACTORIAL TABLE\n");
    printf("═══════════════════════════════════\n");
    printf("  n  |       n!\n");
    printf("───────────────────────────────────\n");
    for(int i = 0; i <= n; i++) {
        printf(" %2d  | %20llu\n", i, factorialIterative(i));
    }
    printf("═══════════════════════════════════\n");
}

// Permutation
unsigned long long permutation(int n, int r) {
    if(r > n) return 0;
    unsigned long long result = 1;
    for(int i = n; i > n - r; i--) {
        result *= i;
    }
    return result;
}

// Combination
unsigned long long combination(int n, int r) {
    if(r > n) return 0;
    if(r > n - r) r = n - r;  // Optimization
    unsigned long long result = 1;
    for(int i = 0; i < r; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

// Derangement
unsigned long long derangement(int n) {
    if(n == 0) return 1;
    if(n == 1) return 0;
    unsigned long long d[n + 1];
    d[0] = 1;
    d[1] = 0;
    for(int i = 2; i <= n; i++) {
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
    }
    return d[n];
}

// Double factorial
double doubleFactorial(int n) {
    double result = 1;
    for(int i = n; i > 0; i -= 2) {
        result *= i;
    }
    return result;
}

// Prime factorization of n!
void factorialPrimeFactors(int n) {
    printf("\nPrime factorization of %d!:\n", n);
    printf("─────────────────────────────\n");
    
    // Count power of each prime in n!
    for(int p = 2; p <= n; p++) {
        bool isPrime = true;
        for(int i = 2; i * i <= p; i++) {
            if(p % i == 0) {
                isPrime = false;
                break;
            }
        }
        
        if(isPrime) {
            int power = 0;
            int pk = p;
            while(pk <= n) {
                power += n / pk;
                pk *= p;
            }
            printf("%d^%d ", p, power);
        }
    }
    printf("\n");
}

// Check if factorial number
bool isFactorialNumber(unsigned long long num) {
    unsigned long long fact = 1;
    int i = 1;
    while(fact < num) {
        i++;
        fact *= i;
    }
    return fact == num;
}

// Find factorial numbers
void findFactorialNumbers(int limit) {
    printf("\nFactorial numbers up to %d:\n", limit);
    printf("──────────────────────────────\n");
    
    unsigned long long fact = 1;
    int n = 0;
    
    while(fact <= limit) {
        printf("%d! = %llu\n", n, fact);
        n++;
        fact *= n;
    }
}

// Factorial digit sum
void factorialDigitSum(int n) {
    if(n > 20) {
        printf("Number too large for exact calculation!\n");
        return;
    }
    
    unsigned long long fact = factorialIterative(n);
    int sum = 0;
    unsigned long long temp = fact;
    
    while(temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    
    printf("\n%d! = %llu\n", n, fact);
    printf("Sum of digits = %d\n", sum);
}

// Compare algorithms
void compareAlgorithms(int n) {
    if(n > 20) {
        printf("Number too large!\n");
        return;
    }
    
    clock_t start, end;
    double time_taken;
    
    printf("\n═══════════════════════════════════════════\n");
    printf("  ALGORITHM PERFORMANCE COMPARISON\n");
    printf("═══════════════════════════════════════════\n");
    
    // Iterative
    start = clock();
    for(int i = 0; i < 1000000; i++) {
        factorialIterative(n);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Iterative:  %.4f ms (1M iterations)\n", time_taken);
    
    // Recursive
    start = clock();
    for(int i = 0; i < 1000000; i++) {
        factorialRecursive(n);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Recursive:  %.4f ms (1M iterations)\n", time_taken);
    
    printf("\nResult: %d! = %llu\n", n, factorialIterative(n));
}

// Factorial series
void factorialSeries(int terms) {
    printf("\nFactorial Series: 1! + 2! + 3! + ... + %d!\n", terms);
    printf("─────────────────────────────────────────────\n");
    
    unsigned long long sum = 0;
    for(int i = 1; i <= terms && i <= 20; i++) {
        unsigned long long fact = factorialIterative(i);
        sum += fact;
        printf("%d! = %llu (sum = %llu)\n", i, fact, sum);
    }
    
    printf("\nTotal sum = %llu\n", sum);
}

// Catalan number
void catalanNumber(int n) {
    if(n > 10) {
        printf("Number too large!\n");
        return;
    }
    
    unsigned long long catalan = combination(2 * n, n) / (n + 1);
    printf("\nCatalan number C(%d) = %llu\n", n, catalan);
    printf("\nApplications:\n");
    printf("- Number of valid parentheses combinations\n");
    printf("- Number of binary search trees with n nodes\n");
    printf("- Number of ways to triangulate a polygon\n");
}

// Bell number
void bellNumber(int n) {
    unsigned long long bell[n + 1][n + 1];
    bell[0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        bell[i][0] = bell[i - 1][i - 1];
        for(int j = 1; j <= i; j++) {
            bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
        }
    }
    
    printf("\nBell number B(%d) = %llu\n", n, bell[n][0]);
    printf("(Number of partitions of a set of %d elements)\n", n);
}

// Partition function
void partitionFunction(int n) {
    int p[n + 1];
    p[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        p[i] = 0;
        for(int j = 1; j <= i; j++) {
            p[i] += p[i - j];
        }
    }
    
    printf("\nPartition P(%d) = %d\n", n, p[n]);
    printf("(Number of ways to partition %d)\n", n);
}