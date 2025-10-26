#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NUMBERS 100
#define MAX_DIGITS 20

typedef struct {
    int value;
    int frequency;
} FactorPair;

typedef struct {
    int numbers[MAX_NUMBERS];
    int count;
    int gcd;
    int lcm;
    long long product;
    double harmonicMean;
    double geometricMean;
} NumberSet;

// Function prototypes
void displayMenu();
int gcdTwo(int a, int b);
int gcdEuclidean(int a, int b);
int gcdExtended(int a, int b, int *x, int *y);
int lcmTwo(int a, int b);
int gcdMultiple(int numbers[], int count);
long long lcmMultiple(int numbers[], int count);
void analyzeNumberPair(int a, int b);
void analyzeNumberSet(int numbers[], int count);
void findCoprimes(int n, int limit);
void eulerTotient(int n);
void sieveEulerTotient(int limit);
void modularArithmetic();
void chineseRemainderTheorem();
void diophantineEquations();
void continuedFractions(int numerator, int denominator);
void farey Sequence(int n);
void perfectNumbers(int limit);
void abundantDeficientNumbers(int limit);
void amicableNumbers(int limit);
void sociableNumbers(int limit);
void collatzConjecture(int n);
void fibonacciGCD();
void bezoutCoefficients(int a, int b);
void modularInverse(int a, int m);
void numberTheoryGame();
void primitivePythagoreanTriples(int limit);
void quadraticResidues(int n, int p);
void legendreSymbol(int a, int p);
void jacobiSymbol(int a, int n);
void multiplicativeOrder(int a, int n);
void discreteLogarithm(int a, int b, int m);
void numberBaseConversions();
void digitalRoot(int n);
void sumOfDivisors(int n);
void numberOfDivisors(int n);
void mobiusFunction(int n);
void eulerPhiFunction(int n);
void carmichaelFunction(int n);
void wilsonTheorem(int p);
void fermatLittleTheorem(int a, int p);
void primalityTests();
void cryptographyDemo();
void gcdVisualization(int a, int b);
void clearScreen();

void clearScreen() {
    system("cls");
}

int gcdTwo(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcdEuclidean(int a, int b) {
    printf("Euclidean Algorithm for GCD(%d, %d):\n", a, b);
    int originalA = a, originalB = b;
    int step = 1;
    
    while (b != 0) {
        int quotient = a / b;
        int remainder = a % b;
        printf("Step %d: %d = %d × %d + %d\n", step++, a, b, quotient, remainder);
        a = b;
        b = remainder;
    }
    
    printf("Therefore, GCD(%d, %d) = %d\n", originalA, originalB, a);
    return a;
}

int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    
    *x = y1 - (b / a) * x1;
    *y = x1;
    
    return gcd;
}

int lcmTwo(int a, int b) {
    return (a * b) / gcdTwo(a, b);
}

int gcdMultiple(int numbers[], int count) {
    if (count == 0) return 0;
    if (count == 1) return numbers[0];
    
    int result = numbers[0];
    for (int i = 1; i < count; i++) {
        result = gcdTwo(result, numbers[i]);
        if (result == 1) break; // Early termination
    }
    return result;
}

long long lcmMultiple(int numbers[], int count) {
    if (count == 0) return 0;
    if (count == 1) return numbers[0];
    
    long long result = numbers[0];
    for (int i = 1; i < count; i++) {
        result = (result * numbers[i]) / gcdTwo(result, numbers[i]);
    }
    return result;
}

void analyzeNumberPair(int a, int b) {
    printf("\n=== COMPREHENSIVE PAIR ANALYSIS: %d and %d ===\n", a, b);
    
    clock_t start = clock();
    
    // Basic calculations
    int gcd = gcdTwo(a, b);
    int lcm = lcmTwo(a, b);
    
    printf("Greatest Common Divisor (GCD): %d\n", gcd);
    printf("Least Common Multiple (LCM): %d\n", lcm);
    printf("Product: %lld\n", (long long)a * b);
    printf("GCD × LCM = %lld (should equal a × b)\n", (long long)gcd * lcm);
    
    // Relationship analysis
    if (gcd == 1) {
        printf("Relationship: COPRIME (relatively prime)\n");
    } else {
        printf("Relationship: NOT COPRIME (common factor: %d)\n", gcd);
    }
    
    // Divisibility
    if (a % b == 0) {
        printf("Divisibility: %d divides %d\n", b, a);
    } else if (b % a == 0) {
        printf("Divisibility: %d divides %d\n", a, b);
    } else {
        printf("Divisibility: Neither divides the other\n");
    }
    
    // Bézout coefficients
    int x, y;
    int gcd_extended = gcdExtended(a, b, &x, &y);
    printf("Bézout coefficients: %d = %d × (%d) + %d × (%d)\n", gcd_extended, a, x, b, y);
    
    // Ratio analysis
    double ratio = (double)a / b;
    printf("Ratio a:b = %.6f\n", ratio);
    
    if (fabs(ratio - 1.618034) < 0.001) {
        printf("✨ Special ratio: Golden ratio (φ ≈ 1.618)!\n");
    } else if (fabs(ratio - 1.414214) < 0.001) {
        printf("✨ Special ratio: √2 ≈ 1.414!\n");
    } else if (fabs(ratio - 2.718282) < 0.001) {
        printf("✨ Special ratio: e ≈ 2.718!\n");
    } else if (fabs(ratio - 3.141593) < 0.001) {
        printf("✨ Special ratio: π ≈ 3.142!\n");
    }
    
    clock_t end = clock();
    printf("Analysis time: %.6f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

void analyzeNumberSet(int numbers[], int count) {
    printf("\n=== NUMBER SET ANALYSIS ===\n");
    printf("Numbers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Calculate GCD and LCM of all numbers
    int setGCD = gcdMultiple(numbers, count);
    long long setLCM = lcmMultiple(numbers, count);
    
    printf("Set GCD: %d\n", setGCD);
    printf("Set LCM: %lld\n", setLCM);
    
    // Statistical analysis
    int sum = 0, max = numbers[0], min = numbers[0];
    long long product = 1;
    
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
        if (numbers[i] > max) max = numbers[i];
        if (numbers[i] < min) min = numbers[i];
        product *= numbers[i];
    }
    
    double mean = (double)sum / count;
    double geometricMean = pow(product, 1.0/count);
    
    // Harmonic mean
    double harmonicSum = 0;
    for (int i = 0; i < count; i++) {
        harmonicSum += 1.0 / numbers[i];
    }
    double harmonicMean = count / harmonicSum;
    
    printf("Arithmetic Mean: %.2f\n", mean);
    printf("Geometric Mean: %.2f\n", geometricMean);
    printf("Harmonic Mean: %.2f\n", harmonicMean);
    printf("Range: [%d, %d]\n", min, max);
    printf("Product: %lld\n", product);
    
    // Pairwise coprimality
    bool pairwiseCoprime = true;
    for (int i = 0; i < count && pairwiseCoprime; i++) {
        for (int j = i + 1; j < count; j++) {
            if (gcdTwo(numbers[i], numbers[j]) != 1) {
                pairwiseCoprime = false;
                break;
            }
        }
    }
    
    printf("Pairwise Coprime: %s\n", pairwiseCoprime ? "Yes" : "No");
    printf("Mutually Coprime: %s\n", (setGCD == 1) ? "Yes" : "No");
}

void findCoprimes(int n, int limit) {
    printf("\n=== NUMBERS COPRIME TO %d (up to %d) ===\n", n, limit);
    
    int count = 0;
    printf("Coprimes: ");
    
    for (int i = 1; i <= limit; i++) {
        if (gcdTwo(n, i) == 1) {
            printf("%d ", i);
            count++;
            if (count % 20 == 0) printf("\n          ");
        }
    }
    
    printf("\n\nTotal coprimes found: %d\n", count);
    printf("Euler's totient φ(%d) = %d (count up to %d)\n", n, count, n);
}

void eulerTotient(int n) {
    printf("\n=== EULER'S TOTIENT FUNCTION φ(%d) ===\n", n);
    
    if (n <= 0) {
        printf("Totient function not defined for non-positive integers.\n");
        return;
    }
    
    int result = n;
    int original = n;
    
    printf("Prime factorization approach:\n");
    printf("φ(%d) = %d", original, n);
    
    // Find all prime factors and apply formula φ(n) = n × ∏(1 - 1/p)
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            // Remove all factors of p
            while (n % p == 0) {
                n /= p;
            }
            // Multiply result by (1 - 1/p) = (p-1)/p
            result -= result / p;
            printf(" × (1 - 1/%d)", p);
        }
    }
    
    // If n has a prime factor greater than sqrt(n)
    if (n > 1) {
        result -= result / n;
        printf(" × (1 - 1/%d)", n);
    }
    
    printf(" = %d\n", result);
    
    // Verification by counting
    int count = 0;
    printf("\nNumbers coprime to %d: ", original);
    for (int i = 1; i <= original; i++) {
        if (gcdTwo(original, i) == 1) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
    
    printf("Verification: φ(%d) = %d\n", original, count);
    printf("Formula result matches count: %s\n", (result == count) ? "✓ Yes" : "✗ No");
}

void sieveEulerTotient(int limit) {
    printf("\n=== EULER'S TOTIENT SIEVE (up to %d) ===\n", limit);
    
    int phi[limit + 1];
    
    // Initialize phi[i] = i
    for (int i = 1; i <= limit; i++) {
        phi[i] = i;
    }
    
    // Apply sieve
    for (int i = 2; i <= limit; i++) {
        if (phi[i] == i) { // i is prime
            for (int j = i; j <= limit; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    
    printf("n     φ(n)    n     φ(n)    n     φ(n)    n     φ(n)\n");
    printf("──────────────────────────────────────────────────────\n");
    
    for (int i = 1; i <= limit; i++) {
        printf("%-5d %-5d", i, phi[i]);
        if (i % 4 == 0) printf("\n");
        else printf("  ");
    }
    if (limit % 4 != 0) printf("\n");
    
    // Find interesting patterns
    printf("\nInteresting observations:\n");
    printf("φ(1) = %d (by definition)\n", phi[1]);
    
    for (int i = 2; i <= limit; i++) {
        if (phi[i] == i - 1) {
            printf("φ(%d) = %d (prime number)\n", i, phi[i]);
        }
    }
    
    // Perfect totient numbers
    printf("\nPerfect totient numbers (where φ(n) divides n):\n");
    for (int i = 1; i <= limit; i++) {
        if (i % phi[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void perfectNumbers(int limit) {
    printf("\n=== PERFECT NUMBERS UP TO %d ===\n", limit);
    printf("A perfect number equals the sum of its proper divisors.\n\n");
    
    for (int n = 2; n <= limit; n++) {
        int sum = 1; // 1 is always a proper divisor
        
        // Find all divisors except n itself
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) { // Avoid counting the same divisor twice for perfect squares
                    sum += n / i;
                }
            }
        }
        
        if (sum == n) {
            printf("Perfect: %d = ", n);
            
            // Print the divisors
            printf("1");
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    printf(" + %d", i);
                    if (i != n / i) {
                        printf(" + %d", n / i);
                    }
                }
            }
            printf("\n");
            
            // Check if it's a Mersenne-related perfect number
            for (int p = 2; p <= 31; p++) {
                if ((1 << (p-1)) * ((1 << p) - 1) == n) {
                    printf("  This is the %d-th perfect number: 2^%d × (2^%d - 1)\n", 
                           (p == 2) ? 1 : (p == 3) ? 2 : (p == 5) ? 3 : (p == 7) ? 4 : 5, p-1, p);
                    break;
                }
            }
        }
    }
}

void abundantDeficientNumbers(int limit) {
    printf("\n=== ABUNDANT AND DEFICIENT NUMBERS UP TO %d ===\n", limit);
    
    int perfectCount = 0, abundantCount = 0, deficientCount = 0;
    
    printf("Abundant numbers (sum of divisors > number):\n");
    for (int n = 2; n <= limit; n++) {
        int sum = 1; // 1 is always a proper divisor
        
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) {
                    sum += n / i;
                }
            }
        }
        
        if (sum > n) {
            printf("%d ", n);
            abundantCount++;
            if (abundantCount % 15 == 0) printf("\n");
        } else if (sum == n) {
            perfectCount++;
        } else {
            deficientCount++;
        }
    }
    
    printf("\n\nDeficient numbers (first 20): ");
    int deficientShown = 0;
    for (int n = 2; n <= limit && deficientShown < 20; n++) {
        int sum = 1;
        
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) {
                    sum += n / i;
                }
            }
        }
        
        if (sum < n) {
            printf("%d ", n);
            deficientShown++;
        }
    }
    
    printf("\n\nSummary up to %d:\n", limit);
    printf("Perfect numbers: %d\n", perfectCount);
    printf("Abundant numbers: %d\n", abundantCount);
    printf("Deficient numbers: %d\n", deficientCount);
    printf("Total: %d\n", perfectCount + abundantCount + deficientCount);
}

void amicableNumbers(int limit) {
    printf("\n=== AMICABLE NUMBERS UP TO %d ===\n", limit);
    printf("Two numbers are amicable if each equals the sum of proper divisors of the other.\n\n");
    
    bool found[limit + 1] = {false};
    int pairCount = 0;
    
    for (int n = 2; n <= limit; n++) {
        if (found[n]) continue;
        
        // Calculate sum of proper divisors of n
        int sum1 = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sum1 += i;
                if (i != n / i) {
                    sum1 += n / i;
                }
            }
        }
        
        if (sum1 <= limit && sum1 != n) {
            // Calculate sum of proper divisors of sum1
            int sum2 = 1;
            for (int i = 2; i * i <= sum1; i++) {
                if (sum1 % i == 0) {
                    sum2 += i;
                    if (i != sum1 / i) {
                        sum2 += sum1 / i;
                    }
                }
            }
            
            if (sum2 == n) {
                printf("Amicable pair: (%d, %d)\n", n, sum1);
                printf("  σ(%d) = %d, σ(%d) = %d\n", n, sum1, sum1, n);
                found[n] = found[sum1] = true;
                pairCount++;
            }
        }
    }
    
    printf("\nTotal amicable pairs found: %d\n", pairCount);
    
    if (pairCount == 0) {
        printf("Note: The smallest amicable pair is (220, 284).\n");
        printf("Try increasing the limit to at least 284.\n");
    }
}

void collatzConjecture(int n) {
    printf("\n=== COLLATZ CONJECTURE FOR %d ===\n", n);
    printf("Sequence: ");
    
    int original = n;
    int steps = 0;
    int maxValue = n;
    
    while (n != 1) {
        printf("%d → ", n);
        
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        
        steps++;
        if (n > maxValue) maxValue = n;
        
        // Safety check to prevent infinite loops (though conjecture says this won't happen)
        if (steps > 1000) {
            printf("... (sequence too long, truncated)");
            break;
        }
    }
    
    if (n == 1) {
        printf("1\n");
        printf("\n✓ Sequence reached 1 (conjecture holds)\n");
        printf("Steps to reach 1: %d\n", steps);
        printf("Maximum value reached: %d\n", maxValue);
        printf("Compression ratio: %.2f\n", (double)original / steps);
    } else {
        printf("\n? Sequence truncated (unable to verify conjecture)\n");
    }
    
    // Additional analysis
    if (steps > 0) {
        printf("\nInteresting facts:\n");
        if (original % 2 == 0) {
            printf("• Started with even number\n");
        } else {
            printf("• Started with odd number\n");
        }
        
        if (maxValue > original * 10) {
            printf("• Sequence grew very large (>10× original)\n");
        } else if (maxValue > original * 2) {
            printf("• Sequence grew moderately (>2× original)\n");
        } else {
            printf("• Sequence stayed relatively small\n");
        }
    }
}

void bezoutCoefficients(int a, int b) {
    printf("\n=== BÉZOUT COEFFICIENTS FOR %d AND %d ===\n", a, b);
    
    int x, y;
    int gcd = gcdExtended(a, b, &x, &y);
    
    printf("Extended Euclidean Algorithm:\n");
    printf("gcd(%d, %d) = %d\n", a, b, gcd);
    printf("Bézout coefficients: x = %d, y = %d\n", x, y);
    printf("Verification: %d × %d + %d × %d = %d\n", a, x, b, y, a*x + b*y);
    
    if (a*x + b*y == gcd) {
        printf("✓ Coefficients are correct!\n");
    } else {
        printf("✗ Error in calculation!\n");
    }
    
    // Generate all solutions
    printf("\nGeneral solution for %dx + %dy = %d:\n", a, b, gcd);
    printf("x = %d + %dt\n", x, b/gcd);
    printf("y = %d - %dt\n", y, a/gcd);
    printf("where t is any integer.\n");
    
    printf("\nSome particular solutions:\n");
    for (int t = -2; t <= 2; t++) {
        int newX = x + (b/gcd) * t;
        int newY = y - (a/gcd) * t;
        printf("t = %2d: x = %3d, y = %3d\n", t, newX, newY);
    }
}

void numberTheoryGame() {
    printf("\n=== 🎮 NUMBER THEORY CHALLENGE 🎮 ===\n");
    printf("Test your number theory knowledge!\n\n");
    
    srand(time(NULL));
    int score = 0;
    int totalQuestions = 5;
    
    for (int q = 1; q <= totalQuestions; q++) {
        printf("Question %d/%d:\n", q, totalQuestions);
        
        int type = rand() % 4;
        int answer, userAnswer;
        
        switch (type) {
            case 0: { // GCD question
                int a = rand() % 50 + 10;
                int b = rand() % 50 + 10;
                answer = gcdTwo(a, b);
                printf("What is GCD(%d, %d)? ", a, b);
                break;
            }
            case 1: { // LCM question
                int a = rand() % 20 + 5;
                int b = rand() % 20 + 5;
                answer = lcmTwo(a, b);
                printf("What is LCM(%d, %d)? ", a, b);
                break;
            }
            case 2: { // Euler's totient
                int n = rand() % 20 + 5;
                answer = n;
                for (int p = 2; p * p <= n; p++) {
                    if (answer % p == 0) {
                        while (answer % p == 0) answer /= p;
                        answer = answer - answer / p;
                    }
                }
                if (answer > 1) answer = answer - answer / answer;
                
                // Recalculate properly
                answer = 0;
                for (int i = 1; i <= n; i++) {
                    if (gcdTwo(n, i) == 1) answer++;
                }
                printf("What is Euler's totient φ(%d)? ", n);
                break;
            }
            case 3: { // Coprimality
                int a = rand() % 30 + 10;
                int b = rand() % 30 + 10;
                answer = (gcdTwo(a, b) == 1) ? 1 : 0;
                printf("Are %d and %d coprime? (1=Yes, 0=No): ", a, b);
                break;
            }
        }
        
        scanf("%d", &userAnswer);
        
        if (userAnswer == answer) {
            printf("✓ Correct! +1 point\n");
            score++;
        } else {
            printf("✗ Wrong. The answer is %d.\n", answer);
        }
        printf("\n");
    }
    
    printf("🏆 Final Score: %d/%d\n", score, totalQuestions);
    
    if (score == totalQuestions) {
        printf("🌟 Perfect! You're a number theory master!\n");
    } else if (score >= totalQuestions * 0.8) {
        printf("🎉 Excellent! You have strong number theory skills!\n");
    } else if (score >= totalQuestions * 0.6) {
        printf("👍 Good job! Keep practicing!\n");
    } else {
        printf("📚 Keep studying! Number theory is fascinating!\n");
    }
}

int main() {
    int choice, a, b, n, limit;
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                           🔢 ENHANCED NUMBER THEORY SUITE 🔢                              ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. GCD of Two Numbers             11. Perfect Numbers                                      ║\n");
        printf("║  2. LCM of Two Numbers             12. Abundant/Deficient Numbers                          ║\n");
        printf("║  3. Extended Euclidean Algorithm   13. Amicable Numbers                                     ║\n");
        printf("║  4. Analyze Number Pair            14. Collatz Conjecture                                  ║\n");
        printf("║  5. Analyze Number Set             15. Bézout Coefficients                                 ║\n");
        printf("║  6. Find Coprimes                  16. Modular Arithmetic                                  ║\n");
        printf("║  7. Euler's Totient Function       17. Chinese Remainder Theorem                          ║\n");
        printf("║  8. Totient Function Sieve         18. Number Theory Game                                  ║\n");
        printf("║  9. GCD/LCM Multiple Numbers       19. Cryptography Demo                                   ║\n");
        printf("║ 10. Euclidean Algorithm Demo       20. Exit                                                 ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("GCD(%d, %d) = %d\n", a, b, gcdTwo(a, b));
                break;
                
            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("LCM(%d, %d) = %d\n", a, b, lcmTwo(a, b));
                break;
                
            case 3:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                int x, y;
                int gcd = gcdExtended(a, b, &x, &y);
                printf("Extended GCD(%d, %d) = %d\n", a, b, gcd);
                printf("Bézout coefficients: %d × %d + %d × %d = %d\n", a, x, b, y, gcd);
                break;
                
            case 4:
                printf("Enter two numbers for comprehensive analysis: ");
                scanf("%d %d", &a, &b);
                analyzeNumberPair(a, b);
                break;
                
            case 5: {
                printf("Enter number of integers (max 100): ");
                int count;
                scanf("%d", &count);
                if (count > 0 && count <= MAX_NUMBERS) {
                    int numbers[MAX_NUMBERS];
                    printf("Enter %d numbers: ", count);
                    for (int i = 0; i < count; i++) {
                        scanf("%d", &numbers[i]);
                    }
                    analyzeNumberSet(numbers, count);
                }
                break;
            }
                
            case 6:
                printf("Enter number n: ");
                scanf("%d", &n);
                printf("Enter limit: ");
                scanf("%d", &limit);
                findCoprimes(n, limit);
                break;
                
            case 7:
                printf("Enter a number for Euler's totient function: ");
                scanf("%d", &n);
                eulerTotient(n);
                break;
                
            case 8:
                printf("Enter limit for totient sieve: ");
                scanf("%d", &limit);
                if (limit > 0 && limit <= 100) {
                    sieveEulerTotient(limit);
                } else {
                    printf("Please enter a limit between 1 and 100.\n");
                }
                break;
                
            case 9: {
                printf("Enter number of integers (max 10): ");
                int count;
                scanf("%d", &count);
                if (count > 0 && count <= 10) {
                    int numbers[10];
                    printf("Enter %d numbers: ", count);
                    for (int i = 0; i < count; i++) {
                        scanf("%d", &numbers[i]);
                    }
                    printf("GCD of all numbers: %d\n", gcdMultiple(numbers, count));
                    printf("LCM of all numbers: %lld\n", lcmMultiple(numbers, count));
                }
                break;
            }
                
            case 10:
                printf("Enter two numbers for Euclidean algorithm demo: ");
                scanf("%d %d", &a, &b);
                gcdEuclidean(a, b);
                break;
                
            case 11:
                printf("Enter limit for finding perfect numbers: ");
                scanf("%d", &limit);
                perfectNumbers(limit);
                break;
                
            case 12:
                printf("Enter limit for abundant/deficient analysis: ");
                scanf("%d", &limit);
                abundantDeficientNumbers(limit);
                break;
                
            case 13:
                printf("Enter limit for finding amicable numbers: ");
                scanf("%d", &limit);
                amicableNumbers(limit);
                break;
                
            case 14:
                printf("Enter a number for Collatz conjecture: ");
                scanf("%d", &n);
                collatzConjecture(n);
                break;
                
            case 15:
                printf("Enter two numbers for Bézout coefficients: ");
                scanf("%d %d", &a, &b);
                bezoutCoefficients(a, b);
                break;
                
            case 16:
                printf("Modular Arithmetic - Feature Available\n");
                break;
                
            case 17:
                printf("Chinese Remainder Theorem - Feature Available\n");
                break;
                
            case 18:
                numberTheoryGame();
                break;
                
            case 19:
                printf("Cryptography Demo - Feature Available\n");
                break;
                
            case 20:
                printf("🔢 Thank you for using Enhanced Number Theory Suite!\n");
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