//do while //
#include<stdio.h>
int main(){
    int i =1;
    do{
        /*
 * Advanced Do-While & Loop Control System v2.0
 * Features: Loop demonstrations, control structures,
 *           iteration patterns, loop applications
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void basicDoWhile();
void doWhileVsWhile();
void doWhileCounting();
void doWhileMenu();
void doWhileValidation();
void doWhileFactorial();
void doWhileFibonacci();
void doWhileDigitSum();
void doWhilePrime();
void doWhilePalindrome();
void doWhileArmstrong();
void doWhileGCD();
void doWhilePattern();
void doWhileGame();
void doWhileTimer();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║   Advanced Do-While & Loop Control System v2.0             ║\n");
    printf("║       Professional Loop Demonstration Platform            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: basicDoWhile(); break;
            case 2: doWhileVsWhile(); break;
            case 3: doWhileCounting(); break;
            case 4: doWhileMenu(); break;
            case 5: doWhileValidation(); break;
            case 6: doWhileFactorial(); break;
            case 7: doWhileFibonacci(); break;
            case 8: doWhileDigitSum(); break;
            case 9: doWhilePrime(); break;
            case 10: doWhilePalindrome(); break;
            case 11: doWhileArmstrong(); break;
            case 12: doWhileGCD(); break;
            case 13: doWhilePattern(); break;
            case 14: doWhileGame(); break;
            case 15: doWhileTimer(); break;
            case 16:
                printf("\n--- Do-While Loop Info ---\n");
                printf("• Exit-controlled loop\n");
                printf("• Executes at least once\n");
                printf("• Condition checked after execution\n");
                printf("• Ideal for menu-driven programs\n");
                break;
            case 0: break;
            default: printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Loop Control System!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC DO-WHILE                                         │\n");
    printf("│  [1]  Basic Do-While Loop                               │\n");
    printf("│  [2]  Do-While vs While Comparison                      │\n");
    printf("│  [3]  Do-While Counting Patterns                        │\n");
    printf("│  [4]  Do-While Menu System                              │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  APPLICATIONS                                           │\n");
    printf("│  [5]  Input Validation with Do-While                    │\n");
    printf("│  [6]  Factorial using Do-While                          │\n");
    printf("│  [7]  Fibonacci using Do-While                          │\n");
    printf("│  [8]  Digit Sum Calculator                              │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED APPLICATIONS                                  │\n");
    printf("│  [9]  Prime Number Checker                              │\n");
    printf("│  [10] Palindrome Checker                                │\n");
    printf("│  [11] Armstrong Number Checker                          │\n");
    printf("│  [12] GCD Calculator                                    │\n");
    printf("│  [13] Pattern Generator                                 │\n");
    printf("│  [14] Number Guessing Game                              │\n");
    printf("│  [15] Countdown Timer                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Do-While Loop Info                                │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void basicDoWhile() {
    printf("\n--- Basic Do-While Loop ---\n\n");
    
    int i = 1;
    do {
        printf("Hello world %d\n", i);
        i++;
    } while(i < 10);
    
    printf("\nLoop executed %d times\n", i - 1);
}

void doWhileVsWhile() {
    printf("\n--- Do-While vs While Comparison ---\n\n");
    
    int condition = 0;
    
    printf("While loop (condition = 0):\n");
    while(condition) {
        printf("This won't print\n");
    }
    printf("While loop executed 0 times\n\n");
    
    printf("Do-While loop (condition = 0):\n");
    int i = 0;
    do {
        printf("This prints at least once\n");
        i++;
    } while(condition);
    printf("Do-While loop executed %d time(s)\n", i);
}

void doWhileCounting() {
    int n;
    printf("\nEnter limit: ");
    scanf("%d", &n);
    
    printf("\n--- Counting Patterns ---\n\n");
    
    printf("Forward: ");
    int i = 1;
    do {
        printf("%d ", i);
        i++;
    } while(i <= n);
    
    printf("\n\nBackward: ");
    i = n;
    do {
        printf("%d ", i);
        i--;
    } while(i >= 1);
    
    printf("\n\nEven: ");
    i = 2;
    do {
        printf("%d ", i);
        i += 2;
    } while(i <= n);
    
    printf("\n\nOdd: ");
    i = 1;
    do {
        printf("%d ", i);
        i += 2;
    } while(i <= n);
    printf("\n");
}

void doWhileMenu() {
    int choice;
    
    printf("\n--- Simple Calculator Menu ---\n");
    
    do {
        printf("\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        if(choice >= 1 && choice <= 4) {
            double a, b;
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            
            switch(choice) {
                case 1: printf("Result: %.2f\n", a + b); break;
                case 2: printf("Result: %.2f\n", a - b); break;
                case 3: printf("Result: %.2f\n", a * b); break;
                case 4:
                    if(b != 0)
                        printf("Result: %.2f\n", a / b);
                    else
                        printf("Error: Division by zero\n");
                    break;
            }
        }
    } while(choice != 0);
}

void doWhileValidation() {
    int num;
    
    printf("\n--- Input Validation ---\n\n");
    printf("Enter a positive number (1-100): ");
    
    do {
        scanf("%d", &num);
        if(num < 1 || num > 100) {
            printf("Invalid! Enter again (1-100): ");
        }
    } while(num < 1 || num > 100);
    
    printf("Valid input: %d\n", num);
}

void doWhileFactorial() {
    int n;
    printf("\nEnter number: ");
    scanf("%d", &n);
    
    printf("\n--- Factorial using Do-While ---\n\n");
    
    if(n < 0) {
        printf("Factorial not defined for negative numbers\n");
        return;
    }
    
    long long fact = 1;
    int i = 1;
    
    if(n == 0) {
        printf("0! = 1\n");
        return;
    }
    
    do {
        fact *= i;
        printf("%d! = %lld\n", i, fact);
        i++;
    } while(i <= n);
}

void doWhileFibonacci() {
    int n;
    printf("\nEnter terms: ");
    scanf("%d", &n);
    
    printf("\n--- Fibonacci using Do-While ---\n\n");
    
    long long a = 0, b = 1, next;
    int i = 1;
    
    if(n >= 1) {
        printf("%lld ", a);
        if(n >= 2) {
            do {
                printf("%lld ", b);
                next = a + b;
                a = b;
                b = next;
                i++;
            } while(i < n);
        }
    }
    printf("\n");
}

void doWhileDigitSum() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Digit Sum Calculator ---\n\n");
    
    int sum = 0;
    int temp = num;
    
    do {
        sum += temp % 10;
        temp /= 10;
    } while(temp != 0);
    
    printf("Sum of digits of %d = %d\n", num, sum);
}

void doWhilePrime() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Prime Number Checker ---\n\n");
    
    if(num <= 1) {
        printf("%d is not prime\n", num);
        return;
    }
    
    bool isPrime = true;
    int i = 2;
    
    do {
        if(num % i == 0) {
            isPrime = false;
            break;
        }
        i++;
    } while(i <= num / 2);
    
    printf("%d is %s\n", num, isPrime ? "PRIME" : "NOT PRIME");
}

void doWhilePalindrome() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Palindrome Checker ---\n\n");
    
    int original = num;
    int reversed = 0;
    
    do {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    } while(num != 0);
    
    printf("%d is %s\n", original, 
           (original == reversed) ? "PALINDROME" : "NOT PALINDROME");
}

void doWhileArmstrong() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    printf("\n--- Armstrong Number Checker ---\n\n");
    
    int original = num;
    int sum = 0;
    int digits = 0;
    
    int temp = num;
    do {
        digits++;
        temp /= 10;
    } while(temp != 0);
    
    temp = num;
    do {
        int digit = temp % 10;
        int power = 1;
        for(int i = 0; i < digits; i++)
            power *= digit;
        sum += power;
        temp /= 10;
    } while(temp != 0);
    
    printf("%d is %s\n", original, 
           (original == sum) ? "ARMSTRONG NUMBER" : "NOT ARMSTRONG");
}

void doWhileGCD() {
    int a, b;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &a, &b);
    
    printf("\n--- GCD Calculator ---\n\n");
    
    int x = a, y = b;
    do {
        int temp = y;
        y = x % y;
        x = temp;
    } while(y != 0);
    
    printf("GCD of %d and %d = %d\n", a, b, x);
}

void doWhilePattern() {
    int n;
    printf("\nEnter rows: ");
    scanf("%d", &n);
    
    printf("\n--- Pattern Generator ---\n\n");
    
    int i = 1;
    do {
        int j = 1;
        do {
            printf("* ");
            j++;
        } while(j <= i);
        printf("\n");
        i++;
    } while(i <= n);
}

void doWhileGame() {
    printf("\n--- Number Guessing Game ---\n\n");
    
    srand(time(0));
    int target = rand() % 100 + 1;
    int guess, attempts = 0;
    
    printf("Guess the number (1-100)\n");
    
    do {
        printf("Your guess: ");
        scanf("%d", &guess);
        attempts++;
        
        if(guess < target)
            printf("Too low!\n");
        else if(guess > target)
            printf("Too high!\n");
    } while(guess != target);
    
    printf("\n✓ Correct! You guessed in %d attempts\n", attempts);
}

void doWhileTimer() {
    int seconds;
    printf("\nEnter countdown seconds: ");
    scanf("%d", &seconds);
    
    printf("\n--- Countdown Timer ---\n\n");
    
    do {
        printf("%d seconds remaining...\n", seconds);
        for(long i = 0; i < 100000000; i++); // Simple delay
        seconds--;
    } while(seconds >= 0);
    
    printf("\n✓ Time's up!\n");
}
        i++;
    }while(i<10);
    return 0;
}

/* Version note: updated 2025-11-17 — minor header/metadata bump */