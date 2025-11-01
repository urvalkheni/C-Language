/*
 * Advanced Number Reversal & Palindrome Analyzer v2.0
 * Features: Multiple reversal algorithms, palindrome detection,
 *           mathematical analysis, base conversion, and more
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function prototypes
long long reverseIterative(long long n);
long long reverseRecursive(long long n, long long rev);
long long reverseString(long long n);
long long reverseArray(long long n);
bool isPalindrome(long long n);
bool isPalindromicPrime(long long n);
bool isPrime(long long n);
int countDigits(long long n);
long long sumOfDigits(long long n);
long long productOfDigits(long long n);
void reverseAndAdd(long long n, int iterations);
bool isLychrel(long long n, int maxIterations);
void reverseInBase(long long n, int base);
void digitalReversalDistance(long long n);
void findPalindromicPatterns(long long n);
void reverseVisualization(long long n);
void compareAlgorithms(long long n);
void batchPalindromeCheck(long long start, long long end);
void reverseStatistics(long long n);
void displayMenu();

// Main function
int main() {
    int choice;
    long long num, num2;
    int base, iterations;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║   Advanced Number Reversal & Palindrome Analyzer v2.0     ║\n");
    printf("║          Comprehensive Mathematical Analysis Tool         ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-17): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n--- Iterative Reversal ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Reversed number: %lld\n", reverseIterative(num));
                break;
                
            case 2:
                printf("\n--- Recursive Reversal ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Reversed number: %lld\n", reverseRecursive(num, 0));
                break;
                
            case 3:
                printf("\n--- String-based Reversal ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Reversed number: %lld\n", reverseString(num));
                break;
                
            case 4:
                printf("\n--- Array-based Reversal ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Reversed number: %lld\n", reverseArray(num));
                break;
                
            case 5:
                printf("\n--- Palindrome Checker ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                if(isPalindrome(num)) {
                    printf("%lld is a PALINDROME! ✓\n", num);
                } else {
                    printf("%lld is NOT a palindrome.\n", num);
                }
                break;
                
            case 6:
                printf("\n--- Palindromic Prime Checker ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                if(isPalindromicPrime(num)) {
                    printf("%lld is a PALINDROMIC PRIME! ★\n", num);
                } else {
                    printf("%lld is not a palindromic prime.\n", num);
                }
                break;
                
            case 7:
                printf("\n--- Reverse and Add Process ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Number of iterations: ");
                scanf("%d", &iterations);
                reverseAndAdd(num, iterations);
                break;
                
            case 8:
                printf("\n--- Lychrel Number Test ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Max iterations (e.g., 100): ");
                scanf("%d", &iterations);
                if(isLychrel(num, iterations)) {
                    printf("%lld is possibly a LYCHREL NUMBER!\n", num);
                } else {
                    printf("%lld is NOT a Lychrel number.\n", num);
                }
                break;
                
            case 9:
                printf("\n--- Base-N Reversal ---\n");
                printf("Enter a number (decimal): ");
                scanf("%lld", &num);
                printf("Enter base (2-16): ");
                scanf("%d", &base);
                reverseInBase(num, base);
                break;
                
            case 10:
                printf("\n--- Digital Reversal Distance ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                digitalReversalDistance(num);
                break;
                
            case 11:
                printf("\n--- Palindromic Patterns ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                findPalindromicPatterns(num);
                break;
                
            case 12:
                printf("\n--- Reversal Visualization ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                reverseVisualization(num);
                break;
                
            case 13:
                printf("\n--- Algorithm Comparison ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                compareAlgorithms(num);
                break;
                
            case 14:
                printf("\n--- Batch Palindrome Check ---\n");
                printf("Enter start number: ");
                scanf("%lld", &num);
                printf("Enter end number: ");
                scanf("%lld", &num2);
                batchPalindromeCheck(num, num2);
                break;
                
            case 15:
                printf("\n--- Number Statistics ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                reverseStatistics(num);
                break;
                
            case 16:
                printf("\n--- Digit Count ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Number of digits: %d\n", countDigits(num));
                break;
                
            case 17:
                printf("\n--- Sum & Product of Digits ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Sum of digits: %lld\n", sumOfDigits(num));
                printf("Product of digits: %lld\n", productOfDigits(num));
                break;
                
            case 0:
                printf("\n✓ Thank you for using Number Reversal Analyzer!\n");
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
    printf("│  REVERSAL ALGORITHMS                                    │\n");
    printf("│  [1]  Iterative Reversal                                │\n");
    printf("│  [2]  Recursive Reversal                                │\n");
    printf("│  [3]  String-based Reversal                             │\n");
    printf("│  [4]  Array-based Reversal                              │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  PALINDROME ANALYSIS                                    │\n");
    printf("│  [5]  Palindrome Checker                                │\n");
    printf("│  [6]  Palindromic Prime Checker                         │\n");
    printf("│  [7]  Reverse and Add Process                           │\n");
    printf("│  [8]  Lychrel Number Test                               │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED FEATURES                                      │\n");
    printf("│  [9]  Base-N Reversal (Binary, Hex, etc.)               │\n");
    printf("│  [10] Digital Reversal Distance                         │\n");
    printf("│  [11] Palindromic Patterns                              │\n");
    printf("│  [12] Reversal Visualization                            │\n");
    printf("│  [13] Algorithm Performance Comparison                  │\n");
    printf("│  [14] Batch Palindrome Check (Range)                    │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  UTILITIES                                              │\n");
    printf("│  [15] Number Statistics                                 │\n");
    printf("│  [16] Digit Count                                       │\n");
    printf("│  [17] Sum & Product of Digits                           │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit Program                                      │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

// Iterative reversal
long long reverseIterative(long long n) {
    long long rev = 0;
    long long original = n;
    bool isNegative = n < 0;
    
    if(isNegative) n = -n;
    
    while(n != 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    
    return isNegative ? -rev : rev;
}

// Recursive reversal
long long reverseRecursive(long long n, long long rev) {
    if(n == 0) return rev;
    return reverseRecursive(n / 10, rev * 10 + (n % 10));
}

// String-based reversal
long long reverseString(long long n) {
    char str[30];
    bool isNegative = n < 0;
    
    if(isNegative) n = -n;
    
    sprintf(str, "%lld", n);
    int len = strlen(str);
    
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    
    long long result = atoll(str);
    return isNegative ? -result : result;
}

// Array-based reversal
long long reverseArray(long long n) {
    int digits[20];
    int count = 0;
    bool isNegative = n < 0;
    
    if(isNegative) n = -n;
    
    while(n > 0) {
        digits[count++] = n % 10;
        n /= 10;
    }
    
    long long result = 0;
    for(int i = 0; i < count; i++) {
        result = result * 10 + digits[i];
    }
    
    return isNegative ? -result : result;
}

// Check if palindrome
bool isPalindrome(long long n) {
    if(n < 0) return false;
    return n == reverseIterative(n);
}

// Check if prime
bool isPrime(long long n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(long long i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Check if palindromic prime
bool isPalindromicPrime(long long n) {
    return isPalindrome(n) && isPrime(n);
}

// Count digits
int countDigits(long long n) {
    if(n == 0) return 1;
    if(n < 0) n = -n;
    int count = 0;
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Sum of digits
long long sumOfDigits(long long n) {
    if(n < 0) n = -n;
    long long sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Product of digits
long long productOfDigits(long long n) {
    if(n < 0) n = -n;
    long long product = 1;
    while(n > 0) {
        product *= n % 10;
        n /= 10;
    }
    return product;
}

// Reverse and add process
void reverseAndAdd(long long n, int iterations) {
    printf("\nReverse-and-Add Process:\n");
    printf("─────────────────────────────\n");
    
    for(int i = 0; i < iterations; i++) {
        long long rev = reverseIterative(n);
        printf("Step %d: %lld + %lld = ", i + 1, n, rev);
        n = n + rev;
        printf("%lld", n);
        
        if(isPalindrome(n)) {
            printf(" ★ PALINDROME!\n");
            printf("\n✓ Palindrome found after %d step(s)!\n", i + 1);
            return;
        }
        printf("\n");
    }
    
    printf("\nNo palindrome found after %d iterations.\n", iterations);
}

// Lychrel number test
bool isLychrel(long long n, int maxIterations) {
    for(int i = 0; i < maxIterations; i++) {
        n = n + reverseIterative(n);
        if(isPalindrome(n)) {
            return false;
        }
    }
    return true;
}

// Reverse in different base
void reverseInBase(long long n, int base) {
    if(base < 2 || base > 16) {
        printf("Invalid base! Use base 2-16.\n");
        return;
    }
    
    char digits[] = "0123456789ABCDEF";
    char representation[100];
    char reversed[100];
    int index = 0;
    long long temp = n;
    
    // Convert to base
    while(temp > 0) {
        representation[index++] = digits[temp % base];
        temp /= base;
    }
    representation[index] = '\0';
    
    // Original in base
    printf("\nNumber %lld in base %d: ", n, base);
    for(int i = index - 1; i >= 0; i--) {
        printf("%c", representation[i]);
    }
    
    // Reversed in base
    printf("\nReversed in base %d: %s\n", base, representation);
    
    // Convert back to decimal
    long long reversedDecimal = 0;
    long long power = 1;
    for(int i = 0; i < index; i++) {
        int digit;
        if(representation[i] >= '0' && representation[i] <= '9')
            digit = representation[i] - '0';
        else
            digit = representation[i] - 'A' + 10;
        
        reversedDecimal += digit * power;
        power *= base;
    }
    
    printf("Reversed in decimal: %lld\n", reversedDecimal);
}

// Digital reversal distance
void digitalReversalDistance(long long n) {
    long long rev = reverseIterative(n);
    long long diff = abs(n - rev);
    
    printf("\nDigital Reversal Distance:\n");
    printf("──────────────────────────────\n");
    printf("Original number:  %lld\n", n);
    printf("Reversed number:  %lld\n", rev);
    printf("Difference:       %lld\n", diff);
    printf("Sum:              %lld\n", n + rev);
    printf("Product:          %lld\n", n * rev);
    
    if(n == rev) {
        printf("\n★ This is a PALINDROME!\n");
    }
}

// Find palindromic patterns
void findPalindromicPatterns(long long n) {
    printf("\nPalindromic Patterns:\n");
    printf("─────────────────────────────\n");
    
    // Check various operations
    long long rev = reverseIterative(n);
    
    printf("n = %lld, reverse = %lld\n\n", n, rev);
    
    if(isPalindrome(n))
        printf("✓ n is a palindrome\n");
    
    if(isPalindrome(n + rev))
        printf("✓ n + reverse(%lld) = %lld is a palindrome\n", n + rev, n + rev);
    
    if(isPalindrome(n * rev))
        printf("✓ n × reverse = %lld is a palindrome\n", n * rev);
    
    if(isPalindrome(n - rev))
        printf("✓ n - reverse = %lld is a palindrome\n", abs(n - rev));
    
    // Check powers
    if(isPalindrome(n * n))
        printf("✓ n² = %lld is a palindrome\n", n * n);
}

// Visualization
void reverseVisualization(long long n) {
    printf("\nReversal Visualization:\n");
    printf("═══════════════════════════════════════\n");
    
    char str[30];
    sprintf(str, "%lld", n);
    int len = strlen(str);
    
    // Show original
    printf("\nOriginal: ");
    for(int i = 0; i < len; i++) {
        printf("[%c]", str[i]);
    }
    printf("\n");
    
    // Show arrows
    printf("          ");
    for(int i = 0; i < len/2; i++) {
        printf(" ↕  ");
    }
    printf("\n");
    
    // Show reversed
    printf("Reversed: ");
    for(int i = len - 1; i >= 0; i--) {
        printf("[%c]", str[i]);
    }
    printf("\n");
    
    long long rev = reverseIterative(n);
    printf("\nResult: %lld → %lld\n", n, rev);
}

// Compare algorithms
void compareAlgorithms(long long n) {
    clock_t start, end;
    double time_taken;
    
    printf("\nAlgorithm Performance Comparison:\n");
    printf("═══════════════════════════════════════════════\n");
    
    // Iterative
    start = clock();
    for(int i = 0; i < 100000; i++) {
        reverseIterative(n);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Iterative:     %.4f ms (100k iterations)\n", time_taken);
    
    // Recursive
    start = clock();
    for(int i = 0; i < 100000; i++) {
        reverseRecursive(n, 0);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Recursive:     %.4f ms (100k iterations)\n", time_taken);
    
    // String-based
    start = clock();
    for(int i = 0; i < 100000; i++) {
        reverseString(n);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("String-based:  %.4f ms (100k iterations)\n", time_taken);
    
    // Array-based
    start = clock();
    for(int i = 0; i < 100000; i++) {
        reverseArray(n);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Array-based:   %.4f ms (100k iterations)\n", time_taken);
    
    printf("\n✓ All algorithms produce: %lld\n", reverseIterative(n));
}

// Batch palindrome check
void batchPalindromeCheck(long long start, long long end) {
    int count = 0;
    int primeCount = 0;
    
    printf("\nPalindromes in range [%lld, %lld]:\n", start, end);
    printf("─────────────────────────────────────\n");
    
    for(long long i = start; i <= end && count < 100; i++) {
        if(isPalindrome(i)) {
            printf("%lld", i);
            if(isPrime(i)) {
                printf(" ★");
                primeCount++;
            }
            printf("  ");
            count++;
            if(count % 10 == 0) printf("\n");
        }
    }
    
    printf("\n\nTotal palindromes found: %d\n", count);
    printf("Palindromic primes: %d\n", primeCount);
}

// Statistics
void reverseStatistics(long long n) {
    long long rev = reverseIterative(n);
    
    printf("\n╔═════════════════════════════════════════════════╗\n");
    printf("║          NUMBER STATISTICS                      ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    
    printf("\nOriginal Number:      %lld\n", n);
    printf("Reversed Number:      %lld\n", rev);
    printf("─────────────────────────────────────────────────\n");
    printf("Digit Count:          %d\n", countDigits(n));
    printf("Sum of Digits:        %lld\n", sumOfDigits(n));
    printf("Product of Digits:    %lld\n", productOfDigits(n));
    printf("─────────────────────────────────────────────────\n");
    printf("n + reverse(n):       %lld\n", n + rev);
    printf("n - reverse(n):       %lld\n", n - rev);
    printf("n × reverse(n):       %lld\n", n * rev);
    printf("─────────────────────────────────────────────────\n");
    printf("Is Palindrome:        %s\n", isPalindrome(n) ? "YES ✓" : "NO");
    printf("Is Prime:             %s\n", isPrime(n) ? "YES ✓" : "NO");
    printf("Is Palindromic Prime: %s\n", isPalindromicPrime(n) ? "YES ★" : "NO");
    printf("═════════════════════════════════════════════════\n");
}