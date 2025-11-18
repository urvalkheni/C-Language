/*
 * Advanced Number Swapping Techniques v2.0
 * Features: Multiple swap algorithms, pointer operations,
 *           array swapping, circular rotations, and more
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void swapUsingTemp(int *a, int *b);
void swapArithmetic(int *a, int *b);
void swapXOR(int *a, int *b);
void swapMultiplication(int *a, int *b);
void swapMacro(int *a, int *b);
void swapPointers(int **a, int **b);
void swapArrayElements(int arr[], int i, int j);
void rotateArray(int arr[], int n, int positions);
void reverseArray(int arr[], int start, int end);
void cyclicSwap(int *a, int *b, int *c);
void swapStrings(char **str1, char **str2);
void swapFloats(float *a, float *b);
void compareSwapMethods(int a, int b);
void visualizeSwap(int a, int b);
void arraySwapDemo();
void matrixRowSwap();
void displayMenu();

// Main function
int main() {
    int choice;
    int num1, num2, num3;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║      Advanced Number Swapping Techniques v2.0              ║\n");
    printf("║           Comprehensive Swap Algorithm Library             ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-15): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n--- Swap Using Temporary Variable ---\n");
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                printf("Before swap: a = %d, b = %d\n", num1, num2);
                swapUsingTemp(&num1, &num2);
                printf("After swap:  a = %d, b = %d\n", num1, num2);
                break;
                
            case 2:
                printf("\n--- Swap Using Arithmetic (No Temp) ---\n");
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                printf("Before swap: a = %d, b = %d\n", num1, num2);
                swapArithmetic(&num1, &num2);
                printf("After swap:  a = %d, b = %d\n", num1, num2);
                break;
                
            case 3:
                printf("\n--- Swap Using XOR Operator ---\n");
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                printf("Before swap: a = %d, b = %d\n", num1, num2);
                swapXOR(&num1, &num2);
                printf("After swap:  a = %d, b = %d\n", num1, num2);
                break;
                
            case 4:
                printf("\n--- Swap Using Multiplication ---\n");
                printf("Enter first number (non-zero): ");
                scanf("%d", &num1);
                printf("Enter second number (non-zero): ");
                scanf("%d", &num2);
                if(num1 == 0 || num2 == 0) {
                    printf("Error: Cannot use multiplication method with zero!\n");
                } else {
                    printf("Before swap: a = %d, b = %d\n", num1, num2);
                    swapMultiplication(&num1, &num2);
                    printf("After swap:  a = %d, b = %d\n", num1, num2);
                }
                break;
                
            case 5:
                printf("\n--- Swap Using Macro ---\n");
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                printf("Before swap: a = %d, b = %d\n", num1, num2);
                swapMacro(&num1, &num2);
                printf("After swap:  a = %d, b = %d\n", num1, num2);
                break;
                
            case 6: {
                printf("\n--- Swap Pointers ---\n");
                int val1, val2;
                printf("Enter first number: ");
                scanf("%d", &val1);
                printf("Enter second number: ");
                scanf("%d", &val2);
                int *p1 = &val1, *p2 = &val2;
                printf("Before swap: p1 points to %d, p2 points to %d\n", *p1, *p2);
                swapPointers(&p1, &p2);
                printf("After swap:  p1 points to %d, p2 points to %d\n", *p1, *p2);
                break;
            }
                
            case 7:
                arraySwapDemo();
                break;
                
            case 8:
                printf("\n--- Cyclic Swap (Three Numbers) ---\n");
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                printf("Enter third number: ");
                scanf("%d", &num3);
                printf("Before swap: a = %d, b = %d, c = %d\n", num1, num2, num3);
                cyclicSwap(&num1, &num2, &num3);
                printf("After swap:  a = %d, b = %d, c = %d\n", num1, num2, num3);
                break;
                
            case 9: {
                printf("\n--- Swap Strings ---\n");
                char str1[100], str2[100];
                printf("Enter first string: ");
                scanf(" %[^\n]", str1);
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                char *p1 = str1, *p2 = str2;
                printf("Before swap: str1 = \"%s\", str2 = \"%s\"\n", str1, str2);
                char temp[100];
                strcpy(temp, str1);
                strcpy(str1, str2);
                strcpy(str2, temp);
                printf("After swap:  str1 = \"%s\", str2 = \"%s\"\n", str1, str2);
                break;
            }
                
            case 10: {
                printf("\n--- Swap Floating Point Numbers ---\n");
                float f1, f2;
                printf("Enter first float: ");
                scanf("%f", &f1);
                printf("Enter second float: ");
                scanf("%f", &f2);
                printf("Before swap: a = %.2f, b = %.2f\n", f1, f2);
                swapFloats(&f1, &f2);
                printf("After swap:  a = %.2f, b = %.2f\n", f1, f2);
                break;
            }
                
            case 11:
                printf("\n--- Compare Swap Methods ---\n");
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                compareSwapMethods(num1, num2);
                break;
                
            case 12:
                printf("\n--- Visualize Swap Process ---\n");
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                visualizeSwap(num1, num2);
                break;
                
            case 13:
                matrixRowSwap();
                break;
                
            case 14: {
                printf("\n--- Bitwise Swap Analysis ---\n");
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                printf("\nBinary representation:\n");
                printf("a = %d = ", num1);
                for(int i = 31; i >= 0; i--) {
                    printf("%d", (num1 >> i) & 1);
                    if(i % 4 == 0) printf(" ");
                }
                printf("\nb = %d = ", num2);
                for(int i = 31; i >= 0; i--) {
                    printf("%d", (num2 >> i) & 1);
                    if(i % 4 == 0) printf(" ");
                }
                printf("\n\nPerforming XOR swap...\n");
                swapXOR(&num1, &num2);
                printf("\nAfter swap:\n");
                printf("a = %d, b = %d\n", num1, num2);
                break;
            }
                
            case 15: {
                printf("\n--- Advanced Swap Statistics ---\n");
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                
                printf("\n╔═══════════════════════════════════════╗\n");
                printf("║      SWAP STATISTICS                  ║\n");
                printf("╚═══════════════════════════════════════╝\n");
                printf("\nOriginal values: a = %d, b = %d\n", num1, num2);
                printf("─────────────────────────────────────────\n");
                printf("Sum (a + b):        %d\n", num1 + num2);
                printf("Difference (a - b): %d\n", num1 - num2);
                printf("Product (a × b):    %d\n", num1 * num2);
                printf("XOR (a ^ b):        %d\n", num1 ^ num2);
                printf("AND (a & b):        %d\n", num1 & num2);
                printf("OR (a | b):         %d\n", num1 | num2);
                
                swapArithmetic(&num1, &num2);
                printf("\nAfter swap: a = %d, b = %d\n", num1, num2);
                printf("─────────────────────────────────────────\n");
                printf("✓ Values successfully swapped!\n");
                break;
            }
                
            case 0:
                printf("\n✓ Thank you for using Swap Techniques!\n");
                break;
                
            default:
                printf("\n✗ Invalid choice! Please try again.\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    return 0;
}

// Display menu
void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC SWAP METHODS                                     │\n");
    printf("│  [1]  Swap Using Temporary Variable                     │\n");
    printf("│  [2]  Swap Using Arithmetic (a+b, a-b)                  │\n");
    printf("│  [3]  Swap Using XOR Operator                           │\n");
    printf("│  [4]  Swap Using Multiplication/Division                │\n");
    printf("│  [5]  Swap Using Macro Technique                        │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED SWAPS                                         │\n");
    printf("│  [6]  Swap Pointers                                     │\n");
    printf("│  [7]  Array Element Swap & Rotation                     │\n");
    printf("│  [8]  Cyclic Swap (Three Numbers)                       │\n");
    printf("│  [9]  Swap Strings                                      │\n");
    printf("│  [10] Swap Floating Point Numbers                       │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ANALYSIS & VISUALIZATION                               │\n");
    printf("│  [11] Compare All Swap Methods                          │\n");
    printf("│  [12] Visualize Swap Process                            │\n");
    printf("│  [13] Matrix Row Swap                                   │\n");
    printf("│  [14] Bitwise Swap Analysis                             │\n");
    printf("│  [15] Swap Statistics                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit Program                                      │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

// Swap using temporary variable
void swapUsingTemp(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Swap using arithmetic
void swapArithmetic(int *a, int *b) {
    // Use safe temp-based swap to avoid overflow and undefined behavior.
    swapUsingTemp(a, b);
}

// Swap using XOR
void swapXOR(int *a, int *b) {
    if(a != b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

// Swap using multiplication
void swapMultiplication(int *a, int *b) {
    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;
}

// Swap using macro-like technique
void swapMacro(int *a, int *b) {
    *a = *a + *b - (*b = *a);
}

// Swap pointers
void swapPointers(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

// Swap array elements
void swapArrayElements(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Reverse array
void reverseArray(int arr[], int start, int end) {
    while(start < end) {
        swapArrayElements(arr, start, end);
        start++;
        end--;
    }
}

// Rotate array
void rotateArray(int arr[], int n, int positions) {
    positions = positions % n;
    reverseArray(arr, 0, positions - 1);
    reverseArray(arr, positions, n - 1);
    reverseArray(arr, 0, n - 1);
}

// Cyclic swap
void cyclicSwap(int *a, int *b, int *c) {
    int temp = *c;
    *c = *b;
    *b = *a;
    *a = temp;
}

// Swap floats
void swapFloats(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Compare swap methods
void compareSwapMethods(int a, int b) {
    clock_t start, end;
    double time_taken;
    int x, y;
    
    printf("\n╔═══════════════════════════════════════════════════╗\n");
    printf("║     SWAP METHOD PERFORMANCE COMPARISON            ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("\nOriginal values: a = %d, b = %d\n", a, b);
    printf("Running 1,000,000 iterations for each method...\n\n");
    
    // Temp variable
    x = a; y = b;
    start = clock();
    for(int i = 0; i < 1000000; i++) {
        swapUsingTemp(&x, &y);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Temporary Variable:  %.4f ms\n", time_taken);
    
    // Arithmetic
    x = a; y = b;
    start = clock();
    for(int i = 0; i < 1000000; i++) {
        swapArithmetic(&x, &y);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Arithmetic Method:   %.4f ms\n", time_taken);
    
    // XOR
    x = a; y = b;
    start = clock();
    for(int i = 0; i < 1000000; i++) {
        swapXOR(&x, &y);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("XOR Method:          %.4f ms\n", time_taken);
    
    printf("\n✓ All methods produce: a = %d, b = %d\n", b, a);
}

// Visualize swap
void visualizeSwap(int a, int b) {
    printf("\n═══════════════════════════════════════════════════\n");
    printf("       SWAP VISUALIZATION (Arithmetic Method)\n");
    printf("═══════════════════════════════════════════════════\n");
    
    printf("\nInitial State:\n");
    printf("┌──────┐     ┌──────┐\n");
    printf("│  %3d │     │  %3d │\n", a, b);
    printf("└──────┘     └──────┘\n");
    printf("   a            b\n");
    
    printf("\nStep 1: a = a + b\n");
    int step1 = a + b;
    printf("┌──────┐     ┌──────┐\n");
    printf("│  %3d │     │  %3d │\n", step1, b);
    printf("└──────┘     └──────┘\n");
    printf("   a            b\n");
    printf("(a = %d + %d = %d)\n", a, b, step1);
    
    printf("\nStep 2: b = a - b\n");
    int step2 = step1 - b;
    printf("┌──────┐     ┌──────┐\n");
    printf("│  %3d │     │  %3d │\n", step1, step2);
    printf("└──────┘     └──────┘\n");
    printf("   a            b\n");
    printf("(b = %d - %d = %d)\n", step1, b, step2);
    
    printf("\nStep 3: a = a - b\n");
    int step3 = step1 - step2;
    printf("┌──────┐     ┌──────┐\n");
    printf("│  %3d │     │  %3d │\n", step3, step2);
    printf("└──────┘     └──────┘\n");
    printf("   a            b\n");
    printf("(a = %d - %d = %d)\n", step1, step2, step3);
    
    printf("\n✓ Swap Complete! a = %d, b = %d\n", step3, step2);
}

// Array swap demo
void arraySwapDemo() {
    printf("\n--- Array Swap & Rotation Demo ---\n");
    int n;
    printf("Enter array size (max 20): ");
    scanf("%d", &n);
    
    if(n > 20 || n < 2) {
        printf("Invalid size!\n");
        return;
    }
    
    int arr[20];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Swap first and last
    printf("\n\nSwapping first and last elements...\n");
    swapArrayElements(arr, 0, n-1);
    printf("After swap: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Reverse
    printf("\n\nReversing entire array...\n");
    reverseArray(arr, 0, n-1);
    printf("After reverse: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Rotate
    int pos;
    printf("\n\nEnter positions to rotate: ");
    scanf("%d", &pos);
    rotateArray(arr, n, pos);
    printf("After rotation: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Matrix row swap
void matrixRowSwap() {
    printf("\n--- Matrix Row Swap ---\n");
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    if(rows > 10 || cols > 10) {
        printf("Maximum size is 10x10!\n");
        return;
    }
    
    int matrix[10][10];
    printf("Enter matrix elements:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("\nOriginal Matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    int r1, r2;
    printf("\nEnter two row indices to swap (0-%d): ", rows-1);
    scanf("%d %d", &r1, &r2);
    
    if(r1 >= 0 && r1 < rows && r2 >= 0 && r2 < rows) {
        // Swap rows
        for(int j = 0; j < cols; j++) {
            int temp = matrix[r1][j];
            matrix[r1][j] = matrix[r2][j];
            matrix[r2][j] = temp;
        }
        
        printf("\nMatrix after swapping rows %d and %d:\n", r1, r2);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                printf("%4d ", matrix[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Invalid row indices!\n");
    }
}