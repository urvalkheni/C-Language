#include <stdio.h>

// Function to find GCD using Euclidean algorithm
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find GCD using recursion
int findGCDRecursive(int a, int b) {
    if (b == 0)
        return a;
    return findGCDRecursive(b, a % b);
}

int main() {
    int num1, num2, choice;
    
    printf("=== GCD (Greatest Common Divisor) Calculator ===\n\n");
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    printf("\nChoose method:\n");
    printf("1. Iterative (Euclidean Algorithm)\n");
    printf("2. Recursive\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    int gcd;
    if (choice == 2) {
        gcd = findGCDRecursive(num1, num2);
        printf("\nGCD using Recursive method: %d\n", gcd);
    } else {
        gcd = findGCD(num1, num2);
        printf("\nGCD using Iterative method: %d\n", gcd);
    }
    
    // Calculate LCM using formula: LCM = (a * b) / GCD
    int lcm = (num1 * num2) / gcd;
    printf("LCM of %d and %d: %d\n", num1, num2, lcm);
    
    return 0;
}
