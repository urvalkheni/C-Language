/*
 * Advanced Armstrong Number Analyzer v2.0
 * Features: Armstrong detection, generation, analysis,
 *           narcissistic numbers, and digit operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
void checkArmstrong();
void armstrongRange();
void generateArmstrong();
void narcissisticNumbers();
void digitPower();
void armstrongStatistics();
void multiDigitArmstrong();
void perfectDigitalInvariant();
void sumOfPowers();
void armstrongPyramid();
void digitalRoot();
void happyNumber();
void kaprekarNumber();
void automorphicNumber();
void armstrongAnalysis();
void displayMenu();

// Helper functions
int countDigits(int num);
int power(int base, int exp);
bool isArmstrong(int num);

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║      Advanced Armstrong Number Analyzer v2.0              ║\n");
    printf("║         Comprehensive Digit Analysis System                ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                checkArmstrong();
                break;
            case 2:
                armstrongRange();
                break;
            case 3:
                generateArmstrong();
                break;
            case 4:
                narcissisticNumbers();
                break;
            case 5:
                digitPower();
                break;
            case 6:
                armstrongStatistics();
                break;
            case 7:
                multiDigitArmstrong();
                break;
            case 8:
                perfectDigitalInvariant();
                break;
            case 9:
                sumOfPowers();
                break;
            case 10:
                armstrongPyramid();
                break;
            case 11:
                digitalRoot();
                break;
            case 12:
                happyNumber();
                break;
            case 13:
                kaprekarNumber();
                break;
            case 14:
                automorphicNumber();
                break;
            case 15:
                armstrongAnalysis();
                break;
            case 16:
                printf("\n--- Armstrong Numbers Info ---\n");
                printf("\n• Definition: Sum of digits raised to\n");
                printf("  power of digit count equals number\n");
                printf("• Example: 153 = 1³ + 5³ + 3³\n");
                printf("• Also called: Narcissistic numbers\n");
                printf("• 3-digit: 153, 370, 371, 407\n");
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Armstrong Analyzer!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC OPERATIONS                                       │\n");
    printf("│  [1]  Check Armstrong Number                            │\n");
    printf("│  [2]  Armstrong Numbers in Range                        │\n");
    printf("│  [3]  Generate N Armstrong Numbers                      │\n");
    printf("│  [4]  Narcissistic Numbers                              │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  DIGIT ANALYSIS                                         │\n");
    printf("│  [5]  Digit Power Calculator                            │\n");
    printf("│  [6]  Armstrong Statistics                              │\n");
    printf("│  [7]  Multi-Digit Armstrong Finder                      │\n");
    printf("│  [8]  Perfect Digital Invariant                         │\n");
    printf("│  [9]  Sum of Powers                                     │\n");
    printf("│  [10] Armstrong Pyramid                                 │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL NUMBERS                                        │\n");
    printf("│  [11] Digital Root                                      │\n");
    printf("│  [12] Happy Number                                      │\n");
    printf("│  [13] Kaprekar Number                                   │\n");
    printf("│  [14] Automorphic Number                                │\n");
    printf("│  [15] Comprehensive Analysis                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Armstrong Info                                    │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

int countDigits(int num) {
    int count = 0;
    while(num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int power(int base, int exp) {
    int result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

bool isArmstrong(int num) {
    int original = num, sum = 0;
    int digits = countDigits(num);
    
    while(num != 0) {
        int digit = num % 10;
        sum += power(digit, digits);
        num /= 10;
    }
    
    return sum == original;
}

void checkArmstrong() {
    int n;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    
    int original = n, sum = 0;
    int digits = countDigits(n);
    
    printf("\n--- Armstrong Check ---\n");
    printf("Number: %d\n", n);
    printf("Digits: %d\n", digits);
    printf("\nCalculation:\n");
    
    int temp = n;
    while(temp != 0) {
        int digit = temp % 10;
        int p = power(digit, digits);
        printf("%d^%d = %d\n", digit, digits, p);
        sum += p;
        temp /= 10;
    }
    
    printf("\nSum: %d\n", sum);
    printf("Result: %s\n", sum == original ? "Armstrong Number ✓" : "Not Armstrong ✗");
}

void armstrongRange() {
    int start, end;
    printf("\nEnter start: ");
    scanf("%d", &start);
    printf("Enter end: ");
    scanf("%d", &end);
    
    if(start < 0 || end < 0 || start > end) {
        printf("Error: Invalid range! Start must be >= 0 and start <= end.\n");
        return;
    }
    
    if(end > 999999) {
        printf("Warning: Large range may take time to compute.\n");
    }
    
    printf("\n--- Armstrong Numbers in Range ---\n");
    printf("Range: %d to %d\n\n", start, end);
    
    int count = 0;
    for(int i = start; i <= end; i++) {
        if(isArmstrong(i)) {
            printf("%d ", i);
            count++;
        }
    }
    
    if(count == 0)
        printf("No Armstrong numbers found");
    printf("\n\nTotal: %d\n", count);
}

void generateArmstrong() {
    int n;
    printf("\nHow many Armstrong numbers to generate: ");
    scanf("%d", &n);
    
    printf("\n--- First %d Armstrong Numbers ---\n\n", n);
    
    int count = 0, num = 0;
    while(count < n) {
        if(isArmstrong(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

void narcissisticNumbers() {
    int digits;
    printf("\nEnter number of digits: ");
    scanf("%d", &digits);
    
    printf("\n--- %d-Digit Narcissistic Numbers ---\n\n", digits);
    
    int start = power(10, digits - 1);
    int end = power(10, digits) - 1;
    
    if(digits == 1) start = 0;
    
    int count = 0;
    for(int i = start; i <= end; i++) {
        if(isArmstrong(i)) {
            printf("%d ", i);
            count++;
        }
    }
    
    if(count == 0)
        printf("No narcissistic numbers");
    printf("\n\nTotal: %d\n", count);
}

void digitPower() {
    int num;
    printf("\nEnter a number: ");
    scanf("%d", &num);
    
    int digits = countDigits(num);
    
    printf("\n--- Digit Power Calculator ---\n");
    printf("Number: %d\n", num);
    printf("Digits: %d\n\n", digits);
    
    int temp = num;
    while(temp != 0) {
        int digit = temp % 10;
        printf("%d^%d = %d\n", digit, digits, power(digit, digits));
        temp /= 10;
    }
}

void armstrongStatistics() {
    int limit;
    printf("\nEnter upper limit: ");
    scanf("%d", &limit);
    
    int count[10] = {0};
    int total = 0;
    
    for(int i = 0; i <= limit; i++) {
        if(isArmstrong(i)) {
            count[countDigits(i)]++;
            total++;
        }
    }
    
    printf("\n--- Armstrong Statistics ---\n");
    printf("Range: 0 to %d\n\n", limit);
    
    for(int i = 1; i < 10; i++) {
        if(count[i] > 0) {
            printf("%d-digit Armstrong numbers: %d\n", i, count[i]);
        }
    }
    
    printf("\nTotal Armstrong numbers: %d\n", total);
}

void multiDigitArmstrong() {
    printf("\n--- Multi-Digit Armstrong Numbers ---\n\n");
    
    printf("1-digit: ");
    for(int i = 0; i < 10; i++)
        if(isArmstrong(i)) printf("%d ", i);
    
    printf("\n2-digit: None");
    
    printf("\n3-digit: ");
    for(int i = 100; i < 1000; i++)
        if(isArmstrong(i)) printf("%d ", i);
    
    printf("\n4-digit: ");
    int count = 0;
    for(int i = 1000; i < 10000 && count < 10; i++) {
        if(isArmstrong(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
}

void perfectDigitalInvariant() {
    int num, k;
    printf("\nEnter number: ");
    scanf("%d", &num);
    printf("Enter power k: ");
    scanf("%d", &k);
    
    int original = num, sum = 0;
    
    while(num != 0) {
        int digit = num % 10;
        sum += power(digit, k);
        num /= 10;
    }
    
    printf("\n--- Perfect Digital Invariant ---\n");
    printf("Number: %d\n", original);
    printf("Power: %d\n", k);
    printf("Sum: %d\n", sum);
    printf("Result: %s\n", sum == original ? "PDI" : "Not PDI");
}

void sumOfPowers() {
    int n, p;
    printf("\nEnter number: ");
    scanf("%d", &n);
    printf("Enter power: ");
    scanf("%d", &p);
    
    printf("\n--- Sum of Powers ---\n");
    
    int sum = 0;
    int temp = n;
    
    while(temp != 0) {
        int digit = temp % 10;
        sum += power(digit, p);
        temp /= 10;
    }
    
    printf("Sum: %d\n", sum);
}

void armstrongPyramid() {
    int levels;
    printf("\nEnter number of levels: ");
    scanf("%d", &levels);
    
    printf("\n--- Armstrong Pyramid ---\n\n");
    
    int num = 0, count = 0;
    for(int i = 1; i <= levels; i++) {
        for(int j = 0; j < i && count < levels; j++) {
            while(!isArmstrong(num)) num++;
            printf("%d ", num);
            num++;
            count++;
        }
        printf("\n");
    }
}

void digitalRoot() {
    int n;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    
    printf("\n--- Digital Root ---\n");
    printf("Number: %d\n", n);
    
    while(n >= 10) {
        int sum = 0;
        while(n != 0) {
            sum += n % 10;
            n /= 10;
        }
        printf("→ %d\n", sum);
        n = sum;
    }
    
    printf("\nDigital Root: %d\n", n);
}

void happyNumber() {
    int n;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    
    printf("\n--- Happy Number ---\n");
    printf("Number: %d\n", n);
    
    int seen[1000] = {0};
    int steps = 0;
    
    while(n != 1 && !seen[n]) {
        seen[n] = 1;
        int sum = 0;
        while(n != 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
        printf("→ %d\n", n);
        steps++;
        if(steps > 100) break;
    }
    
    printf("\nResult: %s\n", n == 1 ? "Happy Number ✓" : "Sad Number ✗");
}

void kaprekarNumber() {
    int n;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    
    long long square = (long long)n * n;
    int digits = countDigits(n);
    int divisor = power(10, digits);
    
    int right = square % divisor;
    int left = square / divisor;
    
    printf("\n--- Kaprekar Number ---\n");
    printf("Number: %d\n", n);
    printf("Square: %lld\n", square);
    printf("Left: %d, Right: %d\n", left, right);
    printf("Sum: %d\n", left + right);
    printf("Result: %s\n", (left + right == n) ? "Kaprekar ✓" : "Not Kaprekar ✗");
}

void automorphicNumber() {
    int n;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    
    long long square = (long long)n * n;
    int digits = countDigits(n);
    int divisor = power(10, digits);
    
    printf("\n--- Automorphic Number ---\n");
    printf("Number: %d\n", n);
    printf("Square: %lld\n", square);
    printf("Last %d digits of square: %lld\n", digits, square % divisor);
    printf("Result: %s\n", (square % divisor == n) ? "Automorphic ✓" : "Not Automorphic ✗");
}

void armstrongAnalysis() {
    int n;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    
    printf("\n--- Comprehensive Analysis ---\n");
    printf("Number: %d\n", n);
    printf("Digits: %d\n", countDigits(n));
    printf("\nTests:\n");
    printf("• Armstrong: %s\n", isArmstrong(n) ? "Yes ✓" : "No ✗");
    
    long long square = (long long)n * n;
    int digits = countDigits(n);
    int divisor = power(10, digits);
    
    printf("• Automorphic: %s\n", (square % divisor == n) ? "Yes ✓" : "No ✗");
    
    int left = square / divisor;
    int right = square % divisor;
    printf("• Kaprekar: %s\n", (left + right == n) ? "Yes ✓" : "No ✗");
}