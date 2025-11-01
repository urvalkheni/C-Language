/*
 * Advanced GCD/LCM & Number Theory Calculator v2.0
 * Features: Multiple GCD algorithms, LCM calculation,
 *           number theory functions, and mathematical analysis
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// Function prototypes
int gcdEuclidean(int a, int b);
int gcdSubtraction(int a, int b);
int gcdRecursive(int a, int b);
int gcdBinary(int a, int b);
int gcdExtended(int a, int b, int *x, int *y);
int lcm(int a, int b);
int gcdMultiple(int arr[], int n);
int lcmMultiple(int arr[], int n);
bool areCoprime(int a, int b);
int eulerTotient(int n);
void primeFactorization(int n);
void commonDivisors(int a, int b);
void allDivisors(int n);
int countDivisors(int n);
int sumOfDivisors(int n);
void bezoutIdentity(int a, int b);
void diophantineEquation(int a, int b, int c);
void gcdLcmProperties(int a, int b);
void compareGCDAlgorithms(int a, int b);
void gcdPattern(int a, int b);
void fibonacciGCD(int n);
void displayMenu();

// Main function
int main() {
    int choice;
    int a, b, c, n;
    int arr[100];
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║     Advanced GCD/LCM & Number Theory Calculator v2.0       ║\n");
    printf("║          Comprehensive Mathematical Functions Tool         ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-20): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n--- GCD (Euclidean Algorithm) ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                printf("GCD(%d, %d) = %d\n", a, b, gcdEuclidean(a, b));
                break;
                
            case 2:
                printf("\n--- GCD (Subtraction Method) ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                printf("GCD(%d, %d) = %d\n", a, b, gcdSubtraction(a, b));
                break;
                
            case 3:
                printf("\n--- GCD (Recursive) ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                printf("GCD(%d, %d) = %d\n", a, b, gcdRecursive(a, b));
                break;
                
            case 4:
                printf("\n--- GCD (Binary/Stein's Algorithm) ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                printf("GCD(%d, %d) = %d\n", a, b, gcdBinary(a, b));
                break;
                
            case 5: {
                printf("\n--- Extended Euclidean Algorithm ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                int x, y;
                int gcd = gcdExtended(a, b, &x, &y);
                printf("GCD(%d, %d) = %d\n", a, b, gcd);
                printf("Coefficients: x = %d, y = %d\n", x, y);
                printf("Verification: %d × %d + %d × %d = %d\n", a, x, b, y, gcd);
                break;
            }
                
            case 6:
                printf("\n--- LCM Calculator ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                printf("LCM(%d, %d) = %d\n", a, b, lcm(a, b));
                break;
                
            case 7:
                printf("\n--- GCD of Multiple Numbers ---\n");
                printf("How many numbers? ");
                scanf("%d", &n);
                printf("Enter %d numbers:\n", n);
                for(int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("GCD = %d\n", gcdMultiple(arr, n));
                break;
                
            case 8:
                printf("\n--- LCM of Multiple Numbers ---\n");
                printf("How many numbers? ");
                scanf("%d", &n);
                printf("Enter %d numbers:\n", n);
                for(int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("LCM = %d\n", lcmMultiple(arr, n));
                break;
                
            case 9:
                printf("\n--- Check if Coprime ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                if(areCoprime(a, b))
                    printf("%d and %d are COPRIME (relatively prime) ✓\n", a, b);
                else
                    printf("%d and %d are NOT coprime.\n", a, b);
                break;
                
            case 10:
                printf("\n--- Euler's Totient Function φ(n) ---\n");
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("φ(%d) = %d\n", n, eulerTotient(n));
                printf("(Count of numbers coprime to %d)\n", n);
                break;
                
            case 11:
                printf("\n--- Prime Factorization ---\n");
                printf("Enter a number: ");
                scanf("%d", &n);
                primeFactorization(n);
                break;
                
            case 12:
                printf("\n--- Common Divisors ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                commonDivisors(a, b);
                break;
                
            case 13:
                printf("\n--- All Divisors ---\n");
                printf("Enter a number: ");
                scanf("%d", &n);
                allDivisors(n);
                break;
                
            case 14:
                printf("\n--- Divisor Statistics ---\n");
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Number of divisors: %d\n", countDivisors(n));
                printf("Sum of divisors: %d\n", sumOfDivisors(n));
                break;
                
            case 15:
                printf("\n--- Bézout's Identity ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                bezoutIdentity(a, b);
                break;
                
            case 16:
                printf("\n--- Linear Diophantine Equation ---\n");
                printf("Solve: ax + by = c\n");
                printf("Enter a: ");
                scanf("%d", &a);
                printf("Enter b: ");
                scanf("%d", &b);
                printf("Enter c: ");
                scanf("%d", &c);
                diophantineEquation(a, b, c);
                break;
                
            case 17:
                printf("\n--- GCD & LCM Properties ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                gcdLcmProperties(a, b);
                break;
                
            case 18:
                printf("\n--- Algorithm Comparison ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                compareGCDAlgorithms(a, b);
                break;
                
            case 19:
                printf("\n--- GCD Pattern Analysis ---\n");
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                gcdPattern(a, b);
                break;
                
            case 20:
                printf("\n--- Fibonacci GCD Property ---\n");
                printf("Enter n: ");
                scanf("%d", &n);
                fibonacciGCD(n);
                break;
                
            case 0:
                printf("\n✓ Thank you for using GCD/LCM Calculator!\n");
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
    printf("│  GCD ALGORITHMS                                         │\n");
    printf("│  [1]  Euclidean Algorithm                               │\n");
    printf("│  [2]  Subtraction Method                                │\n");
    printf("│  [3]  Recursive Algorithm                               │\n");
    printf("│  [4]  Binary (Stein's) Algorithm                        │\n");
    printf("│  [5]  Extended Euclidean Algorithm                      │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  LCM & MULTIPLE NUMBERS                                 │\n");
    printf("│  [6]  LCM (Least Common Multiple)                       │\n");
    printf("│  [7]  GCD of Multiple Numbers                           │\n");
    printf("│  [8]  LCM of Multiple Numbers                           │\n");
    printf("│  [9]  Check if Coprime                                  │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  NUMBER THEORY                                          │\n");
    printf("│  [10] Euler's Totient Function φ(n)                     │\n");
    printf("│  [11] Prime Factorization                               │\n");
    printf("│  [12] Common Divisors                                   │\n");
    printf("│  [13] All Divisors of a Number                          │\n");
    printf("│  [14] Divisor Statistics (Count & Sum)                  │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED FEATURES                                      │\n");
    printf("│  [15] Bézout's Identity                                 │\n");
    printf("│  [16] Linear Diophantine Equation                       │\n");
    printf("│  [17] GCD & LCM Properties                              │\n");
    printf("│  [18] Algorithm Performance Comparison                  │\n");
    printf("│  [19] GCD Pattern Analysis                              │\n");
    printf("│  [20] Fibonacci GCD Property                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit Program                                      │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

// GCD using Euclidean algorithm
int gcdEuclidean(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// GCD using subtraction
int gcdSubtraction(int a, int b) {
    while(a != b) {
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

// GCD using recursion
int gcdRecursive(int a, int b) {
    if(b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

// GCD using binary algorithm (Stein's algorithm)
int gcdBinary(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;
    
    int shift = 0;
    while(((a | b) & 1) == 0) {
        a >>= 1;
        b >>= 1;
        shift++;
    }
    
    while((a & 1) == 0) a >>= 1;
    
    do {
        while((b & 1) == 0) b >>= 1;
        if(a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        b = b - a;
    } while(b != 0);
    
    return a << shift;
}

// Extended Euclidean algorithm
int gcdExtended(int a, int b, int *x, int *y) {
    if(b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    
    int x1, y1;
    int gcd = gcdExtended(b, a % b, &x1, &y1);
    
    *x = y1;
    *y = x1 - (a / b) * y1;
    
    return gcd;
}

// LCM calculation
int lcm(int a, int b) {
    return (a * b) / gcdEuclidean(a, b);
}

// GCD of multiple numbers
int gcdMultiple(int arr[], int n) {
    int result = arr[0];
    for(int i = 1; i < n; i++) {
        result = gcdEuclidean(result, arr[i]);
    }
    return result;
}

// LCM of multiple numbers
int lcmMultiple(int arr[], int n) {
    int result = arr[0];
    for(int i = 1; i < n; i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

// Check if coprime
bool areCoprime(int a, int b) {
    return gcdEuclidean(a, b) == 1;
}

// Euler's totient function
int eulerTotient(int n) {
    int result = n;
    for(int p = 2; p * p <= n; p++) {
        if(n % p == 0) {
            while(n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

// Prime factorization
void primeFactorization(int n) {
    printf("\nPrime factorization of %d:\n", n);
    printf("─────────────────────────────\n");
    
    int count;
    for(int i = 2; i * i <= n; i++) {
        count = 0;
        while(n % i == 0) {
            count++;
            n /= i;
        }
        if(count > 0) {
            printf("%d^%d ", i, count);
        }
    }
    if(n > 1) {
        printf("%d^1", n);
    }
    printf("\n");
}

// Common divisors
void commonDivisors(int a, int b) {
    int gcd = gcdEuclidean(a, b);
    printf("\nCommon divisors of %d and %d:\n", a, b);
    printf("─────────────────────────────────\n");
    
    int count = 0;
    for(int i = 1; i <= gcd; i++) {
        if(gcd % i == 0) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n\nTotal common divisors: %d\n", count);
}

// All divisors
void allDivisors(int n) {
    printf("\nDivisors of %d:\n", n);
    printf("─────────────────────────────\n");
    
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Count divisors
int countDivisors(int n) {
    int count = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if(i * i == n)
                count++;
            else
                count += 2;
        }
    }
    return count;
}

// Sum of divisors
int sumOfDivisors(int n) {
    int sum = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            sum += i;
            if(i * i != n)
                sum += n / i;
        }
    }
    return sum;
}

// Bézout's identity
void bezoutIdentity(int a, int b) {
    int x, y;
    int gcd = gcdExtended(a, b, &x, &y);
    
    printf("\n═══════════════════════════════════════════\n");
    printf("        BÉZOUT'S IDENTITY\n");
    printf("═══════════════════════════════════════════\n");
    printf("\nFor numbers %d and %d:\n", a, b);
    printf("GCD(%d, %d) = %d\n", a, b, gcd);
    printf("\nBézout coefficients:\n");
    printf("%d × (%d) + %d × (%d) = %d\n", a, x, b, y, gcd);
    printf("═══════════════════════════════════════════\n");
}

// Diophantine equation
void diophantineEquation(int a, int b, int c) {
    int x, y;
    int gcd = gcdExtended(a, b, &x, &y);
    
    printf("\n═══════════════════════════════════════════\n");
    printf("   LINEAR DIOPHANTINE EQUATION\n");
    printf("═══════════════════════════════════════════\n");
    printf("\nEquation: %dx + %dy = %d\n", a, b, c);
    printf("GCD(%d, %d) = %d\n", a, b, gcd);
    
    if(c % gcd != 0) {
        printf("\n✗ No integer solutions exist!\n");
        printf("(c must be divisible by GCD)\n");
    } else {
        x = x * (c / gcd);
        y = y * (c / gcd);
        printf("\n✓ Solutions exist!\n");
        printf("One solution: x = %d, y = %d\n", x, y);
        printf("\nGeneral solution:\n");
        printf("x = %d + %dt\n", x, b / gcd);
        printf("y = %d - %dt\n", y, a / gcd);
        printf("(where t is any integer)\n");
    }
    printf("═══════════════════════════════════════════\n");
}

// GCD and LCM properties
void gcdLcmProperties(int a, int b) {
    int gcd_val = gcdEuclidean(a, b);
    int lcm_val = lcm(a, b);
    
    printf("\n╔═══════════════════════════════════════════╗\n");
    printf("║     GCD & LCM PROPERTIES                  ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    
    printf("\nNumbers: %d and %d\n", a, b);
    printf("─────────────────────────────────────────────\n");
    printf("GCD:                %d\n", gcd_val);
    printf("LCM:                %d\n", lcm_val);
    printf("─────────────────────────────────────────────\n");
    printf("a × b:              %d\n", a * b);
    printf("GCD × LCM:          %d\n", gcd_val * lcm_val);
    printf("Property: a×b = GCD×LCM? %s\n", (a*b == gcd_val*lcm_val) ? "✓ YES" : "✗ NO");
    printf("─────────────────────────────────────────────\n");
    printf("Coprime?            %s\n", areCoprime(a, b) ? "YES" : "NO");
    printf("a/GCD:              %d\n", a / gcd_val);
    printf("b/GCD:              %d\n", b / gcd_val);
    printf("═════════════════════════════════════════════\n");
}

// Compare algorithms
void compareGCDAlgorithms(int a, int b) {
    clock_t start, end;
    double time_taken;
    
    printf("\n═══════════════════════════════════════════\n");
    printf("  GCD ALGORITHM PERFORMANCE COMPARISON\n");
    printf("═══════════════════════════════════════════\n");
    printf("\nNumbers: %d and %d\n", a, b);
    printf("Running 1,000,000 iterations...\n\n");
    
    // Euclidean
    start = clock();
    for(int i = 0; i < 1000000; i++) {
        gcdEuclidean(a, b);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Euclidean:    %.4f ms\n", time_taken);
    
    // Recursive
    start = clock();
    for(int i = 0; i < 1000000; i++) {
        gcdRecursive(a, b);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Recursive:    %.4f ms\n", time_taken);
    
    // Binary
    start = clock();
    for(int i = 0; i < 1000000; i++) {
        gcdBinary(a, b);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Binary:       %.4f ms\n", time_taken);
    
    printf("\nGCD(%d, %d) = %d\n", a, b, gcdEuclidean(a, b));
}

// GCD pattern
void gcdPattern(int a, int b) {
    printf("\n═══════════════════════════════════════════\n");
    printf("       GCD PATTERN ANALYSIS\n");
    printf("═══════════════════════════════════════════\n");
    
    printf("\nEuclidean Algorithm Steps:\n");
    printf("─────────────────────────────────────────\n");
    
    int step = 1;
    while(b != 0) {
        printf("Step %d: GCD(%d, %d) = GCD(%d, %d)\n", step++, a, b, b, a % b);
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    printf("\nFinal GCD = %d\n", a);
}

// Fibonacci GCD property
void fibonacciGCD(int n) {
    printf("\nFibonacci GCD Property:\n");
    printf("─────────────────────────────────────────\n");
    
    // Generate Fibonacci numbers
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    printf("\nFibonacci numbers up to F(%d):\n", n);
    for(int i = 0; i <= n; i++) {
        printf("F(%d) = %d\n", i, fib[i]);
    }
    
    printf("\nProperty: GCD(F(n), F(n-1)) = 1\n");
    if(n > 0) {
        printf("GCD(F(%d), F(%d)) = GCD(%d, %d) = %d\n", 
               n, n-1, fib[n], fib[n-1], gcdEuclidean(fib[n], fib[n-1]));
    }
}
