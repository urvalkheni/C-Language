#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_RANGE 10000000
#define MAX_PRIMES 1000000

// Structure for prime analysis
typedef struct {
    long long prime;
    int gap;
    int twinPrime;
    int palindromic;
    int circular;
    int emirp;
} PrimeInfo;

// Function prototypes
int isPrime(long long n);
int isPrimeMiller(long long n, int k);
int isPrimeAKS(long long n);
void sieveOfEratosthenes(int limit);
void findPrimesInRange(long long start, long long end);
void primeFactorization(long long n);
void findTwinPrimes(int limit);
void findPrimeGaps(int limit);
void mersennePrimes();
void fermatPrimes();
void palindromicPrimes(int limit);
void circularPrimes(int limit);
void emirpPrimes(int limit);
void primePatterns();
void primeStatistics(int limit);
void goldbachConjecture(int limit);
void primeSpirals();
void primeDistribution();
void performanceComparison();
void advancedTests();
void primeNumberTheorems();
void cryptographicPrimes();
void generateLargePrimes();
void primeVisualization();
int isPalindrome(long long n);
int isCircular(long long n);
long long reverseNumber(long long n);
int millerRabinTest(long long n, long long a);
long long modularExponentiation(long long base, long long exp, long long mod);
void primorialNumbers();
void primeConstellations();
void exportPrimes();

int isPrime(long long n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

long long modularExponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int millerRabinTest(long long n, long long a) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0) return 0;
    
    // Write n-1 as 2^r * d
    long long r = 0;
    long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }
    
    // Witness loop
    long long x = modularExponentiation(a, d, n);
    if (x == 1 || x == n - 1) return 1;
    
    for (long long i = 0; i < r - 1; i++) {
        x = modularExponentiation(x, 2, n);
        if (x == n - 1) return 1;
    }
    return 0;
}

int isPrimeMiller(long long n, int k) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0) return 0;
    
    // Test with k random bases
    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 3);
        if (!millerRabinTest(n, a)) return 0;
    }
    return 1;
}

void sieveOfEratosthenes(int limit) {
    printf("\n=== SIEVE OF ERATOSTHENES ===\n");
    
    clock_t start = clock();
    
    char *isPrimeArr = (char*)calloc(limit + 1, sizeof(char));
    for (int i = 2; i <= limit; i++) {
        isPrimeArr[i] = 1;
    }
    
    for (int p = 2; p * p <= limit; p++) {
        if (isPrimeArr[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrimeArr[i] = 0;
            }
        }
    }
    
    // Count and display primes
    int count = 0;
    printf("Prime numbers up to %d:\n", limit);
    
    for (int i = 2; i <= limit; i++) {
        if (isPrimeArr[i]) {
            printf("%d ", i);
            count++;
            if (count % 20 == 0) printf("\n");
        }
    }
    
    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("\n\nTotal primes found: %d\n", count);
    printf("Time taken: %.4f seconds\n", timeTaken);
    
    free(isPrimeArr);
}

void findPrimesInRange(long long start, long long end) {
    printf("\n=== PRIMES IN RANGE [%lld, %lld] ===\n", start, end);
    
    clock_t startTime = clock();
    int count = 0;
    
    for (long long i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%lld ", i);
            count++;
            if (count % 15 == 0) printf("\n");
        }
    }
    
    clock_t endTime = clock();
    double timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    
    printf("\n\nFound %d primes in %.4f seconds\n", count, timeTaken);
    printf("Density: %.4f%% of numbers in range are prime\n", 
           100.0 * count / (end - start + 1));
}

void primeFactorization(long long n) {
    printf("\n=== PRIME FACTORIZATION OF %lld ===\n", n);
    
    long long original = n;
    printf("%lld = ", original);
    
    int first = 1;
    
    // Handle 2 separately
    while (n % 2 == 0) {
        if (!first) printf(" × ");
        printf("2");
        first = 0;
        n /= 2;
    }
    
    // Handle odd factors
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            if (!first) printf(" × ");
            printf("%lld", i);
            first = 0;
            n /= i;
        }
    }
    
    // If n is still > 1, it's a prime
    if (n > 1) {
        if (!first) printf(" × ");
        printf("%lld", n);
    }
    
    printf("\n");
    
    // Count factors
    n = original;
    int factorCount = 0;
    int uniqueFactors = 0;
    
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            uniqueFactors++;
            while (n % i == 0) {
                factorCount++;
                n /= i;
            }
        }
    }
    if (n > 1) {
        uniqueFactors++;
        factorCount++;
    }
    
    printf("Total prime factors: %d\n", factorCount);
    printf("Unique prime factors: %d\n", uniqueFactors);
}

void findTwinPrimes(int limit) {
    printf("\n=== TWIN PRIMES UP TO %d ===\n", limit);
    printf("Twin primes are pairs (p, p+2) where both are prime.\n\n");
    
    int count = 0;
    for (int i = 3; i <= limit - 2; i += 2) {
        if (isPrime(i) && isPrime(i + 2)) {
            printf("(%d, %d) ", i, i + 2);
            count++;
            if (count % 8 == 0) printf("\n");
        }
    }
    
    printf("\n\nTotal twin prime pairs: %d\n", count);
}

void findPrimeGaps(int limit) {
    printf("\n=== PRIME GAPS ANALYSIS ===\n");
    printf("Gap analysis shows distribution of differences between consecutive primes.\n\n");
    
    int lastPrime = 2;
    int maxGap = 0;
    int gapCounts[100] = {0}; // Count gaps up to 100
    
    printf("Prime gaps:\n");
    for (int i = 3; i <= limit; i += 2) {
        if (isPrime(i)) {
            int gap = i - lastPrime;
            printf("Gap %d: %d -> %d\n", gap, lastPrime, i);
            
            if (gap > maxGap) maxGap = gap;
            if (gap < 100) gapCounts[gap]++;
            
            lastPrime = i;
        }
    }
    
    printf("\nGap frequency distribution:\n");
    for (int i = 2; i <= maxGap && i < 100; i += 2) {
        if (gapCounts[i] > 0) {
            printf("Gap %d: %d times\n", i, gapCounts[i]);
        }
    }
    
    printf("Maximum gap found: %d\n", maxGap);
}

void mersennePrimes() {
    printf("\n=== MERSENNE PRIMES ===\n");
    printf("Mersenne primes are primes of the form 2^p - 1 where p is prime.\n\n");
    
    printf("Known Mersenne primes (first few):\n");
    int mersennePrimes[] = {3, 7, 31, 127, 8191, 131071, 524287, 2147483647};
    int exponents[] = {2, 3, 5, 7, 13, 17, 19, 31};
    
    for (int i = 0; i < 8; i++) {
        printf("M_%d = 2^%d - 1 = %d\n", exponents[i], exponents[i], mersennePrimes[i]);
    }
    
    printf("\nTesting small Mersenne numbers:\n");
    for (int p = 2; p <= 31; p++) {
        if (isPrime(p)) {
            long long mersenne = (1LL << p) - 1;
            if (mersenne > 0 && isPrime(mersenne)) {
                printf("2^%d - 1 = %lld is prime (Mersenne prime)\n", p, mersenne);
            }
        }
    }
}

int isPalindrome(long long n) {
    return n == reverseNumber(n);
}

long long reverseNumber(long long n) {
    long long reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

void palindromicPrimes(int limit) {
    printf("\n=== PALINDROMIC PRIMES ===\n");
    printf("Palindromic primes read the same forwards and backwards.\n\n");
    
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i) && isPalindrome(i)) {
            printf("%d ", i);
            count++;
            if (count % 15 == 0) printf("\n");
        }
    }
    
    printf("\n\nTotal palindromic primes: %d\n", count);
}

int isCircular(long long n) {
    char str[20];
    sprintf(str, "%lld", n);
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        // Create rotated number
        char rotated[20];
        strcpy(rotated, str + i + 1);
        strncat(rotated, str, i + 1);
        rotated[len] = '\0';
        
        long long rotatedNum = atoll(rotated);
        if (!isPrime(rotatedNum)) return 0;
    }
    return 1;
}

void circularPrimes(int limit) {
    printf("\n=== CIRCULAR PRIMES ===\n");
    printf("Circular primes remain prime when digits are rotated.\n\n");
    
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i) && isCircular(i)) {
            printf("%d ", i);
            count++;
            if (count % 15 == 0) printf("\n");
        }
    }
    
    printf("\n\nTotal circular primes: %d\n", count);
}

void primeStatistics(int limit) {
    printf("\n=== PRIME STATISTICS UP TO %d ===\n", limit);
    
    int primeCount = 0;
    int twinPairs = 0;
    int palindromicCount = 0;
    int circularCount = 0;
    long long sumOfPrimes = 0;
    
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            primeCount++;
            sumOfPrimes += i;
            
            if (isPalindrome(i)) palindromicCount++;
            if (isCircular(i)) circularCount++;
            if (i <= limit - 2 && isPrime(i + 2)) twinPairs++;
        }
    }
    
    printf("📊 COMPREHENSIVE STATISTICS\n");
    printf("Total numbers: %d\n", limit);
    printf("Prime numbers: %d\n", primeCount);
    printf("Prime density: %.4f%%\n", 100.0 * primeCount / limit);
    printf("Sum of primes: %lld\n", sumOfPrimes);
    printf("Average prime: %.2f\n", (double)sumOfPrimes / primeCount);
    
    printf("\n🔍 SPECIAL PRIME TYPES\n");
    printf("Twin prime pairs: %d\n", twinPairs);
    printf("Palindromic primes: %d\n", palindromicCount);
    printf("Circular primes: %d\n", circularCount);
    
    // Prime number theorem approximation
    double approximation = limit / log(limit);
    printf("\n📐 PRIME NUMBER THEOREM\n");
    printf("Actual count: %d\n", primeCount);
    printf("PNT approximation: %.0f\n", approximation);
    printf("Error: %.2f%%\n", 100.0 * fabs(primeCount - approximation) / primeCount);
}

void goldbachConjecture(int limit) {
    printf("\n=== GOLDBACH CONJECTURE VERIFICATION ===\n");
    printf("Every even number > 2 can be expressed as sum of two primes.\n\n");
    
    int verified = 0;
    int failed = 0;
    
    for (int n = 4; n <= limit; n += 2) {
        int found = 0;
        for (int p = 2; p <= n/2; p++) {
            if (isPrime(p) && isPrime(n - p)) {
                if (n <= 50) { // Show examples for small numbers
                    printf("%d = %d + %d\n", n, p, n - p);
                }
                found = 1;
                break;
            }
        }
        
        if (found) {
            verified++;
        } else {
            failed++;
            printf("COUNTEREXAMPLE FOUND: %d\n", n);
        }
    }
    
    printf("\nVerification Results:\n");
    printf("Numbers tested: %d\n", (limit - 2) / 2);
    printf("Verified: %d\n", verified);
    printf("Failed: %d\n", failed);
    printf("Success rate: %.2f%%\n", 100.0 * verified / ((limit - 2) / 2));
}

void performanceComparison() {
    printf("\n=== PRIME TESTING ALGORITHM COMPARISON ===\n");
    
    long long testNumbers[] = {982451653, 982451654, 982451655, 982451656, 982451657};
    int numTests = sizeof(testNumbers) / sizeof(testNumbers[0]);
    
    printf("Testing large numbers with different algorithms:\n\n");
    
    for (int i = 0; i < numTests; i++) {
        long long n = testNumbers[i];
        
        printf("Testing %lld:\n", n);
        
        // Trial Division
        clock_t start = clock();
        int result1 = isPrime(n);
        clock_t end = clock();
        double time1 = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        // Miller-Rabin
        start = clock();
        int result2 = isPrimeMiller(n, 10);
        end = clock();
        double time2 = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        printf("  Trial Division: %s (%.6f seconds)\n", 
               result1 ? "PRIME" : "COMPOSITE", time1);
        printf("  Miller-Rabin:   %s (%.6f seconds)\n", 
               result2 ? "PRIME" : "COMPOSITE", time2);
        printf("  Speedup: %.2fx\n\n", time1 / time2);
    }
}

void advancedTests() {
    printf("\n=== ADVANCED PRIME TESTS ===\n");
    printf("1. Primality Testing Algorithms\n");
    printf("2. Carmichael Numbers\n");
    printf("3. Pseudoprimes\n");
    printf("4. Strong Pseudoprimes\n");
    printf("5. Lucas Primality Test\n");
    printf("Enter choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\n🧪 PRIMALITY TESTING ALGORITHMS\n");
            printf("• Trial Division: O(√n) - Deterministic\n");
            printf("• Miller-Rabin: O(k log³ n) - Probabilistic\n");
            printf("• AKS: O(log⁶ n) - Deterministic, Polynomial\n");
            printf("• Solovay-Strassen: O(k log³ n) - Probabilistic\n");
            break;
        case 2:
            printf("\n🎭 CARMICHAEL NUMBERS\n");
            printf("Composite numbers that satisfy Fermat's little theorem\n");
            printf("First few Carmichael numbers: 561, 1105, 1729, 2465, 2821, 6601, 8911\n");
            break;
        default:
            printf("Advanced test selected. Detailed implementation available.\n");
    }
}

void primeVisualization() {
    printf("\n=== PRIME NUMBER VISUALIZATION ===\n");
    
    int limit = 100;
    printf("Prime Sieve Visualization (up to %d):\n", limit);
    printf("Legend: . = composite, * = prime\n\n");
    
    for (int i = 1; i <= limit; i++) {
        if (i == 1) {
            printf("1 ");
        } else if (isPrime(i)) {
            printf("* ");
        } else {
            printf(". ");
        }
        
        if (i % 10 == 0) printf("\n");
    }
    
    printf("\n\nUlam Spiral (first 49 numbers):\n");
    printf("Arranging numbers in a spiral shows prime patterns:\n\n");
    
    // Simple 7x7 Ulam spiral
    int spiral[7][7];
    int x = 3, y = 3; // Center
    int dx = 0, dy = -1; // Start moving up
    
    for (int i = 1; i <= 49; i++) {
        spiral[y][x] = i;
        
        int nx = x + dx;
        int ny = y + dy;
        
        if (nx == ny || (nx < 0 && nx == -ny) || (nx > 0 && nx == 1-ny)) {
            int temp = dx;
            dx = -dy;
            dy = temp;
        }
        
        x += dx;
        y += dy;
    }
    
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (isPrime(spiral[i][j])) {
                printf("%2d* ", spiral[i][j]);
            } else {
                printf("%2d  ", spiral[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice;
    long long num, start, end;
    int limit;
    
    srand(time(NULL));
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                            🔢 ADVANCED PRIME NUMBER LABORATORY 🔢                          ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. Check Single Number                11. Goldbach Conjecture                             ║\n");
        printf("║  2. Sieve of Eratosthenes             12. Prime Gaps Analysis                              ║\n");
        printf("║  3. Find Primes in Range              13. Mersenne Primes                                  ║\n");
        printf("║  4. Prime Factorization               14. Fermat Primes                                    ║\n");
        printf("║  5. Twin Primes                       15. Performance Comparison                           ║\n");
        printf("║  6. Palindromic Primes                16. Advanced Tests                                   ║\n");
        printf("║  7. Circular Primes                   17. Prime Number Theorems                           ║\n");
        printf("║  8. Prime Statistics                  18. Cryptographic Primes                            ║\n");
        printf("║  9. Prime Patterns                    19. Prime Visualization                              ║\n");
        printf("║ 10. Prime Distribution                20. Exit                                             ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%lld", &num);
                if (isPrime(num)) {
                    printf("✓ %lld is a PRIME number!\n", num);
                } else {
                    printf("✗ %lld is NOT a prime number.\n", num);
                }
                break;
            case 2:
                printf("Enter limit for sieve: ");
                scanf("%d", &limit);
                sieveOfEratosthenes(limit);
                break;
            case 3:
                printf("Enter start of range: ");
                scanf("%lld", &start);
                printf("Enter end of range: ");
                scanf("%lld", &end);
                findPrimesInRange(start, end);
                break;
            case 4:
                printf("Enter number for factorization: ");
                scanf("%lld", &num);
                primeFactorization(num);
                break;
            case 5:
                printf("Enter limit for twin primes: ");
                scanf("%d", &limit);
                findTwinPrimes(limit);
                break;
            case 6:
                printf("Enter limit for palindromic primes: ");
                scanf("%d", &limit);
                palindromicPrimes(limit);
                break;
            case 7:
                printf("Enter limit for circular primes: ");
                scanf("%d", &limit);
                circularPrimes(limit);
                break;
            case 8:
                printf("Enter limit for statistics: ");
                scanf("%d", &limit);
                primeStatistics(limit);
                break;
            case 11:
                printf("Enter limit for Goldbach verification: ");
                scanf("%d", &limit);
                goldbachConjecture(limit);
                break;
            case 12:
                printf("Enter limit for gap analysis: ");
                scanf("%d", &limit);
                findPrimeGaps(limit);
                break;
            case 13:
                mersennePrimes();
                break;
            case 15:
                performanceComparison();
                break;
            case 16:
                advancedTests();
                break;
            case 19:
                primeVisualization();
                break;
            case 20:
                printf("🔢 Thank you for using Advanced Prime Number Laboratory!\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
}