// Enhanced Number Reversal Analyzer with Palindrome Detection and Advanced Features
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>

#define MAX_ITERATIONS 1000

// Function prototypes
void displayMainMenu();
void reverseNumber();
void palindromeCheck();
void reverseAndAdd();
void digitalReverseAnalysis();
void baseReversal();
void reversePatterns();
void lychrelNumberTest();
void reverseStatistics();
void stringReversal();
void arrayReversal();
void bitwiseReversal();
long long reverse(long long n);
bool isPalindrome(long long n);
long long reverseInBase(long long n, int base);
int countDigits(long long n);
void displayReversalSteps(long long n);
void kaprekarRoutine(long long n, int digits);

int main() {
    int choice;
    
    printf("===============================================\n");
    printf("   ENHANCED NUMBER REVERSAL ANALYZER v2.0\n");
    printf("===============================================\n");
    printf("Advanced Reversal, Palindrome Detection,\n");
    printf("Lychrel Numbers, and Mathematical Analysis\n");
    printf("===============================================\n\n");

    while(1) {
        displayMainMenu();
        printf("Enter your choice (1-12, 0 to exit): ");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("\nThank you for using Enhanced Number Reversal Analyzer!\n");
                exit(0);
            case 1:
                reverseNumber();
                break;
            case 2:
                palindromeCheck();
                break;
            case 3:
                reverseAndAdd();
                break;
            case 4:
                digitalReverseAnalysis();
                break;
            case 5:
                baseReversal();
                break;
            case 6:
                reversePatterns();
                break;
            case 7:
                lychrelNumberTest();
                break;
            case 8:
                reverseStatistics();
                break;
            case 9:
                stringReversal();
                break;
            case 10:
                arrayReversal();
                break;
            case 11:
                bitwiseReversal();
                break;
            case 12: {
                printf("Enter 4-digit number for Kaprekar routine: ");
                long long num;
                scanf("%lld", &num);
                kaprekarRoutine(num, 4);
                break;
            }
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}

void displayMainMenu() {
    printf("\n============ REVERSAL ANALYZER MENU ============\n");
    printf("1.  Basic Number Reversal\n");
    printf("2.  Palindrome Checker\n");
    printf("3.  Reverse and Add Process\n");
    printf("4.  Digital Reverse Analysis\n");
    printf("5.  Base-N Reversal\n");
    printf("6.  Reversal Patterns\n");
    printf("7.  Lychrel Number Test\n");
    printf("8.  Reversal Statistics\n");
    printf("9.  String Reversal\n");
    printf("10. Array Reversal\n");
    printf("11. Bitwise Reversal\n");
    printf("12. Kaprekar's Routine (6174)\n");
    printf("0.  Exit\n");
    printf("===============================================\n");
}

void reverseNumber() {
    long long n, reversed, original;
    
    printf("\n=== BASIC NUMBER REVERSAL ===\n");
    printf("Enter a number: ");
    scanf("%lld", &n);
    
    original = n;
    reversed = reverse(n);
    
    printf("\n--- Reversal Details ---\n");
    printf("Original number:  %lld\n", original);
    printf("Reversed number:  %lld\n", reversed);
    printf("Number of digits: %d\n", countDigits(original));
    
    // Visual representation
    printf("\nVisual breakdown:\n");
    displayReversalSteps(original);
    
    // Mathematical properties
    printf("\n--- Mathematical Properties ---\n");
    printf("Sum: %lld + %lld = %lld\n", original, reversed, original + reversed);
    printf("Difference: %lld - %lld = %lld\n", 
           original > reversed ? original : reversed,
           original > reversed ? reversed : original,
           llabs(original - reversed));
    printf("Product: %lld × %lld = %lld\n", original, reversed, original * reversed);
    
    if(reversed != 0) {
        printf("Ratio: %lld / %lld = %.6f\n", original, reversed, (double)original / reversed);
    }
    
    // Check if palindrome
    if(isPalindrome(original)) {
        printf("\n✓ This number is a PALINDROME!\n");
    } else {
        printf("\n✗ This number is NOT a palindrome\n");
        printf("Difference from palindrome: %lld\n", llabs(original - reversed));
    }
}

void palindromeCheck() {
    long long n;
    
    printf("\n=== PALINDROME CHECKER ===\n");
    printf("Enter a number: ");
    scanf("%lld", &n);
    
    long long reversed = reverse(n);
    
    printf("\n--- Palindrome Analysis ---\n");
    printf("Original: %lld\n", n);
    printf("Reversed: %lld\n", reversed);
    
    if(isPalindrome(n)) {
        printf("\n✓ %lld is a PALINDROME!\n", n);
        
        // Analyze palindrome structure
        printf("\nPalindrome properties:\n");
        int digits = countDigits(n);
        printf("- Length: %d digits\n", digits);
        printf("- Symmetric: YES\n");
        
        // Check if it's made of repeated digits
        long long temp = n;
        int firstDigit = temp % 10;
        bool allSame = true;
        while(temp > 0) {
            if(temp % 10 != firstDigit) {
                allSame = false;
                break;
            }
            temp /= 10;
        }
        
        if(allSame) {
            printf("- Type: Repdigit (all same digits)\n");
        } else {
            printf("- Type: True palindrome\n");
        }
        
    } else {
        printf("\n✗ %lld is NOT a palindrome\n", n);
        printf("Steps to make palindrome:\n");
        printf("1. Current: %lld\n", n);
        printf("2. To palindrome: Need to match with reverse %lld\n", reversed);
    }
    
    // Show nearby palindromes
    printf("\n--- Nearby Palindromes ---\n");
    int found = 0;
    for(long long i = n - 10; i <= n + 10 && found < 5; i++) {
        if(i >= 0 && isPalindrome(i) && i != n) {
            printf("  %lld\n", i);
            found++;
        }
    }
}

void reverseAndAdd() {
    long long n;
    
    printf("\n=== REVERSE AND ADD PROCESS ===\n");
    printf("This process repeatedly adds a number to its reverse\n");
    printf("until a palindrome is obtained (or max iterations)\n\n");
    
    printf("Enter starting number: ");
    scanf("%lld", &n);
    
    long long current = n;
    int iterations = 0;
    int maxIterations = 100;
    
    printf("\nIteration  Number         + Reverse      = Result       Palindrome?\n");
    printf("---------------------------------------------------------------------\n");
    
    while(!isPalindrome(current) && iterations < maxIterations) {
        long long rev = reverse(current);
        long long sum = current + rev;
        
        printf("%-10d %-14lld + %-14lld = %-14lld %s\n", 
               iterations, current, rev, sum, 
               isPalindrome(sum) ? "YES ✓" : "NO");
        
        current = sum;
        iterations++;
        
        if(isPalindrome(current)) {
            printf("\n✓ Palindrome reached: %lld after %d iterations!\n", current, iterations);
            break;
        }
    }
    
    if(iterations >= maxIterations) {
        printf("\n⚠ Maximum iterations reached without finding palindrome\n");
        printf("This might be a Lychrel number candidate!\n");
    }
    
    printf("\n--- Summary ---\n");
    printf("Starting number: %lld\n", n);
    printf("Final number: %lld\n", current);
    printf("Iterations: %d\n", iterations);
    printf("Growth factor: %.2fx\n", (double)current / n);
}

void digitalReverseAnalysis() {
    long long n;
    
    printf("\n=== DIGITAL REVERSE ANALYSIS ===\n");
    printf("Comprehensive analysis of number reversal properties\n\n");
    
    printf("Enter number: ");
    scanf("%lld", &n);
    
    long long original = n;
    long long reversed = reverse(n);
    
    printf("\n--- Detailed Analysis ---\n");
    printf("Original: %lld\n", original);
    printf("Reversed: %lld\n", reversed);
    
    // Digit-by-digit comparison
    printf("\nDigit comparison (right to left):\n");
    long long temp1 = original, temp2 = reversed;
    int position = 1;
    
    while(temp1 > 0 || temp2 > 0) {
        int d1 = temp1 % 10;
        int d2 = temp2 % 10;
        printf("Position %d: %d vs %d %s\n", position, d1, d2, 
               (d1 == d2) ? "✓" : "✗");
        temp1 /= 10;
        temp2 /= 10;
        position++;
    }
    
    // Reversibility index
    int matchingDigits = 0;
    temp1 = original;
    temp2 = reversed;
    int totalDigits = countDigits(original);
    
    while(temp1 > 0) {
        if(temp1 % 10 == temp2 % 10) matchingDigits++;
        temp1 /= 10;
        temp2 /= 10;
    }
    
    double symmetryIndex = (double)matchingDigits / totalDigits * 100;
    printf("\nSymmetry index: %.2f%% (%d/%d digits match)\n", 
           symmetryIndex, matchingDigits, totalDigits);
    
    // Reversal patterns
    printf("\n--- Reversal Patterns ---\n");
    printf("n + reverse(n) = %lld\n", original + reversed);
    printf("n - reverse(n) = %lld\n", original - reversed);
    printf("n × reverse(n) = %lld\n", original * reversed);
    
    // Check divisibility
    if(reversed != 0) {
        if(original % reversed == 0) {
            printf("%lld is divisible by its reverse (%lld ÷ %lld = %lld)\n", 
                   original, original, reversed, original / reversed);
        }
        if(reversed % original == 0) {
            printf("Reverse is divisible by original (%lld ÷ %lld = %lld)\n", 
                   reversed, reversed, original, reversed / original);
        }
    }
}

void baseReversal() {
    long long n;
    int base;
    
    printf("\n=== BASE-N REVERSAL ===\n");
    printf("Reverse numbers in different bases (2-16)\n\n");
    
    printf("Enter number (in decimal): ");
    scanf("%lld", &n);
    printf("Enter base (2-16): ");
    scanf("%d", &base);
    
    if(base < 2 || base > 16) {
        printf("Invalid base! Must be between 2 and 16.\n");
        return;
    }
    
    // Convert to base and show
    printf("\n--- Base %d Conversion ---\n", base);
    printf("Decimal: %lld\n", n);
    
    // Show base representation
    printf("Base %d: ", base);
    if(n == 0) {
        printf("0");
    } else {
        char baseRep[64];
        int index = 0;
        long long temp = n;
        
        while(temp > 0) {
            int digit = temp % base;
            baseRep[index++] = (digit < 10) ? '0' + digit : 'A' + digit - 10;
            temp /= base;
        }
        
        // Print in correct order
        for(int i = index - 1; i >= 0; i--) {
            printf("%c", baseRep[i]);
        }
        
        // Reversed representation
        printf("\nReversed in base %d: ", base);
        for(int i = 0; i < index; i++) {
            printf("%c", baseRep[i]);
        }
    }
    
    long long reversedInBase = reverseInBase(n, base);
    printf("\nReversed (back to decimal): %lld\n", reversedInBase);
    
    // Compare across multiple bases
    printf("\n--- Multi-Base Comparison ---\n");
    printf("Base   Original   Reversed\n");
    printf("-----------------------------\n");
    for(int b = 2; b <= 16; b++) {
        long long rev = reverseInBase(n, b);
        printf("%-6d %-10lld %-10lld\n", b, n, rev);
    }
}

void reversePatterns() {
    printf("\n=== REVERSAL PATTERNS IN MATHEMATICS ===\n");
    
    printf("\n1. Numbers equal to their reverse (Palindromes):\n");
    printf("   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, ..., 101, 111, 121, ...\n");
    
    printf("\n2. Numbers where n × reverse(n) is palindromic:\n");
    printf("   Examples:\n");
    int found = 0;
    for(long long n = 10; n <= 100 && found < 10; n++) {
        long long rev = reverse(n);
        long long product = n * rev;
        if(isPalindrome(product)) {
            printf("   %lld × %lld = %lld ✓\n", n, rev, product);
            found++;
        }
    }
    
    printf("\n3. Numbers where n + reverse(n) = 10^k - 1:\n");
    printf("   Examples: 19 + 91 = 110, 29 + 92 = 121\n");
    
    printf("\n4. Reversal Divisibility:\n");
    printf("   Numbers divisible by their reverse:\n");
    found = 0;
    for(long long n = 10; n <= 200 && found < 10; n++) {
        long long rev = reverse(n);
        if(rev > 0 && n % rev == 0 && n != rev) {
            printf("   %lld ÷ %lld = %lld\n", n, rev, n / rev);
            found++;
        }
    }
    
    printf("\n5. Famous Reversal Properties:\n");
    printf("   - 1089 trick: Take any 3-digit number (not all same),\n");
    printf("     reverse and subtract, then reverse and add → always 1089!\n");
    printf("   - Kaprekar's constant 6174: Similar process for 4-digit numbers\n");
}

void lychrelNumberTest() {
    long long n;
    
    printf("\n=== LYCHREL NUMBER TEST ===\n");
    printf("Lychrel numbers are suspected to never form palindromes\n");
    printf("through the reverse-and-add process\n\n");
    
    printf("Enter number to test: ");
    scanf("%lld", &n);
    
    printf("Testing if %lld is a Lychrel number candidate...\n\n", n);
    
    long long current = n;
    int iterations = 0;
    int maxIterations = 200;
    bool foundPalindrome = false;
    
    while(iterations < maxIterations) {
        long long rev = reverse(current);
        current = current + rev;
        iterations++;
        
        if(isPalindrome(current)) {
            printf("✓ Palindrome found: %lld after %d iterations\n", current, iterations);
            printf("This is NOT a Lychrel number\n");
            foundPalindrome = true;
            break;
        }
        
        if(iterations % 50 == 0) {
            printf("Iteration %d: %lld (still searching...)\n", iterations, current);
        }
    }
    
    if(!foundPalindrome) {
        printf("\n⚠ No palindrome found after %d iterations!\n", maxIterations);
        printf("Current value: %lld\n", current);
        printf("This is a LYCHREL NUMBER CANDIDATE\n\n");
        printf("Known Lychrel candidates: 196, 295, 394, 493, 592, 689, 788, 887, 986\n");
    }
    
    printf("\nIterations performed: %d\n", iterations);
    if(n != current) {
        printf("Growth: %lld → %lld (%.2fx)\n", n, current, (double)current / n);
    }
}

void reverseStatistics() {
    printf("\n=== REVERSAL STATISTICS ===\n");
    printf("Statistical analysis of number reversals\n\n");
    
    int limit;
    printf("Enter upper limit for analysis (max 10000): ");
    scanf("%d", &limit);
    
    if(limit > 10000) limit = 10000;
    
    int palindromeCount = 0;
    int reverseGreaterCount = 0;
    int reverseDivisibleCount = 0;
    int reversePrimeCount = 0;
    
    printf("\nAnalyzing numbers from 1 to %d...\n", limit);
    
    for(long long n = 1; n <= limit; n++) {
        long long rev = reverse(n);
        
        if(isPalindrome(n)) palindromeCount++;
        if(rev > n) reverseGreaterCount++;
        if(rev > 0 && n % rev == 0) reverseDivisibleCount++;
    }
    
    printf("\n--- Statistics ---\n");
    printf("Total numbers: %d\n", limit);
    printf("Palindromes: %d (%.2f%%)\n", palindromeCount, 
           (double)palindromeCount / limit * 100);
    printf("Reverse > Original: %d (%.2f%%)\n", reverseGreaterCount,
           (double)reverseGreaterCount / limit * 100);
    printf("Divisible by reverse: %d (%.2f%%)\n", reverseDivisibleCount,
           (double)reverseDivisibleCount / limit * 100);
    
    // Show distribution by digit count
    printf("\n--- Palindrome Distribution by Digits ---\n");
    int digitCounts[10] = {0};
    
    for(long long n = 1; n <= limit; n++) {
        if(isPalindrome(n)) {
            int digits = countDigits(n);
            if(digits < 10) digitCounts[digits]++;
        }
    }
    
    for(int d = 1; d < 10; d++) {
        if(digitCounts[d] > 0) {
            printf("%d-digit palindromes: %d\n", d, digitCounts[d]);
        }
    }
}

void stringReversal() {
    char str[1000];
    
    printf("\n=== STRING REVERSAL ===\n");
    printf("Enter a string to reverse: ");
    getchar(); // Clear buffer
    fgets(str, sizeof(str), stdin);
    
    // Remove newline
    str[strcspn(str, "\n")] = 0;
    
    int len = strlen(str);
    char reversed[1000];
    
    // Reverse the string
    for(int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    
    printf("\n--- String Reversal ---\n");
    printf("Original: %s\n", str);
    printf("Reversed: %s\n", reversed);
    printf("Length: %d characters\n", len);
    
    // Check if palindrome
    bool isPalin = true;
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - 1 - i]) {
            isPalin = false;
            break;
        }
    }
    
    if(isPalin) {
        printf("✓ This string is a palindrome!\n");
    } else {
        printf("✗ This string is not a palindrome\n");
    }
}

void arrayReversal() {
    int size;
    
    printf("\n=== ARRAY REVERSAL ===\n");
    printf("Enter array size: ");
    scanf("%d", &size);
    
    if(size <= 0 || size > 100) {
        printf("Invalid size! Use 1-100.\n");
        return;
    }
    
    int arr[100];
    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    // Reverse the array in place
    for(int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    
    printf("\nReversed array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bitwiseReversal() {
    unsigned int n;
    
    printf("\n=== BITWISE REVERSAL ===\n");
    printf("Reverse the binary representation of a number\n\n");
    
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    
    printf("\nOriginal number: %u\n", n);
    printf("Binary representation: ");
    
    // Print binary
    for(int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if(i % 4 == 0) printf(" ");
    }
    
    // Reverse bits
    unsigned int reversed = 0;
    unsigned int temp = n;
    int bits = sizeof(n) * 8;
    
    for(int i = 0; i < bits; i++) {
        reversed <<= 1;
        reversed |= (temp & 1);
        temp >>= 1;
    }
    
    printf("\n\nReversed binary: ");
    for(int i = 31; i >= 0; i--) {
        printf("%d", (reversed >> i) & 1);
        if(i % 4 == 0) printf(" ");
    }
    
    printf("\n\nReversed number: %u\n", reversed);
}

void kaprekarRoutine(long long n, int digits) {
    printf("\n=== KAPREKAR'S ROUTINE (6174) ===\n");
    printf("Arranging digits in ascending and descending order,\n");
    printf("then subtracting to reach Kaprekar's constant\n\n");
    
    long long current = n;
    int iterations = 0;
    int maxIter = 20;
    
    printf("Starting number: %lld\n\n", n);
    
    while(current != 6174 && iterations < maxIter) {
        // Convert to digits
        int digitArr[10];
        long long temp = current;
        int count = 0;
        
        // Pad with zeros if needed
        while(count < digits) {
            digitArr[count++] = (count < countDigits(current)) ? temp % 10 : 0;
            if(temp > 0) temp /= 10;
        }
        
        // Sort ascending
        for(int i = 0; i < digits - 1; i++) {
            for(int j = i + 1; j < digits; j++) {
                if(digitArr[i] > digitArr[j]) {
                    int t = digitArr[i];
                    digitArr[i] = digitArr[j];
                    digitArr[j] = t;
                }
            }
        }
        
        long long ascending = 0;
        for(int i = 0; i < digits; i++) {
            ascending = ascending * 10 + digitArr[i];
        }
        
        // Sort descending
        long long descending = 0;
        for(int i = digits - 1; i >= 0; i--) {
            descending = descending * 10 + digitArr[i];
        }
        
        current = descending - ascending;
        iterations++;
        
        printf("Step %d: %lld - %lld = %lld\n", iterations, descending, ascending, current);
        
        if(current == 6174) {
            printf("\n✓ Reached Kaprekar's constant 6174 in %d steps!\n", iterations);
            break;
        }
    }
    
    if(iterations >= maxIter) {
        printf("\nMax iterations reached\n");
    }
}

// Helper functions
long long reverse(long long n) {
    long long reversed = 0;
    bool isNegative = (n < 0);
    n = llabs(n);
    
    while(n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    return isNegative ? -reversed : reversed;
}

bool isPalindrome(long long n) {
    return n == reverse(n);
}

long long reverseInBase(long long n, int base) {
    long long reversed = 0;
    
    while(n > 0) {
        reversed = reversed * base + n % base;
        n /= base;
    }
    
    return reversed;
}

int countDigits(long long n) {
    if(n == 0) return 1;
    n = llabs(n);
    int count = 0;
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

void displayReversalSteps(long long n) {
    printf("Breaking down %lld:\n", n);
    
    long long temp = n;
    int position = 1;
    
    printf("Position | Digit | Value\n");
    printf("---------|-------|--------\n");
    
    while(temp > 0) {
        int digit = temp % 10;
        long long placeValue = digit * (long long)pow(10, position - 1);
        printf("   %d     |   %d   | %lld\n", position, digit, placeValue);
        temp /= 10;
        position++;
    }
    
    printf("\nReversal process:\n");
    temp = n;
    long long reversed = 0;
    int step = 1;
    
    while(temp > 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        printf("Step %d: Extract %d, build %lld\n", step, digit, reversed);
        temp /= 10;
        step++;
    }
}