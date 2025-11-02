/*
 * Advanced Number Properties Analyzer v2.0
 * Features: Complete mathematical property analysis,
 *           number theory, and special number detection
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
void checkBasic(int num);
void checkPrime(int num);
void checkPerfect(int num);
void checkArmstrong(int num);
void checkPalindrome(int num);
void checkFibonacci(int num);
void checkHarshad(int num);
void checkAbundant(int num);
void checkDeficient(int num);
void checkAutomorphic(int num);
void checkNeon(int num);
void checkDuck(int num);
void checkSpy(int num);
void checkKrishnamurthy(int num);
void checkPronic(int num);
void displayAllProperties(int num);
void numberFactorization(int num);
void digitAnalysis(int num);
void displayMenu();

// Main function
int main() {
    int choice, num;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║    Advanced Number Properties Analyzer v2.0               ║\n");
    printf("║     Comprehensive Mathematical Analysis Tool              ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-18): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        if(choice >= 1 && choice <= 18) {
            printf("\nEnter a number: ");
            scanf("%d", &num);
            
            switch(choice) {
                case 1:
                    checkBasic(num);
                    break;
                case 2:
                    checkPrime(num);
                    break;
                case 3:
                    checkPerfect(num);
                    break;
                case 4:
                    checkArmstrong(num);
                    break;
                case 5:
                    checkPalindrome(num);
                    break;
                case 6:
                    checkFibonacci(num);
                    break;
                case 7:
                    checkHarshad(num);
                    break;
                case 8:
                    checkAbundant(num);
                    break;
                case 9:
                    checkDeficient(num);
                    break;
                case 10:
                    checkAutomorphic(num);
                    break;
                case 11:
                    checkNeon(num);
                    break;
                case 12:
                    checkDuck(num);
                    break;
                case 13:
                    checkSpy(num);
                    break;
                case 14:
                    checkKrishnamurthy(num);
                    break;
                case 15:
                    checkPronic(num);
                    break;
                case 16:
                    displayAllProperties(num);
                    break;
                case 17:
                    numberFactorization(num);
                    break;
                case 18:
                    digitAnalysis(num);
                    break;
            }
        } else {
            printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Number Analyzer!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC PROPERTIES                                       │\n");
    printf("│  [1]  Check Even/Odd/Zero/Positive/Negative             │\n");
    printf("│  [2]  Check Prime Number                                │\n");
    printf("│  [3]  Check Perfect Number                              │\n");
    printf("│  [4]  Check Armstrong Number                            │\n");
    printf("│  [5]  Check Palindrome Number                           │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL NUMBERS                                        │\n");
    printf("│  [6]  Check Fibonacci Number                            │\n");
    printf("│  [7]  Check Harshad Number                              │\n");
    printf("│  [8]  Check Abundant Number                             │\n");
    printf("│  [9]  Check Deficient Number                            │\n");
    printf("│  [10] Check Automorphic Number                          │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED TYPES                                         │\n");
    printf("│  [11] Check Neon Number                                 │\n");
    printf("│  [12] Check Duck Number                                 │\n");
    printf("│  [13] Check Spy Number                                  │\n");
    printf("│  [14] Check Krishnamurthy Number                        │\n");
    printf("│  [15] Check Pronic Number                               │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  COMPREHENSIVE ANALYSIS                                 │\n");
    printf("│  [16] Display All Properties                            │\n");
    printf("│  [17] Prime Factorization                               │\n");
    printf("│  [18] Digit Analysis                                    │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void checkBasic(int num) {
    printf("\n--- Basic Properties ---\n");
    
    if(num == 0) {
        printf("✓ %d is ZERO\n", num);
    } else if(num > 0) {
        printf("✓ %d is POSITIVE\n", num);
        if(num % 2 == 0)
            printf("✓ %d is EVEN\n", num);
        else
            printf("✓ %d is ODD\n", num);
    } else {
        printf("✓ %d is NEGATIVE\n", num);
        printf("  Absolute value: %d\n", abs(num));
    }
}

void checkPrime(int num) {
    printf("\n--- Prime Check ---\n");
    
    if(num <= 1) {
        printf("✗ %d is NOT prime (must be > 1)\n", num);
        return;
    }
    
    bool isPrime = true;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            isPrime = false;
            break;
        }
    }
    
    if(isPrime)
        printf("✓ %d is a PRIME number\n", num);
    else
        printf("✗ %d is NOT prime\n", num);
}

void checkPerfect(int num) {
    printf("\n--- Perfect Number Check ---\n");
    
    if(num <= 0) {
        printf("✗ Invalid (must be positive)\n");
        return;
    }
    
    int sum = 0;
    printf("Divisors: ");
    for(int i = 1; i < num; i++) {
        if(num % i == 0) {
            printf("%d ", i);
            sum += i;
        }
    }
    printf("\nSum of divisors: %d\n", sum);
    
    if(sum == num)
        printf("✓ %d is a PERFECT number\n", num);
    else
        printf("✗ %d is NOT perfect\n", num);
}

void checkArmstrong(int num) {
    printf("\n--- Armstrong Number Check ---\n");
    
    int original = abs(num), sum = 0, temp = original, digits = 0;
    
    while(temp > 0) {
        digits++;
        temp /= 10;
    }
    
    temp = original;
    while(temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }
    
    printf("Number of digits: %d\n", digits);
    printf("Sum of digits^%d: %d\n", digits, sum);
    
    if(sum == original)
        printf("✓ %d is an ARMSTRONG number\n", num);
    else
        printf("✗ %d is NOT Armstrong\n", num);
}

void checkPalindrome(int num) {
    printf("\n--- Palindrome Check ---\n");
    
    int original = abs(num), reversed = 0, temp = original;
    
    while(temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    
    printf("Original: %d\n", original);
    printf("Reversed: %d\n", reversed);
    
    if(reversed == original)
        printf("✓ %d is a PALINDROME\n", num);
    else
        printf("✗ %d is NOT palindrome\n", num);
}

void checkFibonacci(int num) {
    printf("\n--- Fibonacci Check ---\n");
    
    if(num < 0) {
        printf("✗ Invalid (must be non-negative)\n");
        return;
    }
    
    int a = 0, b = 1, c;
    printf("Fibonacci sequence: 0 1 ");
    
    while(b < num) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
    
    if(b == num || num == 0)
        printf("✓ %d is a FIBONACCI number\n", num);
    else
        printf("✗ %d is NOT Fibonacci\n", num);
}

void checkHarshad(int num) {
    printf("\n--- Harshad (Niven) Number Check ---\n");
    
    if(num <= 0) {
        printf("✗ Invalid (must be positive)\n");
        return;
    }
    
    int sum = 0, temp = num;
    while(temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    
    printf("Sum of digits: %d\n", sum);
    
    if(num % sum == 0)
        printf("✓ %d is a HARSHAD number\n", num);
    else
        printf("✗ %d is NOT Harshad\n", num);
}

void checkAbundant(int num) {
    printf("\n--- Abundant Number Check ---\n");
    
    if(num <= 0) {
        printf("✗ Invalid (must be positive)\n");
        return;
    }
    
    int sum = 0;
    for(int i = 1; i < num; i++) {
        if(num % i == 0) sum += i;
    }
    
    printf("Sum of proper divisors: %d\n", sum);
    
    if(sum > num)
        printf("✓ %d is ABUNDANT (sum > number)\n", num);
    else
        printf("✗ %d is NOT abundant\n", num);
}

void checkDeficient(int num) {
    printf("\n--- Deficient Number Check ---\n");
    
    if(num <= 0) {
        printf("✗ Invalid (must be positive)\n");
        return;
    }
    
    int sum = 0;
    for(int i = 1; i < num; i++) {
        if(num % i == 0) sum += i;
    }
    
    printf("Sum of proper divisors: %d\n", sum);
    
    if(sum < num)
        printf("✓ %d is DEFICIENT (sum < number)\n", num);
    else
        printf("✗ %d is NOT deficient\n", num);
}

void checkAutomorphic(int num) {
    printf("\n--- Automorphic Number Check ---\n");
    
    if(num < 0) {
        printf("✗ Invalid (must be non-negative)\n");
        return;
    }
    
    int square = num * num;
    int temp = num, digits = 0;
    
    while(temp > 0) {
        digits++;
        temp /= 10;
    }
    
    int divisor = pow(10, digits);
    int lastDigits = square % divisor;
    
    printf("%d² = %d\n", num, square);
    printf("Last %d digit(s): %d\n", digits, lastDigits);
    
    if(lastDigits == num)
        printf("✓ %d is AUTOMORPHIC\n", num);
    else
        printf("✗ %d is NOT automorphic\n", num);
}

void checkNeon(int num) {
    printf("\n--- Neon Number Check ---\n");
    
    if(num < 0) {
        printf("✗ Invalid (must be non-negative)\n");
        return;
    }
    
    int square = num * num, sum = 0, temp = square;
    
    while(temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    
    printf("%d² = %d\n", num, square);
    printf("Sum of digits of square: %d\n", sum);
    
    if(sum == num)
        printf("✓ %d is a NEON number\n", num);
    else
        printf("✗ %d is NOT neon\n", num);
}

void checkDuck(int num) {
    printf("\n--- Duck Number Check ---\n");
    
    if(num <= 0) {
        printf("✗ Invalid (must be positive)\n");
        return;
    }
    
    int temp = num;
    bool hasZero = false, firstDigit = true;
    
    while(temp > 0) {
        int digit = temp % 10;
        if(digit == 0 && !firstDigit) hasZero = true;
        firstDigit = false;
        temp /= 10;
    }
    
    if(hasZero)
        printf("✓ %d is a DUCK number (contains 0 but doesn't start with 0)\n", num);
    else
        printf("✗ %d is NOT duck\n", num);
}

void checkSpy(int num) {
    printf("\n--- Spy Number Check ---\n");
    
    int sum = 0, product = 1, temp = abs(num);
    
    while(temp > 0) {
        int digit = temp % 10;
        sum += digit;
        product *= digit;
        temp /= 10;
    }
    
    printf("Sum of digits: %d\n", sum);
    printf("Product of digits: %d\n", product);
    
    if(sum == product)
        printf("✓ %d is a SPY number\n", num);
    else
        printf("✗ %d is NOT spy\n", num);
}

void checkKrishnamurthy(int num) {
    printf("\n--- Krishnamurthy Number Check ---\n");
    
    if(num < 0) {
        printf("✗ Invalid (must be non-negative)\n");
        return;
    }
    
    int sum = 0, temp = num;
    
    while(temp > 0) {
        int digit = temp % 10;
        int fact = 1;
        for(int i = 1; i <= digit; i++) fact *= i;
        sum += fact;
        temp /= 10;
    }
    
    printf("Sum of factorial of digits: %d\n", sum);
    
    if(sum == num)
        printf("✓ %d is a KRISHNAMURTHY number\n", num);
    else
        printf("✗ %d is NOT Krishnamurthy\n", num);
}

void checkPronic(int num) {
    printf("\n--- Pronic Number Check ---\n");
    
    if(num < 0) {
        printf("✗ Invalid (must be non-negative)\n");
        return;
    }
    
    int n = sqrt(num);
    
    if(n * (n + 1) == num)
        printf("✓ %d is PRONIC (%d × %d)\n", num, n, n+1);
    else
        printf("✗ %d is NOT pronic\n", num);
}

void displayAllProperties(int num) {
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║           COMPREHENSIVE ANALYSIS: %d\n", num);
    printf("╚════════════════════════════════════════════════════════════╝\n");
    
    checkBasic(num);
    checkPrime(num);
    checkPerfect(num);
    checkArmstrong(num);
    checkPalindrome(num);
    checkFibonacci(num);
}

void numberFactorization(int num) {
    printf("\n--- Prime Factorization ---\n");
    
    if(num <= 1) {
        printf("✗ Cannot factorize %d\n", num);
        return;
    }
    
    int n = abs(num);
    printf("%d = ", n);
    
    for(int i = 2; i <= n; i++) {
        while(n % i == 0) {
            printf("%d", i);
            n /= i;
            if(n > 1) printf(" × ");
        }
    }
    printf("\n");
}

void digitAnalysis(int num) {
    printf("\n--- Digit Analysis ---\n");
    
    int temp = abs(num), digitCount = 0, digitSum = 0, digitProduct = 1;
    int maxDigit = 0, minDigit = 9;
    
    while(temp > 0) {
        int digit = temp % 10;
        digitCount++;
        digitSum += digit;
        digitProduct *= digit;
        if(digit > maxDigit) maxDigit = digit;
        if(digit < minDigit) minDigit = digit;
        temp /= 10;
    }
    
    printf("Number of digits: %d\n", digitCount);
    printf("Sum of digits: %d\n", digitSum);
    printf("Product of digits: %d\n", digitProduct);
    printf("Maximum digit: %d\n", maxDigit);
    printf("Minimum digit: %d\n", minDigit);
    printf("Average digit: %.2f\n", (float)digitSum / digitCount);
}