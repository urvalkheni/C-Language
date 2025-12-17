/*
 * Advanced Arithmetic Operations Calculator v2.0
 * Features: Division, modulo, comprehensive arithmetic,
 *           mathematical operations, and number analysis
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
void basicDivision(int a, int b);
void moduloOperation(int a, int b);
void divisionWithRemainder(int a, int b);
void allArithmeticOps(int a, int b);
void powerOperation(int base, int exp);
void squareRoot(int n);
void factorial(int n);
void percentageCalculator(float num, float percent);
void averageCalculator();
void compoundInterest(float principal, float rate, int time);
void simpleInterest(float principal, float rate, int time);
void quadraticEquation(float a, float b, float c);
void arithmeticProgression(int a, int d, int n);
void geometricProgression(int a, int r, int n);
void fractionSimplifier(int num, int den);
void displayMenu();
int gcd(int a, int b);

int main() {
    int choice, a, b, n;
    float f1, f2, f3;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║   Advanced Arithmetic Operations Calculator v2.0          ║\n");
    printf("║        Comprehensive Mathematical Operations              ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                printf("\nEnter dividend: ");
                scanf("%d", &a);
                printf("Enter divisor: ");
                scanf("%d", &b);
                if(b == 0) {
                    printf("Error: Division by zero is undefined!\n");
                    break;
                }
                basicDivision(a, b);
                break;
                
            case 2:
                printf("\nEnter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                moduloOperation(a, b);
                break;
                
            case 3:
                printf("\nEnter dividend: ");
                scanf("%d", &a);
                printf("Enter divisor: ");
                scanf("%d", &b);
                divisionWithRemainder(a, b);
                break;
                
            case 4:
                printf("\nEnter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                allArithmeticOps(a, b);
                break;
                
            case 5:
                printf("\nEnter base: ");
                scanf("%d", &a);
                printf("Enter exponent: ");
                scanf("%d", &b);
                powerOperation(a, b);
                break;
                
            case 6:
                printf("\nEnter number: ");
                scanf("%d", &n);
                squareRoot(n);
                break;
                
            case 7:
                printf("\nEnter number: ");
                scanf("%d", &n);
                factorial(n);
                break;
                
            case 8:
                printf("\nEnter number: ");
                scanf("%f", &f1);
                printf("Enter percentage: ");
                scanf("%f", &f2);
                percentageCalculator(f1, f2);
                break;
                
            case 9:
                averageCalculator();
                break;
                
            case 10:
                printf("\nEnter principal amount: ");
                scanf("%f", &f1);
                printf("Enter rate of interest (%%): ");
                scanf("%f", &f2);
                printf("Enter time (years): ");
                scanf("%d", &n);
                compoundInterest(f1, f2, n);
                break;
                
            case 11:
                printf("\nEnter principal amount: ");
                scanf("%f", &f1);
                printf("Enter rate of interest (%%): ");
                scanf("%f", &f2);
                printf("Enter time (years): ");
                scanf("%d", &n);
                simpleInterest(f1, f2, n);
                break;
                
            case 12:
                printf("\nSolve: ax² + bx + c = 0\n");
                printf("Enter a: ");
                scanf("%f", &f1);
                printf("Enter b: ");
                scanf("%f", &f2);
                printf("Enter c: ");
                scanf("%f", &f3);
                quadraticEquation(f1, f2, f3);
                break;
                
            case 13:
                printf("\nEnter first term (a): ");
                scanf("%d", &a);
                printf("Enter common difference (d): ");
                scanf("%d", &b);
                printf("Enter number of terms: ");
                scanf("%d", &n);
                arithmeticProgression(a, b, n);
                break;
                
            case 14:
                printf("\nEnter first term (a): ");
                scanf("%d", &a);
                printf("Enter common ratio (r): ");
                scanf("%d", &b);
                printf("Enter number of terms: ");
                scanf("%d", &n);
                geometricProgression(a, b, n);
                break;
                
            case 15:
                printf("\nEnter numerator: ");
                scanf("%d", &a);
                printf("Enter denominator: ");
                scanf("%d", &b);
                fractionSimplifier(a, b);
                break;
                
            case 16:
                printf("\n--- Quick Reference ---\n");
                printf("\nOperations:\n");
                printf("• Division: a ÷ b\n");
                printf("• Modulo: a %% b (remainder)\n");
                printf("• Power: a^b\n");
                printf("• SI: P×R×T/100\n");
                printf("• CI: P(1+R/100)^T\n");
                break;
                
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Arithmetic Calculator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC OPERATIONS                                       │\n");
    printf("│  [1]  Basic Division                                    │\n");
    printf("│  [2]  Modulo Operation                                  │\n");
    printf("│  [3]  Division with Remainder                           │\n");
    printf("│  [4]  All Arithmetic Operations                         │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED OPERATIONS                                    │\n");
    printf("│  [5]  Power Operation                                   │\n");
    printf("│  [6]  Square Root                                       │\n");
    printf("│  [7]  Factorial                                         │\n");
    printf("│  [8]  Percentage Calculator                             │\n");
    printf("│  [9]  Average Calculator                                │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  FINANCIAL                                              │\n");
    printf("│  [10] Compound Interest                                 │\n");
    printf("│  [11] Simple Interest                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  MATHEMATICAL                                           │\n");
    printf("│  [12] Quadratic Equation Solver                         │\n");
    printf("│  [13] Arithmetic Progression                            │\n");
    printf("│  [14] Geometric Progression                             │\n");
    printf("│  [15] Fraction Simplifier                               │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Quick Reference                                   │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void basicDivision(int a, int b) {
    printf("\n--- Basic Division ---\n");
    
    if(b == 0) {
        printf("✗ Error: Cannot divide by zero!\n");
        return;
    }
    
    printf("%d ÷ %d = %.4f\n", a, b, (float)a / b);
    printf("Integer result: %d\n", a / b);
}

void moduloOperation(int a, int b) {
    printf("\n--- Modulo Operation ---\n");
    
    if(b == 0) {
        printf("✗ Error: Cannot perform modulo with zero!\n");
        return;
    }
    
    printf("%d %% %d = %d\n", a, b, a % b);
    printf("This is the remainder when %d is divided by %d\n", a, b);
}

void divisionWithRemainder(int a, int b) {
    printf("\n--- Division with Remainder ---\n");
    
    if(b == 0) {
        printf("✗ Error: Cannot divide by zero!\n");
        return;
    }
    
    int quotient = a / b;
    int remainder = a % b;
    
    printf("%d ÷ %d\n", a, b);
    printf("Quotient:  %d\n", quotient);
    printf("Remainder: %d\n", remainder);
    printf("Verification: %d = (%d × %d) + %d\n", a, b, quotient, remainder);
}

void allArithmeticOps(int a, int b) {
    printf("\n--- All Arithmetic Operations ---\n");
    printf("Numbers: %d, %d\n\n", a, b);
    
    printf("Addition:       %d + %d = %d\n", a, b, a + b);
    printf("Subtraction:    %d - %d = %d\n", a, b, a - b);
    printf("Multiplication: %d × %d = %d\n", a, b, a * b);
    
    if(b != 0) {
        printf("Division:       %d ÷ %d = %.4f\n", a, b, (float)a / b);
        printf("Modulo:         %d %% %d = %d\n", a, b, a % b);
    } else {
        printf("Division:       Cannot divide by zero\n");
    }
}

void powerOperation(int base, int exp) {
    printf("\n--- Power Operation ---\n");
    
    if(exp < 0) {
        printf("%d^%d = %.6f\n", base, exp, pow(base, exp));
    } else {
        long long result = 1;
        for(int i = 0; i < exp; i++) {
            result *= base;
        }
        printf("%d^%d = %lld\n", base, exp, result);
    }
}

void squareRoot(int n) {
    printf("\n--- Square Root ---\n");
    
    if(n < 0) {
        printf("✗ Cannot find square root of negative number!\n");
        return;
    }
    
    double sqrtVal = sqrt(n);
    printf("√%d = %.6f\n", n, sqrtVal);
    
    int intSqrt = (int)sqrtVal;
    if(intSqrt * intSqrt == n) {
        printf("%d is a perfect square (%d × %d)\n", n, intSqrt, intSqrt);
    }
}

void factorial(int n) {
    printf("\n--- Factorial ---\n");
    
    if(n < 0) {
        printf("✗ Factorial not defined for negative numbers!\n");
        return;
    }
    
    long long result = 1;
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    
    printf("%d! = %lld\n", n, result);
}

void percentageCalculator(float num, float percent) {
    printf("\n--- Percentage Calculator ---\n");
    
    float result = (num * percent) / 100;
    printf("%.2f%% of %.2f = %.2f\n", percent, num, result);
    printf("%.2f + %.2f%% = %.2f\n", num, percent, num + result);
    printf("%.2f - %.2f%% = %.2f\n", num, percent, num - result);
}

void averageCalculator() {
    int n;
    printf("\n--- Average Calculator ---\n");
    printf("How many numbers? ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("✗ Invalid count!\n");
        return;
    }
    
    float sum = 0, num;
    for(int i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%f", &num);
        sum += num;
    }
    
    printf("\nSum: %.2f\n", sum);
    printf("Average: %.2f\n", sum / n);
}

void compoundInterest(float principal, float rate, int time) {
    printf("\n--- Compound Interest ---\n");
    
    float amount = principal * pow(1 + rate / 100, time);
    float interest = amount - principal;
    
    printf("Principal: %.2f\n", principal);
    printf("Rate: %.2f%%\n", rate);
    printf("Time: %d years\n", time);
    printf("\nAmount: %.2f\n", amount);
    printf("Compound Interest: %.2f\n", interest);
}

void simpleInterest(float principal, float rate, int time) {
    printf("\n--- Simple Interest ---\n");
    
    float interest = (principal * rate * time) / 100;
    float amount = principal + interest;
    
    printf("Principal: %.2f\n", principal);
    printf("Rate: %.2f%%\n", rate);
    printf("Time: %d years\n", time);
    printf("\nSimple Interest: %.2f\n", interest);
    printf("Amount: %.2f\n", amount);
}

void quadraticEquation(float a, float b, float c) {
    printf("\n--- Quadratic Equation Solver ---\n");
    printf("Equation: %.2fx² + %.2fx + %.2f = 0\n\n", a, b, c);
    
    if(a == 0) {
        printf("✗ Not a quadratic equation (a cannot be 0)\n");
        return;
    }
    
    float discriminant = b * b - 4 * a * c;
    printf("Discriminant: %.2f\n", discriminant);
    
    if(discriminant > 0) {
        float root1 = (-b + sqrt(discriminant)) / (2 * a);
        float root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two real roots:\n");
        printf("x₁ = %.4f\n", root1);
        printf("x₂ = %.4f\n", root2);
    } else if(discriminant == 0) {
        float root = -b / (2 * a);
        printf("One real root:\n");
        printf("x = %.4f\n", root);
    } else {
        float realPart = -b / (2 * a);
        float imagPart = sqrt(-discriminant) / (2 * a);
        printf("Two complex roots:\n");
        printf("x₁ = %.4f + %.4fi\n", realPart, imagPart);
        printf("x₂ = %.4f - %.4fi\n", realPart, imagPart);
    }
}

void arithmeticProgression(int a, int d, int n) {
    printf("\n--- Arithmetic Progression ---\n");
    printf("First term: %d, Common difference: %d\n", a, d);
    printf("Number of terms: %d\n\n", n);
    
    int lastTerm = a + (n - 1) * d;
    int sum = (n * (a + lastTerm)) / 2;
    
    printf("nth term: %d\n", lastTerm);
    printf("Sum of %d terms: %d\n", n, sum);
    
    printf("\nSequence: ");
    for(int i = 0; i < (n < 10 ? n : 10); i++) {
        printf("%d ", a + i * d);
    }
    if(n > 10) printf("...");
    printf("\n");
}

void geometricProgression(int a, int r, int n) {
    printf("\n--- Geometric Progression ---\n");
    printf("First term: %d, Common ratio: %d\n", a, r);
    printf("Number of terms: %d\n\n", n);
    
    long long lastTerm = a * pow(r, n - 1);
    printf("nth term: %lld\n", lastTerm);
    
    if(r != 1) {
        long long sum = a * (pow(r, n) - 1) / (r - 1);
        printf("Sum of %d terms: %lld\n", n, sum);
    } else {
        printf("Sum of %d terms: %d\n", n, a * n);
    }
    
    printf("\nSequence: ");
    long long term = a;
    for(int i = 0; i < (n < 10 ? n : 10); i++) {
        printf("%lld ", term);
        term *= r;
    }
    if(n > 10) printf("...");
    printf("\n");
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void fractionSimplifier(int num, int den) {
    printf("\n--- Fraction Simplifier ---\n");
    
    if(den == 0) {
        printf("✗ Denominator cannot be zero!\n");
        return;
    }
    
    printf("Original fraction: %d/%d\n", num, den);
    
    int g = gcd(num, den);
    int simplifiedNum = num / g;
    int simplifiedDen = den / g;
    
    printf("Simplified: %d/%d\n", simplifiedNum, simplifiedDen);
    printf("Decimal: %.6f\n", (float)num / den);
    
    if(abs(num) >= abs(den)) {
        int whole = num / den;
        int remainder = abs(num % den);
        printf("Mixed number: %d %d/%d\n", whole, remainder, abs(den));
    }
}