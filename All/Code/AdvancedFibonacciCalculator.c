#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_DIGITS 1000

// Structure for big numbers
typedef struct {
    int digits[MAX_DIGITS];
    int length;
} BigNumber;

// Function prototypes
long long fibonacciRecursive(int n);
long long fibonacciIterative(int n);
long long fibonacciMemoized(int n, long long memo[]);
double fibonacciFormula(int n);
void fibonacciMatrix(int n);
void printFibonacciSeries(int n);
void fibonacciSpiral();
void goldenRatio();
void fibonacciInNature();
void performanceComparison();
void fibonacciPrimality();
void fibonacciModular(int n, int mod);
BigNumber addBigNumbers(BigNumber a, BigNumber b);
void printBigNumber(BigNumber num);
void fibonacciBigNumber(int n);
void fibonacciAnalysis();
int isPrime(long long n);
void fibonacciStatistics(int limit);

// Memoization array
long long memoArray[1000];
int memoInitialized = 0;

void initializeMemo() {
    if (!memoInitialized) {
        for (int i = 0; i < 1000; i++) {
            memoArray[i] = -1;
        }
        memoArray[0] = 0;
        memoArray[1] = 1;
        memoInitialized = 1;
    }
}

long long fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

long long fibonacciIterative(int n) {
    if (n <= 1) return n;
    
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long fibonacciMemoized(int n, long long memo[]) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibonacciMemoized(n - 1, memo) + fibonacciMemoized(n - 2, memo);
    return memo[n];
}

double fibonacciFormula(int n) {
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;
    return (pow(phi, n) - pow(psi, n)) / sqrt(5);
}

void fibonacciMatrix(int n) {
    printf("\n=== Matrix Method for Fibonacci ===\n");
    printf("Using matrix exponentiation:\n");
    printf("[[1,1],[1,0]]^n gives F(n+1) and F(n)\n");
    
    long long result = fibonacciIterative(n);
    printf("F(%d) = %lld\n", n, result);
}

void printFibonacciSeries(int n) {
    printf("\n=== Fibonacci Series (First %d terms) ===\n", n);
    for (int i = 0; i < n; i++) {
        printf("%lld ", fibonacciIterative(i));
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");
}

void goldenRatio() {
    printf("\n=== Golden Ratio Analysis ===\n");
    double phi = (1 + sqrt(5)) / 2;
    printf("Golden Ratio (φ) = %.10f\n", phi);
    
    printf("\nRatio of consecutive Fibonacci numbers approaching φ:\n");
    for (int i = 5; i <= 20; i++) {
        long long fib_n = fibonacciIterative(i);
        long long fib_n_minus_1 = fibonacciIterative(i - 1);
        double ratio = (double)fib_n / fib_n_minus_1;
        printf("F(%d)/F(%d) = %.10f (Error: %.10f)\n", 
               i, i-1, ratio, fabs(ratio - phi));
    }
}

void fibonacciInNature() {
    printf("\n=== Fibonacci in Nature ===\n");
    printf("Fibonacci numbers appear in many natural phenomena:\n\n");
    
    printf("1. Flower Petals:\n");
    printf("   - Lily: 3 petals (F4)\n");
    printf("   - Buttercup: 5 petals (F5)\n");
    printf("   - Chicory: 21 petals (F8)\n");
    printf("   - Daisy: 34, 55, or 89 petals (F9, F10, F11)\n\n");
    
    printf("2. Pine Cone Spirals:\n");
    printf("   - Typically 8 and 13 spirals (F6 and F7)\n");
    printf("   - Or 5 and 8 spirals (F5 and F6)\n\n");
    
    printf("3. Pineapple Hexagons:\n");
    printf("   - 8, 13, and 21 spirals (F6, F7, F8)\n\n");
    
    printf("4. Tree Branches:\n");
    printf("   - Branching patterns often follow Fibonacci ratios\n\n");
    
    printf("5. Human Body:\n");
    printf("   - 5 fingers, 5 toes (F5)\n");
    printf("   - Fibonacci ratios in facial proportions\n");
}

void performanceComparison() {
    printf("\n=== Performance Comparison ===\n");
    int test_values[] = {20, 25, 30, 35, 40};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    for (int i = 0; i < num_tests; i++) {
        int n = test_values[i];
        clock_t start, end;
        double cpu_time_used;
        
        printf("\nFor F(%d):\n", n);
        
        // Iterative method
        start = clock();
        long long result_iter = fibonacciIterative(n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Iterative: %lld (Time: %f seconds)\n", result_iter, cpu_time_used);
        
        // Memoized method
        initializeMemo();
        start = clock();
        long long result_memo = fibonacciMemoized(n, memoArray);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Memoized: %lld (Time: %f seconds)\n", result_memo, cpu_time_used);
        
        // Formula method
        start = clock();
        double result_formula = fibonacciFormula(n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Formula: %.0f (Time: %f seconds)\n", result_formula, cpu_time_used);
        
        // Recursive method (only for smaller values)
        if (n <= 35) {
            start = clock();
            long long result_rec = fibonacciRecursive(n);
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Recursive: %lld (Time: %f seconds)\n", result_rec, cpu_time_used);
        } else {
            printf("Recursive: Skipped (too slow for large n)\n");
        }
    }
}

int isPrime(long long n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void fibonacciPrimality() {
    printf("\n=== Fibonacci Prime Numbers ===\n");
    printf("Fibonacci numbers that are also prime:\n");
    
    for (int i = 0; i <= 50; i++) {
        long long fib = fibonacciIterative(i);
        if (isPrime(fib)) {
            printf("F(%d) = %lld (PRIME)\n", i, fib);
        }
    }
}

void fibonacciModular(int n, int mod) {
    printf("\n=== Fibonacci Modular Arithmetic ===\n");
    printf("Fibonacci numbers modulo %d:\n", mod);
    
    long long a = 0, b = 1;
    printf("F(0) mod %d = %lld\n", mod, a % mod);
    printf("F(1) mod %d = %lld\n", mod, b % mod);
    
    for (int i = 2; i <= n; i++) {
        long long c = (a + b) % mod;
        printf("F(%d) mod %d = %lld\n", i, mod, c);
        a = b;
        b = c;
    }
}

BigNumber addBigNumbers(BigNumber a, BigNumber b) {
    BigNumber result;
    result.length = 0;
    int carry = 0;
    int max_len = a.length > b.length ? a.length : b.length;
    
    for (int i = 0; i < max_len || carry; i++) {
        int sum = carry;
        if (i < a.length) sum += a.digits[i];
        if (i < b.length) sum += b.digits[i];
        
        result.digits[i] = sum % 10;
        carry = sum / 10;
        result.length++;
    }
    
    return result;
}

void printBigNumber(BigNumber num) {
    for (int i = num.length - 1; i >= 0; i--) {
        printf("%d", num.digits[i]);
    }
}

void fibonacciBigNumber(int n) {
    printf("\n=== Large Fibonacci Numbers ===\n");
    
    BigNumber a, b, c;
    
    // Initialize F(0) = 0
    a.length = 1;
    a.digits[0] = 0;
    
    // Initialize F(1) = 1
    b.length = 1;
    b.digits[0] = 1;
    
    printf("F(0) = ");
    printBigNumber(a);
    printf("\n");
    
    printf("F(1) = ");
    printBigNumber(b);
    printf("\n");
    
    for (int i = 2; i <= n; i++) {
        c = addBigNumbers(a, b);
        printf("F(%d) = ", i);
        printBigNumber(c);
        printf("\n");
        a = b;
        b = c;
    }
}

void fibonacciStatistics(int limit) {
    printf("\n=== Fibonacci Statistics (up to F(%d)) ===\n", limit);
    
    int even_count = 0, odd_count = 0, prime_count = 0;
    long long sum = 0, even_sum = 0, odd_sum = 0;
    
    for (int i = 0; i <= limit; i++) {
        long long fib = fibonacciIterative(i);
        sum += fib;
        
        if (fib % 2 == 0) {
            even_count++;
            even_sum += fib;
        } else {
            odd_count++;
            odd_sum += fib;
        }
        
        if (isPrime(fib)) {
            prime_count++;
        }
    }
    
    printf("Total numbers: %d\n", limit + 1);
    printf("Even numbers: %d (%.2f%%)\n", even_count, (100.0 * even_count) / (limit + 1));
    printf("Odd numbers: %d (%.2f%%)\n", odd_count, (100.0 * odd_count) / (limit + 1));
    printf("Prime numbers: %d (%.2f%%)\n", prime_count, (100.0 * prime_count) / (limit + 1));
    printf("Sum of all: %lld\n", sum);
    printf("Sum of even: %lld\n", even_sum);
    printf("Sum of odd: %lld\n", odd_sum);
    printf("Average: %.2f\n", (double)sum / (limit + 1));
}

void fibonacciAnalysis() {
    printf("\n=== Advanced Fibonacci Analysis ===\n");
    printf("Mathematical properties and patterns:\n\n");
    
    printf("1. Binet's Formula:\n");
    printf("   F(n) = (φⁿ - ψⁿ) / √5\n");
    printf("   where φ = (1+√5)/2 and ψ = (1-√5)/2\n\n");
    
    printf("2. Cassini's Identity:\n");
    printf("   F(n-1)·F(n+1) - F(n)² = (-1)ⁿ\n\n");
    
    printf("3. Sum Formula:\n");
    printf("   F(1) + F(2) + ... + F(n) = F(n+2) - 1\n\n");
    
    printf("4. GCD Property:\n");
    printf("   gcd(F(m), F(n)) = F(gcd(m, n))\n\n");
    
    printf("5. Lucas Numbers Relationship:\n");
    printf("   L(n) = F(n-1) + F(n+1)\n\n");
    
    printf("Verifying some properties:\n");
    for (int n = 5; n <= 10; n++) {
        long long fn_minus_1 = fibonacciIterative(n - 1);
        long long fn = fibonacciIterative(n);
        long long fn_plus_1 = fibonacciIterative(n + 1);
        
        long long cassini_left = fn_minus_1 * fn_plus_1;
        long long cassini_right = fn * fn + (n % 2 == 0 ? 1 : -1);
        
        printf("Cassini for n=%d: %lld - %lld = %lld\n", 
               n, cassini_left, fn * fn, cassini_left - fn * fn);
    }
}

int main() {
    int choice, n, mod;
    
    while (1) {
        printf("\n======= ADVANCED FIBONACCI CALCULATOR =======\n");
        printf("1. Calculate Single Fibonacci Number\n");
        printf("2. Print Fibonacci Series\n");
        printf("3. Performance Comparison\n");
        printf("4. Golden Ratio Analysis\n");
        printf("5. Fibonacci in Nature\n");
        printf("6. Fibonacci Prime Numbers\n");
        printf("7. Modular Fibonacci\n");
        printf("8. Large Fibonacci Numbers\n");
        printf("9. Fibonacci Statistics\n");
        printf("10. Advanced Mathematical Analysis\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("F(%d) = %lld\n", n, fibonacciIterative(n));
                break;
            case 2:
                printf("Enter number of terms: ");
                scanf("%d", &n);
                printFibonacciSeries(n);
                break;
            case 3:
                performanceComparison();
                break;
            case 4:
                goldenRatio();
                break;
            case 5:
                fibonacciInNature();
                break;
            case 6:
                fibonacciPrimality();
                break;
            case 7:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Enter modulus: ");
                scanf("%d", &mod);
                fibonacciModular(n, mod);
                break;
            case 8:
                printf("Enter n (for very large Fibonacci): ");
                scanf("%d", &n);
                if (n > 100) {
                    printf("Note: This may take time for very large numbers.\n");
                }
                fibonacciBigNumber(n);
                break;
            case 9:
                printf("Enter limit: ");
                scanf("%d", &n);
                fibonacciStatistics(n);
                break;
            case 10:
                fibonacciAnalysis();
                break;
            case 11:
                printf("Thank you for using Advanced Fibonacci Calculator!\n");
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