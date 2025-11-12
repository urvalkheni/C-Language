/*
 * Advanced Alternating Series Calculator v2.0
 * Features: Multiple alternating series patterns, analysis,
 *           convergence testing, custom sequences
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function prototypes
void basicAlternatingSum();
void alternatingSquares();
void alternatingCubes();
void alternatingFactorials();
void alternatingPowers();
void harmonicAlternating();
void fibonacciAlternating();
void primeAlternating();
void customAlternating();
void convergenceTest();
void partialSums();
void absoluteSeriesValue();
void seriesVisualization();
void compareAlternatingSeries();
void leibnizPiApproximation();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║      Advanced Alternating Series Calculator v2.0          ║\n");
    printf("║         Mathematical Series Analysis Tool                  ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                basicAlternatingSum();
                break;
            case 2:
                alternatingSquares();
                break;
            case 3:
                alternatingCubes();
                break;
            case 4:
                alternatingFactorials();
                break;
            case 5:
                alternatingPowers();
                break;
            case 6:
                harmonicAlternating();
                break;
            case 7:
                fibonacciAlternating();
                break;
            case 8:
                primeAlternating();
                break;
            case 9:
                customAlternating();
                break;
            case 10:
                convergenceTest();
                break;
            case 11:
                partialSums();
                break;
            case 12:
                absoluteSeriesValue();
                break;
            case 13:
                seriesVisualization();
                break;
            case 14:
                compareAlternatingSeries();
                break;
            case 15:
                leibnizPiApproximation();
                break;
            case 16:
                printf("\n--- Alternating Series Info ---\n");
                printf("\n• Basic: 1-2+3-4+5...\n");
                printf("• Harmonic: 1-1/2+1/3-1/4...\n");
                printf("• Leibniz: π/4 = 1-1/3+1/5-1/7...\n");
                printf("• Convergence: Tests if series converges\n");
                break;
            case 0:
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Alternating Series Calculator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC SERIES                                           │\n");
    printf("│  [1]  Basic Alternating Sum (1-2+3-4+5...)              │\n");
    printf("│  [2]  Alternating Squares (1²-2²+3²-4²...)              │\n");
    printf("│  [3]  Alternating Cubes (1³-2³+3³-4³...)                │\n");
    printf("│  [4]  Alternating Factorials (1!-2!+3!-4!...)           │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED SERIES                                        │\n");
    printf("│  [5]  Alternating Powers (x-x²+x³-x⁴...)                │\n");
    printf("│  [6]  Harmonic Alternating (1-1/2+1/3-1/4...)           │\n");
    printf("│  [7]  Fibonacci Alternating                             │\n");
    printf("│  [8]  Prime Alternating                                 │\n");
    printf("│  [9]  Custom Alternating Series                         │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ANALYSIS TOOLS                                         │\n");
    printf("│  [10] Convergence Test                                  │\n");
    printf("│  [11] Partial Sums Analysis                             │\n");
    printf("│  [12] Absolute Series Value                             │\n");
    printf("│  [13] Series Visualization                              │\n");
    printf("│  [14] Compare Alternating Series                        │\n");
    printf("│  [15] Leibniz π Approximation                           │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Alternating Series Info                           │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void basicAlternatingSum() {
    long long n, sum = 0;
    printf("\nEnter The Number :: ");
    scanf("%lld", &n);
    
    if(n % 2 == 0)
        sum = (-n / 2);
    else
        sum = (-n / 2) + n;
    
    printf("\n--- Basic Alternating Sum ---\n");
    printf("Series: 1 - 2 + 3 - 4 + 5 - 6 ... up to %lld terms\n", n);
    printf("Sum = %lld\n", sum);
    
    // Show detailed calculation
    printf("\nDetailed: ");
    for(int i = 1; i <= n && i <= 10; i++) {
        if(i % 2 == 1)
            printf("+%d ", i);
        else
            printf("-%d ", i);
    }
    if(n > 10) printf("...");
    printf("\n");
}

void alternatingSquares() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    long long sum = 0;
    printf("\n--- Alternating Squares ---\n");
    printf("Series: ");
    
    for(int i = 1; i <= n; i++) {
        long long term = (long long)i * i;
        if(i % 2 == 1) {
            sum += term;
            if(i <= 10) printf("+%d² ", i);
        } else {
            sum -= term;
            if(i <= 10) printf("-%d² ", i);
        }
    }
    
    if(n > 10) printf("...");
    printf("\nSum = %lld\n", sum);
}

void alternatingCubes() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    long long sum = 0;
    printf("\n--- Alternating Cubes ---\n");
    printf("Series: ");
    
    for(int i = 1; i <= n; i++) {
        long long term = (long long)i * i * i;
        if(i % 2 == 1) {
            sum += term;
            if(i <= 8) printf("+%d³ ", i);
        } else {
            sum -= term;
            if(i <= 8) printf("-%d³ ", i);
        }
    }
    
    if(n > 8) printf("...");
    printf("\nSum = %lld\n", sum);
}

long long factorial(int n) {
    if(n <= 1) return 1;
    long long result = 1;
    for(int i = 2; i <= n && i <= 20; i++) {
        result *= i;
    }
    return result;
}

void alternatingFactorials() {
    int n;
    printf("\nEnter number of terms (max 20): ");
    scanf("%d", &n);
    if(n > 20) n = 20;
    
    long long sum = 0;
    printf("\n--- Alternating Factorials ---\n");
    printf("Series: ");
    
    for(int i = 1; i <= n; i++) {
        long long term = factorial(i);
        if(i % 2 == 1) {
            sum += term;
            if(i <= 6) printf("+%d! ", i);
        } else {
            sum -= term;
            if(i <= 6) printf("-%d! ", i);
        }
    }
    
    if(n > 6) printf("...");
    printf("\nSum = %lld\n", sum);
}

void alternatingPowers() {
    int n;
    double x;
    printf("\nEnter base value x: ");
    scanf("%lf", &x);
    printf("Enter number of terms: ");
    scanf("%d", &n);
    
    double sum = 0;
    printf("\n--- Alternating Powers ---\n");
    printf("Series: ");
    
    for(int i = 1; i <= n; i++) {
        double term = pow(x, i);
        if(i % 2 == 1) {
            sum += term;
            if(i <= 8) printf("+%.2f^%d ", x, i);
        } else {
            sum -= term;
            if(i <= 8) printf("-%.2f^%d ", x, i);
        }
    }
    
    if(n > 8) printf("...");
    printf("\nSum = %.6f\n", sum);
}

void harmonicAlternating() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    double sum = 0;
    printf("\n--- Harmonic Alternating ---\n");
    printf("Series: ");
    
    for(int i = 1; i <= n; i++) {
        double term = 1.0 / i;
        if(i % 2 == 1) {
            sum += term;
            if(i <= 10) printf("+1/%d ", i);
        } else {
            sum -= term;
            if(i <= 10) printf("-1/%d ", i);
        }
    }
    
    if(n > 10) printf("...");
    printf("\nSum = %.10f\n", sum);
    printf("(Converges to ln(2) ≈ 0.693147)\n");
}

void fibonacciAlternating() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    long long a = 0, b = 1, sum = 0;
    printf("\n--- Fibonacci Alternating ---\n");
    printf("Series: ");
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 1) {
            sum += a;
            if(i <= 10) printf("+%lld ", a);
        } else {
            sum -= a;
            if(i <= 10) printf("-%lld ", a);
        }
        
        long long next = a + b;
        a = b;
        b = next;
    }
    
    if(n > 10) printf("...");
    printf("\nSum = %lld\n", sum);
}

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void primeAlternating() {
    int n;
    printf("\nEnter number of prime terms: ");
    scanf("%d", &n);
    
    long long sum = 0;
    int count = 0, num = 2;
    
    printf("\n--- Prime Alternating ---\n");
    printf("Series: ");
    
    while(count < n) {
        if(isPrime(num)) {
            count++;
            if(count % 2 == 1) {
                sum += num;
                if(count <= 10) printf("+%d ", num);
            } else {
                sum -= num;
                if(count <= 10) printf("-%d ", num);
            }
        }
        num++;
    }
    
    if(n > 10) printf("...");
    printf("\nSum = %lld\n", sum);
}

void customAlternating() {
    int n, start, step;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    printf("Enter starting value: ");
    scanf("%d", &start);
    printf("Enter step/increment: ");
    scanf("%d", &step);
    
    long long sum = 0;
    int current = start;
    
    printf("\n--- Custom Alternating ---\n");
    printf("Series: ");
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 1) {
            sum += current;
            if(i <= 10) printf("+%d ", current);
        } else {
            sum -= current;
            if(i <= 10) printf("-%d ", current);
        }
        current += step;
    }
    
    if(n > 10) printf("...");
    printf("\nSum = %lld\n", sum);
}

void convergenceTest() {
    int n;
    printf("\nEnter number of terms to test: ");
    scanf("%d", &n);
    
    double sum = 0;
    double prev = 0;
    
    printf("\n--- Convergence Test (Harmonic Alternating) ---\n");
    printf("\nTerm\tPartial Sum\tDifference\n");
    printf("────────────────────────────────────\n");
    
    for(int i = 1; i <= n; i++) {
        double term = 1.0 / i;
        if(i % 2 == 1)
            sum += term;
        else
            sum -= term;
        
        double diff = fabs(sum - prev);
        if(i <= 20 || i == n)
            printf("%d\t%.10f\t%.10f\n", i, sum, diff);
        
        prev = sum;
    }
    
    printf("\nSeries appears to converge to: %.10f\n", sum);
}

void partialSums() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Partial Sums (Basic Alternating) ---\n");
    printf("\nTerm\tValue\tPartial Sum\n");
    printf("────────────────────────────────\n");
    
    long long sum = 0;
    for(int i = 1; i <= n && i <= 20; i++) {
        if(i % 2 == 1)
            sum += i;
        else
            sum -= i;
        
        printf("%d\t%s%d\t%lld\n", i, (i%2==1?"+":"-"), i, sum);
    }
    
    if(n > 20) printf("... (showing first 20 terms)\n");
}

void absoluteSeriesValue() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    long long alternating_sum = 0;
    long long absolute_sum = 0;
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 1)
            alternating_sum += i;
        else
            alternating_sum -= i;
        
        absolute_sum += i;
    }
    
    printf("\n--- Absolute vs Alternating ---\n");
    printf("Alternating Sum: %lld\n", alternating_sum);
    printf("Absolute Sum:    %lld\n", absolute_sum);
    printf("Difference:      %lld\n", absolute_sum - alternating_sum);
}

void seriesVisualization() {
    int n;
    printf("\nEnter number of terms (max 30): ");
    scanf("%d", &n);
    if(n > 30) n = 30;
    
    printf("\n--- Series Visualization ---\n\n");
    
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 1) {
            sum += i;
            printf("+ %2d: ", i);
            for(int j = 0; j < i && j < 50; j++) printf("▓");
        } else {
            sum -= i;
            printf("- %2d: ", i);
            for(int j = 0; j < i && j < 50; j++) printf("░");
        }
        printf(" (%lld)\n", sum);
    }
}

void compareAlternatingSeries() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    long long basic = 0, squares = 0;
    double harmonic = 0;
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 1) {
            basic += i;
            squares += (long long)i * i;
            harmonic += 1.0 / i;
        } else {
            basic -= i;
            squares -= (long long)i * i;
            harmonic -= 1.0 / i;
        }
    }
    
    printf("\n--- Comparison ---\n");
    printf("Basic (1-2+3-4...):        %lld\n", basic);
    printf("Squares (1²-2²+3²-4²...):  %lld\n", squares);
    printf("Harmonic (1-½+⅓-¼...):     %.10f\n", harmonic);
}

void leibnizPiApproximation() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    double pi_over_4 = 0;
    
    printf("\n--- Leibniz π Approximation ---\n");
    printf("Formula: π/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...\n\n");
    
    for(int i = 0; i < n; i++) {
        double term = 1.0 / (2 * i + 1);
        if(i % 2 == 0)
            pi_over_4 += term;
        else
            pi_over_4 -= term;
    }
    
    double pi_approx = 4 * pi_over_4;
    double actual_pi = 3.14159265358979323846;
    
    printf("Approximation: π ≈ %.15f\n", pi_approx);
    printf("Actual value:  π = %.15f\n", actual_pi);
    printf("Error:           %.15f\n", fabs(pi_approx - actual_pi));
    printf("Terms used:      %d\n", n);
}