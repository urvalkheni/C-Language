#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_RANGE 10000000
#define MAX_RESULTS 1000

// Structure to store Armstrong number analysis
typedef struct {
    long long number;
    int digits;
    int sum_of_powers;
    char breakdown[200];
} ArmstrongInfo;

// Function prototypes
int countDigits(long long num);
long long power(int base, int exp);
int isArmstrong(long long num);
void findArmstrongInRange(long long start, long long end);
void analyzeArmstrongNumber(long long num);
void findAllArmstrongByDigits(int digits);
void generateArmstrongPattern();
void armstrongStatistics();
void perfectNumbersComparison();
void narcissisticNumbers();
void advancedArmstrongAnalysis();
void armstrongPerformanceTest();
void multiBaseArmstrong();
void armstrongVisualization(long long num);
ArmstrongInfo* getAllArmstrongNumbers(int max_digits, int* count);

int countDigits(long long num) {
    if (num == 0) return 1;
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

long long power(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int isArmstrong(long long num) {
    if (num < 0) return 0;
    
    long long originalNum = num;
    long long sum = 0;
    int digits = countDigits(num);
    
    while (num > 0) {
        int digit = num % 10;
        sum += power(digit, digits);
        num /= 10;
    }
    
    return sum == originalNum;
}

void analyzeArmstrongNumber(long long num) {
    printf("\n=== DETAILED ANALYSIS OF %lld ===\n", num);
    
    if (!isArmstrong(num)) {
        printf("%lld is NOT an Armstrong number.\n", num);
        
        // Show what it would need to be
        long long originalNum = num;
        long long sum = 0;
        int digits = countDigits(num);
        
        printf("Calculation: ");
        while (num > 0) {
            int digit = num % 10;
            printf("%d^%d", digit, digits);
            if (num > 9) printf(" + ");
            sum += power(digit, digits);
            num /= 10;
        }
        printf(" = %lld\n", sum);
        printf("Difference: %lld - %lld = %lld\n", sum, originalNum, sum - originalNum);
        return;
    }
    
    printf("%lld IS an Armstrong number!\n", num);
    
    long long tempNum = num;
    int digits = countDigits(num);
    long long sum = 0;
    
    printf("Number of digits: %d\n", digits);
    printf("Calculation breakdown:\n");
    
    // Store digits for proper order display
    int digitArray[20];
    int digitCount = 0;
    long long temp = num;
    
    while (temp > 0) {
        digitArray[digitCount++] = temp % 10;
        temp /= 10;
    }
    
    // Display calculation in correct order
    for (int i = digitCount - 1; i >= 0; i--) {
        printf("  %d^%d = %lld\n", digitArray[i], digits, power(digitArray[i], digits));
        sum += power(digitArray[i], digits);
    }
    
    printf("Total sum: %lld\n", sum);
    printf("Original number: %lld\n", num);
    printf("✓ Sum equals original number!\n");
}

void findArmstrongInRange(long long start, long long end) {
    printf("\n=== ARMSTRONG NUMBERS IN RANGE [%lld, %lld] ===\n", start, end);
    
    int count = 0;
    clock_t startTime = clock();
    
    for (long long i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            printf("%lld ", i);
            count++;
            if (count % 10 == 0) printf("\n");
        }
    }
    
    clock_t endTime = clock();
    double timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    
    printf("\n\nFound %d Armstrong numbers in %.4f seconds.\n", count, timeTaken);
    printf("Search rate: %.0f numbers per second\n", (end - start + 1) / timeTaken);
}

void findAllArmstrongByDigits(int digits) {
    printf("\n=== ALL %d-DIGIT ARMSTRONG NUMBERS ===\n", digits);
    
    long long start = (digits == 1) ? 0 : power(10, digits - 1);
    long long end = power(10, digits) - 1;
    
    int count = 0;
    for (long long i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            printf("%lld\n", i);
            analyzeArmstrongNumber(i);
            count++;
        }
    }
    
    printf("\nTotal %d-digit Armstrong numbers: %d\n", digits, count);
}

void generateArmstrongPattern() {
    printf("\n=== ARMSTRONG NUMBERS PATTERN ANALYSIS ===\n");
    
    printf("Armstrong numbers by digit count:\n");
    for (int digits = 1; digits <= 7; digits++) {
        long long start = (digits == 1) ? 0 : power(10, digits - 1);
        long long end = power(10, digits) - 1;
        
        int count = 0;
        printf("%d-digit: ", digits);
        
        for (long long i = start; i <= end && count < 20; i++) {
            if (isArmstrong(i)) {
                printf("%lld ", i);
                count++;
            }
        }
        
        if (count == 0) {
            printf("None found");
        } else if (count == 20) {
            printf("... (showing first 20)");
        }
        
        printf(" [Total: ");
        count = 0;
        for (long long i = start; i <= end; i++) {
            if (isArmstrong(i)) count++;
        }
        printf("%d]\n", count);
    }
}

void armstrongStatistics() {
    printf("\n=== ARMSTRONG NUMBERS STATISTICS ===\n");
    
    int digitStats[10] = {0};
    int totalCount = 0;
    long long largestFound = 0;
    
    // Collect statistics up to 6-digit numbers
    for (long long i = 0; i < 1000000; i++) {
        if (isArmstrong(i)) {
            int digits = countDigits(i);
            digitStats[digits]++;
            totalCount++;
            if (i > largestFound) largestFound = i;
        }
    }
    
    printf("Statistical Analysis:\n");
    printf("Total Armstrong numbers found (0-999999): %d\n", totalCount);
    printf("Largest Armstrong number found: %lld\n", largestFound);
    
    printf("\nDistribution by digit count:\n");
    for (int i = 1; i <= 6; i++) {
        if (digitStats[i] > 0) {
            printf("%d-digit numbers: %d (%.2f%%)\n", 
                   i, digitStats[i], (100.0 * digitStats[i]) / totalCount);
        }
    }
    
    // Calculate density
    printf("\nDensity analysis:\n");
    for (int digits = 1; digits <= 6; digits++) {
        long long rangeSize = (digits == 1) ? 10 : 9 * power(10, digits - 1);
        if (digitStats[digits] > 0) {
            printf("%d-digit: %.6f%% of all %d-digit numbers are Armstrong\n",
                   digits, (100.0 * digitStats[digits]) / rangeSize, digits);
        }
    }
}

void narcissisticNumbers() {
    printf("\n=== NARCISSISTIC NUMBERS (Generalized Armstrong) ===\n");
    printf("These are numbers equal to sum of their digits raised to various powers:\n\n");
    
    // Check for numbers where sum of digits^k equals the number
    for (int k = 1; k <= 5; k++) {
        printf("Numbers equal to sum of digits^%d:\n", k);
        int count = 0;
        
        for (long long num = 1; num < 10000 && count < 10; num++) {
            long long temp = num;
            long long sum = 0;
            
            while (temp > 0) {
                int digit = temp % 10;
                sum += power(digit, k);
                temp /= 10;
            }
            
            if (sum == num) {
                printf("%lld ", num);
                count++;
            }
        }
        
        if (count == 0) {
            printf("None found in range");
        }
        printf("\n");
    }
}

void multiBaseArmstrong() {
    printf("\n=== ARMSTRONG NUMBERS IN DIFFERENT BASES ===\n");
    
    int bases[] = {2, 3, 8, 16};
    int numBases = sizeof(bases) / sizeof(bases[0]);
    
    for (int b = 0; b < numBases; b++) {
        int base = bases[b];
        printf("\nBase %d Armstrong-like numbers:\n", base);
        
        for (int num = 1; num < 1000; num++) {
            // Convert to base and check if sum of digits^digitCount equals original
            int temp = num;
            int digits = 0;
            int digitArray[20];
            
            // Convert to base
            while (temp > 0) {
                digitArray[digits++] = temp % base;
                temp /= base;
            }
            
            // Calculate sum of powers
            long long sum = 0;
            for (int i = 0; i < digits; i++) {
                sum += power(digitArray[i], digits);
            }
            
            if (sum == num) {
                printf("%d ", num);
            }
        }
        printf("\n");
    }
}

void armstrongVisualization(long long num) {
    printf("\n=== VISUAL BREAKDOWN OF %lld ===\n", num);
    
    if (!isArmstrong(num)) {
        printf("%lld is not an Armstrong number.\n", num);
        return;
    }
    
    int digits = countDigits(num);
    long long temp = num;
    int digitArray[20];
    int digitCount = 0;
    
    // Extract digits
    while (temp > 0) {
        digitArray[digitCount++] = temp % 10;
        temp /= 10;
    }
    
    printf("Visual representation:\n");
    printf("Original number: ");
    for (int i = digitCount - 1; i >= 0; i--) {
        printf("[%d]", digitArray[i]);
    }
    printf("\n");
    
    printf("Powers calculation:\n");
    for (int i = digitCount - 1; i >= 0; i--) {
        printf("%d^%d = %-8lld", digitArray[i], digits, power(digitArray[i], digits));
        
        // Visual bar representation
        printf(" |");
        int barLength = power(digitArray[i], digits) / 100;
        if (barLength > 50) barLength = 50;
        for (int j = 0; j < barLength; j++) {
            printf("█");
        }
        printf("\n");
    }
    
    long long sum = 0;
    for (int i = 0; i < digitCount; i++) {
        sum += power(digitArray[i], digits);
    }
    printf("\nSum: %lld = Original number: %lld ✓\n", sum, num);
}

void armstrongPerformanceTest() {
    printf("\n=== PERFORMANCE TEST ===\n");
    
    int ranges[] = {1000, 10000, 100000, 1000000};
    int numRanges = sizeof(ranges) / sizeof(ranges[0]);
    
    for (int r = 0; r < numRanges; r++) {
        int range = ranges[r];
        clock_t start = clock();
        
        int count = 0;
        for (int i = 0; i < range; i++) {
            if (isArmstrong(i)) {
                count++;
            }
        }
        
        clock_t end = clock();
        double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        printf("Range 0-%d: Found %d Armstrong numbers in %.4f seconds\n", 
               range, count, timeTaken);
        printf("  Rate: %.0f checks per second\n", range / timeTaken);
    }
}

void advancedArmstrongAnalysis() {
    printf("\n=== ADVANCED MATHEMATICAL ANALYSIS ===\n");
    
    printf("Interesting properties of Armstrong numbers:\n\n");
    
    printf("1. Digital Root Analysis:\n");
    int armstrongNums[] = {0, 1, 153, 371, 407, 1634, 8208, 9474};
    int numArmstrong = sizeof(armstrongNums) / sizeof(armstrongNums[0]);
    
    for (int i = 0; i < numArmstrong; i++) {
        int num = armstrongNums[i];
        int digitalRoot = num;
        while (digitalRoot >= 10) {
            int sum = 0;
            while (digitalRoot > 0) {
                sum += digitalRoot % 10;
                digitalRoot /= 10;
            }
            digitalRoot = sum;
        }
        printf("  %d → Digital root: %d\n", num, digitalRoot);
    }
    
    printf("\n2. Sum of Digits Analysis:\n");
    for (int i = 0; i < numArmstrong; i++) {
        int num = armstrongNums[i];
        int sumDigits = 0;
        int temp = num;
        while (temp > 0) {
            sumDigits += temp % 10;
            temp /= 10;
        }
        printf("  %d → Sum of digits: %d\n", num, sumDigits);
    }
    
    printf("\n3. Palindrome Check:\n");
    for (int i = 0; i < numArmstrong; i++) {
        int num = armstrongNums[i];
        int reversed = 0;
        int temp = num;
        while (temp > 0) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }
        printf("  %d → Reversed: %d → %s\n", 
               num, reversed, (num == reversed) ? "Palindrome" : "Not palindrome");
    }
}

int main() {
    int choice;
    long long num, start, end;
    int digits;
    
    while (1) {
        printf("\n======= ADVANCED ARMSTRONG NUMBER ANALYZER =======\n");
        printf("1. Check Single Number\n");
        printf("2. Detailed Analysis of Number\n");
        printf("3. Find Armstrong Numbers in Range\n");
        printf("4. Find All Armstrong Numbers by Digit Count\n");
        printf("5. Pattern Analysis\n");
        printf("6. Statistical Analysis\n");
        printf("7. Narcissistic Numbers\n");
        printf("8. Multi-base Armstrong Numbers\n");
        printf("9. Visual Breakdown\n");
        printf("10. Performance Test\n");
        printf("11. Advanced Mathematical Analysis\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%lld", &num);
                if (isArmstrong(num)) {
                    printf("%lld is an Armstrong number!\n", num);
                } else {
                    printf("%lld is NOT an Armstrong number.\n", num);
                }
                break;
            case 2:
                printf("Enter a number for detailed analysis: ");
                scanf("%lld", &num);
                analyzeArmstrongNumber(num);
                break;
            case 3:
                printf("Enter start of range: ");
                scanf("%lld", &start);
                printf("Enter end of range: ");
                scanf("%lld", &end);
                findArmstrongInRange(start, end);
                break;
            case 4:
                printf("Enter number of digits (1-7): ");
                scanf("%d", &digits);
                if (digits >= 1 && digits <= 7) {
                    findAllArmstrongByDigits(digits);
                } else {
                    printf("Please enter a digit count between 1 and 7.\n");
                }
                break;
            case 5:
                generateArmstrongPattern();
                break;
            case 6:
                armstrongStatistics();
                break;
            case 7:
                narcissisticNumbers();
                break;
            case 8:
                multiBaseArmstrong();
                break;
            case 9:
                printf("Enter a number for visual breakdown: ");
                scanf("%lld", &num);
                armstrongVisualization(num);
                break;
            case 10:
                armstrongPerformanceTest();
                break;
            case 11:
                advancedArmstrongAnalysis();
                break;
            case 12:
                printf("Thank you for using Advanced Armstrong Number Analyzer!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
}