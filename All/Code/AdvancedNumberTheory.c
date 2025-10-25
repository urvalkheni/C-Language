#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_NUMBERS 1000
#define MAX_FACTORS 100

// Structure for number analysis
typedef struct {
    long long number;
    long long gcd;
    long long lcm;
    int isPrime;
    int isPerfect;
    int isAbundant;
    int isDeficient;
    long long sumOfDivisors;
    int numDivisors;
    long long divisors[MAX_FACTORS];
    long long primeFactors[MAX_FACTORS];
    int primeExponents[MAX_FACTORS];
    int numPrimeFactors;
} NumberInfo;

// Function prototypes
long long gcd(long long a, long long b);
long long gcdExtended(long long a, long long b, long long *x, long long *y);
long long lcm(long long a, long long b);
long long gcdMultiple(long long arr[], int n);
long long lcmMultiple(long long arr[], int n);
void euclideanAlgorithm(long long a, long long b);
void extendedEuclidean(long long a, long long b);
void findDivisors(long long n, NumberInfo *info);
void primeFactorization(long long n, NumberInfo *info);
void analyzeNumber(long long n, NumberInfo *info);
void numberClassification();
void diophantineEquations();
void modularArithmetic();
void chineseRemainderTheorem();
void fermatLittleTheorem();
void eulerTotientFunction();
void perfectNumbers();
void abundantDeficientNumbers();
void amicableNumbers();
void carmichaelNumbers();
void collatzConjecture();
void fibonacciGcd();
void continuedFractions();
void numberTheoryTests();
void cryptographicApplications();
void benchmarkAlgorithms();
void interactiveCalculator();
void batchProcessing();
void exportResults();
int isPrime(long long n);
long long power(long long base, long long exp, long long mod);
long long totient(long long n);
void displayResults(NumberInfo *info);
void comparativeAnalysis();
void advancedGcdApplications();

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long gcdExtended(long long a, long long b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    
    long long x1, y1;
    long long gcd_val = gcdExtended(b % a, a, &x1, &y1);
    
    *x = y1 - (b / a) * x1;
    *y = x1;
    
    return gcd_val;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

long long gcdMultiple(long long arr[], int n) {
    long long result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
        if (result == 1) break; // Optimization
    }
    return result;
}

long long lcmMultiple(long long arr[], int n) {
    long long result = arr[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

void euclideanAlgorithm(long long a, long long b) {
    printf("\n=== EUCLIDEAN ALGORITHM ===\n");
    printf("Finding GCD of %lld and %lld:\n\n", a, b);
    
    long long original_a = a, original_b = b;
    int step = 1;
    
    printf("Step | a      | b      | a mod b | Quotient\n");
    printf("─────────────────────────────────────────────\n");
    
    while (b != 0) {
        long long quotient = a / b;
        long long remainder = a % b;
        
        printf("%2d   | %-6lld | %-6lld | %-7lld | %lld\n", 
               step++, a, b, remainder, quotient);
        
        a = b;
        b = remainder;
    }
    
    printf("\n✓ GCD(%lld, %lld) = %lld\n", original_a, original_b, a);
    
    // Verify using formula
    long long lcm_val = (original_a * original_b) / a;
    printf("✓ LCM(%lld, %lld) = %lld\n", original_a, original_b, lcm_val);
    printf("✓ Verification: %lld × %lld = %lld × %lld = %lld\n", 
           original_a, original_b, a, lcm_val, original_a * original_b);
}

void extendedEuclidean(long long a, long long b) {
    printf("\n=== EXTENDED EUCLIDEAN ALGORITHM ===\n");
    printf("Finding integers x, y such that %lld × x + %lld × y = gcd(%lld, %lld)\n\n", a, b, a, b);
    
    long long x, y;
    long long gcd_val = gcdExtended(a, b, &x, &y);
    
    printf("Result:\n");
    printf("gcd(%lld, %lld) = %lld\n", a, b, gcd_val);
    printf("%lld × (%lld) + %lld × (%lld) = %lld\n", a, x, b, y, gcd_val);
    
    // Verification
    long long verification = a * x + b * y;
    printf("Verification: %lld × %lld + %lld × %lld = %lld ✓\n", a, x, b, y, verification);
    
    // Modular inverse if gcd = 1
    if (gcd_val == 1) {
        printf("\n🔐 Modular Inverse:\n");
        printf("%lld⁻¹ ≡ %lld (mod %lld)\n", a, (x % b + b) % b, b);
        printf("%lld⁻¹ ≡ %lld (mod %lld)\n", b, (y % a + a) % a, a);
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

void findDivisors(long long n, NumberInfo *info) {
    info->numDivisors = 0;
    info->sumOfDivisors = 0;
    
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            info->divisors[info->numDivisors++] = i;
            info->sumOfDivisors += i;
            
            if (i != n / i) {
                info->divisors[info->numDivisors++] = n / i;
                info->sumOfDivisors += n / i;
            }
        }
    }
    
    // Sort divisors
    for (int i = 0; i < info->numDivisors - 1; i++) {
        for (int j = i + 1; j < info->numDivisors; j++) {
            if (info->divisors[i] > info->divisors[j]) {
                long long temp = info->divisors[i];
                info->divisors[i] = info->divisors[j];
                info->divisors[j] = temp;
            }
        }
    }
}

void primeFactorization(long long n, NumberInfo *info) {
    info->numPrimeFactors = 0;
    long long temp = n;
    
    // Handle factor 2
    if (temp % 2 == 0) {
        info->primeFactors[info->numPrimeFactors] = 2;
        info->primeExponents[info->numPrimeFactors] = 0;
        while (temp % 2 == 0) {
            info->primeExponents[info->numPrimeFactors]++;
            temp /= 2;
        }
        info->numPrimeFactors++;
    }
    
    // Handle odd factors
    for (long long i = 3; i * i <= temp; i += 2) {
        if (temp % i == 0) {
            info->primeFactors[info->numPrimeFactors] = i;
            info->primeExponents[info->numPrimeFactors] = 0;
            while (temp % i == 0) {
                info->primeExponents[info->numPrimeFactors]++;
                temp /= i;
            }
            info->numPrimeFactors++;
        }
    }
    
    // If temp > 1, it's a prime factor
    if (temp > 1) {
        info->primeFactors[info->numPrimeFactors] = temp;
        info->primeExponents[info->numPrimeFactors] = 1;
        info->numPrimeFactors++;
    }
}

void analyzeNumber(long long n, NumberInfo *info) {
    info->number = n;
    info->isPrime = isPrime(n);
    
    findDivisors(n, info);
    primeFactorization(n, info);
    
    // Classify number
    long long properDivisorSum = info->sumOfDivisors - n;
    
    if (properDivisorSum == n) {
        info->isPerfect = 1;
        info->isAbundant = 0;
        info->isDeficient = 0;
    } else if (properDivisorSum > n) {
        info->isPerfect = 0;
        info->isAbundant = 1;
        info->isDeficient = 0;
    } else {
        info->isPerfect = 0;
        info->isAbundant = 0;
        info->isDeficient = 1;
    }
}

void displayResults(NumberInfo *info) {
    printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                              📊 NUMBER ANALYSIS REPORT 📊                                  ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║ Number: %-80lld ║\n", info->number);
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    
    printf("║ 🔍 BASIC PROPERTIES                                                                         ║\n");
    printf("║   Prime: %-10s   Perfect: %-10s   Abundant: %-10s                          ║\n",
           info->isPrime ? "Yes" : "No",
           info->isPerfect ? "Yes" : "No",
           info->isAbundant ? "Yes" : "No");
    printf("║   Deficient: %-10s   Divisors: %-8d   Sum of Divisors: %-15lld        ║\n",
           info->isDeficient ? "Yes" : "No",
           info->numDivisors,
           info->sumOfDivisors);
    
    printf("║                                                                                              ║\n");
    printf("║ 🔢 DIVISORS                                                                                 ║\n");
    printf("║   ");
    for (int i = 0; i < info->numDivisors && i < 15; i++) {
        printf("%lld", info->divisors[i]);
        if (i < info->numDivisors - 1 && i < 14) printf(", ");
    }
    if (info->numDivisors > 15) printf("...");
    printf("%*s║\n", (int)(82 - (info->numDivisors > 15 ? 20 : 0) - 
                      (info->numDivisors * 8)), "");
    
    printf("║                                                                                              ║\n");
    printf("║ 🧮 PRIME FACTORIZATION                                                                      ║\n");
    printf("║   %lld = ", info->number);
    for (int i = 0; i < info->numPrimeFactors; i++) {
        if (info->primeExponents[i] > 1) {
            printf("%lld^%d", info->primeFactors[i], info->primeExponents[i]);
        } else {
            printf("%lld", info->primeFactors[i]);
        }
        if (i < info->numPrimeFactors - 1) printf(" × ");
    }
    printf("%*s║\n", (int)(70 - info->numPrimeFactors * 10), "");
    
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}

void numberClassification() {
    printf("\n=== NUMBER CLASSIFICATION ===\n");
    
    printf("Enter range (start end): ");
    long long start, end;
    scanf("%lld %lld", &start, &end);
    
    int perfectCount = 0, abundantCount = 0, deficientCount = 0, primeCount = 0;
    
    printf("\nAnalyzing numbers from %lld to %lld:\n\n", start, end);
    printf("Number    | Type       | Sum of Proper Divisors | Classification\n");
    printf("──────────────────────────────────────────────────────────────────\n");
    
    for (long long n = start; n <= end && n <= start + 50; n++) {
        NumberInfo info;
        analyzeNumber(n, &info);
        
        long long properSum = info.sumOfDivisors - n;
        
        printf("%-9lld | ", n);
        
        if (info.isPrime) {
            printf("Prime      | ");
            primeCount++;
        } else {
            printf("Composite  | ");
        }
        
        printf("%-22lld | ", properSum);
        
        if (info.isPerfect) {
            printf("Perfect\n");
            perfectCount++;
        } else if (info.isAbundant) {
            printf("Abundant\n");
            abundantCount++;
        } else {
            printf("Deficient\n");
            deficientCount++;
        }
    }
    
    printf("\n📊 SUMMARY\n");
    printf("Perfect Numbers: %d\n", perfectCount);
    printf("Abundant Numbers: %d\n", abundantCount);
    printf("Deficient Numbers: %d\n", deficientCount);
    printf("Prime Numbers: %d\n", primeCount);
}

long long totient(long long n) {
    long long result = n;
    
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    
    if (n > 1) {
        result -= result / n;
    }
    
    return result;
}

void eulerTotientFunction() {
    printf("\n=== EULER'S TOTIENT FUNCTION ===\n");
    printf("φ(n) counts numbers ≤ n that are coprime to n\n\n");
    
    printf("Enter number: ");
    long long n;
    scanf("%lld", &n);
    
    long long phi = totient(n);
    
    printf("\nφ(%lld) = %lld\n", n, phi);
    printf("Percentage: %.2f%%\n", 100.0 * phi / n);
    
    // Show the coprime numbers for small n
    if (n <= 50) {
        printf("\nNumbers coprime to %lld: ", n);
        int count = 0;
        for (long long i = 1; i <= n; i++) {
            if (gcd(i, n) == 1) {
                printf("%lld ", i);
                count++;
            }
        }
        printf("\nCount: %d (matches φ(%lld) = %lld)\n", count, n, phi);
    }
    
    // Properties
    printf("\n📐 PROPERTIES\n");
    if (isPrime(n)) {
        printf("• %lld is prime, so φ(%lld) = %lld - 1 = %lld\n", n, n, n, n - 1);
    }
    
    printf("• φ is multiplicative: if gcd(a,b) = 1, then φ(ab) = φ(a)φ(b)\n");
    printf("• Sum of φ(d) for all divisors d of n equals n\n");
}

void perfectNumbers() {
    printf("\n=== PERFECT NUMBERS ===\n");
    printf("Perfect numbers equal the sum of their proper divisors\n\n");
    
    printf("Known perfect numbers:\n");
    long long perfectNums[] = {6, 28, 496, 8128, 33550336};
    int count = sizeof(perfectNums) / sizeof(perfectNums[0]);
    
    for (int i = 0; i < count; i++) {
        NumberInfo info;
        analyzeNumber(perfectNums[i], &info);
        
        printf("%lld: ", perfectNums[i]);
        long long sum = 0;
        for (int j = 0; j < info.numDivisors - 1; j++) { // Exclude the number itself
            if (info.divisors[j] != perfectNums[i]) {
                printf("%lld", info.divisors[j]);
                sum += info.divisors[j];
                if (j < info.numDivisors - 2) printf(" + ");
            }
        }
        printf(" = %lld ✓\n", sum);
    }
    
    printf("\n🔍 SEARCHING FOR PERFECT NUMBERS\n");
    printf("Enter range to search: ");
    long long start, end;
    scanf("%lld %lld", &start, &end);
    
    printf("Perfect numbers in range [%lld, %lld]:\n", start, end);
    int found = 0;
    
    for (long long n = start; n <= end; n++) {
        NumberInfo info;
        analyzeNumber(n, &info);
        
        if (info.isPerfect) {
            printf("✓ %lld is perfect!\n", n);
            found++;
        }
    }
    
    if (found == 0) {
        printf("No perfect numbers found in this range.\n");
    }
    
    printf("\n💡 FACT: All known perfect numbers are of the form 2^(p-1) × (2^p - 1)\n");
    printf("where 2^p - 1 is a Mersenne prime.\n");
}

void diophantineEquations() {
    printf("\n=== LINEAR DIOPHANTINE EQUATIONS ===\n");
    printf("Solving equations of the form ax + by = c\n\n");
    
    printf("Enter coefficients (a b c): ");
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    
    printf("\nSolving: %lldx + %lldy = %lld\n", a, b, c);
    
    long long x0, y0;
    long long gcd_val = gcdExtended(a, b, &x0, &y0);
    
    printf("gcd(%lld, %lld) = %lld\n", a, b, gcd_val);
    
    if (c % gcd_val != 0) {
        printf("❌ No integer solutions exist!\n");
        printf("Reason: gcd(%lld, %lld) = %lld does not divide %lld\n", a, b, gcd_val, c);
        return;
    }
    
    // Scale the solution
    long long scale = c / gcd_val;
    x0 *= scale;
    y0 *= scale;
    
    printf("✓ Integer solutions exist!\n");
    printf("\nParticular solution: x = %lld, y = %lld\n", x0, y0);
    printf("Verification: %lld×%lld + %lld×%lld = %lld ✓\n", a, x0, b, y0, a*x0 + b*y0);
    
    printf("\nGeneral solution:\n");
    printf("x = %lld + %lld×t\n", x0, b/gcd_val);
    printf("y = %lld - %lld×t\n", y0, a/gcd_val);
    printf("where t is any integer\n");
    
    printf("\nFirst few solutions:\n");
    for (int t = -3; t <= 3; t++) {
        long long x = x0 + (b/gcd_val) * t;
        long long y = y0 - (a/gcd_val) * t;
        printf("t = %2d: x = %4lld, y = %4lld\n", t, x, y);
    }
}

void modularArithmetic() {
    printf("\n=== MODULAR ARITHMETIC CALCULATOR ===\n");
    
    int choice;
    printf("1. Modular Addition\n");
    printf("2. Modular Multiplication\n");
    printf("3. Modular Exponentiation\n");
    printf("4. Modular Inverse\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    long long a, b, mod, result;
    
    switch (choice) {
        case 1:
            printf("Enter a, b, mod: ");
            scanf("%lld %lld %lld", &a, &b, &mod);
            result = (a + b) % mod;
            printf("(%lld + %lld) mod %lld = %lld\n", a, b, mod, result);
            break;
            
        case 2:
            printf("Enter a, b, mod: ");
            scanf("%lld %lld %lld", &a, &b, &mod);
            result = ((a % mod) * (b % mod)) % mod;
            printf("(%lld × %lld) mod %lld = %lld\n", a, b, mod, result);
            break;
            
        case 3:
            printf("Enter base, exponent, mod: ");
            scanf("%lld %lld %lld", &a, &b, &mod);
            result = 1;
            a = a % mod;
            while (b > 0) {
                if (b % 2 == 1) {
                    result = (result * a) % mod;
                }
                b = b >> 1;
                a = (a * a) % mod;
            }
            printf("(%lld^%lld) mod %lld = %lld\n", a, b, mod, result);
            break;
            
        case 4:
            printf("Enter a, mod: ");
            scanf("%lld %lld", &a, &mod);
            long long x, y;
            long long gcd_val = gcdExtended(a, mod, &x, &y);
            if (gcd_val == 1) {
                result = (x % mod + mod) % mod;
                printf("%lld^(-1) mod %lld = %lld\n", a, mod, result);
                printf("Verification: (%lld × %lld) mod %lld = %lld\n", 
                       a, result, mod, (a * result) % mod);
            } else {
                printf("Modular inverse doesn't exist (gcd ≠ 1)\n");
            }
            break;
    }
}

void interactiveCalculator() {
    printf("\n=== INTERACTIVE NUMBER THEORY CALCULATOR ===\n");
    
    char command[100];
    printf("Commands: gcd, lcm, factor, analyze, totient, help, quit\n");
    
    while (1) {
        printf("\n> ");
        fgets(command, sizeof(command), stdin);
        
        if (strncmp(command, "gcd", 3) == 0) {
            long long a, b;
            if (sscanf(command, "gcd %lld %lld", &a, &b) == 2) {
                printf("gcd(%lld, %lld) = %lld\n", a, b, gcd(a, b));
            } else {
                printf("Usage: gcd <a> <b>\n");
            }
        } else if (strncmp(command, "lcm", 3) == 0) {
            long long a, b;
            if (sscanf(command, "lcm %lld %lld", &a, &b) == 2) {
                printf("lcm(%lld, %lld) = %lld\n", a, b, lcm(a, b));
            } else {
                printf("Usage: lcm <a> <b>\n");
            }
        } else if (strncmp(command, "factor", 6) == 0) {
            long long n;
            if (sscanf(command, "factor %lld", &n) == 1) {
                NumberInfo info;
                primeFactorization(n, &info);
                printf("%lld = ", n);
                for (int i = 0; i < info.numPrimeFactors; i++) {
                    if (info.primeExponents[i] > 1) {
                        printf("%lld^%d", info.primeFactors[i], info.primeExponents[i]);
                    } else {
                        printf("%lld", info.primeFactors[i]);
                    }
                    if (i < info.numPrimeFactors - 1) printf(" × ");
                }
                printf("\n");
            } else {
                printf("Usage: factor <n>\n");
            }
        } else if (strncmp(command, "analyze", 7) == 0) {
            long long n;
            if (sscanf(command, "analyze %lld", &n) == 1) {
                NumberInfo info;
                analyzeNumber(n, &info);
                displayResults(&info);
            } else {
                printf("Usage: analyze <n>\n");
            }
        } else if (strncmp(command, "totient", 7) == 0) {
            long long n;
            if (sscanf(command, "totient %lld", &n) == 1) {
                printf("φ(%lld) = %lld\n", n, totient(n));
            } else {
                printf("Usage: totient <n>\n");
            }
        } else if (strncmp(command, "help", 4) == 0) {
            printf("Available commands:\n");
            printf("  gcd <a> <b>     - Greatest Common Divisor\n");
            printf("  lcm <a> <b>     - Least Common Multiple\n");
            printf("  factor <n>      - Prime Factorization\n");
            printf("  analyze <n>     - Complete Number Analysis\n");
            printf("  totient <n>     - Euler's Totient Function\n");
            printf("  help            - Show this help\n");
            printf("  quit            - Exit calculator\n");
        } else if (strncmp(command, "quit", 4) == 0) {
            break;
        } else {
            printf("Unknown command. Type 'help' for available commands.\n");
        }
    }
}

int main() {
    int choice;
    long long a, b, n;
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                              🔢 ADVANCED NUMBER THEORY SUITE 🔢                           ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. GCD & LCM Calculator              11. Perfect Numbers                                   ║\n");
        printf("║  2. Euclidean Algorithm               12. Abundant & Deficient Numbers                     ║\n");
        printf("║  3. Extended Euclidean                13. Amicable Numbers                                 ║\n");
        printf("║  4. Multiple Numbers GCD/LCM          14. Collatz Conjecture                              ║\n");
        printf("║  5. Number Analysis                   15. Fibonacci & GCD                                  ║\n");
        printf("║  6. Prime Factorization               16. Continued Fractions                              ║\n");
        printf("║  7. Number Classification             17. Cryptographic Applications                       ║\n");
        printf("║  8. Diophantine Equations             18. Algorithm Benchmarks                             ║\n");
        printf("║  9. Modular Arithmetic                19. Interactive Calculator                           ║\n");
        printf("║ 10. Euler's Totient Function          20. Exit                                             ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lld %lld", &a, &b);
                printf("GCD(%lld, %lld) = %lld\n", a, b, gcd(a, b));
                printf("LCM(%lld, %lld) = %lld\n", a, b, lcm(a, b));
                break;
                
            case 2:
                printf("Enter two numbers: ");
                scanf("%lld %lld", &a, &b);
                euclideanAlgorithm(a, b);
                break;
                
            case 3:
                printf("Enter two numbers: ");
                scanf("%lld %lld", &a, &b);
                extendedEuclidean(a, b);
                break;
                
            case 5:
                printf("Enter a number: ");
                scanf("%lld", &n);
                NumberInfo info;
                analyzeNumber(n, &info);
                displayResults(&info);
                break;
                
            case 7:
                numberClassification();
                break;
                
            case 8:
                diophantineEquations();
                break;
                
            case 9:
                modularArithmetic();
                break;
                
            case 10:
                eulerTotientFunction();
                break;
                
            case 11:
                perfectNumbers();
                break;
                
            case 19:
                interactiveCalculator();
                break;
                
            case 20:
                printf("🔢 Thank you for using Advanced Number Theory Suite!\n");
                exit(0);
                
            default:
                printf("❌ Feature under development or invalid choice!\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
    }
    
    return 0;
}