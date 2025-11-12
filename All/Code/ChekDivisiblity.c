/*
 * Advanced Divisibility & Number Analysis System v2.0
 * Features: Divisibility tests, number properties,
 *           factorization, mathematical analysis
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void basicDivisibility();
void multiDivisibility();
void divisibilityRules();
void commonDivisors();
void divisibilityPattern();
void primeFactorization();
void findAllDivisors();
void gcdLcm();
void perfectNumber();
void abundantDeficient();
void divisibilityBy3();
void divisibilityBy11();
void customDivisibility();
void divisibilityTable();
void numberClassification();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║  Advanced Divisibility & Number Analysis System v2.0      ║\n");
    printf("║       Professional Mathematical Analysis Platform         ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: basicDivisibility(); break;
            case 2: multiDivisibility(); break;
            case 3: divisibilityRules(); break;
            case 4: commonDivisors(); break;
            case 5: divisibilityPattern(); break;
            case 6: primeFactorization(); break;
            case 7: findAllDivisors(); break;
            case 8: gcdLcm(); break;
            case 9: perfectNumber(); break;
            case 10: abundantDeficient(); break;
            case 11: divisibilityBy3(); break;
            case 12: divisibilityBy11(); break;
            case 13: customDivisibility(); break;
            case 14: divisibilityTable(); break;
            case 15: numberClassification(); break;
            case 16:
                printf("\n--- Divisibility Info ---\n");
                printf("• Tests if number divides evenly\n");
                printf("• Finds factors and divisors\n");
                printf("• Analyzes number properties\n");
                printf("• Mathematical classifications\n");
                break;
            case 0: break;
            default: printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Divisibility Analysis!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC DIVISIBILITY                                     │\n");
    printf("│  [1]  Basic Divisibility Check (5 & 3)                  │\n");
    printf("│  [2]  Multiple Divisibility Test                        │\n");
    printf("│  [3]  Divisibility Rules (2-11)                         │\n");
    printf("│  [4]  Common Divisors                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED ANALYSIS                                      │\n");
    printf("│  [5]  Divisibility Pattern                              │\n");
    printf("│  [6]  Prime Factorization                               │\n");
    printf("│  [7]  Find All Divisors                                 │\n");
    printf("│  [8]  GCD & LCM                                         │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  NUMBER PROPERTIES                                      │\n");
    printf("│  [9]  Perfect Number Check                              │\n");
    printf("│  [10] Abundant/Deficient Check                          │\n");
    printf("│  [11] Divisibility by 3 (Digit Sum)                     │\n");
    printf("│  [12] Divisibility by 11 (Alternating)                  │\n");
    printf("│  [13] Custom Divisibility Range                         │\n");
    printf("│  [14] Divisibility Table                                │\n");
    printf("│  [15] Complete Number Classification                    │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Divisibility Info                                 │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void basicDivisibility() {
    int a;
    printf("Enter Positive Integer Number :: ");
    scanf("%d", &a);
    
    printf("\n--- Basic Divisibility Check ---\n\n");
    
    if(a % 5 == 0 && a % 3 == 0) {
        printf("✓ Number is divisable by 5 & 3.\n");
    } else {
        printf("✗ Number is not divisable by 5 & 3.\n");
    }
    
    printf("\nIndividual checks:\n");
    printf("Divisible by 3: %s\n", (a % 3 == 0) ? "Yes" : "No");
    printf("Divisible by 5: %s\n", (a % 5 == 0) ? "Yes" : "No");
}

void multiDivisibility() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Multiple Divisibility Test ---\n\n");
    
    int divisors[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = sizeof(divisors) / sizeof(divisors[0]);
    
    for(int i = 0; i < count; i++) {
        if(num % divisors[i] == 0)
            printf("✓ Divisible by %d\n", divisors[i]);
        else
            printf("✗ Not divisible by %d\n", divisors[i]);
    }
}

void divisibilityRules() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Divisibility Rules ---\n\n");
    
    printf("By 2: %s (last digit %s)\n", 
           (num % 2 == 0) ? "Yes" : "No",
           (num % 2 == 0) ? "even" : "odd");
    
    printf("By 5: %s (last digit %s)\n",
           (num % 5 == 0) ? "Yes" : "No",
           (num % 10 == 0 || num % 10 == 5) ? "0 or 5" : "other");
    
    int digitSum = 0, temp = num;
    while(temp) {
        digitSum += temp % 10;
        temp /= 10;
    }
    printf("By 3: %s (digit sum = %d)\n",
           (num % 3 == 0) ? "Yes" : "No", digitSum);
    
    printf("By 9: %s (digit sum = %d)\n",
           (num % 9 == 0) ? "Yes" : "No", digitSum);
    
    printf("By 10: %s (last digit %s)\n",
           (num % 10 == 0) ? "Yes" : "No",
           (num % 10 == 0) ? "is 0" : "is not 0");
}

void commonDivisors() {
    int a, b;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &a, &b);
    
    printf("\n--- Common Divisors ---\n\n");
    
    int limit = (a < b) ? a : b;
    printf("Common divisors: ");
    
    for(int i = 1; i <= limit; i++) {
        if(a % i == 0 && b % i == 0)
            printf("%d ", i);
    }
    printf("\n");
}

void divisibilityPattern() {
    int start, end, divisor;
    printf("\nEnter range (start end): ");
    scanf("%d %d", &start, &end);
    printf("Enter divisor: ");
    scanf("%d", &divisor);
    
    printf("\n--- Divisibility Pattern ---\n\n");
    printf("Numbers divisible by %d:\n", divisor);
    
    int count = 0;
    for(int i = start; i <= end; i++) {
        if(i % divisor == 0) {
            printf("%d ", i);
            count++;
            if(count % 10 == 0) printf("\n");
        }
    }
    printf("\n\nTotal count: %d\n", count);
}

void primeFactorization() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Prime Factorization ---\n\n");
    printf("%d = ", num);
    
    int temp = num;
    bool first = true;
    
    for(int i = 2; i <= temp; i++) {
        int count = 0;
        while(temp % i == 0) {
            count++;
            temp /= i;
        }
        if(count > 0) {
            if(!first) printf(" × ");
            if(count == 1)
                printf("%d", i);
            else
                printf("%d^%d", i, count);
            first = false;
        }
    }
    printf("\n");
}

void findAllDivisors() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- All Divisors ---\n\n");
    
    int count = 0;
    int sum = 0;
    
    printf("Divisors: ");
    for(int i = 1; i <= num; i++) {
        if(num % i == 0) {
            printf("%d ", i);
            count++;
            sum += i;
        }
    }
    
    printf("\n\nTotal divisors: %d\n", count);
    printf("Sum of divisors: %d\n", sum);
}

void gcdLcm() {
    int a, b;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &a, &b);
    
    printf("\n--- GCD & LCM ---\n\n");
    
    int x = a, y = b;
    while(y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    int gcd = x;
    int lcm = (a * b) / gcd;
    
    printf("GCD(%d, %d) = %d\n", a, b, gcd);
    printf("LCM(%d, %d) = %d\n", a, b, lcm);
}

void perfectNumber() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Perfect Number Check ---\n\n");
    
    int sum = 0;
    printf("Proper divisors: ");
    for(int i = 1; i < num; i++) {
        if(num % i == 0) {
            printf("%d ", i);
            sum += i;
        }
    }
    
    printf("\n\nSum = %d\n", sum);
    printf("%d is %s\n", num, 
           (sum == num) ? "PERFECT" : "NOT PERFECT");
}

void abundantDeficient() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Abundant/Deficient Check ---\n\n");
    
    int sum = 0;
    for(int i = 1; i < num; i++) {
        if(num % i == 0)
            sum += i;
    }
    
    printf("Sum of proper divisors: %d\n", sum);
    
    if(sum > num)
        printf("%d is ABUNDANT\n", num);
    else if(sum < num)
        printf("%d is DEFICIENT\n", num);
    else
        printf("%d is PERFECT\n", num);
}

void divisibilityBy3() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Divisibility by 3 (Digit Sum Rule) ---\n\n");
    
    int sum = 0, temp = num;
    while(temp) {
        sum += temp % 10;
        temp /= 10;
    }
    
    printf("Number: %d\n", num);
    printf("Digit sum: %d\n", sum);
    printf("Divisible by 3: %s\n", (sum % 3 == 0) ? "YES" : "NO");
    printf("Actual check: %s\n", (num % 3 == 0) ? "YES" : "NO");
}

void divisibilityBy11() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Divisibility by 11 (Alternating Sum) ---\n\n");
    
    int altSum = 0, temp = num, sign = 1;
    while(temp) {
        altSum += sign * (temp % 10);
        sign *= -1;
        temp /= 10;
    }
    
    printf("Number: %d\n", num);
    printf("Alternating sum: %d\n", altSum);
    printf("Divisible by 11: %s\n", (altSum % 11 == 0) ? "YES" : "NO");
    printf("Actual check: %s\n", (num % 11 == 0) ? "YES" : "NO");
}

void customDivisibility() {
    int num, start, end;
    printf("\nEnter number: ");
    scanf("%d", &num);
    printf("Enter divisor range (start end): ");
    scanf("%d %d", &start, &end);
    
    printf("\n--- Custom Divisibility Range ---\n\n");
    printf("Divisors of %d in range [%d, %d]:\n", num, start, end);
    
    int count = 0;
    for(int i = start; i <= end; i++) {
        if(num % i == 0) {
            printf("%d ", i);
            count++;
        }
    }
    
    printf("\n\nCount: %d\n", count);
}

void divisibilityTable() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Divisibility Table ---\n\n");
    printf("Div\tResult\tRemainder\tDivisible\n");
    printf("───────────────────────────────────────\n");
    
    for(int i = 2; i <= 12; i++) {
        printf("%d\t%d\t%d\t\t%s\n", 
               i, num/i, num%i, 
               (num%i == 0) ? "✓" : "✗");
    }
}

void numberClassification() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Complete Number Classification ---\n\n");
    
    printf("Number: %d\n\n", num);
    
    printf("Parity: %s\n", (num % 2 == 0) ? "EVEN" : "ODD");
    
    bool isPrime = true;
    if(num <= 1) isPrime = false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            isPrime = false;
            break;
        }
    }
    printf("Prime: %s\n", isPrime ? "YES" : "NO");
    
    int divisorSum = 0;
    for(int i = 1; i < num; i++)
        if(num % i == 0) divisorSum += i;
    
    if(divisorSum == num)
        printf("Type: PERFECT\n");
    else if(divisorSum > num)
        printf("Type: ABUNDANT\n");
    else
        printf("Type: DEFICIENT\n");
    
    printf("\nDivisibility:\n");
    for(int i = 2; i <= 10; i++)
        if(num % i == 0)
            printf("  • Divisible by %d\n", i);
}