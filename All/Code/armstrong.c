// Enhanced Armstrong Number Analyzer with Comprehensive Narcissistic Number Analysis
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_DIGITS 20
#define MAX_ARMSTRONG 100000

// Structure to store Armstrong number information
typedef struct {
    long long number;
    int digits;
    long long digitSum;
    char breakdown[200];
} ArmstrongInfo;

// Function prototypes
void displayMainMenu();
bool isArmstrong(long long num);
bool isGeneralizedArmstrong(long long num, int power);
void findArmstrongInRange(long long start, long long end);
void generateArmstrongSequence(int maxDigits);
void armstrongVisualization(long long num);
void narcissisticAnalysis();
void perfectDigitalInvariant(long long num);
void armstrongStatistics(long long limit);
void duffySequence();
void armstrongPatterns();
void customBaseArmstrong(long long num, int base);
long long power(long long base, int exp);
int countDigits(long long num);
int countDigitsInBase(long long num, int base);
long long digitPowerSum(long long num, int power);
long long digitPowerSumBase(long long num, int power, int base);
void displayArmstrongInfo(ArmstrongInfo info);
void kaprekarAnalysis(long long num);
void happyNumberCheck(long long num);

// Global storage for Armstrong numbers
ArmstrongInfo armstrongList[1000];
int armstrongCount = 0;

int main() {
    int choice;
    long long number;
    
    printf("===============================================\n");
    printf("   ENHANCED ARMSTRONG NUMBER ANALYZER v2.0\n");
    printf("===============================================\n");
    printf("Comprehensive Narcissistic Number Analysis,\n");
    printf("Pattern Recognition, and Mathematical Properties\n");
    printf("===============================================\n\n");

    while(1) {
        displayMainMenu();
        printf("Enter your choice (1-12, 0 to exit): ");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("\nThank you for using Enhanced Armstrong Analyzer!\n");
                printf("Total Armstrong numbers found in session: %d\n", armstrongCount);
                exit(0);
            case 1:
                printf("Enter number to check: ");
                scanf("%lld", &number);
                if(number < 0) {
                    printf("Negative numbers cannot be Armstrong numbers.\n");
                } else {
                    printf("\n=== ARMSTRONG NUMBER CHECK ===\n");
                    if(isArmstrong(number)) {
                        printf("%lld is an ARMSTRONG NUMBER!\n", number);
                        armstrongVisualization(number);
                    } else {
                        printf("%lld is NOT an Armstrong number.\n", number);
                        armstrongVisualization(number);
                    }
                }
                break;
            case 2:
                printf("Enter start of range: ");
                long long start, end;
                scanf("%lld", &start);
                printf("Enter end of range: ");
                scanf("%lld", &end);
                findArmstrongInRange(start, end);
                break;
            case 3:
                printf("Enter maximum number of digits: ");
                int maxDigits;
                scanf("%d", &maxDigits);
                if(maxDigits > 0 && maxDigits <= 10) {
                    generateArmstrongSequence(maxDigits);
                } else {
                    printf("Invalid input! Please enter digits between 1 and 10\n");
                }
                break;
            case 4:
                printf("Enter number for visualization: ");
                scanf("%lld", &number);
                armstrongVisualization(number);
                break;
            case 5:
                narcissisticAnalysis();
                break;
            case 6:
                printf("Enter number for PDI analysis: ");
                scanf("%lld", &number);
                perfectDigitalInvariant(number);
                break;
            case 7:
                printf("Enter limit for statistics: ");
                scanf("%lld", &number);
                armstrongStatistics(number);
                break;
            case 8:
                duffySequence();
                break;
            case 9:
                armstrongPatterns();
                break;
            case 10:
                printf("Enter number: ");
                scanf("%lld", &number);
                printf("Enter base (2-16): ");
                int base;
                scanf("%d", &base);
                if(base >= 2 && base <= 16) {
                    customBaseArmstrong(number, base);
                } else {
                    printf("Base must be between 2 and 16\n");
                }
                break;
            case 11:
                printf("Enter number for Kaprekar analysis: ");
                scanf("%lld", &number);
                kaprekarAnalysis(number);
                break;
            case 12:
                printf("Enter number for Happy Number check: ");
                scanf("%lld", &number);
                happyNumberCheck(number);
                break;
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
    printf("\n============ ARMSTRONG ANALYZER MENU ============\n");
    printf("1.  Single Number Armstrong Check\n");
    printf("2.  Find Armstrong Numbers in Range\n");
    printf("3.  Generate Armstrong Sequence by Digits\n");
    printf("4.  Armstrong Number Visualization\n");
    printf("5.  Narcissistic Number Analysis\n");
    printf("6.  Perfect Digital Invariant Analysis\n");
    printf("7.  Armstrong Number Statistics\n");
    printf("8.  Duffy Sequence Analysis\n");
    printf("9.  Armstrong Number Patterns\n");
    printf("10. Custom Base Armstrong Check\n");
    printf("11. Kaprekar Number Analysis\n");
    printf("12. Happy Number Check\n");
    printf("0.  Exit\n");
    printf("===============================================\n");
}

bool isArmstrong(long long num) {
    if(num < 0) return false;
    
    int digits = countDigits(num);
    long long sum = digitPowerSum(num, digits);
    
    return sum == num;
}

bool isGeneralizedArmstrong(long long num, int power) {
    if(num < 0) return false;
    
    long long sum = digitPowerSum(num, power);
    return sum == num;
}

void findArmstrongInRange(long long start, long long end) {
    printf("\n=== ARMSTRONG NUMBERS IN RANGE [%lld, %lld] ===\n", start, end);
    
    if(start < 0) start = 0;
    if(end > 1000000) {
        printf("Warning: Large range may take time. Limiting to 1,000,000\n");
        end = 1000000;
    }
    
    int found = 0;
    clock_t startTime = clock();
    
    printf("Armstrong numbers found:\n");
    for(long long num = start; num <= end; num++) {
        if(isArmstrong(num)) {
            printf("%lld ", num);
            found++;
            if(found % 10 == 0) printf("\n");
        }
    }
    
    if(found % 10 != 0) printf("\n");
    
    clock_t endTime = clock();
    double timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    
    printf("\nTotal Armstrong numbers found: %d\n", found);
    printf("Search completed in %.6f seconds\n", timeTaken);
    printf("Average density: %.6f%% in range\n", (double)found / (end - start + 1) * 100);
}

void generateArmstrongSequence(int maxDigits) {
    printf("\n=== ARMSTRONG NUMBER SEQUENCE ===\n");
    printf("Generating all Armstrong numbers up to %d digits\n\n", maxDigits);
    
    armstrongCount = 0;
    
    for(int digits = 1; digits <= maxDigits; digits++) {
        printf("--- %d-digit Armstrong numbers ---\n", digits);
        
        long long start = (digits == 1) ? 0 : power(10, digits - 1);
        long long end = power(10, digits) - 1;
        
        int countInDigits = 0;
        for(long long num = start; num <= end; num++) {
            if(isArmstrong(num)) {
                ArmstrongInfo info;
                info.number = num;
                info.digits = digits;
                info.digitSum = digitPowerSum(num, digits);
                
                // Create breakdown string
                sprintf(info.breakdown, "%lld = ", num);
                long long temp = num;
                bool first = true;
                while(temp > 0) {
                    long long digit = temp % 10;
                    if(!first) strcat(info.breakdown, " + ");
                    char digitStr[50];
                    sprintf(digitStr, "%lld^%d", digit, digits);
                    strcat(info.breakdown, digitStr);
                    first = false;
                    temp /= 10;
                }
                
                armstrongList[armstrongCount++] = info;
                printf("%lld ", num);
                countInDigits++;
            }
        }
        
        if(countInDigits == 0) {
            printf("None found");
        }
        printf("\n");
    }
    
    printf("\nTotal Armstrong numbers found: %d\n", armstrongCount);
    
    // Show detailed breakdown for first few
    printf("\n--- Detailed Breakdown (first 10) ---\n");
    for(int i = 0; i < armstrongCount && i < 10; i++) {
        displayArmstrongInfo(armstrongList[i]);
    }
}

void armstrongVisualization(long long num) {
    printf("\n=== ARMSTRONG VISUALIZATION ===\n");
    printf("Number: %lld\n", num);
    
    int digits = countDigits(num);
    printf("Number of digits: %d\n", digits);
    
    printf("\nStep-by-step calculation:\n");
    printf("%lld = ", num);
    
    long long temp = num;
    long long sum = 0;
    bool first = true;
    
    // Build the equation string
    char equation[500] = "";
    while(temp > 0) {
        long long digit = temp % 10;
        long long digitPower = power(digit, digits);
        
        if(!first) {
            printf(" + ");
            strcat(equation, " + ");
        }
        printf("%lld^%d", digit, digits);
        
        char termStr[50];
        sprintf(termStr, "%lld^%d (%lld)", digit, digits, digitPower);
        strcat(equation, termStr);
        
        sum += digitPower;
        first = false;
        temp /= 10;
    }
    
    printf("\n");
    printf("     = %s\n", equation);
    printf("     = %lld\n", sum);
    
    if(sum == num) {
        printf("\n✓ %lld = %lld → ARMSTRONG NUMBER!\n", sum, num);
    } else {
        printf("\n✗ %lld ≠ %lld → NOT an Armstrong number\n", sum, num);
        printf("Difference: %lld\n", llabs(sum - num));
    }
    
    // Additional analysis
    printf("\n--- Additional Analysis ---\n");
    printf("Sum/Original ratio: %.6f\n", (double)sum / num);
    printf("Digit sum: %lld\n", digitPowerSum(num, 1));
    printf("Product of digits: ");
    temp = num;
    long long product = 1;
    while(temp > 0) {
        product *= temp % 10;
        temp /= 10;
    }
    printf("%lld\n", product);
}

void narcissisticAnalysis() {
    printf("\n=== NARCISSISTIC NUMBER ANALYSIS ===\n");
    printf("Exploring generalized narcissistic numbers with different powers\n\n");
    
    printf("Narcissistic numbers are numbers equal to the sum of their digits\n");
    printf("raised to various powers (not necessarily the number of digits)\n\n");
    
    long long testNum = 153;
    printf("Example analysis for %lld:\n", testNum);
    
    for(int power = 1; power <= 6; power++) {
        long long sum = digitPowerSum(testNum, power);
        printf("Power %d: %lld → %s\n", power, sum, 
               (sum == testNum) ? "NARCISSISTIC!" : "not narcissistic");
    }
    
    printf("\n--- Known Narcissistic Numbers by Power ---\n");
    printf("Power 1: 1, 2, 3, 4, 5, 6, 7, 8, 9\n");
    printf("Power 2: None exist\n");
    printf("Power 3: 153, 371, 407\n");
    printf("Power 4: 1634, 8208, 9474\n");
    printf("Power 5: 54748, 92727, 93084\n");
    printf("Power 6: 548834\n");
    
    printf("\nNote: These are also called 'Pluperfect Digital Invariants'\n");
}

void perfectDigitalInvariant(long long num) {
    printf("\n=== PERFECT DIGITAL INVARIANT ANALYSIS ===\n");
    printf("Testing number %lld for PDI properties\n", num);
    
    printf("\nPDI test with different powers:\n");
    for(int power = 1; power <= 8; power++) {
        long long sum = digitPowerSum(num, power);
        bool isPDI = (sum == num);
        printf("k=%d: %lld^%d terms = %lld %s\n", 
               power, num, power, sum, isPDI ? "✓ PDI" : "");
    }
    
    // Find the natural power (number of digits)
    int naturalPower = countDigits(num);
    long long naturalSum = digitPowerSum(num, naturalPower);
    
    printf("\nNatural power analysis (power = number of digits = %d):\n", naturalPower);
    printf("%lld with power %d gives sum %lld\n", num, naturalPower, naturalSum);
    
    if(naturalSum == num) {
        printf("This is a classic Armstrong number!\n");
    } else {
        printf("This is not a classic Armstrong number\n");
        printf("To be Armstrong-like, it would need sum = %lld\n", num);
    }
}

void armstrongStatistics(long long limit) {
    printf("\n=== ARMSTRONG NUMBER STATISTICS ===\n");
    printf("Analyzing Armstrong numbers up to %lld\n", limit);
    
    int digitCounts[11] = {0}; // Count by number of digits
    int totalCount = 0;
    
    for(long long num = 0; num <= limit; num++) {
        if(isArmstrong(num)) {
            int digits = countDigits(num);
            digitCounts[digits]++;
            totalCount++;
        }
    }
    
    printf("\nDistribution by digit count:\n");
    printf("Digits   Count   Examples\n");
    printf("------------------------\n");
    
    for(int d = 1; d <= 10; d++) {
        if(digitCounts[d] > 0) {
            printf("  %d      %3d     ", d, digitCounts[d]);
            
            // Show first few examples
            int shown = 0;
            long long start = (d == 1) ? 0 : power(10, d - 1);
            long long end = power(10, d) - 1;
            if(end > limit) end = limit;
            
            for(long long num = start; num <= end && shown < 5; num++) {
                if(isArmstrong(num)) {
                    printf("%lld ", num);
                    shown++;
                }
            }
            printf("\n");
        }
    }
    
    printf("\nStatistical Summary:\n");
    printf("Total Armstrong numbers: %d\n", totalCount);
    printf("Density: %.8f%% of numbers up to %lld\n", 
           (double)totalCount / (limit + 1) * 100, limit);
    printf("Average gap: %.2f\n", (double)limit / totalCount);
    
    // Growth analysis
    printf("\nGrowth pattern:\n");
    for(int d = 1; d <= 6; d++) {
        if(digitCounts[d] > 0) {
            long long rangeSize = (d == 1) ? 10 : 9 * power(10, d - 1);
            printf("%d-digit: %d/%lld = %.6f%%\n", 
                   d, digitCounts[d], rangeSize, 
                   (double)digitCounts[d] / rangeSize * 100);
        }
    }
}

void duffySequence() {
    printf("\n=== DUFFY SEQUENCE ANALYSIS ===\n");
    printf("The Duffy sequence: numbers where sum of cubes of digits equals the number\n");
    printf("This is the sequence of 3-narcissistic numbers\n\n");
    
    printf("Duffy numbers (3-narcissistic): ");
    int count = 0;
    for(long long num = 1; num <= 100000; num++) {
        if(isGeneralizedArmstrong(num, 3)) {
            printf("%lld ", num);
            count++;
        }
    }
    
    printf("\n\nFound %d Duffy numbers\n", count);
    printf("These numbers satisfy: n = sum of (digits^3)\n");
    
    // Show detailed calculation for 153
    printf("\nExample calculation for 153:\n");
    printf("153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ✓\n");
}

void armstrongPatterns() {
    printf("\n=== ARMSTRONG NUMBER PATTERNS ===\n");
    
    printf("1. Single digit numbers (0-9): All are Armstrong numbers\n");
    printf("   Because each digit equals itself when raised to power 1\n\n");
    
    printf("2. Two-digit numbers: NO Armstrong numbers exist\n");
    printf("   Maximum possible: 9² + 9² = 81 + 81 = 162 (3 digits)\n");
    printf("   But we need exactly 2 digits, so impossible\n\n");
    
    printf("3. Three-digit Armstrong numbers: 153, 371, 407\n");
    printf("   Pattern: Each equals sum of cubes of its digits\n\n");
    
    printf("4. Digit sum patterns in Armstrong numbers:\n");
    long long armstrong[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 371, 407, 1634, 8208, 9474};
    int armstrongSize = sizeof(armstrong) / sizeof(armstrong[0]);
    
    for(int i = 0; i < armstrongSize; i++) {
        long long num = armstrong[i];
        long long digitSum = digitPowerSum(num, 1);
        printf("   %lld → digit sum = %lld\n", num, digitSum);
    }
    
    printf("\n5. Mathematical properties:\n");
    printf("   - Armstrong numbers become very sparse as digit count increases\n");
    printf("   - No 2-digit Armstrong numbers exist\n");
    printf("   - Largest known: 1741725 (7 digits)\n");
    printf("   - Finite number of Armstrong numbers exist\n");
}

void customBaseArmstrong(long long num, int base) {
    printf("\n=== CUSTOM BASE ARMSTRONG ANALYSIS ===\n");
    printf("Checking if %lld is Armstrong in base %d\n", num, base);
    
    int digits = countDigitsInBase(num, base);
    long long sum = digitPowerSumBase(num, digits, base);
    
    printf("Number %lld in base %d:\n", num, base);
    printf("Digits in base %d: %d\n", base, digits);
    
    // Show base conversion
    printf("Base %d representation: ", base);
    long long temp = num;
    if(temp == 0) {
        printf("0");
    } else {
        char baseRep[64];
        int index = 0;
        while(temp > 0) {
            int digit = temp % base;
            baseRep[index++] = (digit < 10) ? '0' + digit : 'A' + digit - 10;
            temp /= base;
        }
        for(int i = index - 1; i >= 0; i--) {
            printf("%c", baseRep[i]);
        }
    }
    
    printf("\nCalculation: ");
    temp = num;
    bool first = true;
    while(temp > 0) {
        int digit = temp % base;
        if(!first) printf(" + ");
        printf("%d^%d", digit, digits);
        first = false;
        temp /= base;
    }
    printf(" = %lld\n", sum);
    
    if(sum == num) {
        printf("✓ %lld IS an Armstrong number in base %d!\n", num, base);
    } else {
        printf("✗ %lld is NOT an Armstrong number in base %d\n", num, base);
    }
}

void kaprekarAnalysis(long long num) {
    printf("\n=== KAPREKAR NUMBER ANALYSIS ===\n");
    printf("Analyzing %lld for Kaprekar properties\n", num);
    
    long long square = num * num;
    printf("%lld² = %lld\n", num, square);
    
    // Split the square and check if parts sum to original
    char squareStr[20];
    sprintf(squareStr, "%lld", square);
    int len = strlen(squareStr);
    
    printf("Checking all possible splits of %lld:\n", square);
    bool isKaprekar = false;
    
    for(int split = 1; split < len; split++) {
        char leftPart[20], rightPart[20];
        strncpy(leftPart, squareStr, split);
        leftPart[split] = '\0';
        strcpy(rightPart, squareStr + split);
        
        long long left = (strlen(leftPart) > 0) ? atoll(leftPart) : 0;
        long long right = (strlen(rightPart) > 0) ? atoll(rightPart) : 0;
        
        printf("Split at position %d: %lld + %lld = %lld\n", 
               split, left, right, left + right);
        
        if(left + right == num && right > 0) {
            printf("✓ KAPREKAR NUMBER found!\n");
            isKaprekar = true;
        }
    }
    
    if(!isKaprekar) {
        printf("Not a Kaprekar number\n");
    }
    
    printf("\nKnown Kaprekar numbers: 1, 9, 45, 55, 99, 297, 703, 999, ...\n");
}

void happyNumberCheck(long long num) {
    printf("\n=== HAPPY NUMBER ANALYSIS ===\n");
    printf("Checking if %lld is a happy number\n", num);
    
    printf("Happy number process (sum of squares of digits until 1 or cycle):\n");
    
    long long current = num;
    int steps = 0;
    long long seen[1000];
    int seenCount = 0;
    
    while(current != 1 && steps < 50) {
        // Check if we've seen this number before (cycle detection)
        for(int i = 0; i < seenCount; i++) {
            if(seen[i] == current) {
                printf("Cycle detected! Not a happy number.\n");
                return;
            }
        }
        
        seen[seenCount++] = current;
        
        long long sum = 0;
        long long temp = current;
        printf("Step %d: %lld → ", steps + 1, current);
        
        bool first = true;
        while(temp > 0) {
            long long digit = temp % 10;
            if(!first) printf(" + ");
            printf("%lld²", digit);
            sum += digit * digit;
            first = false;
            temp /= 10;
        }
        
        printf(" = %lld\n", sum);
        current = sum;
        steps++;
    }
    
    if(current == 1) {
        printf("✓ %lld is a HAPPY NUMBER! (reached 1 in %d steps)\n", num, steps);
    } else {
        printf("Process stopped after %d steps (likely cycling)\n", steps);
    }
    
    printf("\nFirst few happy numbers: 1, 7, 10, 13, 19, 23, 28, 31, ...\n");
}

// Helper functions
long long power(long long base, int exp) {
    long long result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int countDigits(long long num) {
    if(num == 0) return 1;
    int count = 0;
    while(num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

int countDigitsInBase(long long num, int base) {
    if(num == 0) return 1;
    int count = 0;
    while(num > 0) {
        count++;
        num /= base;
    }
    return count;
}

long long digitPowerSum(long long num, int power) {
    long long sum = 0;
    while(num > 0) {
        long long digit = num % 10;
        sum += (long long)pow(digit, power);
        num /= 10;
    }
    return sum;
}

long long digitPowerSumBase(long long num, int power, int base) {
    long long sum = 0;
    while(num > 0) {
        long long digit = num % base;
        sum += (long long)pow(digit, power);
        num /= base;
    }
    return sum;
}

void displayArmstrongInfo(ArmstrongInfo info) {
    printf("%lld (%d digits): %s = %lld\n", 
           info.number, info.digits, info.breakdown, info.digitSum);
}
