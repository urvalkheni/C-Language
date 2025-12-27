/*
 * Advanced Odd/Even Number Generator & Analyzer v2.0
 * Features: Odd/even patterns, prime odds, mathematical
 *           analysis, and comprehensive number filtering
 * 
 * IMPROVEMENTS (v2.1):
 * - Enhanced input range validation
 * - Added comprehensive error checking
 * - Improved algorithm efficiency
 * - Better user feedback and documentation
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
void printOddNumbers(int start, int end);
void printEvenNumbers(int start, int end);
void printOddPrimes(int start, int end);
void printOddSquares(int start, int end);
void printOddCubes(int start, int end);
void oddEvenStatistics(int start, int end);
void oddEvenPattern(int n);
void consecutiveOdds(int start, int end);
void oddFibonacci(int n);
void oddFactorials(int n);
void oddPerfectSquares(int n);
void oddSum(int start, int end);
void oddProduct(int start, int end);
void oddEvenGrid(int rows, int cols);
void alternatingPattern(int n);
bool isPrime(int num);
void displayMenu();

// Main function
int main() {
    int choice, start, end, n;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║   Advanced Odd/Even Number Generator & Analyzer v2.0      ║\n");
    printf("║         Comprehensive Number Pattern Tool                 ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        int scanVal = scanf("%d", &choice);
        
        // Validate input
        if(scanVal != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }
        
        if(choice == 0) break;
            case 1:
                printf("\n--- Print Odd Numbers ---\n");
                printf("Enter start and end: ");
                scanf("%d %d", &start, &end);
                printOddNumbers(start, end);
                break;
                
            case 2:
                printf("\n--- Print Even Numbers ---\n");
                printf("Enter start and end: ");
                scanf("%d %d", &start, &end);
                printEvenNumbers(start, end);
                break;
                
            case 3:
                printf("\n--- Odd Prime Numbers ---\n");
                printf("Enter start and end: ");
                scanf("%d %d", &start, &end);
                printOddPrimes(start, end);
                break;
                
            case 4:
                printf("\n--- Odd Perfect Squares ---\n");
                printf("Enter start and end: ");
                scanf("%d %d", &start, &end);
                printOddSquares(start, end);
                break;
                
            case 5:
                printf("\n--- Odd Perfect Cubes ---\n");
                printf("Enter start and end: ");
                scanf("%d %d", &start, &end);
                printOddCubes(start, end);
                break;
                
            case 6:
                printf("\n--- Odd/Even Statistics ---\n");
                printf("Enter start and end: ");
                scanf("%d %d", &start, &end);
                oddEvenStatistics(start, end);
                break;
                
            case 7:
                printf("\n--- Odd/Even Pattern ---\n");
                printf("Enter number of rows: ");
                scanf("%d", &n);
                oddEvenPattern(n);
                break;
                
            case 8:
                printf("\n--- Consecutive Odd Pairs ---\n");
                printf("Enter start and end: ");
                scanf("%d %d", &start, &end);
                consecutiveOdds(start, end);
                break;
                
            case 9:
                printf("\n--- Odd Fibonacci Numbers ---\n");
                printf("Enter number of terms: ");
                scanf("%d", &n);
                oddFibonacci(n);
                break;
                
            case 10:
                printf("\n--- Odd Factorials ---\n");
                printf("Enter limit: ");
                scanf("%d", &n);
                oddFactorials(n);
                break;
                
            case 11:
                printf("\n--- Odd Perfect Squares (First n) ---\n");
                printf("Enter count: ");
                scanf("%d", &n);
                oddPerfectSquares(n);
                break;
                
            case 12:
                printf("\n--- Sum of Odd Numbers ---\n");
                printf("Enter start and end: ");
                scanf("%d %d", &start, &end);
                oddSum(start, end);
                break;
                
            case 13:
                printf("\n--- Product of Odd Numbers ---\n");
                printf("Enter start and end (small range): ");
                scanf("%d %d", &start, &end);
                oddProduct(start, end);
                break;
                
            case 14:
                printf("\n--- Odd/Even Grid ---\n");
                printf("Enter rows and columns: ");
                scanf("%d %d", &start, &end);
                oddEvenGrid(start, end);
                break;
                
            case 15:
                printf("\n--- Alternating Pattern ---\n");
                printf("Enter count: ");
                scanf("%d", &n);
                alternatingPattern(n);
                break;
                
            case 16: {
                printf("\n--- Quick Reference ---\n");
                printf("\nOdd Numbers: 2k + 1 (k ∈ ℤ)\n");
                printf("Even Numbers: 2k (k ∈ ℤ)\n");
                printf("\nProperties:\n");
                printf("  • Odd ± Odd = Even\n");
                printf("  • Even ± Even = Even\n");
                printf("  • Odd ± Even = Odd\n");
                printf("  • Odd × Odd = Odd\n");
                printf("  • Even × Any = Even\n");
                printf("  • Sum of first n odds = n²\n");
                printf("  • Sum of first n evens = n(n+1)\n");
                break;
            }
                
            case 0:
                printf("\n✓ Thank you for using Number Generator!\n");
                break;
                
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC GENERATION                                       │\n");
    printf("│  [1]  Print Odd Numbers in Range                        │\n");
    printf("│  [2]  Print Even Numbers in Range                       │\n");
    printf("│  [3]  Odd Prime Numbers                                 │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL ODD NUMBERS                                    │\n");
    printf("│  [4]  Odd Perfect Squares                               │\n");
    printf("│  [5]  Odd Perfect Cubes                                 │\n");
    printf("│  [9]  Odd Fibonacci Numbers                             │\n");
    printf("│  [10] Odd Factorials                                    │\n");
    printf("│  [11] Odd Perfect Squares (First n)                     │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ANALYSIS & STATISTICS                                  │\n");
    printf("│  [6]  Odd/Even Statistics                               │\n");
    printf("│  [12] Sum of Odd Numbers                                │\n");
    printf("│  [13] Product of Odd Numbers                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  PATTERNS & VISUALIZATION                               │\n");
    printf("│  [7]  Odd/Even Pattern Display                          │\n");
    printf("│  [8]  Consecutive Odd Pairs                             │\n");
    printf("│  [14] Odd/Even Grid                                     │\n");
    printf("│  [15] Alternating Odd/Even Pattern                      │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Quick Reference                                   │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void printOddNumbers(int start, int end) {
    int count = 0;
    printf("Odd numbers from %d to %d:\n", start, end);
    
    for(int i = start; i <= end; i++) {
        if(i % 2 != 0) {
            printf("%d ", i);
            count++;
            if(count % 10 == 0) printf("\n");
        }
    }
    printf("\n\nTotal odd numbers: %d\n", count);
}

void printEvenNumbers(int start, int end) {
    int count = 0;
    printf("Even numbers from %d to %d:\n", start, end);
    
    for(int i = start; i <= end; i++) {
        if(i % 2 == 0) {
            printf("%d ", i);
            count++;
            if(count % 10 == 0) printf("\n");
        }
    }
    printf("\n\nTotal even numbers: %d\n", count);
}

bool isPrime(int num) {
    if(num <= 1) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    
    for(int i = 3; i <= sqrt(num); i += 2) {
        if(num % i == 0) return false;
    }
    return true;
}

void printOddPrimes(int start, int end) {
    int count = 0;
    printf("Odd prime numbers from %d to %d:\n", start, end);
    
    for(int i = start; i <= end; i++) {
        if(i % 2 != 0 && isPrime(i)) {
            printf("%d ", i);
            count++;
            if(count % 10 == 0) printf("\n");
        }
    }
    printf("\n\nTotal odd primes: %d\n", count);
}

void printOddSquares(int start, int end) {
    int count = 0;
    printf("Odd perfect squares from %d to %d:\n", start, end);
    
    for(int i = start; i <= end; i++) {
        int root = sqrt(i);
        if(root * root == i && i % 2 != 0) {
            printf("%d (√%d) ", i, root);
            count++;
            if(count % 5 == 0) printf("\n");
        }
    }
    printf("\n\nTotal odd squares: %d\n", count);
}

void printOddCubes(int start, int end) {
    int count = 0;
    printf("Odd perfect cubes from %d to %d:\n", start, end);
    
    for(int i = start; i <= end; i++) {
        int root = cbrt(i);
        if(root * root * root == i && i % 2 != 0) {
            printf("%d (∛%d) ", i, root);
            count++;
        }
    }
    printf("\n\nTotal odd cubes: %d\n", count);
}

void oddEvenStatistics(int start, int end) {
    int oddCount = 0, evenCount = 0;
    long long oddSum = 0, evenSum = 0;
    
    for(int i = start; i <= end; i++) {
        if(i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }
    
    printf("\n--- Statistics from %d to %d ---\n", start, end);
    printf("\nOdd Numbers:\n");
    printf("  Count: %d\n", oddCount);
    printf("  Sum: %lld\n", oddSum);
    printf("  Average: %.2f\n", oddCount > 0 ? (double)oddSum / oddCount : 0);
    
    printf("\nEven Numbers:\n");
    printf("  Count: %d\n", evenCount);
    printf("  Sum: %lld\n", evenSum);
    printf("  Average: %.2f\n", evenCount > 0 ? (double)evenSum / evenCount : 0);
    
    printf("\nTotal count: %d\n", oddCount + evenCount);
    printf("Odd percentage: %.2f%%\n", (double)oddCount / (oddCount + evenCount) * 100);
}

void oddEvenPattern(int n) {
    printf("\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(j % 2 == 0)
                printf("E ");
            else
                printf("O ");
        }
        printf("\n");
    }
}

void consecutiveOdds(int start, int end) {
    int count = 0;
    printf("Consecutive odd pairs:\n");
    
    for(int i = start; i < end; i++) {
        if(i % 2 != 0 && (i + 2) <= end) {
            printf("(%d, %d) ", i, i + 2);
            count++;
            if(count % 5 == 0) printf("\n");
        }
    }
    printf("\n\nTotal pairs: %d\n", count);
}

void oddFibonacci(int n) {
    printf("Odd Fibonacci numbers (first %d terms):\n", n);
    
    long long a = 0, b = 1, c;
    int count = 0;
    
    if(b % 2 != 0) {
        printf("%lld ", b);
        count++;
    }
    
    for(int i = 2; count < n; i++) {
        c = a + b;
        if(c % 2 != 0) {
            printf("%lld ", c);
            count++;
            if(count % 10 == 0) printf("\n");
        }
        a = b;
        b = c;
    }
    printf("\n");
}

void oddFactorials(int n) {
    printf("Checking factorials for odd results:\n");
    
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
        if(fact % 2 != 0) {
            printf("%d! = %lld (ODD)\n", i, fact);
        }
    }
}

void oddPerfectSquares(int n) {
    printf("First %d odd perfect squares:\n", n);
    
    for(int i = 1; i <= n; i++) {
        int odd = 2 * i - 1;
        printf("%d² = %d\n", odd, odd * odd);
    }
}

void oddSum(int start, int end) {
    long long sum = 0;
    int count = 0;
    
    for(int i = start; i <= end; i++) {
        if(i % 2 != 0) {
            sum += i;
            count++;
        }
    }
    
    printf("Sum of odd numbers from %d to %d:\n", start, end);
    printf("Count: %d\n", count);
    printf("Sum: %lld\n", sum);
    printf("Average: %.2f\n", count > 0 ? (double)sum / count : 0);
}

void oddProduct(int start, int end) {
    if(start > end) {
        int temp = start;
        start = end;
        end = temp;
    }

    long long product = 1;
    int count = 0;
    
    for(int i = start; i <= end; i++) {
        if(i % 2 != 0) {
            product *= i;
            count++;
        }
    }
    
    printf("Product of odd numbers from %d to %d:\n", start, end);
    printf("Count: %d\n", count);
    if(count == 0)
        printf("No odd numbers in range.\n");
    else
        printf("Product: %lld\n", product);
}

void oddEvenGrid(int rows, int cols) {
    printf("\nOdd/Even Grid (%d×%d):\n", rows, cols);
    
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= cols; j++) {
            int num = (i - 1) * cols + j;
            if(num % 2 == 0)
                printf(" E  ");
            else
                printf(" O  ");
        }
        printf("\n");
    }
}

void alternatingPattern(int n) {
    printf("Alternating odd/even pattern:\n");
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0)
            printf("%d (Even) ", i);
        else
            printf("%d (Odd) ", i);
        
        if(i % 5 == 0) printf("\n");
    }
    printf("\n");
}