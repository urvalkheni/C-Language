/*
 * Advanced Sequence Analyzer & Generator v2.0
 * Features: AP, GP, HP sequences, Fibonacci,
 *           pattern analysis, and series operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
void arithmeticProgression();
void geometricProgression();
void harmonicProgression();
void fibonacciSeries();
void triangularNumbers();
void squareNumbers();
void cubeNumbers();
void primeNumbers();
void perfectNumbers();
void factorialSeries();
void sequenceSum();
void sequenceProduct();
void seriesConverter();
void customSequence();
void sequenceAnalyzer();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║      Advanced Sequence Analyzer & Generator v2.0          ║\n");
    printf("║         Comprehensive Series Analysis Tool                 ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                arithmeticProgression();
                break;
            case 2:
                geometricProgression();
                break;
            case 3:
                harmonicProgression();
                break;
            case 4:
                fibonacciSeries();
                break;
            case 5:
                triangularNumbers();
                break;
            case 6:
                squareNumbers();
                break;
            case 7:
                cubeNumbers();
                break;
            case 8:
                primeNumbers();
                break;
            case 9:
                perfectNumbers();
                break;
            case 10:
                factorialSeries();
                break;
            case 11:
                sequenceSum();
                break;
            case 12:
                sequenceProduct();
                break;
            case 13:
                seriesConverter();
                break;
            case 14:
                customSequence();
                break;
            case 15:
                sequenceAnalyzer();
                break;
            case 16:
                printf("\n--- Sequence Types ---\n");
                printf("\n• AP: Each term = previous + d\n");
                printf("• GP: Each term = previous × r\n");
                printf("• HP: Reciprocals form AP\n");
                printf("• Fibonacci: Sum of previous two\n");
                printf("• Triangular: n(n+1)/2\n");
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Sequence Analyzer!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  CLASSIC PROGRESSIONS                                   │\n");
    printf("│  [1]  Arithmetic Progression (AP)                       │\n");
    printf("│  [2]  Geometric Progression (GP)                        │\n");
    printf("│  [3]  Harmonic Progression (HP)                         │\n");
    printf("│  [4]  Fibonacci Series                                  │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  NUMBER SEQUENCES                                       │\n");
    printf("│  [5]  Triangular Numbers                                │\n");
    printf("│  [6]  Square Numbers                                    │\n");
    printf("│  [7]  Cube Numbers                                      │\n");
    printf("│  [8]  Prime Numbers                                     │\n");
    printf("│  [9]  Perfect Numbers                                   │\n");
    printf("│  [10] Factorial Series                                  │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SEQUENCE OPERATIONS                                    │\n");
    printf("│  [11] Sequence Sum Calculator                           │\n");
    printf("│  [12] Sequence Product Calculator                       │\n");
    printf("│  [13] Series Converter                                  │\n");
    printf("│  [14] Custom Sequence Generator                         │\n");
    printf("│  [15] Sequence Type Analyzer                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Sequence Types Reference                          │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void arithmeticProgression() {
    int a, d, n;
    printf("\nEnter first term (a): ");
    scanf("%d", &a);
    printf("Enter common difference (d): ");
    scanf("%d", &d);
    printf("Enter number of terms (n): ");
    scanf("%d", &n);
    
    printf("\n--- Arithmetic Progression ---\n");
    printf("Series: ");
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int term = a + i * d;
        printf("%d ", term);
        sum += term;
    }
    
    int lastTerm = a + (n - 1) * d;
    printf("\n\nFirst term: %d\n", a);
    printf("Last term: %d\n", lastTerm);
    printf("Sum of %d terms: %d\n", n, sum);
    printf("Formula sum: %d\n", (n * (a + lastTerm)) / 2);
}

void geometricProgression() {
    int a, r, n;
    printf("\nEnter first term (a): ");
    scanf("%d", &a);
    printf("Enter common ratio (r): ");
    scanf("%d", &r);
    printf("Enter number of terms (n): ");
    scanf("%d", &n);
    
    printf("\n--- Geometric Progression ---\n");
    printf("Series: ");
    
    long long term = a;
    long long sum = 0;
    
    for(int i = 0; i < n; i++) {
        printf("%lld ", term);
        sum += term;
        term *= r;
    }
    
    printf("\n\nSum of %d terms: %lld\n", n, sum);
    if(r != 1) {
        long long formulaSum = a * (pow(r, n) - 1) / (r - 1);
        printf("Formula sum: %lld\n", formulaSum);
    }
}

void harmonicProgression() {
    int a, d, n;
    printf("\nEnter first term denominator (a): ");
    scanf("%d", &a);
    printf("Enter common difference (d): ");
    scanf("%d", &d);
    printf("Enter number of terms (n): ");
    scanf("%d", &n);
    
    printf("\n--- Harmonic Progression ---\n");
    printf("Series: ");
    
    float sum = 0;
    for(int i = 0; i < n; i++) {
        float term = 1.0 / (a + i * d);
        printf("1/%d ", a + i * d);
        sum += term;
    }
    
    printf("\n\nSum: %.4f\n", sum);
}

void fibonacciSeries() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Fibonacci Series ---\n");
    printf("Series: ");
    
    long long a = 0, b = 1;
    
    for(int i = 0; i < n; i++) {
        printf("%lld ", a);
        long long next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

void triangularNumbers() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Triangular Numbers ---\n");
    printf("Series: ");
    
    for(int i = 1; i <= n; i++) {
        int term = i * (i + 1) / 2;
        printf("%d ", term);
    }
    printf("\n");
}

void squareNumbers() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Square Numbers ---\n");
    printf("Series: ");
    
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        printf("%d ", i * i);
        sum += i * i;
    }
    
    printf("\n\nSum of squares: %d\n", sum);
    printf("Formula: %d\n", n * (n + 1) * (2 * n + 1) / 6);
}

void cubeNumbers() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Cube Numbers ---\n");
    printf("Series: ");
    
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        long long cube = (long long)i * i * i;
        printf("%lld ", cube);
        sum += cube;
    }
    
    printf("\n\nSum of cubes: %lld\n", sum);
}

void primeNumbers() {
    int n;
    printf("\nEnter how many primes to display: ");
    scanf("%d", &n);
    
    printf("\n--- Prime Numbers ---\n");
    printf("Series: ");
    
    int count = 0, num = 2;
    
    while(count < n) {
        bool isPrime = true;
        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

void perfectNumbers() {
    int n;
    printf("\nEnter how many perfect numbers to find: ");
    scanf("%d", &n);
    
    printf("\n--- Perfect Numbers ---\n");
    printf("Series: ");
    
    int count = 0, num = 1;
    
    while(count < n && num < 10000) {
        int sum = 0;
        for(int i = 1; i < num; i++) {
            if(num % i == 0)
                sum += i;
        }
        if(sum == num && num > 0) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

void factorialSeries() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Factorial Series ---\n");
    printf("Series: ");
    
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
        printf("%lld ", fact);
    }
    printf("\n");
}

void sequenceSum() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    int arr[100];
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    printf("\n--- Sequence Sum ---\n");
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / n);
}

void sequenceProduct() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    int arr[100];
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    long long product = 1;
    for(int i = 0; i < n; i++) {
        product *= arr[i];
    }
    
    printf("\n--- Sequence Product ---\n");
    printf("Product: %lld\n", product);
}

void seriesConverter() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    int arr[100];
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\n--- Series Converter ---\n");
    printf("Original: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\nReversed: ");
    for(int i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    
    printf("\nSquared: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i] * arr[i]);
    
    printf("\n");
}

void customSequence() {
    int n, a, type;
    printf("\nEnter starting number: ");
    scanf("%d", &a);
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Choose pattern:\n");
    printf("1. Add 2  2. Add 3  3. Multiply 2  4. Square\n");
    printf("Choice: ");
    scanf("%d", &type);
    
    printf("\n--- Custom Sequence ---\n");
    printf("Series: ");
    
    int term = a;
    for(int i = 0; i < n; i++) {
        printf("%d ", term);
        switch(type) {
            case 1: term += 2; break;
            case 2: term += 3; break;
            case 3: term *= 2; break;
            case 4: term = term * term; break;
        }
    }
    printf("\n");
}

void sequenceAnalyzer() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    int arr[100];
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\n--- Sequence Analysis ---\n");
    
    // Check if AP
    bool isAP = true;
    int d = arr[1] - arr[0];
    for(int i = 2; i < n; i++) {
        if(arr[i] - arr[i-1] != d) {
            isAP = false;
            break;
        }
    }
    
    // Check if GP
    bool isGP = true;
    if(arr[0] != 0) {
        float r = (float)arr[1] / arr[0];
        for(int i = 2; i < n; i++) {
            if(arr[i-1] != 0 && (float)arr[i] / arr[i-1] != r) {
                isGP = false;
                break;
            }
        }
    } else {
        isGP = false;
    }
    
    printf("Sequence Type: ");
    if(isAP)
        printf("Arithmetic Progression (d=%d)\n", d);
    else if(isGP)
        printf("Geometric Progression (r=%.2f)\n", (float)arr[1] / arr[0]);
    else
        printf("Custom/Mixed\n");
}