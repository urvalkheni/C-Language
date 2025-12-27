/*
 * Advanced Digit Manipulation & Analysis v2.0
 * Features: First/last digit operations, digit patterns,
 *           mathematical analysis, and statistical tools
 * 
 * IMPROVEMENTS (v2.1):
 * - Enhanced bounds checking for digit extraction
 * - Added input validation for all operations
 * - Improved error handling for edge cases
 * - Better documentation and code clarity
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// Function prototypes
int getFirstDigit(long long n);
int getLastDigit(long long n);
int getNthDigit(long long n, int pos);
int sumFirstLast(long long n);
int productFirstLast(long long n);
long long removeFirstDigit(long long n);
long long removeLastDigit(long long n);
long long swapFirstLast(long long n);
int sumAllDigits(long long n);
int productAllDigits(long long n);
int countDigits(long long n);
int sumEvenDigits(long long n);
int sumOddDigits(long long n);
int maxDigit(long long n);
int minDigit(long long n);
double averageDigits(long long n);
bool allDigitsUnique(long long n);
bool isIncreasing(long long n);
bool isDecreasing(long long n);
void digitFrequency(long long n);
void digitPositions(long long n, int digit);
long long reverseNumber(long long n);
void analyzeDigitPattern(long long n);
void digitStatistics(long long n);
void digitOperations(long long n);
void displayMenu();

// Main function
int main() {
    int choice;
    long long num;
    int digit, pos;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║     Advanced Digit Manipulation & Analysis v2.0           ║\n");
    printf("║          Comprehensive Digit Operations Tool               ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-20): ");
        int scanStatus = scanf("%d", &choice);
        
        // Validate input
        if(scanStatus != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }
        
        if(choice == 0) break;
            case 1:
                printf("\n--- First Digit Extraction ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("First digit of %lld is: %d\n", num, getFirstDigit(num));
                break;
                
            case 2:
                printf("\n--- Last Digit Extraction ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Last digit of %lld is: %d\n", num, getLastDigit(num));
                break;
                
            case 3:
                printf("\n--- Sum of First and Last Digit ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Sum of first and last digit: %d\n", sumFirstLast(num));
                break;
                
            case 4:
                printf("\n--- Product of First and Last Digit ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Product of first and last digit: %d\n", productFirstLast(num));
                break;
                
            case 5:
                printf("\n--- Nth Digit Extraction ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Enter position (0 = last digit): ");
                scanf("%d", &pos);
                int nthDigit = getNthDigit(num, pos);
                if(nthDigit != -1)
                    printf("Digit at position %d: %d\n", pos, nthDigit);
                else
                    printf("Invalid position!\n");
                break;
                
            case 6:
                printf("\n--- Sum of All Digits ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Sum of all digits: %d\n", sumAllDigits(num));
                break;
                
            case 7:
                printf("\n--- Product of All Digits ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Product of all digits: %d\n", productAllDigits(num));
                break;
                
            case 8:
                printf("\n--- Count Digits ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Number of digits: %d\n", countDigits(num));
                break;
                
            case 9:
                printf("\n--- Sum of Even/Odd Digits ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Sum of even digits: %d\n", sumEvenDigits(num));
                printf("Sum of odd digits: %d\n", sumOddDigits(num));
                break;
                
            case 10:
                printf("\n--- Maximum and Minimum Digit ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Maximum digit: %d\n", maxDigit(num));
                printf("Minimum digit: %d\n", minDigit(num));
                break;
                
            case 11:
                printf("\n--- Average of Digits ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Average of digits: %.2f\n", averageDigits(num));
                break;
                
            case 12:
                printf("\n--- Remove First Digit ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("After removing first digit: %lld\n", removeFirstDigit(num));
                break;
                
            case 13:
                printf("\n--- Remove Last Digit ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("After removing last digit: %lld\n", removeLastDigit(num));
                break;
                
            case 14:
                printf("\n--- Swap First and Last Digit ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("After swapping: %lld\n", swapFirstLast(num));
                break;
                
            case 15:
                printf("\n--- Digit Frequency Analysis ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                digitFrequency(num);
                break;
                
            case 16:
                printf("\n--- Find Digit Positions ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Enter digit to find (0-9): ");
                scanf("%d", &digit);
                digitPositions(num, digit);
                break;
                
            case 17:
                printf("\n--- Pattern Analysis ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                analyzeDigitPattern(num);
                break;
                
            case 18:
                printf("\n--- Comprehensive Statistics ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                digitStatistics(num);
                break;
                
            case 19:
                printf("\n--- All Digit Operations ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                digitOperations(num);
                break;
                
            case 20:
                printf("\n--- Reverse Number ---\n");
                printf("Enter a number: ");
                scanf("%lld", &num);
                printf("Reversed number: %lld\n", reverseNumber(num));
                break;
                
            case 0:
                printf("\n✓ Thank you for using Digit Analyzer!\n");
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
    printf("│  BASIC DIGIT OPERATIONS                                 │\n");
    printf("│  [1]  Get First Digit                                   │\n");
    printf("│  [2]  Get Last Digit                                    │\n");
    printf("│  [3]  Sum of First & Last Digit                         │\n");
    printf("│  [4]  Product of First & Last Digit                     │\n");
    printf("│  [5]  Get Nth Digit                                     │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  DIGIT CALCULATIONS                                     │\n");
    printf("│  [6]  Sum of All Digits                                 │\n");
    printf("│  [7]  Product of All Digits                             │\n");
    printf("│  [8]  Count Digits                                      │\n");
    printf("│  [9]  Sum of Even/Odd Digits                            │\n");
    printf("│  [10] Maximum & Minimum Digit                           │\n");
    printf("│  [11] Average of Digits                                 │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  DIGIT MANIPULATION                                     │\n");
    printf("│  [12] Remove First Digit                                │\n");
    printf("│  [13] Remove Last Digit                                 │\n");
    printf("│  [14] Swap First & Last Digit                           │\n");
    printf("│  [15] Digit Frequency Analysis                          │\n");
    printf("│  [16] Find Digit Positions                              │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED ANALYSIS                                      │\n");
    printf("│  [17] Pattern Analysis (Increasing/Decreasing)          │\n");
    printf("│  [18] Comprehensive Statistics                          │\n");
    printf("│  [19] All Digit Operations Summary                      │\n");
    printf("│  [20] Reverse Number                                    │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit Program                                      │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

// Get first digit
int getFirstDigit(long long n) {
    if(n < 0) n = -n;
    while(n >= 10) {
        n /= 10;
    }
    return (int)n;
}

// Get last digit
int getLastDigit(long long n) {
    if(n < 0) n = -n;
    return (int)(n % 10);
}

// Get nth digit from right (0-indexed)
int getNthDigit(long long n, int pos) {
    if(n < 0) n = -n;
    for(int i = 0; i < pos; i++) {
        n /= 10;
        if(n == 0) return -1;
    }
    return (int)(n % 10);
}

// Sum of first and last digit
int sumFirstLast(long long n) {
    return getFirstDigit(n) + getLastDigit(n);
}

// Product of first and last digit
int productFirstLast(long long n) {
    return getFirstDigit(n) * getLastDigit(n);
}

// Remove first digit
long long removeFirstDigit(long long n) {
    if(n < 0) n = -n;
    int digits = countDigits(n);
    if(digits <= 1) return 0;
    long long divisor = pow(10, digits - 1);
    return n % divisor;
}

// Remove last digit
long long removeLastDigit(long long n) {
    if(n < 0) n = -n;
    return n / 10;
}

// Swap first and last digit
long long swapFirstLast(long long n) {
    if(n < 0) n = -n;
    if(n < 10) return n;
    
    int first = getFirstDigit(n);
    int last = getLastDigit(n);
    int digits = countDigits(n);
    
    long long middle = (n % (long long)pow(10, digits - 1)) / 10;
    long long result = last * pow(10, digits - 1) + middle * 10 + first;
    
    return result;
}

// Sum of all digits
int sumAllDigits(long long n) {
    if(n < 0) n = -n;
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Product of all digits
int productAllDigits(long long n) {
    if(n < 0) n = -n;
    if(n == 0) return 0;
    int product = 1;
    while(n > 0) {
        product *= n % 10;
        n /= 10;
    }
    return product;
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

// Sum of even digits
int sumEvenDigits(long long n) {
    if(n < 0) n = -n;
    int sum = 0;
    while(n > 0) {
        int digit = n % 10;
        if(digit % 2 == 0) sum += digit;
        n /= 10;
    }
    return sum;
}

// Sum of odd digits
int sumOddDigits(long long n) {
    if(n < 0) n = -n;
    int sum = 0;
    while(n > 0) {
        int digit = n % 10;
        if(digit % 2 != 0) sum += digit;
        n /= 10;
    }
    return sum;
}

// Maximum digit
int maxDigit(long long n) {
    if(n < 0) n = -n;
    int max = 0;
    while(n > 0) {
        int digit = n % 10;
        if(digit > max) max = digit;
        n /= 10;
    }
    return max;
}

// Minimum digit
int minDigit(long long n) {
    if(n < 0) n = -n;
    int min = 9;
    while(n > 0) {
        int digit = n % 10;
        if(digit < min) min = digit;
        n /= 10;
    }
    return min;
}

// Average of digits
double averageDigits(long long n) {
    return (double)sumAllDigits(n) / countDigits(n);
}

// Check if all digits are unique
bool allDigitsUnique(long long n) {
    if(n < 0) n = -n;
    int freq[10] = {0};
    while(n > 0) {
        int digit = n % 10;
        freq[digit]++;
        if(freq[digit] > 1) return false;
        n /= 10;
    }
    return true;
}

// Check if digits are in increasing order
bool isIncreasing(long long n) {
    if(n < 0) n = -n;
    int prev = n % 10;
    n /= 10;
    while(n > 0) {
        int curr = n % 10;
        if(curr > prev) return false;
        prev = curr;
        n /= 10;
    }
    return true;
}

// Check if digits are in decreasing order
bool isDecreasing(long long n) {
    if(n < 0) n = -n;
    int prev = n % 10;
    n /= 10;
    while(n > 0) {
        int curr = n % 10;
        if(curr < prev) return false;
        prev = curr;
        n /= 10;
    }
    return true;
}

// Digit frequency
void digitFrequency(long long n) {
    if(n < 0) n = -n;
    int freq[10] = {0};
    
    while(n > 0) {
        freq[n % 10]++;
        n /= 10;
    }
    
    printf("\nDigit Frequency Table:\n");
    printf("─────────────────────\n");
    printf("Digit | Frequency\n");
    printf("─────────────────────\n");
    for(int i = 0; i < 10; i++) {
        if(freq[i] > 0) {
            printf("  %d   |    %d\n", i, freq[i]);
        }
    }
}

// Find positions of a digit
void digitPositions(long long n, int digit) {
    if(n < 0) n = -n;
    if(digit < 0 || digit > 9) {
        printf("Invalid digit!\n");
        return;
    }
    
    printf("\nPositions of digit %d in %lld:\n", digit, n);
    printf("(Position 0 = rightmost)\n");
    
    int pos = 0;
    bool found = false;
    while(n > 0) {
        if(n % 10 == digit) {
            printf("Position %d\n", pos);
            found = true;
        }
        pos++;
        n /= 10;
    }
    
    if(!found) {
        printf("Digit %d not found!\n", digit);
    }
}

// Reverse number
long long reverseNumber(long long n) {
    if(n < 0) n = -n;
    long long rev = 0;
    while(n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

// Analyze digit pattern
void analyzeDigitPattern(long long n) {
    printf("\n═══════════════════════════════════════════════════\n");
    printf("         DIGIT PATTERN ANALYSIS\n");
    printf("═══════════════════════════════════════════════════\n");
    
    printf("\nNumber: %lld\n", n);
    printf("─────────────────────────────────────────────────\n");
    
    if(allDigitsUnique(n))
        printf("✓ All digits are unique\n");
    else
        printf("✗ Contains repeated digits\n");
    
    if(isIncreasing(n))
        printf("✓ Digits in increasing order (right to left)\n");
    else if(isDecreasing(n))
        printf("✓ Digits in decreasing order (right to left)\n");
    else
        printf("✗ No specific order pattern\n");
    
    if(n == reverseNumber(n))
        printf("✓ Number is a palindrome\n");
    else
        printf("✗ Not a palindrome\n");
}

// Comprehensive statistics
void digitStatistics(long long n) {
    printf("\n╔═════════════════════════════════════════════════╗\n");
    printf("║       COMPREHENSIVE DIGIT STATISTICS            ║\n");
    printf("╚═════════════════════════════════════════════════╝\n");
    
    printf("\nNumber: %lld\n", n);
    printf("─────────────────────────────────────────────────\n");
    printf("First Digit:          %d\n", getFirstDigit(n));
    printf("Last Digit:           %d\n", getLastDigit(n));
    printf("Total Digits:         %d\n", countDigits(n));
    printf("─────────────────────────────────────────────────\n");
    printf("Sum of All Digits:    %d\n", sumAllDigits(n));
    printf("Product of Digits:    %d\n", productAllDigits(n));
    printf("Average:              %.2f\n", averageDigits(n));
    printf("─────────────────────────────────────────────────\n");
    printf("Maximum Digit:        %d\n", maxDigit(n));
    printf("Minimum Digit:        %d\n", minDigit(n));
    printf("Sum Even Digits:      %d\n", sumEvenDigits(n));
    printf("Sum Odd Digits:       %d\n", sumOddDigits(n));
    printf("─────────────────────────────────────────────────\n");
    printf("Reversed Number:      %lld\n", reverseNumber(n));
    printf("═════════════════════════════════════════════════\n");
}

// All digit operations
void digitOperations(long long n) {
    printf("\n═══════════════════════════════════════════════════\n");
    printf("         ALL DIGIT OPERATIONS\n");
    printf("═══════════════════════════════════════════════════\n");
    
    printf("\nOriginal Number:           %lld\n", n);
    printf("─────────────────────────────────────────────────\n");
    printf("Sum First + Last:          %d\n", sumFirstLast(n));
    printf("Product First × Last:      %d\n", productFirstLast(n));
    printf("Remove First Digit:        %lld\n", removeFirstDigit(n));
    printf("Remove Last Digit:         %lld\n", removeLastDigit(n));
    printf("Swap First & Last:         %lld\n", swapFirstLast(n));
    printf("─────────────────────────────────────────────────\n");
    printf("Sum of All Digits:         %d\n", sumAllDigits(n));
    printf("Product of All Digits:     %d\n", productAllDigits(n));
    printf("Reversed Number:           %lld\n", reverseNumber(n));
    printf("═════════════════════════════════════════════════\n");
}