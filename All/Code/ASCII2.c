/*
 * Advanced ASCII Table & Character Analyzer v2.0
 * Features: Complete ASCII tables, character conversions,
 *           encoding analysis, and character utilities
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void printASCIITable();
void printUppercaseTable();
void printLowercaseTable();
void printDigitsTable();
void printSpecialCharsTable();
void printExtendedASCII();
void charToASCII();
void asciiToChar();
void stringASCIIValues();
void asciiRangeDisplay();
void characterComparison();
void asciiArithmetic();
void controlCharacters();
void printableCharacters();
void customRangeASCII();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║     Advanced ASCII Table & Character Analyzer v2.0        ║\n");
    printf("║          Complete ASCII Reference System                  ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1: printASCIITable(); break;
            case 2: printUppercaseTable(); break;
            case 3: printLowercaseTable(); break;
            case 4: printDigitsTable(); break;
            case 5: printSpecialCharsTable(); break;
            case 6: printExtendedASCII(); break;
            case 7: charToASCII(); break;
            case 8: asciiToChar(); break;
            case 9: stringASCIIValues(); break;
            case 10: asciiRangeDisplay(); break;
            case 11: characterComparison(); break;
            case 12: asciiArithmetic(); break;
            case 13: controlCharacters(); break;
            case 14: printableCharacters(); break;
            case 15: customRangeASCII(); break;
            case 16:
                printf("\n--- ASCII Info ---\n");
                printf("• ASCII: American Standard Code for Information Interchange\n");
                printf("• Range: 0-127 (Standard), 0-255 (Extended)\n");
                printf("• Uppercase: 65-90 (A-Z)\n");
                printf("• Lowercase: 97-122 (a-z)\n");
                printf("• Digits: 48-57 (0-9)\n");
                break;
            case 0: break;
            default: printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using ASCII Analyzer!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ASCII TABLES                                           │\n");
    printf("│  [1]  Complete ASCII Table                              │\n");
    printf("│  [2]  Uppercase Letters (A-Z)                           │\n");
    printf("│  [3]  Lowercase Letters (a-z)                           │\n");
    printf("│  [4]  Digits Table (0-9)                                │\n");
    printf("│  [5]  Special Characters                                │\n");
    printf("│  [6]  Extended ASCII (128-255)                          │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  CONVERSIONS                                            │\n");
    printf("│  [7]  Character to ASCII                                │\n");
    printf("│  [8]  ASCII to Character                                │\n");
    printf("│  [9]  String ASCII Values                               │\n");
    printf("│  [10] ASCII Range Display                               │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  UTILITIES                                              │\n");
    printf("│  [11] Character Comparison                              │\n");
    printf("│  [12] ASCII Arithmetic                                  │\n");
    printf("│  [13] Control Characters                                │\n");
    printf("│  [14] Printable Characters                              │\n");
    printf("│  [15] Custom Range ASCII                                │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] ASCII Info                                        │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void printASCIITable() {
    printf("\n--- Complete ASCII Table (32-126) ---\n\n");
    printf("Dec\tHex\tChar\t|\tDec\tHex\tChar\t|\tDec\tHex\tChar\n");
    printf("────────────────────────────────────────────────────────────────────\n");
    
    for(int i = 32; i < 64; i++) {
        printf("%d\t%X\t%c\t|\t", i, i, i);
        printf("%d\t%X\t%c\t|\t", i+32, i+32, i+32);
        printf("%d\t%X\t%c\n", i+64, i+64, i+64);
    }
}

void printUppercaseTable() {
    printf("\n--- Uppercase Letters Table ---\n\n");
    printf("Letter\tASCII\tHex\tBinary\n");
    printf("────────────────────────────────────\n");
    
    for(int i = 65; i < 91; i++) {
        printf("%c\t%d\t%X\t", i, i, i);
        for(int j = 7; j >= 0; j--) {
            printf("%d", (i >> j) & 1);
        }
        printf("\n");
    }
}

void printLowercaseTable() {
    printf("\n--- Lowercase Letters Table ---\n\n");
    printf("Letter\tASCII\tHex\tBinary\n");
    printf("────────────────────────────────────\n");
    
    for(int j = 97; j < 123; j++) {
        printf("%c\t%d\t%X\t", j, j, j);
        for(int k = 7; k >= 0; k--) {
            printf("%d", (j >> k) & 1);
        }
        printf("\n");
    }
}

void printDigitsTable() {
    printf("\n--- Digits Table (0-9) ---\n\n");
    printf("Digit\tASCII\tHex\tBinary\n");
    printf("────────────────────────────────────\n");
    
    for(int i = 48; i <= 57; i++) {
        printf("%c\t%d\t%X\t", i, i, i);
        for(int j = 7; j >= 0; j--) {
            printf("%d", (i >> j) & 1);
        }
        printf("\n");
    }
}

void printSpecialCharsTable() {
    printf("\n--- Special Characters ---\n\n");
    printf("Char\tASCII\tDescription\n");
    printf("─────────────────────────────────────────\n");
    printf("!\t33\tExclamation mark\n");
    printf("@\t64\tAt sign\n");
    printf("#\t35\tHash\n");
    printf("$\t36\tDollar\n");
    printf("%%\t37\tPercent\n");
    printf("&\t38\tAmpersand\n");
    printf("*\t42\tAsterisk\n");
    printf("+\t43\tPlus\n");
    printf("-\t45\tMinus\n");
    printf("/\t47\tSlash\n");
    printf("=\t61\tEquals\n");
}

void printExtendedASCII() {
    printf("\n--- Extended ASCII (128-255) ---\n\n");
    
    for(int i = 128; i < 256; i++) {
        printf("%d:%c  ", i, i);
        if((i - 127) % 10 == 0) printf("\n");
    }
    printf("\n");
}

void charToASCII() {
    char ch;
    printf("\nEnter a character: ");
    scanf("%c", &ch);
    
    printf("\n--- Character to ASCII ---\n");
    printf("Character: '%c'\n", ch);
    printf("ASCII Decimal: %d\n", ch);
    printf("ASCII Hexadecimal: %X\n", ch);
    printf("ASCII Octal: %o\n", ch);
    printf("Binary: ");
    for(int i = 7; i >= 0; i--) {
        printf("%d", (ch >> i) & 1);
    }
    printf("\n");
}

void asciiToChar() {
    int ascii;
    printf("\nEnter ASCII value (0-255): ");
    scanf("%d", &ascii);
    
    if(ascii >= 0 && ascii <= 255) {
        printf("\n--- ASCII to Character ---\n");
        printf("ASCII: %d\n", ascii);
        printf("Character: '%c'\n", ascii);
        printf("Hex: %X\n", ascii);
        printf("Is printable: %s\n", isprint(ascii) ? "Yes" : "No");
    } else {
        printf("Invalid ASCII value!\n");
    }
}

void stringASCIIValues() {
    char str[100];
    printf("\nEnter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    
    printf("\n--- String ASCII Values ---\n");
    printf("String: \"%s\"\n\n", str);
    printf("Char\tASCII\tHex\n");
    printf("────────────────────────\n");
    
    for(int i = 0; str[i] != '\0'; i++) {
        printf("'%c'\t%d\t%X\n", str[i], str[i], str[i]);
    }
}

void asciiRangeDisplay() {
    int start, end;
    printf("\nEnter start ASCII: ");
    scanf("%d", &start);
    printf("Enter end ASCII: ");
    scanf("%d", &end);
    
    if(start >= 0 && end <= 255 && start <= end) {
        printf("\n--- ASCII Range %d to %d ---\n\n", start, end);
        
        for(int i = start; i <= end; i++) {
            printf("%3d:%c  ", i, isprint(i) ? i : '.');
            if((i - start + 1) % 10 == 0) printf("\n");
        }
        printf("\n");
    } else {
        printf("Invalid range!\n");
    }
}

void characterComparison() {
    char ch1, ch2;
    printf("\nEnter first character: ");
    scanf(" %c", &ch1);
    printf("Enter second character: ");
    scanf(" %c", &ch2);
    
    printf("\n--- Character Comparison ---\n");
    printf("'%c' (ASCII: %d) vs '%c' (ASCII: %d)\n", ch1, ch1, ch2, ch2);
    printf("Difference: %d\n", abs(ch1 - ch2));
    
    if(ch1 < ch2)
        printf("'%c' comes before '%c'\n", ch1, ch2);
    else if(ch1 > ch2)
        printf("'%c' comes after '%c'\n", ch1, ch2);
    else
        printf("Both characters are the same\n");
}

void asciiArithmetic() {
    char ch;
    int offset;
    printf("\nEnter a character: ");
    scanf(" %c", &ch);
    printf("Enter offset (+/-): ");
    scanf("%d", &offset);
    
    char result = ch + offset;
    
    printf("\n--- ASCII Arithmetic ---\n");
    printf("Original: '%c' (ASCII: %d)\n", ch, ch);
    printf("Offset: %+d\n", offset);
    printf("Result: '%c' (ASCII: %d)\n", result, result);
}

void controlCharacters() {
    printf("\n--- Control Characters (0-31) ---\n\n");
    printf("Dec\tHex\tName\n");
    printf("─────────────────────────────────\n");
    printf("0\t00\tNUL (Null)\n");
    printf("7\t07\tBEL (Bell)\n");
    printf("8\t08\tBS (Backspace)\n");
    printf("9\t09\tHT (Tab)\n");
    printf("10\t0A\tLF (Line Feed)\n");
    printf("13\t0D\tCR (Carriage Return)\n");
    printf("27\t1B\tESC (Escape)\n");
    printf("32\t20\tSP (Space)\n");
}

void printableCharacters() {
    printf("\n--- Printable Characters (33-126) ---\n\n");
    
    int count = 0;
    for(int i = 33; i <= 126; i++) {
        printf("%c ", i);
        count++;
        if(count % 20 == 0) printf("\n");
    }
    printf("\n\nTotal printable characters: %d\n", count);
}

void customRangeASCII() {
    int start, end, cols;
    printf("\nEnter start value: ");
    scanf("%d", &start);
    printf("Enter end value: ");
    scanf("%d", &end);
    printf("Enter columns: ");
    scanf("%d", &cols);
    
    printf("\n--- Custom ASCII Range ---\n\n");
    
    int count = 0;
    for(int i = start; i <= end && i <= 255; i++) {
        printf("%3d:%c  ", i, isprint(i) ? i : '.');
        count++;
        if(count % cols == 0) printf("\n");
    }
    printf("\n");
}