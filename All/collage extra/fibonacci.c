#include <stdio.h>

// Recursive Fibonacci
long long fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative Fibonacci
long long fibonacciIterative(int n) {
    if (n <= 1)
        return n;
    
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Display Fibonacci series
void displayFibonacciSeries(int n) {
    printf("\nFibonacci Series (first %d terms):\n", n);
    
    long long a = 0, b = 1, c;
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%lld ", a);
        } else if (i == 1) {
            printf("%lld ", b);
        } else {
            c = a + b;
            printf("%lld ", c);
            a = b;
            b = c;
        }
        
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    printf("\n");
}

// Check if a number is in Fibonacci sequence
int isFibonacci(long long num) {
    long long a = 0, b = 1, c;
    
    if (num == 0 || num == 1)
        return 1;
    
    while (b < num) {
        c = a + b;
        a = b;
        b = c;
    }
    
    return (b == num);
}

int main() {
    int choice, n;
    long long num;
    
    printf("=== Fibonacci Calculator ===\n\n");
    printf("1. Find Nth Fibonacci Number\n");
    printf("2. Display Fibonacci Series\n");
    printf("3. Check if number is in Fibonacci Sequence\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\nEnter N (position): ");
            scanf("%d", &n);
            if (n < 0) {
                printf("Please enter a positive number.\n");
            } else {
                printf("\nFibonacci(%d) using Iterative: %lld\n", 
                       n, fibonacciIterative(n));
                if (n <= 40) {
                    printf("Fibonacci(%d) using Recursive: %lld\n", 
                           n, fibonacciRecursive(n));
                } else {
                    printf("(Recursive method too slow for large n)\n");
                }
            }
            break;
            
        case 2:
            printf("\nHow many terms? ");
            scanf("%d", &n);
            if (n <= 0) {
                printf("Please enter a positive number.\n");
            } else {
                displayFibonacciSeries(n);
            }
            break;
            
        case 3:
            printf("\nEnter a number: ");
            scanf("%lld", &num);
            if (isFibonacci(num))
                printf("\n%lld IS in the Fibonacci sequence!\n", num);
            else
                printf("\n%lld is NOT in the Fibonacci sequence.\n", num);
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}
