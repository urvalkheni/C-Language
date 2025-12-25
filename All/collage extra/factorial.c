#include <stdio.h>

// Iterative factorial
unsigned long long factorialIterative(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Recursive factorial
unsigned long long factorialRecursive(int n) {
    if (n <= 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

// Function to display factorial table
void displayFactorialTable(int n) {
    printf("\n+-------+----------------------+\n");
    printf("| N     | Factorial            |\n");
    printf("+-------+----------------------+\n");
    
    for (int i = 0; i <= n; i++) {
        printf("| %-5d | %-20llu |\n", i, factorialIterative(i));
    }
    printf("+-------+----------------------+\n");
}

int main() {
    int num, choice;
    
    printf("=== Factorial Calculator ===\n\n");
    
    printf("1. Calculate Single Factorial\n");
    printf("2. Display Factorial Table\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nEnter a number (0-20): ");
        scanf("%d", &num);
        
        if (num < 0) {
            printf("Factorial is not defined for negative numbers!\n");
        }
        else if (num > 20) {
            printf("Number too large! (Result would overflow)\n");
        }
        else {
            printf("\nUsing Iterative method: %d! = %llu\n", 
                   num, factorialIterative(num));
            printf("Using Recursive method: %d! = %llu\n", 
                   num, factorialRecursive(num));
        }
    }
    else if (choice == 2) {
        printf("\nEnter upper limit (0-20): ");
        scanf("%d", &num);
        
        if (num < 0 || num > 20) {
            printf("Please enter a number between 0 and 20.\n");
        }
        else {
            displayFactorialTable(num);
        }
    }
    else {
        printf("Invalid choice!\n");
    }
    
    return 0;
}
