/*
 * Advanced Digit Operations & Analysis Tool v2.0
 * Features: Digit counting, sum, product, manipulation,
 *           patterns, and comprehensive digit analysis
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
void countDigits(long long n);
void sumOfDigits(long long n);
void productOfDigits(long long n);
void reverseDigits(long long n);
void findMaxMinDigit(long long n);
void countEvenOddDigits(long long n);
void findDigitFrequency(long long n);
void removeDigit(long long n);
void insertDigit(long long n);
void digitAtPosition(long long n);
void sumOfEvenDigits(long long n);
void sumOfOddDigits(long long n);
void alternateDigitSum(long long n);
void digitalRoot(long long n);
void persistenceNumber(long long n);
void displayMenu();

int main() {
    int choice;
    long long num;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║    Advanced Digit Operations & Analysis Tool v2.0         ║\n");
    printf("║         Comprehensive Digit Manipulation System           ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        if(choice >= 1 && choice <= 16) {
            printf("\nEnter a number: ");
            scanf("%lld", &num);
            
            switch(choice) {
                case 1:
                    countDigits(num);
                    break;
                case 2:
                    sumOfDigits(num);
                    break;
                case 3:
                    productOfDigits(num);
                    break;
                case 4:
                    reverseDigits(num);
                    break;
                case 5:
                    findMaxMinDigit(num);
                    break;
                case 6:
                    countEvenOddDigits(num);
                    break;
                case 7:
                    findDigitFrequency(num);
                    break;
                case 8:
                    removeDigit(num);
                    break;
                case 9:
                    insertDigit(num);
                    break;
                case 10:
                    digitAtPosition(num);
                    break;
                case 11:
                    sumOfEvenDigits(num);
                    break;
                case 12:
                    sumOfOddDigits(num);
                    break;
                case 13:
                    alternateDigitSum(num);
                    break;
                case 14:
                    digitalRoot(num);
                    break;
                case 15:
                    persistenceNumber(num);
                    break;
                case 16: {
                    printf("\n--- Quick Reference ---\n");
                    printf("\nDigit Operations:\n");
                    printf("• Count: Total number of digits\n");
                    printf("• Sum: Add all digits\n");
                    printf("• Product: Multiply all digits\n");
                    printf("• Digital Root: Recursive sum until single digit\n");
                    printf("• Persistence: Steps to reach single digit product\n");
                    break;
                }
            }
        } else {
            printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Digit Analyzer!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC OPERATIONS                                       │\n");
    printf("│  [1]  Count Digits                                      │\n");
    printf("│  [2]  Sum of Digits                                     │\n");
    printf("│  [3]  Product of Digits                                 │\n");
    printf("│  [4]  Reverse Digits                                    │\n");
    printf("│  [5]  Find Max/Min Digit                                │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ANALYSIS                                               │\n");
    printf("│  [6]  Count Even/Odd Digits                             │\n");
    printf("│  [7]  Digit Frequency                                   │\n");
    printf("│  [10] Digit at Position                                 │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  MANIPULATION                                           │\n");
    printf("│  [8]  Remove Digit                                      │\n");
    printf("│  [9]  Insert Digit                                      │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL OPERATIONS                                     │\n");
    printf("│  [11] Sum of Even Digits                                │\n");
    printf("│  [12] Sum of Odd Digits                                 │\n");
    printf("│  [13] Alternate Digit Sum                               │\n");
    printf("│  [14] Digital Root                                      │\n");
    printf("│  [15] Multiplicative Persistence                        │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Quick Reference                                   │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void countDigits(long long n) {
    printf("\n--- Count Digits ---\n");
    n = llabs(n);
    
    if(n == 0) {
        printf("Number of digits: 1\n");
        return;
    }
    
    int count = 0;
    long long temp = n;
    while(temp > 0) {
        count++;
        temp /= 10;
    }
    
    printf("Number: %lld\n", n);
    printf("Number of digits: %d\n", count);
}

void sumOfDigits(long long n) {
    printf("\n--- Sum of Digits ---\n");
    n = llabs(n);
    
    long long sum = 0, temp = n;
    while(temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    
    printf("Number: %lld\n", n);
    printf("Sum of digits: %lld\n", sum);
}

void productOfDigits(long long n) {
    printf("\n--- Product of Digits ---\n");
    n = llabs(n);
    
    long long product = 1, temp = n;
    while(temp > 0) {
        product *= temp % 10;
        temp /= 10;
    }
    
    printf("Number: %lld\n", n);
    printf("Product of digits: %lld\n", product);
}

void reverseDigits(long long n) {
    printf("\n--- Reverse Digits ---\n");
    bool isNegative = n < 0;
    n = llabs(n);
    
    long long reversed = 0, temp = n;
    while(temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    
    printf("Original: %lld\n", n);
    printf("Reversed: %lld\n", isNegative ? -reversed : reversed);
}

void findMaxMinDigit(long long n) {
    printf("\n--- Find Max/Min Digit ---\n");
    n = llabs(n);
    
    int max = 0, min = 9;
    long long temp = n;
    
    while(temp > 0) {
        int digit = temp % 10;
        if(digit > max) max = digit;
        if(digit < min) min = digit;
        temp /= 10;
    }
    
    printf("Number: %lld\n", n);
    printf("Maximum digit: %d\n", max);
    printf("Minimum digit: %d\n", min);
    printf("Difference: %d\n", max - min);
}

void countEvenOddDigits(long long n) {
    printf("\n--- Count Even/Odd Digits ---\n");
    n = llabs(n);
    
    int even = 0, odd = 0;
    long long temp = n;
    
    while(temp > 0) {
        if((temp % 10) % 2 == 0)
            even++;
        else
            odd++;
        temp /= 10;
    }
    
    printf("Number: %lld\n", n);
    printf("Even digits: %d\n", even);
    printf("Odd digits: %d\n", odd);
    printf("Total: %d\n", even + odd);
}

void findDigitFrequency(long long n) {
    printf("\n--- Digit Frequency ---\n");
    n = llabs(n);
    
    int freq[10] = {0};
    long long temp = n;
    
    while(temp > 0) {
        freq[temp % 10]++;
        temp /= 10;
    }
    
    printf("Number: %lld\n\n", n);
    for(int i = 0; i < 10; i++) {
        if(freq[i] > 0) {
            printf("Digit %d: %d time(s)\n", i, freq[i]);
        }
    }
}

void removeDigit(long long n) {
    int pos;
    printf("\n--- Remove Digit ---\n");
    printf("Enter position to remove (1-based): ");
    scanf("%d", &pos);
    
    n = llabs(n);
    long long result = 0, temp = n, multiplier = 1;
    int count = 0;
    
    while(temp > 0) {
        temp /= 10;
        count++;
    }
    
    if(pos < 1 || pos > count) {
        printf("Invalid position!\n");
        return;
    }
    
    temp = n;
    int currentPos = 1;
    while(temp > 0) {
        int digit = temp % 10;
        if(currentPos != pos) {
            result += digit * multiplier;
            multiplier *= 10;
        }
        temp /= 10;
        currentPos++;
    }
    
    printf("Original: %lld\n", n);
    printf("After removing position %d: %lld\n", pos, result);
}

void insertDigit(long long n) {
    int pos, digit;
    printf("\n--- Insert Digit ---\n");
    printf("Enter position to insert (1-based): ");
    scanf("%d", &pos);
    printf("Enter digit to insert (0-9): ");
    scanf("%d", &digit);
    
    if(digit < 0 || digit > 9) {
        printf("Invalid digit!\n");
        return;
    }
    
    n = llabs(n);
    printf("Original: %lld\n", n);
    printf("After inserting %d at position %d: ", digit, pos);
    
    long long result = 0, temp = n, multiplier = 1;
    int currentPos = 1;
    bool inserted = false;
    
    while(temp > 0 || !inserted) {
        if(currentPos == pos && !inserted) {
            result += digit * multiplier;
            multiplier *= 10;
            inserted = true;
        } else {
            result += (temp % 10) * multiplier;
            multiplier *= 10;
            temp /= 10;
            currentPos++;
        }
    }
    
    printf("%lld\n", result);
}

void digitAtPosition(long long n) {
    int pos;
    printf("\n--- Digit at Position ---\n");
    printf("Enter position (1-based from right): ");
    scanf("%d", &pos);
    
    n = llabs(n);
    long long temp = n;
    
    for(int i = 1; i < pos && temp > 0; i++) {
        temp /= 10;
    }
    
    if(temp == 0) {
        printf("Position %d is out of range!\n", pos);
    } else {
        printf("Digit at position %d: %lld\n", pos, temp % 10);
    }
}

void sumOfEvenDigits(long long n) {
    printf("\n--- Sum of Even Digits ---\n");
    n = llabs(n);
    
    long long sum = 0, temp = n;
    while(temp > 0) {
        int digit = temp % 10;
        if(digit % 2 == 0) sum += digit;
        temp /= 10;
    }
    
    printf("Number: %lld\n", n);
    printf("Sum of even digits: %lld\n", sum);
}

void sumOfOddDigits(long long n) {
    printf("\n--- Sum of Odd Digits ---\n");
    n = llabs(n);
    
    long long sum = 0, temp = n;
    while(temp > 0) {
        int digit = temp % 10;
        if(digit % 2 != 0) sum += digit;
        temp /= 10;
    }
    
    printf("Number: %lld\n", n);
    printf("Sum of odd digits: %lld\n", sum);
}

void alternateDigitSum(long long n) {
    printf("\n--- Alternate Digit Sum ---\n");
    n = llabs(n);
    
    long long sum = 0, temp = n;
    bool add = true;
    
    while(temp > 0) {
        if(add)
            sum += temp % 10;
        else
            sum -= temp % 10;
        add = !add;
        temp /= 10;
    }
    
    printf("Number: %lld\n", n);
    printf("Alternate sum: %lld\n", sum);
}

void digitalRoot(long long n) {
    printf("\n--- Digital Root ---\n");
    n = llabs(n);
    
    long long original = n;
    int steps = 0;
    
    while(n >= 10) {
        long long sum = 0;
        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
        steps++;
        printf("Step %d: %lld\n", steps, n);
    }
    
    printf("\nOriginal: %lld\n", original);
    printf("Digital root: %lld\n", n);
    printf("Steps taken: %d\n", steps);
}

void persistenceNumber(long long n) {
    printf("\n--- Multiplicative Persistence ---\n");
    n = llabs(n);
    
    long long original = n;
    int steps = 0;
    
    while(n >= 10) {
        long long product = 1;
        while(n > 0) {
            product *= n % 10;
            n /= 10;
        }
        n = product;
        steps++;
        printf("Step %d: %lld\n", steps, n);
    }
    
    printf("\nOriginal: %lld\n", original);
    printf("Final single digit: %lld\n", n);
    printf("Multiplicative persistence: %d\n", steps);
}