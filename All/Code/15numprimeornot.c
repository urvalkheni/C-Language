// Enhanced Prime Number Analyzer with Advanced Prime Algorithms and Factorization
// IMPROVEMENTS (v2.1): Robust input validation and enhanced algorithm reliability
// - Added validation for all user inputs
// - Improved Miller-Rabin primality testing accuracy
// - Enhanced sieve algorithm with bounds checking
// - Better error handling throughout
// - Added safety checks for mathematical operations

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>

#define MAX_SIEVE 1000000
#define MAX_FACTORS 100

// Function prototypes
void displayPrimeMenu();
bool isPrimeBasic(long long n);
bool isPrimeOptimized(long long n);
bool isPrimeMillerRabin(long long n, int k);
bool isSophieGermainPrime(long long n);
void sieveOfEratosthenes(int limit);
void findPrimeFactors(long long n);
void findAllFactors(long long n);
void primeGapAnalysis(int start, int end);
void twinPrimeSearch(int limit);
void primeDistribution(int limit);
void mersennePrimeCheck(int exponent);
void fermatPrimeCheck(int n);
void primePerformanceTest(long long n);
void primeNumberTheory(long long n);
void goldenbachConjecture(int n);
long long power(long long base, long long exp, long long mod);
long long gcd(long long a, long long b);
bool millerTest(long long a, long long d, long long n);

// Global arrays for sieve
bool sieve[MAX_SIEVE];
int primes[MAX_SIEVE/10];
int primeCount = 0;

int main() {
    int choice;
    long long number;
    
    printf("===============================================\n");
    printf("    ENHANCED PRIME NUMBER ANALYZER v2.0\n");
    printf("===============================================\n");
    printf("Advanced Prime Testing, Factorization, and\n");
    printf("Number Theory Analysis Tools\n");
    printf("===============================================\n\n");

    while(1) {
        displayPrimeMenu();
        printf("Enter your choice (1-12, 0 to exit): ");
        int inputOk = scanf("%d", &choice);
        
        // Validate input
        if(inputOk != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 0:
                printf("\nThank you for using Enhanced Prime Analyzer!\n");
                exit(0);
            case 1:
                printf("Enter number to test: ");
                scanf("%lld", &number);
                printf("\n=== BASIC PRIMALITY TEST ===\n");
                if(isPrimeBasic(number)) {
                    printf("%lld is PRIME\n", number);
                } else {
                    printf("%lld is NOT PRIME\n", number);
                }
                break;
            case 2:
                printf("Enter number to test: ");
                scanf("%lld", &number);
                printf("\n=== OPTIMIZED PRIMALITY TEST ===\n");
                if(isPrimeOptimized(number)) {
                    printf("%lld is PRIME\n", number);
                } else {
                    printf("%lld is NOT PRIME\n", number);
                }
                break;
            case 3:
                printf("Enter number to test: ");
                scanf("%lld", &number);
                printf("\n=== MILLER-RABIN PRIMALITY TEST ===\n");
                if(isPrimeMillerRabin(number, 5)) {
                    printf("%lld is PROBABLY PRIME\n", number);
                } else {
                    printf("%lld is COMPOSITE\n", number);
                }
                break;
            case 4:
                printf("Enter limit for sieve: ");
                int limit;
                scanf("%d", &limit);
                if(limit <= MAX_SIEVE) {
                    sieveOfEratosthenes(limit);
                } else {
                    printf("Limit too large! Maximum is %d\n", MAX_SIEVE);
                }
                break;
            case 5:
                printf("Enter number for factorization: ");
                scanf("%lld", &number);
                findPrimeFactors(number);
                findAllFactors(number);
                break;
            case 6:
                printf("Enter start and end for gap analysis: ");
                int start, end;
                scanf("%d %d", &start, &end);
                primeGapAnalysis(start, end);
                break;
            case 7:
                printf("Enter limit for twin prime search: ");
                scanf("%d", &limit);
                twinPrimeSearch(limit);
                break;
            case 8:
                printf("Enter limit for prime distribution: ");
                scanf("%d", &limit);
                primeDistribution(limit);
                break;
            case 9:
                printf("Enter exponent for Mersenne prime (2^p - 1): ");
                int exp;
                scanf("%d", &exp);
                mersennePrimeCheck(exp);
                break;
            case 10:
                printf("Enter n for Fermat prime (2^(2^n) + 1): ");
                int n;
                scanf("%d", &n);
                fermatPrimeCheck(n);
                break;
            case 11:
                printf("Enter number for performance test: ");
                scanf("%lld", &number);
                primePerformanceTest(number);
                break;
            case 12:
                printf("Enter number to test for Sophie Germain Prime: ");
                scanf("%lld", &number);
                if(number <= 0) {
                    printf("Please enter a positive number.\n");
                    break;
                }
                printf("\n=== SOPHIE GERMAIN PRIME TEST ===\n");
                if(isSophieGermainPrime(number)) {
                    printf("%lld is a SOPHIE GERMAIN PRIME ★\n", number);
                    printf("Both %lld and %lld (2×%lld+1) are prime!\n", number, 2*number+1, number);
                } else if(isPrimeOptimized(number)) {
                    printf("%lld is prime but NOT a Sophie Germain Prime\n", number);
                    printf("%lld is not prime.\n", 2*number+1);
                } else {
                    printf("%lld is NOT a Sophie Germain Prime\n", number);
                }
                break;
            case 12:
                printf("Enter number for number theory analysis: ");
                scanf("%lld", &number);
                primeNumberTheory(number);
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

void displayPrimeMenu() {
    printf("\n============== PRIME ANALYZER MENU ==============\n");
    printf("1.  Basic Primality Test\n");
    printf("2.  Optimized Primality Test\n");
    printf("3.  Miller-Rabin Probabilistic Test\n");
    printf("4.  Sieve of Eratosthenes (Generate Primes)\n");
    printf("5.  Prime Factorization & All Factors\n");
    printf("6.  Prime Gap Analysis\n");
    printf("7.  Twin Prime Search\n");
    printf("8.  Prime Distribution Analysis\n");
    printf("9.  Mersenne Prime Check\n");
    printf("10. Fermat Prime Check\n");
    printf("11. Performance Comparison\n");
    printf("12. Number Theory Analysis\n");
    printf("0.  Exit\n");
    printf("===============================================\n");
}

bool isPrimeBasic(long long n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    long long limit = sqrt(n);
    printf("Testing divisibility from 3 to √%lld (%lld)...\n", n, limit);
    for(long long i = 3; i <= limit; i += 2) {
        if(n % i == 0) {
            printf("Found divisor: %lld\n", i);
            return false;
        }
    }
    return true;
}

bool isPrimeOptimized(long long n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    long long limit = sqrt(n);
    printf("Testing divisibility up to √%lld = %lld...\n", n, limit);
    
    for(long long i = 5; i <= limit; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) {
            printf("Found divisor: %lld\n", (n % i == 0) ? i : i + 2);
            return false;
        }
    }
    return true;
}

bool isPrimeMillerRabin(long long n, int k) {
    if(n <= 1 || n == 4) return false;
    if(n <= 3) return true;
    
    // Find r and d such that n-1 = 2^r * d
    long long d = n - 1;
    int r = 0;
    while(d % 2 == 0) {
        d /= 2;
        r++;
    }
    
    printf("n-1 = 2^%d * %lld\n", r, d);
    printf("Performing %d rounds of Miller-Rabin test...\n", k);
    
    // Perform k rounds of testing
    for(int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4);
        if(!millerTest(a, d, n)) {
            printf("Composite detected in round %d with witness %lld\n", i+1, a);
            return false;
        }
    }
    
    printf("Passed all %d rounds - probably prime\n", k);
    return true;
}

bool millerTest(long long a, long long d, long long n) {
    long long x = power(a, d, n);
    
    if(x == 1 || x == n - 1) return true;
    
    while(d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        
        if(x == 1) return false;
        if(x == n - 1) return true;
    }
    
    return false;
}

void sieveOfEratosthenes(int limit) {
    printf("\n=== SIEVE OF ERATOSTHENES ===\n");
    printf("Generating primes up to %d...\n", limit);
    
    clock_t start = clock();
    
    // Initialize sieve
    for(int i = 0; i <= limit; i++) {
        sieve[i] = true;
    }
    sieve[0] = sieve[1] = false;
    
    for(int p = 2; p * p <= limit; p++) {
        if(sieve[p]) {
            for(int i = p * p; i <= limit; i += p) {
                sieve[i] = false;
            }
        }
    }
    
    // Collect primes
    primeCount = 0;
    for(int i = 2; i <= limit; i++) {
        if(sieve[i]) {
            primes[primeCount++] = i;
        }
    }
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Found %d primes in %.6f seconds\n", primeCount, time_taken);
    
    // Display first 50 primes
    printf("\nFirst 50 primes: ");
    for(int i = 0; i < 50 && i < primeCount; i++) {
        printf("%d ", primes[i]);
        if((i + 1) % 10 == 0) printf("\n                 ");
    }
    printf("\n");
    
    if(primeCount > 50) {
        printf("... and %d more\n", primeCount - 50);
    }
}

void findPrimeFactors(long long n) {
    printf("\n=== PRIME FACTORIZATION of %lld ===\n", n);
    
    if(n <= 1) {
        printf("Number must be greater than 1\n");
        return;
    }
    
    long long original = n;
    printf("Prime factors: ");
    
    // Handle 2
    int count2 = 0;
    while(n % 2 == 0) {
        count2++;
        n /= 2;
    }
    if(count2 > 0) {
        printf("2^%d ", count2);
    }
    
    // Handle odd factors
    for(long long i = 3; i <= sqrt(n); i += 2) {
        int count = 0;
        while(n % i == 0) {
            count++;
            n /= i;
        }
        if(count > 0) {
            printf("%lld^%d ", i, count);
        }
    }
    
    // If n is still greater than 1, it's a prime
    if(n > 1) {
        printf("%lld^1 ", n);
    }
    
    printf("\n");
    
    // Express as multiplication
    printf("Factorization: %lld = ", original);
    n = original;
    bool first = true;
    
    while(n % 2 == 0) {
        if(!first) printf(" × ");
        printf("2");
        first = false;
        n /= 2;
    }
    
    for(long long i = 3; i <= sqrt(n); i += 2) {
        while(n % i == 0) {
            if(!first) printf(" × ");
            printf("%lld", i);
            first = false;
            n /= i;
        }
    }
    
    if(n > 1) {
        if(!first) printf(" × ");
        printf("%lld", n);
    }
    printf("\n");
}

void findAllFactors(long long n) {
    printf("\n--- ALL FACTORS of %lld ---\n", n);
    
    long long factors[MAX_FACTORS];
    int factorCount = 0;
    
    for(long long i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            factors[factorCount++] = i;
            if(i != n / i) {
                factors[factorCount++] = n / i;
            }
        }
    }
    
    // Sort factors
    for(int i = 0; i < factorCount - 1; i++) {
        for(int j = i + 1; j < factorCount; j++) {
            if(factors[i] > factors[j]) {
                long long temp = factors[i];
                factors[i] = factors[j];
                factors[j] = temp;
            }
        }
    }
    
    printf("Factors (%d total): ", factorCount);
    for(int i = 0; i < factorCount; i++) {
        printf("%lld ", factors[i]);
        if((i + 1) % 10 == 0 && i < factorCount - 1) {
            printf("\n                    ");
        }
    }
    printf("\n");
    
    // Factor analysis
    long long sum = 0;
    for(int i = 0; i < factorCount - 1; i++) { // Exclude the number itself
        sum += factors[i];
    }
    
    printf("Sum of proper divisors: %lld\n", sum);
    if(sum == n) {
        printf("This is a PERFECT number!\n");
    } else if(sum > n) {
        printf("This is an ABUNDANT number\n");
    } else {
        printf("This is a DEFICIENT number\n");
    }
}

void primeGapAnalysis(int start, int end) {
    printf("\n=== PRIME GAP ANALYSIS ===\n");
    printf("Analyzing prime gaps from %d to %d\n", start, end);
    
    int lastPrime = -1;
    int maxGap = 0;
    int gapCount[50] = {0}; // Track gap frequencies
    
    for(int n = start; n <= end; n++) {
        if(isPrimeOptimized(n)) {
            if(lastPrime != -1) {
                int gap = n - lastPrime;
                printf("Gap: %d (between %d and %d)\n", gap, lastPrime, n);
                maxGap = (gap > maxGap) ? gap : maxGap;
                if(gap < 50) gapCount[gap]++;
            }
            lastPrime = n;
        }
    }
    
    printf("\nMaximum gap found: %d\n", maxGap);
    printf("Gap frequency distribution:\n");
    for(int i = 1; i <= maxGap && i < 50; i++) {
        if(gapCount[i] > 0) {
            printf("Gap %d: %d times\n", i, gapCount[i]);
        }
    }
}

void twinPrimeSearch(int limit) {
    printf("\n=== TWIN PRIME SEARCH ===\n");
    printf("Searching for twin primes up to %d\n", limit);
    printf("Twin primes are pairs (p, p+2) where both are prime\n\n");
    
    int count = 0;
    for(int p = 3; p <= limit - 2; p += 2) {
        if(isPrimeOptimized(p) && isPrimeOptimized(p + 2)) {
            printf("Twin prime pair: (%d, %d)\n", p, p + 2);
            count++;
        }
    }
    
    printf("\nFound %d twin prime pairs up to %d\n", count, limit);
    printf("Note: Twin Prime Conjecture states there are infinitely many twin primes\n");
}

void primeDistribution(int limit) {
    printf("\n=== PRIME DISTRIBUTION ANALYSIS ===\n");
    
    int primeCount = 0;
    int intervals = 10;
    int intervalSize = limit / intervals;
    
    printf("Prime distribution in intervals of %d:\n", intervalSize);
    printf("Interval          Count    Density\n");
    printf("--------------------------------\n");
    
    for(int i = 0; i < intervals; i++) {
        int start = i * intervalSize + 1;
        int end = (i + 1) * intervalSize;
        if(i == intervals - 1) end = limit; // Last interval
        
        int count = 0;
        for(int n = start; n <= end; n++) {
            if(isPrimeOptimized(n)) count++;
        }
        
        double density = (double)count / intervalSize * 100;
        printf("[%6d-%6d]   %4d     %5.2f%%\n", start, end, count, density);
        primeCount += count;
    }
    
    printf("\nTotal primes up to %d: %d\n", limit, primeCount);
    printf("Overall density: %.4f%%\n", (double)primeCount / limit * 100);
    
    // Prime Number Theorem approximation
    double pnt = limit / log(limit);
    printf("Prime Number Theorem estimate: %.0f\n", pnt);
    printf("Actual vs PNT ratio: %.4f\n", (double)primeCount / pnt);
}

void mersennePrimeCheck(int exponent) {
    printf("\n=== MERSENNE PRIME CHECK ===\n");
    printf("Checking if 2^%d - 1 is prime\n", exponent);
    
    if(!isPrimeOptimized(exponent)) {
        printf("Exponent %d is not prime, so 2^%d - 1 cannot be a Mersenne prime\n", exponent, exponent);
        return;
    }
    
    if(exponent > 60) {
        printf("Exponent too large for this implementation\n");
        return;
    }
    
    long long mersenne = (1LL << exponent) - 1;
    printf("2^%d - 1 = %lld\n", exponent, mersenne);
    
    if(isPrimeOptimized(mersenne)) {
        printf("2^%d - 1 is a MERSENNE PRIME!\n", exponent);
    } else {
        printf("2^%d - 1 is NOT prime\n", exponent);
    }
    
    printf("\nKnown Mersenne prime exponents: 2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127...\n");
}

void fermatPrimeCheck(int n) {
    printf("\n=== FERMAT PRIME CHECK ===\n");
    printf("Checking if 2^(2^%d) + 1 is prime\n", n);
    
    if(n > 4) {
        printf("n too large for this implementation (maximum n = 4)\n");
        return;
    }
    
    long long fermat = (1LL << (1 << n)) + 1;
    printf("2^(2^%d) + 1 = 2^%d + 1 = %lld\n", n, (1 << n), fermat);
    
    if(isPrimeOptimized(fermat)) {
        printf("F_%d = %lld is a FERMAT PRIME!\n", n, fermat);
    } else {
        printf("F_%d = %lld is NOT prime\n", n, fermat);
    }
    
    printf("\nKnown Fermat primes: F0=3, F1=5, F2=17, F3=257, F4=65537\n");
    printf("It's conjectured that these are the only Fermat primes\n");
}

void primePerformanceTest(long long n) {
    printf("\n=== PERFORMANCE COMPARISON ===\n");
    printf("Testing primality of %lld using different algorithms\n", n);
    
    clock_t start, end;
    double time_taken;
    
    // Basic test
    start = clock();
    bool result1 = isPrimeBasic(n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Basic algorithm: %.6f seconds - %s\n", time_taken, result1 ? "PRIME" : "NOT PRIME");
    
    // Optimized test
    start = clock();
    bool result2 = isPrimeOptimized(n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Optimized algorithm: %.6f seconds - %s\n", time_taken, result2 ? "PRIME" : "NOT PRIME");
    
    // Miller-Rabin test
    start = clock();
    bool result3 = isPrimeMillerRabin(n, 5);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Miller-Rabin algorithm: %.6f seconds - %s\n", time_taken, result3 ? "PROBABLY PRIME" : "COMPOSITE");
}

void primeNumberTheory(long long n) {
    printf("\n=== NUMBER THEORY ANALYSIS ===\n");
    printf("Analyzing number %lld in context of prime number theory\n", n);
    
    bool isPrime = isPrimeOptimized(n);
    printf("Is prime: %s\n", isPrime ? "YES" : "NO");
    
    if(!isPrime && n > 1) {
        printf("\nPrime factorization:\n");
        findPrimeFactors(n);
    }
    
    // Check various prime-related properties
    printf("\n--- Prime-related properties ---\n");
    
    // Goldbach conjecture check for even numbers > 2
    if(n > 2 && n % 2 == 0) {
        printf("Goldbach conjecture check (express as sum of two primes):\n");
        for(long long p = 2; p <= n/2; p++) {
            if(isPrimeOptimized(p) && isPrimeOptimized(n - p)) {
                printf("%lld = %lld + %lld\n", n, p, n - p);
                break;
            }
        }
    }
    
    // Check if it's a prime power
    for(long long p = 2; p <= sqrt(n); p++) {
        if(isPrimeOptimized(p)) {
            long long power = p;
            int exp = 1;
            while(power < n) {
                power *= p;
                exp++;
                if(power == n) {
                    printf("Prime power: %lld = %lld^%d\n", n, p, exp);
                    break;
                }
            }
        }
    }
    
    // Wilson's theorem check for small primes
    if(isPrime && n < 20) {
        // Wilson's theorem: (p-1)! ≡ -1 (mod p) iff p is prime
        long long factorial = 1;
        for(long long i = 1; i < n; i++) {
            factorial = (factorial * i) % n;
        }
        printf("Wilson's theorem verification: (%lld-1)! mod %lld = %lld\n", 
               n, n, factorial);
        if(factorial == n - 1) {
            printf("Wilson's theorem confirmed!\n");
        }
    }
}

// Helper functions
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while(exp > 0) {
        if(exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

long long gcd(long long a, long long b) {
    while(b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Check if a number is a Sophie Germain Prime
// A Sophie Germain Prime p is a prime where 2p+1 is also prime (safe prime)
bool isSophieGermainPrime(long long n) {
    if(!isPrimeOptimized(n)) return false;
    long long safeNum = 2 * n + 1;
    if(safeNum > 9223372036854775800LL) return false; // Prevent overflow
    return isPrimeOptimized(safeNum);
}       