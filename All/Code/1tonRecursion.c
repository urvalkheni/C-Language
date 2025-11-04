/*
 * Advanced Recursion Analyzer & Demonstrator v2.0
 * Features: Multiple recursion types, analysis tools,
 *           visualization, and recursive algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
void printNto1();
void print1toN();
void printNaturalSum();
void factorialRecursive();
void fibonacciRecursive();
void powerRecursive();
void gcdRecursive();
void reverseNumberRecursive();
void sumOfDigitsRecursive();
void isPalindromeRecursive();
void towerOfHanoi();
void binarySearchRecursive();
void arrayOperations();
void stringReverseRecursive();
void nestedRecursion();
void displayMenu();

// Helper functions
int printDesc(int n);
int printAsc(int n);
int sum(int n);
int factorial(int n);
int fibonacci(int n);
int power(int base, int exp);
int gcd(int a, int b);
int reverseNum(int n, int rev);
int digitSum(int n);
int isPalindrome(int num, int *original);
void hanoi(int n, char from, char to, char aux);
int binarySearch(int arr[], int low, int high, int key);
void reverseString(char *str, int start, int end);
int nestedFunc(int n);

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║     Advanced Recursion Analyzer & Demonstrator v2.0       ║\n");
    printf("║         Comprehensive Recursive Programming Tool           ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                printNto1();
                break;
            case 2:
                print1toN();
                break;
            case 3:
                printNaturalSum();
                break;
            case 4:
                factorialRecursive();
                break;
            case 5:
                fibonacciRecursive();
                break;
            case 6:
                powerRecursive();
                break;
            case 7:
                gcdRecursive();
                break;
            case 8:
                reverseNumberRecursive();
                break;
            case 9:
                sumOfDigitsRecursive();
                break;
            case 10:
                isPalindromeRecursive();
                break;
            case 11:
                towerOfHanoi();
                break;
            case 12:
                binarySearchRecursive();
                break;
            case 13:
                arrayOperations();
                break;
            case 14:
                stringReverseRecursive();
                break;
            case 15:
                nestedRecursion();
                break;
            case 16:
                printf("\n--- Recursion Types ---\n");
                printf("\n• Direct: Function calls itself\n");
                printf("• Indirect: A calls B, B calls A\n");
                printf("• Tail: Recursive call is last statement\n");
                printf("• Head: Recursive call is first statement\n");
                printf("• Tree: Multiple recursive calls\n");
                printf("• Nested: Recursive call as parameter\n");
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Recursion Analyzer!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC RECURSION                                        │\n");
    printf("│  [1]  Print N to 1 (Descending)                         │\n");
    printf("│  [2]  Print 1 to N (Ascending)                          │\n");
    printf("│  [3]  Sum of Natural Numbers                            │\n");
    printf("│  [4]  Factorial (Recursive)                             │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  MATHEMATICAL RECURSION                                 │\n");
    printf("│  [5]  Fibonacci Sequence                                │\n");
    printf("│  [6]  Power Calculation                                 │\n");
    printf("│  [7]  GCD (Greatest Common Divisor)                     │\n");
    printf("│  [8]  Reverse Number                                    │\n");
    printf("│  [9]  Sum of Digits                                     │\n");
    printf("│  [10] Palindrome Checker                                │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED RECURSION                                     │\n");
    printf("│  [11] Tower of Hanoi                                    │\n");
    printf("│  [12] Binary Search (Recursive)                         │\n");
    printf("│  [13] Array Sum & Product                               │\n");
    printf("│  [14] String Reverse                                    │\n");
    printf("│  [15] Nested Recursion                                  │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Recursion Types Reference                         │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void printNto1() {
    int n;
    printf("\nEnter number: ");
    scanf("%d", &n);
    
    printf("\n--- Print N to 1 ---\n");
    printf("Numbers: ");
    printDesc(n);
    printf("\n");
}

int printDesc(int n) {
    if(n == 0) return 0;
    printf("%d ", n);
    return printDesc(n - 1);
}

void print1toN() {
    int n;
    printf("\nEnter number: ");
    scanf("%d", &n);
    
    printf("\n--- Print 1 to N ---\n");
    printf("Numbers: ");
    printAsc(n);
    printf("\n");
}

int printAsc(int n) {
    if(n == 0) return 0;
    printAsc(n - 1);
    printf("%d ", n);
    return 0;
}

void printNaturalSum() {
    int n;
    printf("\nEnter number: ");
    scanf("%d", &n);
    
    int result = sum(n);
    printf("\n--- Sum of Natural Numbers ---\n");
    printf("Sum of 1 to %d = %d\n", n, result);
}

int sum(int n) {
    if(n == 0) return 0;
    return n + sum(n - 1);
}

void factorialRecursive() {
    int n;
    printf("\nEnter number: ");
    scanf("%d", &n);
    
    if(n < 0) {
        printf("\n✗ Factorial not defined for negative numbers!\n");
        return;
    }
    
    int result = factorial(n);
    printf("\n--- Factorial ---\n");
    printf("%d! = %d\n", n, result);
}

int factorial(int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

void fibonacciRecursive() {
    int n;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    
    printf("\n--- Fibonacci Sequence ---\n");
    printf("First %d terms: ", n);
    
    for(int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void powerRecursive() {
    int base, exp;
    printf("\nEnter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);
    
    int result = power(base, exp);
    printf("\n--- Power Calculation ---\n");
    printf("%d^%d = %d\n", base, exp, result);
}

int power(int base, int exp) {
    if(exp == 0) return 1;
    return base * power(base, exp - 1);
}

void gcdRecursive() {
    int a, b;
    printf("\nEnter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    
    int result = gcd(a, b);
    printf("\n--- GCD (Greatest Common Divisor) ---\n");
    printf("GCD(%d, %d) = %d\n", a, b, result);
}

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void reverseNumberRecursive() {
    int n;
    printf("\nEnter number: ");
    scanf("%d", &n);
    
    int result = reverseNum(n, 0);
    printf("\n--- Reverse Number ---\n");
    printf("Original: %d\n", n);
    printf("Reversed: %d\n", result);
}

int reverseNum(int n, int rev) {
    if(n == 0) return rev;
    return reverseNum(n / 10, rev * 10 + n % 10);
}

void sumOfDigitsRecursive() {
    int n;
    printf("\nEnter number: ");
    scanf("%d", &n);
    
    int result = digitSum(n);
    printf("\n--- Sum of Digits ---\n");
    printf("Number: %d\n", n);
    printf("Sum of digits: %d\n", result);
}

int digitSum(int n) {
    if(n == 0) return 0;
    return (n % 10) + digitSum(n / 10);
}

void isPalindromeRecursive() {
    int n;
    printf("\nEnter number: ");
    scanf("%d", &n);
    
    int original = n;
    int result = isPalindrome(n, &original);
    
    printf("\n--- Palindrome Checker ---\n");
    printf("Number: %d\n", n);
    printf("Result: %s\n", result == original ? "Palindrome" : "Not a Palindrome");
}

int isPalindrome(int num, int *original) {
    static int reversed = 0;
    if(num == 0) {
        int temp = reversed;
        reversed = 0;
        return temp;
    }
    reversed = reversed * 10 + num % 10;
    return isPalindrome(num / 10, original);
}

void towerOfHanoi() {
    int n;
    printf("\nEnter number of disks: ");
    scanf("%d", &n);
    
    printf("\n--- Tower of Hanoi ---\n");
    printf("Steps to solve:\n\n");
    hanoi(n, 'A', 'C', 'B');
    printf("\nTotal moves: %d\n", (1 << n) - 1);
}

void hanoi(int n, char from, char to, char aux) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

void binarySearchRecursive() {
    int n, key;
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    int arr[100];
    printf("Enter %d sorted elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    int result = binarySearch(arr, 0, n - 1, key);
    
    printf("\n--- Binary Search (Recursive) ---\n");
    if(result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found\n", key);
}

int binarySearch(int arr[], int low, int high, int key) {
    if(low > high) return -1;
    
    int mid = low + (high - low) / 2;
    
    if(arr[mid] == key) return mid;
    if(arr[mid] > key) return binarySearch(arr, low, mid - 1, key);
    return binarySearch(arr, mid + 1, high, key);
}

void arrayOperations() {
    int n;
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    int arr[100];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\n--- Array Operations ---\n");
    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void stringReverseRecursive() {
    char str[100];
    printf("\nEnter a string: ");
    scanf(" %[^\n]s", str);
    
    printf("\n--- String Reverse ---\n");
    printf("Original: %s\n", str);
    
    reverseString(str, 0, strlen(str) - 1);
    printf("Reversed: %s\n", str);
}

void reverseString(char *str, int start, int end) {
    if(start >= end) return;
    
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    reverseString(str, start + 1, end - 1);
}

void nestedRecursion() {
    int n;
    printf("\nEnter number: ");
    scanf("%d", &n);
    
    int result = nestedFunc(n);
    printf("\n--- Nested Recursion ---\n");
    printf("nestedFunc(%d) = %d\n", n, result);
}

int nestedFunc(int n) {
    if(n > 100) return n - 10;
    return nestedFunc(nestedFunc(n + 11));
}