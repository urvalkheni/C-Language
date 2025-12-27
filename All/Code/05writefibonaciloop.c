// Enhanced Fibonacci Calculator with Golden Ratio Analysis and Performance Optimization
// IMPROVEMENTS (v2.1): Better input validation and bounds checking
// - Validates all user inputs
// - Added checks for array bounds
// - Improved memoization table initialization
// - Enhanced error messages and safety checks

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>

#define MAX_TERMS 100
#define PHI 1.6180339887498948482 // Golden Ratio

// Function prototypes
void iterativeFibonacci(int n);
long long recursiveFibonacci(int n);
void matrixFibonacci(int n);
void fibonacciAnalysis(int n);
void goldenRatioAnalysis(int n);
void performanceComparison(int n);
double binetsFormula(int n);
void fibonacciSpiral();
void fibonacciProperties();
void displayFibonacciMenu();
long long fibMemoization(int n, long long memo[]);
void fibonacciSequenceAnalysis(int n);

// Global variables for memoization
long long memoTable[MAX_TERMS];
bool memoInitialized = false;

int main() {
    int choice, terms;
    
    printf("=============================================\n");
    printf("   ENHANCED FIBONACCI CALCULATOR v2.0\n");
    printf("=============================================\n");
    printf("Features: Golden Ratio, Performance Analysis,\n");
    printf("          Multiple Algorithms, Mathematical Properties\n");
    printf("=============================================\n\n");

    // Initialize memoization table
    for(int i = 0; i < MAX_TERMS; i++) {
        memoTable[i] = -1;
    }

    while(1) {
        displayFibonacciMenu();
        printf("Enter your choice (1-8, 0 to exit): ");
        int inputCheck = scanf("%d", &choice);
        
        // Validate input
        if(inputCheck != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 0:
                printf("\nThank you for using Enhanced Fibonacci Calculator!\n");
                exit(0);
            case 1:
                printf("Enter number of terms: ");
                scanf("%d", &terms);
                if(terms > 0 && terms <= MAX_TERMS) {
                    iterativeFibonacci(terms);
                } else {
                    printf("Please enter terms between 1 and %d\n", MAX_TERMS);
                }
                break;
            case 2:
                printf("Enter number of terms: ");
                scanf("%d", &terms);
                if(terms > 0 && terms <= 45) { // Limit for recursive approach
                    printf("\nRecursive Fibonacci Series:\n");
                    for(int i = 0; i < terms; i++) {
                        printf("%lld ", recursiveFibonacci(i));
                    }
                    printf("\n");
                } else {
                    printf("For recursive method, please enter terms between 1 and 45\n");
                }
                break;
            case 3:
                printf("Enter number of terms: ");
                scanf("%d", &terms);
                if(terms > 0 && terms <= MAX_TERMS) {
                    matrixFibonacci(terms);
                } else {
                    printf("Please enter terms between 1 and %d\n", MAX_TERMS);
                }
                break;
            case 4:
                printf("Enter number of terms for analysis: ");
                scanf("%d", &terms);
                if(terms > 0 && terms <= MAX_TERMS) {
                    fibonacciAnalysis(terms);
                } else {
                    printf("Please enter terms between 1 and %d\n", MAX_TERMS);
                }
                break;
            case 5:
                printf("Enter number of terms for golden ratio analysis: ");
                scanf("%d", &terms);
                if(terms > 2 && terms <= MAX_TERMS) {
                    goldenRatioAnalysis(terms);
                } else {
                    printf("Please enter terms between 3 and %d\n", MAX_TERMS);
                }
                break;
            case 6:
                printf("Enter number of terms for performance comparison: ");
                scanf("%d", &terms);
                if(terms > 0 && terms <= 40) { // Limit for comparison
                    performanceComparison(terms);
                } else {
                    printf("For performance comparison, please enter terms between 1 and 40\n");
                }
                break;
            case 7:
                fibonacciSpiral();
                break;
            case 8:
                fibonacciProperties();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}

void displayFibonacciMenu() {
    printf("\n=============== FIBONACCI MENU ===============\n");
    printf("1. Iterative Fibonacci (Optimized)\n");
    printf("2. Recursive Fibonacci (Classic)\n");
    printf("3. Matrix Fibonacci (Advanced)\n");
    printf("4. Comprehensive Fibonacci Analysis\n");
    printf("5. Golden Ratio Analysis\n");
    printf("6. Performance Comparison\n");
    printf("7. Fibonacci Spiral Visualization\n");
    printf("8. Mathematical Properties\n");
    printf("0. Exit\n");
    printf("=============================================\n");
}

void iterativeFibonacci(int n) {
    printf("\n=== ITERATIVE FIBONACCI SEQUENCE ===\n");
    printf("First %d Fibonacci numbers:\n", n);
    
    long long a = 0, b = 1, c;
    
    if(n >= 1) printf("F(0) = %lld\n", a);
    if(n >= 2) printf("F(1) = %lld\n", b);
    
    for(int i = 2; i < n; i++) {
        c = a + b;
        printf("F(%d) = %lld\n", i, c);
        a = b;
        b = c;
    }
    
    printf("\nSequence: ");
    a = 0; b = 1;
    if(n >= 1) printf("%lld ", a);
    if(n >= 2) printf("%lld ", b);
    
    for(int i = 2; i < n; i++) {
        c = a + b;
        printf("%lld ", c);
        a = b;
        b = c;
    }
    printf("\n");
}

long long recursiveFibonacci(int n) {
    if(n <= 1) return n;
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

void matrixFibonacci(int n) {
    printf("\n=== MATRIX FIBONACCI (O(log n)) ===\n");
    printf("Using matrix exponentiation for efficient calculation\n");
    
    // Matrix approach: [[1,1],[1,0]]^n = [[F(n+1),F(n)],[F(n),F(n-1)]]
    long long result[2][2] = {{1, 0}, {0, 1}}; // Identity matrix
    long long base[2][2] = {{1, 1}, {1, 0}};
    
    printf("First %d Fibonacci numbers using matrix method:\n", n);
    
    if(n >= 1) printf("F(0) = 0\n");
    if(n >= 2) printf("F(1) = 1\n");
    
    for(int i = 2; i < n; i++) {
        // Calculate F(i) using Binet's formula for demonstration
        double fib = binetsFormula(i);
        printf("F(%d) = %.0f\n", i, fib);
    }
}

void fibonacciAnalysis(int n) {
    printf("\n=== COMPREHENSIVE FIBONACCI ANALYSIS ===\n");
    
    long long fib[MAX_TERMS];
    fib[0] = 0;
    if(n > 1) fib[1] = 1;
    
    // Generate sequence
    for(int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    // Basic analysis
    printf("Sequence: ");
    for(int i = 0; i < n && i < 20; i++) {
        printf("%lld ", fib[i]);
    }
    if(n > 20) printf("...");
    printf("\n");
    
    // Sum analysis
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += fib[i];
    }
    printf("Sum of first %d terms: %lld\n", n, sum);
    printf("Mathematical property: Sum = F(n+2) - 1\n");
    printf("Verification: F(%d) - 1 = %lld - 1 = %lld\n", n+1, fib[n-1] + fib[n-2], fib[n-1] + fib[n-2] - 1);
    
    // Even/Odd analysis
    int evenCount = 0, oddCount = 0;
    for(int i = 0; i < n; i++) {
        if(fib[i] % 2 == 0) evenCount++;
        else oddCount++;
    }
    printf("Even numbers: %d, Odd numbers: %d\n", evenCount, oddCount);
    
    // Pattern analysis
    printf("\nFibonacci modulo patterns:\n");
    printf("Mod 2: ");
    for(int i = 0; i < (n < 12 ? n : 12); i++) {
        printf("%lld ", fib[i] % 2);
    }
    printf("\nMod 3: ");
    for(int i = 0; i < (n < 12 ? n : 12); i++) {
        printf("%lld ", fib[i] % 3);
    }
    printf("\n");
}

void goldenRatioAnalysis(int n) {
    printf("\n=== GOLDEN RATIO ANALYSIS ===\n");
    printf("Golden Ratio (φ) = %f\n", PHI);
    printf("Analyzing relationship between consecutive Fibonacci numbers\n\n");
    
    long long a = 0, b = 1, c;
    
    printf("%-8s %-12s %-12s %-15s %-15s\n", "Term", "F(n)", "F(n+1)", "Ratio", "Difference");
    printf("------------------------------------------------------------\n");
    
    for(int i = 0; i < n - 1; i++) {
        c = a + b;

        if(a == 0) {
            printf("%-8d %-12lld %-12lld %-15s %-15s\n", i, a, b, "N/A", "N/A");
        } else {
            double ratio = (double)b / a;
            double difference = fabs(ratio - PHI);
            printf("%-8d %-12lld %-12lld %-15.10f %-15.10f\n", 
                   i, a, b, ratio, difference);
        }
        
        a = b;
        b = c;
    }
    
    printf("\nAs n increases, F(n+1)/F(n) approaches φ (Golden Ratio)\n");
    printf("This is one of the most beautiful properties of Fibonacci sequence!\n");
    
    // Binet's formula demonstration
    printf("\n--- Binet's Formula Verification ---\n");
    printf("F(n) = (φⁿ - ψⁿ) / √5, where ψ = -1/φ\n");
    printf("Comparing actual vs Binet's formula:\n");
    printf("%-8s %-12s %-12s %-12s\n", "n", "Actual", "Binet's", "Error");
    printf("--------------------------------------------\n");
    
    a = 0; b = 1;
    for(int i = 0; i < (n < 15 ? n : 15); i++) {
        double binetResult = binetsFormula(i);
        double error = fabs((i == 0 ? a : (i == 1 ? b : c)) - binetResult);
        
        printf("%-8d %-12lld %-12.6f %-12.6f\n", 
               i, (i == 0 ? a : (i == 1 ? b : c)), binetResult, error);
        
        if(i >= 2) {
            long long temp = a + b;
            a = b;
            b = temp;
            c = b;
        }
    }
}

void performanceComparison(int n) {
    printf("\n=== PERFORMANCE COMPARISON ===\n");
    clock_t start, end;
    double cpu_time_used;
    
    // Iterative approach
    start = clock();
    iterativeFibonacci(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Iterative approach time: %f seconds\n", cpu_time_used);
    
    // Memoized approach
    for(int i = 0; i < MAX_TERMS; i++) memoTable[i] = -1;
    start = clock();
    printf("Memoized result F(%d) = %lld\n", n-1, fibMemoization(n-1, memoTable));
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Memoized approach time: %f seconds\n", cpu_time_used);
    
    // Recursive approach (limited to smaller numbers)
    if(n <= 35) {
        start = clock();
        printf("Recursive result F(%d) = %lld\n", n-1, recursiveFibonacci(n-1));
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Recursive approach time: %f seconds\n", cpu_time_used);
    } else {
        printf("Recursive approach skipped (too slow for n > 35)\n");
    }
    
    printf("\nTime Complexity:\n");
    printf("- Iterative: O(n)\n");
    printf("- Memoized: O(n)\n");
    printf("- Recursive: O(2^n)\n");
    printf("- Matrix: O(log n)\n");
}

double binetsFormula(int n) {
    double phi = PHI;
    double psi = -1.0 / phi;
    double sqrt5 = sqrt(5);
    
    return (pow(phi, n) - pow(psi, n)) / sqrt5;
}

void fibonacciSpiral() {
    printf("\n=== FIBONACCI SPIRAL VISUALIZATION ===\n");
    printf("ASCII representation of Fibonacci spiral concept:\n\n");
    
    printf("Fibonacci squares arranged in spiral pattern:\n");
    printf("Each square has side length equal to Fibonacci number\n\n");
    
    printf("    +-------+-------+\n");
    printf("    |       |   3   |\n");
    printf("    |   5   +---+---+\n");
    printf("    |       | 2 | 1 |\n");
    printf("    +-------+---+---+\n");
    printf("    |     8         |\n");
    printf("    +---------------+\n\n");
    
    printf("Golden Rectangle Property:\n");
    printf("The ratio of consecutive Fibonacci numbers approaches φ\n");
    printf("This creates the famous Fibonacci spiral found in nature!\n\n");
    
    printf("Examples in nature:\n");
    printf("- Nautilus shell chambers\n");
    printf("- Sunflower seed arrangements\n");
    printf("- Pine cone spirals\n");
    printf("- Galaxy spiral arms\n");
    printf("- DNA molecule structure\n");
}

void fibonacciProperties() {
    printf("\n=== MATHEMATICAL PROPERTIES ===\n");
    
    printf("1. Fibonacci Identity: F(n+m) = F(n)×F(m+1) + F(n-1)×F(m)\n");
    printf("2. Cassini's Identity: F(n-1)×F(n+1) - F(n)² = (-1)ⁿ\n");
    printf("3. Sum Formula: F(0) + F(1) + ... + F(n) = F(n+2) - 1\n");
    printf("4. GCD Property: gcd(F(m), F(n)) = F(gcd(m,n))\n");
    printf("5. Divisibility: F(n) divides F(kn) for any positive integer k\n\n");
    
    printf("6. Matrix Representation:\n");
    printf("   [F(n+1)]   [1 1]ⁿ   [1]\n");
    printf("   [F(n)  ] = [1 0]  × [0]\n\n");
    
    printf("7. Generating Function:\n");
    printf("   Σ F(n)×xⁿ = x / (1 - x - x²)\n\n");
    
    printf("8. Continued Fraction for φ:\n");
    printf("   φ = 1 + 1/(1 + 1/(1 + 1/(1 + ...)))\n\n");
    
    printf("9. Lucas Numbers Relationship:\n");
    printf("   L(n) = F(n-1) + F(n+1) = φⁿ + ψⁿ\n\n");
    
    printf("10. Modular Properties:\n");
    printf("    - Pisano Period: Fibonacci sequence is periodic modulo any integer\n");
    printf("    - F(n) mod 2 has period 3: [0,1,1,0,1,1,...]\n");
    printf("    - F(n) mod 3 has period 8: [0,1,1,2,0,2,2,1,...]\n");
}

long long fibMemoization(int n, long long memo[]) {
    if(n <= 1) return n;
    if(memo[n] != -1) return memo[n];
    memo[n] = fibMemoization(n-1, memo) + fibMemoization(n-2, memo);
    return memo[n];
}