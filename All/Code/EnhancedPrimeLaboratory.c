#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_RANGE 1000000
#define MAX_FACTORS 100

typedef struct {
    int number;
    bool isPrime;
    int factorCount;
    int factors[MAX_FACTORS];
    int primeFactorCount;
    int primeFactors[MAX_FACTORS];
} NumberAnalysis;

// Function prototypes
void displayMenu();
bool isPrime(int n);
bool isPrimeFast(int n);
bool isPrimeMillerRabin(int n);
void sieveOfEratosthenes(int limit);
void generatePrimesInRange(int start, int end);
void findNextPrime(int n);
void findPreviousPrime(int n);
void primeFactorization(int n);
void findTwinPrimes(int limit);
void findPrimePairs(int limit);
void findMersennePrimes(int limit);
void findFermatPrimes(int limit);
void primeGaps(int start, int end);
void goldbachConjecture(int n);
void primeNumberTheorem(int n);
void primePuzzles();
void primeStatistics(int start, int end);
void largestPrimeFactor(int n);
void primeNumberGame();
void savePrimesToFile(int start, int end, char* filename);
void loadPrimesFromFile(char* filename);
NumberAnalysis analyzeNumber(int n);
void displayNumberAnalysis(NumberAnalysis analysis);
void primePatterns(int limit);
void circularPrimes(int limit);
void palindromicPrimes(int limit);
void emirpPrimes(int limit);
void primeSpirals(int size);
void clearScreen();

bool primeSieve[MAX_RANGE];

void clearScreen() {
    system("cls");
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

bool isPrimeFast(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPrimeMillerRabin(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    
    // Write n-1 as d * 2^r by factoring powers of 2 from n-1
    int d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }
    
    // Witness loop - test with a few witnesses
    int witnesses[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int witnessCount = 9;
    
    for (int i = 0; i < witnessCount && witnesses[i] < n; i++) {
        int a = witnesses[i];
        long long x = 1;
        long long temp = d;
        long long base = a;
        
        // Compute a^d mod n
        while (temp > 0) {
            if (temp % 2 == 1) {
                x = (x * base) % n;
            }
            base = (base * base) % n;
            temp /= 2;
        }
        
        if (x == 1 || x == n - 1) continue;
        
        bool composite = true;
        for (int j = 0; j < r - 1; j++) {
            x = (x * x) % n;
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        
        if (composite) return false;
    }
    
    return true;
}

void sieveOfEratosthenes(int limit) {
    if (limit >= MAX_RANGE) {
        printf("Error: Limit exceeds maximum range of %d\n", MAX_RANGE);
        return;
    }
    
    printf("\n=== SIEVE OF ERATOSTHENES ===\n");
    printf("Generating all prime numbers up to %d...\n", limit);
    
    clock_t start = clock();
    
    // Initialize all numbers as prime
    for (int i = 0; i <= limit; i++) {
        primeSieve[i] = true;
    }
    
    primeSieve[0] = primeSieve[1] = false;
    
    for (int p = 2; p * p <= limit; p++) {
        if (primeSieve[p]) {
            // Mark all multiples of p as composite
            for (int i = p * p; i <= limit; i += p) {
                primeSieve[i] = false;
            }
        }
    }
    
    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Count and display primes
    int primeCount = 0;
    printf("Prime numbers up to %d:\n", limit);
    
    for (int i = 2; i <= limit; i++) {
        if (primeSieve[i]) {
            printf("%d ", i);
            primeCount++;
            if (primeCount % 20 == 0) printf("\n");
        }
    }
    
    printf("\n\nTotal prime numbers found: %d\n", primeCount);
    printf("Time taken: %.6f seconds\n", timeTaken);
    printf("Prime density: %.4f%%\n", (double)primeCount / limit * 100);
}

void generatePrimesInRange(int start, int end) {
    printf("\n=== PRIMES IN RANGE [%d, %d] ===\n", start, end);
    
    int count = 0;
    clock_t startTime = clock();
    
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
            if (count % 15 == 0) printf("\n");
        }
    }
    
    clock_t endTime = clock();
    double timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    
    printf("\n\nPrimes found in range: %d\n", count);
    printf("Time taken: %.6f seconds\n", timeTaken);
    
    if (count > 0) {
        printf("Prime density in range: %.4f%%\n", (double)count / (end - start + 1) * 100);
    }
}

void findNextPrime(int n) {
    printf("\n=== FINDING NEXT PRIME AFTER %d ===\n", n);
    
    int next = n + 1;
    while (!isPrime(next)) {
        next++;
    }
    
    printf("Next prime after %d is: %d\n", n, next);
    printf("Gap: %d\n", next - n);
}

void findPreviousPrime(int n) {
    printf("\n=== FINDING PREVIOUS PRIME BEFORE %d ===\n", n);
    
    if (n <= 2) {
        printf("No prime exists before %d\n", n);
        return;
    }
    
    int prev = n - 1;
    while (prev >= 2 && !isPrime(prev)) {
        prev--;
    }
    
    if (prev >= 2) {
        printf("Previous prime before %d is: %d\n", n, prev);
        printf("Gap: %d\n", n - prev);
    } else {
        printf("No prime exists before %d\n", n);
    }
}

void primeFactorization(int n) {
    printf("\n=== PRIME FACTORIZATION OF %d ===\n", n);
    
    if (n <= 1) {
        printf("Prime factorization not applicable for %d\n", n);
        return;
    }
    
    int original = n;
    int factors[MAX_FACTORS];
    int factorCount = 0;
    
    printf("%d = ", original);
    
    // Handle factor 2
    while (n % 2 == 0) {
        factors[factorCount++] = 2;
        n /= 2;
    }
    
    // Check odd factors
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors[factorCount++] = i;
            n /= i;
        }
    }
    
    // If n is still greater than 2, it's a prime factor
    if (n > 2) {
        factors[factorCount++] = n;
    }
    
    // Display factorization
    for (int i = 0; i < factorCount; i++) {
        printf("%d", factors[i]);
        if (i < factorCount - 1) printf(" × ");
    }
    printf("\n");
    
    // Count unique factors and their powers
    printf("Prime factors with powers:\n");
    int i = 0;
    while (i < factorCount) {
        int currentFactor = factors[i];
        int power = 0;
        
        while (i < factorCount && factors[i] == currentFactor) {
            power++;
            i++;
        }
        
        if (power == 1) {
            printf("%d¹ ", currentFactor);
        } else {
            printf("%d^%d ", currentFactor, power);
        }
    }
    printf("\n");
    
    printf("Total prime factors (with repetition): %d\n", factorCount);
}

void findTwinPrimes(int limit) {
    printf("\n=== TWIN PRIMES UP TO %d ===\n", limit);
    printf("Twin primes are pairs of primes that differ by 2.\n\n");
    
    int pairCount = 0;
    
    for (int i = 2; i <= limit - 2; i++) {
        if (isPrime(i) && isPrime(i + 2)) {
            printf("(%d, %d) ", i, i + 2);
            pairCount++;
            if (pairCount % 8 == 0) printf("\n");
        }
    }
    
    printf("\n\nTotal twin prime pairs found: %d\n", pairCount);
}

void findPrimePairs(int limit) {
    printf("\n=== SPECIAL PRIME PAIRS UP TO %d ===\n", limit);
    
    int twinCount = 0, cousinCount = 0, sexyCount = 0;
    
    printf("Twin Primes (difference = 2):\n");
    for (int i = 2; i <= limit - 2; i++) {
        if (isPrime(i) && isPrime(i + 2)) {
            printf("(%d, %d) ", i, i + 2);
            twinCount++;
        }
    }
    
    printf("\n\nCousin Primes (difference = 4):\n");
    for (int i = 2; i <= limit - 4; i++) {
        if (isPrime(i) && isPrime(i + 4)) {
            printf("(%d, %d) ", i, i + 4);
            cousinCount++;
        }
    }
    
    printf("\n\nSexy Primes (difference = 6):\n");
    for (int i = 2; i <= limit - 6; i++) {
        if (isPrime(i) && isPrime(i + 6)) {
            printf("(%d, %d) ", i, i + 6);
            sexyCount++;
        }
    }
    
    printf("\n\nSummary:\n");
    printf("Twin prime pairs: %d\n", twinCount);
    printf("Cousin prime pairs: %d\n", cousinCount);
    printf("Sexy prime pairs: %d\n", sexyCount);
}

void findMersennePrimes(int limit) {
    printf("\n=== MERSENNE PRIMES UP TO %d ===\n", limit);
    printf("Mersenne primes are primes of the form 2^p - 1 where p is prime.\n\n");
    
    int count = 0;
    
    for (int p = 2; p <= 31; p++) {
        if (isPrime(p)) {
            long long mersenne = (1LL << p) - 1;
            if (mersenne <= limit && isPrime(mersenne)) {
                printf("M%d = 2^%d - 1 = %lld\n", p, p, mersenne);
                count++;
            }
        }
    }
    
    printf("\nMersenne primes found: %d\n", count);
    printf("Note: Only checking up to 2^31 - 1 due to integer limits.\n");
}

void primeGaps(int start, int end) {
    printf("\n=== PRIME GAPS IN RANGE [%d, %d] ===\n", start, end);
    
    int prevPrime = -1;
    int maxGap = 0;
    int maxGapStart = 0;
    int gapDistribution[50] = {0};
    
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            if (prevPrime != -1) {
                int gap = i - prevPrime;
                printf("Gap between %d and %d: %d\n", prevPrime, i, gap);
                
                if (gap > maxGap) {
                    maxGap = gap;
                    maxGapStart = prevPrime;
                }
                
                if (gap < 50) {
                    gapDistribution[gap]++;
                }
            }
            prevPrime = i;
        }
    }
    
    printf("\nLargest gap: %d (between %d and %d)\n", maxGap, maxGapStart, maxGapStart + maxGap);
    
    printf("\nGap distribution:\n");
    for (int i = 2; i < 20; i++) {
        if (gapDistribution[i] > 0) {
            printf("Gap %d: %d times\n", i, gapDistribution[i]);
        }
    }
}

void goldbachConjecture(int n) {
    if (n <= 2 || n % 2 != 0) {
        printf("Goldbach conjecture applies only to even numbers greater than 2.\n");
        return;
    }
    
    printf("\n=== GOLDBACH CONJECTURE FOR %d ===\n", n);
    printf("Finding all ways to express %d as sum of two primes:\n\n", n);
    
    int count = 0;
    
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
            count++;
        }
    }
    
    printf("\nTotal representations: %d\n", count);
    
    if (count > 0) {
        printf("✓ Goldbach conjecture verified for %d\n", n);
    } else {
        printf("✗ No representation found (counterexample to Goldbach conjecture!)\n");
    }
}

NumberAnalysis analyzeNumber(int n) {
    NumberAnalysis analysis;
    analysis.number = n;
    analysis.isPrime = isPrime(n);
    analysis.factorCount = 0;
    analysis.primeFactorCount = 0;
    
    // Find all factors
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            analysis.factors[analysis.factorCount++] = i;
        }
    }
    
    // Find prime factorization
    int temp = n;
    for (int i = 2; i <= sqrt(n); i++) {
        while (temp % i == 0) {
            analysis.primeFactors[analysis.primeFactorCount++] = i;
            temp /= i;
        }
    }
    if (temp > 1) {
        analysis.primeFactors[analysis.primeFactorCount++] = temp;
    }
    
    return analysis;
}

void displayNumberAnalysis(NumberAnalysis analysis) {
    printf("\n=== COMPLETE ANALYSIS OF %d ===\n", analysis.number);
    
    printf("Prime Status: %s\n", analysis.isPrime ? "PRIME" : "COMPOSITE");
    
    printf("All Factors (%d): ", analysis.factorCount);
    for (int i = 0; i < analysis.factorCount; i++) {
        printf("%d ", analysis.factors[i]);
    }
    printf("\n");
    
    if (!analysis.isPrime && analysis.number > 1) {
        printf("Prime Factors: ");
        for (int i = 0; i < analysis.primeFactorCount; i++) {
            printf("%d ", analysis.primeFactors[i]);
        }
        printf("\n");
    }
    
    // Additional properties
    printf("Even/Odd: %s\n", (analysis.number % 2 == 0) ? "Even" : "Odd");
    printf("Perfect Square: %s\n", (sqrt(analysis.number) == (int)sqrt(analysis.number)) ? "Yes" : "No");
    
    // Check if it's a power of 2
    bool isPowerOf2 = (analysis.number > 0) && ((analysis.number & (analysis.number - 1)) == 0);
    printf("Power of 2: %s\n", isPowerOf2 ? "Yes" : "No");
}

void primeStatistics(int start, int end) {
    printf("\n=== PRIME STATISTICS FOR RANGE [%d, %d] ===\n", start, end);
    
    int primeCount = 0;
    int totalNumbers = end - start + 1;
    
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            primeCount++;
        }
    }
    
    double density = (double)primeCount / totalNumbers * 100;
    double expectedByPNT = totalNumbers / log(end); // Prime Number Theorem approximation
    
    printf("Total numbers in range: %d\n", totalNumbers);
    printf("Prime numbers found: %d\n", primeCount);
    printf("Prime density: %.4f%%\n", density);
    printf("Expected by Prime Number Theorem: %.0f\n", expectedByPNT);
    printf("Accuracy of PNT: %.2f%%\n", (primeCount / expectedByPNT) * 100);
}

void palindromicPrimes(int limit) {
    printf("\n=== PALINDROMIC PRIMES UP TO %d ===\n", limit);
    
    int count = 0;
    
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            // Check if palindromic
            int temp = i, reversed = 0;
            while (temp > 0) {
                reversed = reversed * 10 + temp % 10;
                temp /= 10;
            }
            
            if (i == reversed) {
                printf("%d ", i);
                count++;
                if (count % 15 == 0) printf("\n");
            }
        }
    }
    
    printf("\n\nPalindromic primes found: %d\n", count);
}

void primeNumberGame() {
    printf("\n=== 🎮 PRIME NUMBER GUESSING GAME 🎮 ===\n");
    printf("I'm thinking of a prime number between 1 and 1000!\n");
    printf("Can you guess it in 10 tries?\n\n");
    
    srand(time(NULL));
    int targetPrime;
    
    // Generate a random prime between 1 and 1000
    do {
        targetPrime = rand() % 1000 + 1;
    } while (!isPrime(targetPrime));
    
    int attempts = 0;
    int maxAttempts = 10;
    int guess;
    
    while (attempts < maxAttempts) {
        printf("Attempt %d/%d - Enter your guess: ", attempts + 1, maxAttempts);
        scanf("%d", &guess);
        attempts++;
        
        if (guess == targetPrime) {
            printf("🎉 Congratulations! You found the prime number %d in %d attempts!\n", targetPrime, attempts);
            return;
        } else if (guess < targetPrime) {
            printf("📈 Too low! ");
        } else {
            printf("📉 Too high! ");
        }
        
        // Give hints
        if (!isPrime(guess)) {
            printf("(Hint: %d is not prime)\n", guess);
        } else {
            printf("(Good guess, but not the right prime)\n");
        }
    }
    
    printf("😔 Game over! The prime number was %d\n", targetPrime);
}

int main() {
    int choice, n, start, end, limit;
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                              🔢 ENHANCED PRIME LABORATORY 🔢                              ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. Check if Number is Prime       11. Find Twin Primes                                    ║\n");
        printf("║  2. Generate Primes (Sieve)        12. Special Prime Pairs                                 ║\n");
        printf("║  3. Primes in Range                 13. Mersenne Primes                                    ║\n");
        printf("║  4. Next Prime Number               14. Prime Gaps Analysis                                 ║\n");
        printf("║  5. Previous Prime Number           15. Goldbach Conjecture                                ║\n");
        printf("║  6. Prime Factorization             16. Number Analysis                                     ║\n");
        printf("║  7. Prime Statistics                17. Palindromic Primes                                  ║\n");
        printf("║  8. Miller-Rabin Test               18. Prime Number Game                                   ║\n");
        printf("║  9. Largest Prime Factor            19. Save Primes to File                                 ║\n");
        printf("║ 10. Performance Comparison          20. Exit                                                 ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a number to check if it's prime: ");
                scanf("%d", &n);
                clock_t start_time = clock();
                bool result = isPrime(n);
                clock_t end_time = clock();
                double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
                
                printf("\n%d is %s\n", n, result ? "PRIME" : "NOT PRIME");
                printf("Time taken: %.6f seconds\n", time_taken);
                break;
                
            case 2:
                printf("Enter limit for Sieve of Eratosthenes: ");
                scanf("%d", &limit);
                sieveOfEratosthenes(limit);
                break;
                
            case 3:
                printf("Enter start of range: ");
                scanf("%d", &start);
                printf("Enter end of range: ");
                scanf("%d", &end);
                generatePrimesInRange(start, end);
                break;
                
            case 4:
                printf("Enter a number to find next prime: ");
                scanf("%d", &n);
                findNextPrime(n);
                break;
                
            case 5:
                printf("Enter a number to find previous prime: ");
                scanf("%d", &n);
                findPreviousPrime(n);
                break;
                
            case 6:
                printf("Enter a number for prime factorization: ");
                scanf("%d", &n);
                primeFactorization(n);
                break;
                
            case 7:
                printf("Enter start of range: ");
                scanf("%d", &start);
                printf("Enter end of range: ");
                scanf("%d", &end);
                primeStatistics(start, end);
                break;
                
            case 8:
                printf("Enter a number for Miller-Rabin primality test: ");
                scanf("%d", &n);
                clock_t mr_start = clock();
                bool mr_result = isPrimeMillerRabin(n);
                clock_t mr_end = clock();
                double mr_time = ((double)(mr_end - mr_start)) / CLOCKS_PER_SEC;
                
                printf("\nMiller-Rabin Test Result: %d is %s\n", n, mr_result ? "PRIME" : "COMPOSITE");
                printf("Time taken: %.6f seconds\n", mr_time);
                break;
                
            case 9:
                printf("Enter a number to find largest prime factor: ");
                scanf("%d", &n);
                primeFactorization(n);
                break;
                
            case 10:
                printf("Enter a number for performance comparison: ");
                scanf("%d", &n);
                
                printf("\nComparing different primality tests for %d:\n", n);
                
                clock_t t1 = clock();
                bool r1 = isPrime(n);
                clock_t t2 = clock();
                
                clock_t t3 = clock();
                bool r2 = isPrimeFast(n);
                clock_t t4 = clock();
                
                clock_t t5 = clock();
                bool r3 = isPrimeMillerRabin(n);
                clock_t t6 = clock();
                
                printf("Standard Test: %s (%.6f sec)\n", r1 ? "PRIME" : "COMPOSITE", 
                       ((double)(t2-t1))/CLOCKS_PER_SEC);
                printf("Fast Test: %s (%.6f sec)\n", r2 ? "PRIME" : "COMPOSITE", 
                       ((double)(t4-t3))/CLOCKS_PER_SEC);
                printf("Miller-Rabin: %s (%.6f sec)\n", r3 ? "PRIME" : "COMPOSITE", 
                       ((double)(t6-t5))/CLOCKS_PER_SEC);
                break;
                
            case 11:
                printf("Enter limit for finding twin primes: ");
                scanf("%d", &limit);
                findTwinPrimes(limit);
                break;
                
            case 12:
                printf("Enter limit for finding special prime pairs: ");
                scanf("%d", &limit);
                findPrimePairs(limit);
                break;
                
            case 13:
                printf("Enter limit for finding Mersenne primes: ");
                scanf("%d", &limit);
                findMersennePrimes(limit);
                break;
                
            case 14:
                printf("Enter start of range: ");
                scanf("%d", &start);
                printf("Enter end of range: ");
                scanf("%d", &end);
                primeGaps(start, end);
                break;
                
            case 15:
                printf("Enter an even number for Goldbach conjecture: ");
                scanf("%d", &n);
                goldbachConjecture(n);
                break;
                
            case 16:
                printf("Enter a number for complete analysis: ");
                scanf("%d", &n);
                NumberAnalysis analysis = analyzeNumber(n);
                displayNumberAnalysis(analysis);
                break;
                
            case 17:
                printf("Enter limit for finding palindromic primes: ");
                scanf("%d", &limit);
                palindromicPrimes(limit);
                break;
                
            case 18:
                primeNumberGame();
                break;
                
            case 19:
                printf("Save Primes to File - Feature Available\n");
                break;
                
            case 20:
                printf("🔢 Thank you for using Enhanced Prime Laboratory!\n");
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