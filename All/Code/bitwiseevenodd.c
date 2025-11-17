/*
 * Advanced Bitwise Operations & Number Analysis v2.1
 * Modified: 2025-11-15
 * Features: Bitwise operators, bit manipulation,
 *           binary operations, parity checking
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bitwiseEvenOdd();
void bitwiseAND();
void bitwiseOR();
void bitwiseXOR();
void bitwiseNOT();
void leftShift();
void rightShift();
void setBit();
void clearBit();
void toggleBit();
void checkBit();
void countSetBits();
void reverseBits();
void swapBits();
void powerOfTwo();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║    Advanced Bitwise Operations & Number Analysis v2.0     ║\n");
    printf("║          Comprehensive Bit Manipulation System            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: bitwiseEvenOdd(); break;
            case 2: bitwiseAND(); break;
            case 3: bitwiseOR(); break;
            case 4: bitwiseXOR(); break;
            case 5: bitwiseNOT(); break;
            case 6: leftShift(); break;
            case 7: rightShift(); break;
            case 8: setBit(); break;
            case 9: clearBit(); break;
            case 10: toggleBit(); break;
            case 11: checkBit(); break;
            case 12: countSetBits(); break;
            case 13: reverseBits(); break;
            case 14: swapBits(); break;
            case 15: powerOfTwo(); break;
            case 16:
                printf("\n--- Bitwise Operators ---\n");
                printf("• & (AND): Both bits 1\n");
                printf("• | (OR): At least one bit 1\n");
                printf("• ^ (XOR): Bits different\n");
                printf("• ~ (NOT): Flip all bits\n");
                printf("• << (Left shift): Multiply by 2\n");
                printf("• >> (Right shift): Divide by 2\n");
                break;
            case 0: break;
            default: printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Bitwise Operations!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC OPERATIONS                                       │\n");
    printf("│  [1]  Bitwise Even/Odd Check                            │\n");
    printf("│  [2]  Bitwise AND (&)                                   │\n");
    printf("│  [3]  Bitwise OR (|)                                    │\n");
    printf("│  [4]  Bitwise XOR (^)                                   │\n");
    printf("│  [5]  Bitwise NOT (~)                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SHIFT OPERATIONS                                       │\n");
    printf("│  [6]  Left Shift (<<)                                   │\n");
    printf("│  [7]  Right Shift (>>)                                  │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BIT MANIPULATION                                       │\n");
    printf("│  [8]  Set Bit                                           │\n");
    printf("│  [9]  Clear Bit                                         │\n");
    printf("│  [10] Toggle Bit                                        │\n");
    printf("│  [11] Check Bit                                         │\n");
    printf("│  [12] Count Set Bits                                    │\n");
    printf("│  [13] Reverse Bits                                      │\n");
    printf("│  [14] Swap Bits                                         │\n");
    printf("│  [15] Power of Two Check                                │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Bitwise Operators Info                            │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void printBinary(unsigned int n) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if(i % 8 == 0 && i != 0) printf(" ");
    }
}

void bitwiseEvenOdd() {
    int num;
    printf("\nEnter a number: ");
    scanf("%d", &num);
    
    printf("\n--- Bitwise Even/Odd Check ---\n");
    printf("Number: %d\n", num);
    printf("Binary: ");
    printBinary(num);
    printf("\n");
    
    if(num & 1) {
        printf("%d is Odd (LSB = 1)\n", num);
    } else {
        printf("%d is Even (LSB = 0)\n", num);
    }
}

void bitwiseAND() {
    int a, b;
    printf("\nEnter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    
    int result = a & b;
    
    printf("\n--- Bitwise AND ---\n");
    printf("A = %d: ", a); printBinary(a); printf("\n");
    printf("B = %d: ", b); printBinary(b); printf("\n");
    printf("A & B = %d: ", result); printBinary(result); printf("\n");
}

void bitwiseOR() {
    int a, b;
    printf("\nEnter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    
    int result = a | b;
    
    printf("\n--- Bitwise OR ---\n");
    printf("A = %d: ", a); printBinary(a); printf("\n");
    printf("B = %d: ", b); printBinary(b); printf("\n");
    printf("A | B = %d: ", result); printBinary(result); printf("\n");
}

void bitwiseXOR() {
    int a, b;
    printf("\nEnter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    
    int result = a ^ b;
    
    printf("\n--- Bitwise XOR ---\n");
    printf("A = %d: ", a); printBinary(a); printf("\n");
    printf("B = %d: ", b); printBinary(b); printf("\n");
    printf("A ^ B = %d: ", result); printBinary(result); printf("\n");
}

void bitwiseNOT() {
    int a;
    printf("\nEnter a number: ");
    scanf("%d", &a);
    
    int result = ~a;
    
    printf("\n--- Bitwise NOT ---\n");
    printf("A = %d: ", a); printBinary(a); printf("\n");
    printf("~A = %d: ", result); printBinary(result); printf("\n");
}

void leftShift() {
    int num, shift;
    printf("\nEnter number: ");
    scanf("%d", &num);
    printf("Enter shift amount: ");
    scanf("%d", &shift);
    if(shift < 0 || shift > 31) {
        printf("Invalid shift amount (0-31).\n");
        return;
    }

    int result = num << shift;
    
    printf("\n--- Left Shift ---\n");
    printf("Original: %d << %d = %d\n", num, shift, result);
    printf("Effect: %d × 2^%d = %d\n", num, shift, result);
    printf("Before: "); printBinary(num); printf("\n");
    printf("After:  "); printBinary(result); printf("\n");
}

void rightShift() {
    int num, shift;
    printf("\nEnter number: ");
    scanf("%d", &num);
    printf("Enter shift amount: ");
    scanf("%d", &shift);
    if(shift < 0 || shift > 31) {
        printf("Invalid shift amount (0-31).\n");
        return;
    }

    int result = num >> shift;
    
    printf("\n--- Right Shift ---\n");
    printf("Original: %d >> %d = %d\n", num, shift, result);
    printf("Effect: %d ÷ 2^%d = %d\n", num, shift, result);
    printf("Before: "); printBinary(num); printf("\n");
    printf("After:  "); printBinary(result); printf("\n");
}

void setBit() {
    int num, pos;
    printf("\nEnter number: ");
    scanf("%d", &num);
    printf("Enter bit position (0-31): ");
    scanf("%d", &pos);
    
    int result = num | (1 << pos);
    
    printf("\n--- Set Bit ---\n");
    printf("Before: "); printBinary(num); printf("\n");
    printf("After:  "); printBinary(result); printf("\n");
    printf("Result: %d\n", result);
}

void clearBit() {
    int num, pos;
    printf("\nEnter number: ");
    scanf("%d", &num);
    printf("Enter bit position (0-31): ");
    scanf("%d", &pos);
    
    int result = num & ~(1 << pos);
    
    printf("\n--- Clear Bit ---\n");
    printf("Before: "); printBinary(num); printf("\n");
    printf("After:  "); printBinary(result); printf("\n");
    printf("Result: %d\n", result);
}

void toggleBit() {
    int num, pos;
    printf("\nEnter number: ");
    scanf("%d", &num);
    printf("Enter bit position (0-31): ");
    scanf("%d", &pos);
    
    int result = num ^ (1 << pos);
    
    printf("\n--- Toggle Bit ---\n");
    printf("Before: "); printBinary(num); printf("\n");
    printf("After:  "); printBinary(result); printf("\n");
    printf("Result: %d\n", result);
}

void checkBit() {
    int num, pos;
    printf("\nEnter number: ");
    scanf("%d", &num);
    printf("Enter bit position (0-31): ");
    scanf("%d", &pos);
    
    int bit = (num >> pos) & 1;
    
    printf("\n--- Check Bit ---\n");
    printf("Number: "); printBinary(num); printf("\n");
    printf("Bit at position %d: %d\n", pos, bit);
}

void countSetBits() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    int count = 0;
    int temp = num;
    
    while(temp) {
        count += temp & 1;
        temp >>= 1;
    }
    
    printf("\n--- Count Set Bits ---\n");
    printf("Number: "); printBinary(num); printf("\n");
    printf("Set bits (1s): %d\n", count);
    printf("Clear bits (0s): %d\n", 32 - count);
}

void reverseBits() {
    unsigned int num;
    printf("\nEnter number: ");
    scanf("%u", &num);
    
    unsigned int result = 0;
    for(int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (num & 1);
        num >>= 1;
    }
    
    printf("\n--- Reverse Bits ---\n");
    printf("Original: %u\n", num);
    printf("Reversed: %u\n", result);
}

void swapBits() {
    int num, pos1, pos2;
    printf("\nEnter number: ");
    scanf("%d", &num);
    printf("Enter first bit position: ");
    scanf("%d", &pos1);
    printf("Enter second bit position: ");
    scanf("%d", &pos2);
    
    int bit1 = (num >> pos1) & 1;
    int bit2 = (num >> pos2) & 1;
    
    if(bit1 != bit2) {
        num ^= (1 << pos1);
        num ^= (1 << pos2);
    }
    
    printf("\n--- Swap Bits ---\n");
    printf("Result: %d\n", num);
    printf("Binary: "); printBinary(num); printf("\n");
}

void powerOfTwo() {
    int num;
    printf("\nEnter number: ");
    scanf("%d", &num);
    
    bool isPower = (num > 0) && ((num & (num - 1)) == 0);
    
    printf("\n--- Power of Two Check ---\n");
    printf("Number: %d\n", num);
    printf("Binary: "); printBinary(num); printf("\n");
    printf("Is power of 2: %s\n", isPower ? "Yes" : "No");
    
    if(isPower) {
        int power = 0;
        int temp = num;
        while(temp > 1) {
            temp >>= 1;
            power++;
        }
        printf("2^%d = %d\n", power, num);
    }
}

/* Version note: updated 2025-11-17 — minor header/metadata bump */
