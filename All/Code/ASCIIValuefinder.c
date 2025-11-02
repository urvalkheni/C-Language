/*
 * Advanced ASCII Character Analyzer v2.0
 * Features: ASCII table, character conversions,
 *           character classification, and encodings
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
void findASCII(char ch);
void findCharFromASCII(int ascii);
void printASCIITable(int start, int end);
void printFullASCIITable();
void characterInfo(char ch);
void stringASCII(char *str);
void convertCase(char ch);
void printControlChars();
void printPrintableChars();
void printAlphabet();
void printDigits();
void printSpecialChars();
void asciiArt(char ch);
void caesarCipher(char *str, int shift);
void characterClassification();
void displayMenu();

// Main function
int main() {
    int choice, ascii, start, end, shift;
    char ch, str[1000];
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║       Advanced ASCII Character Analyzer v2.0              ║\n");
    printf("║         ASCII Tables, Conversions & Analysis              ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        getchar(); // Clear newline
        
        switch(choice) {
            case 1:
                printf("\n--- Find ASCII Value ---\n");
                printf("Enter a character: ");
                scanf("%c", &ch);
                findASCII(ch);
                break;
                
            case 2:
                printf("\n--- Find Character from ASCII ---\n");
                printf("Enter ASCII value (0-127): ");
                scanf("%d", &ascii);
                findCharFromASCII(ascii);
                break;
                
            case 3:
                printf("\n--- ASCII Table Range ---\n");
                printf("Enter start value: ");
                scanf("%d", &start);
                printf("Enter end value: ");
                scanf("%d", &end);
                printASCIITable(start, end);
                break;
                
            case 4:
                printf("\n--- Full ASCII Table ---\n");
                printFullASCIITable();
                break;
                
            case 5:
                printf("\n--- Character Information ---\n");
                printf("Enter a character: ");
                scanf("%c", &ch);
                characterInfo(ch);
                break;
                
            case 6:
                printf("\n--- String ASCII Values ---\n");
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = 0;
                stringASCII(str);
                break;
                
            case 7:
                printf("\n--- Case Conversion ---\n");
                printf("Enter a character: ");
                scanf("%c", &ch);
                convertCase(ch);
                break;
                
            case 8:
                printf("\n--- Control Characters ---\n");
                printControlChars();
                break;
                
            case 9:
                printf("\n--- Printable Characters ---\n");
                printPrintableChars();
                break;
                
            case 10:
                printf("\n--- Alphabet Table ---\n");
                printAlphabet();
                break;
                
            case 11:
                printf("\n--- Digit Table ---\n");
                printDigits();
                break;
                
            case 12:
                printf("\n--- Special Characters ---\n");
                printSpecialChars();
                break;
                
            case 13:
                printf("\n--- ASCII Art ---\n");
                printf("Enter a character: ");
                scanf("%c", &ch);
                asciiArt(ch);
                break;
                
            case 14:
                printf("\n--- Caesar Cipher ---\n");
                printf("Enter text: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = 0;
                printf("Enter shift (1-25): ");
                scanf("%d", &shift);
                caesarCipher(str, shift);
                break;
                
            case 15:
                printf("\n--- Character Classification Guide ---\n");
                characterClassification();
                break;
                
            case 16: {
                printf("\n--- Quick ASCII Lookup ---\n");
                printf("Common characters:\n");
                printf("─────────────────────────\n");
                printf("'A' = %d\n", 'A');
                printf("'Z' = %d\n", 'Z');
                printf("'a' = %d\n", 'a');
                printf("'z' = %d\n", 'z');
                printf("'0' = %d\n", '0');
                printf("'9' = %d\n", '9');
                printf("' ' (space) = %d\n", ' ');
                printf("'\\n' (newline) = %d\n", '\n');
                break;
            }
                
            case 0:
                printf("\n✓ Thank you for using ASCII Analyzer!\n");
                break;
                
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar();
        }
        
    } while(choice != 0);
    
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC OPERATIONS                                       │\n");
    printf("│  [1]  Find ASCII Value of Character                     │\n");
    printf("│  [2]  Find Character from ASCII Value                   │\n");
    printf("│  [3]  Print ASCII Table (Custom Range)                  │\n");
    printf("│  [4]  Print Full ASCII Table (0-127)                    │\n");
    printf("│  [5]  Character Information                             │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  STRING OPERATIONS                                      │\n");
    printf("│  [6]  String to ASCII Values                            │\n");
    printf("│  [7]  Case Conversion (Upper/Lower)                     │\n");
    printf("│  [8]  Control Characters List                           │\n");
    printf("│  [9]  Printable Characters                              │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIALIZED TABLES                                     │\n");
    printf("│  [10] Alphabet ASCII Table                              │\n");
    printf("│  [11] Digit ASCII Table                                 │\n");
    printf("│  [12] Special Characters                                │\n");
    printf("│  [13] ASCII Art Display                                 │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED FEATURES                                      │\n");
    printf("│  [14] Caesar Cipher Encoder                             │\n");
    printf("│  [15] Character Classification Guide                    │\n");
    printf("│  [16] Quick ASCII Lookup                                │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void findASCII(char ch) {
    printf("\nCharacter: '%c'\n", ch);
    printf("ASCII Value: %d\n", (int)ch);
    printf("Hexadecimal: 0x%X\n", (int)ch);
    printf("Octal: 0%o\n", (int)ch);
    printf("Binary: ");
    for(int i = 7; i >= 0; i--) {
        printf("%d", ((int)ch >> i) & 1);
    }
    printf("\n");
}

void findCharFromASCII(int ascii) {
    if(ascii >= 0 && ascii <= 127) {
        printf("\nASCII %d = '%c'\n", ascii, (char)ascii);
        if(ascii < 32 || ascii == 127) {
            printf("(Control character)\n");
        }
    } else {
        printf("Invalid ASCII value! (0-127)\n");
    }
}

void printASCIITable(int start, int end) {
    printf("\n═══════════════════════════════════════\n");
    printf("  ASCII Table (%d to %d)\n", start, end);
    printf("═══════════════════════════════════════\n");
    printf(" Dec | Hex | Oct | Char\n");
    printf("───────────────────────────────────────\n");
    
    for(int i = start; i <= end && i <= 127; i++) {
        printf(" %3d | %2X  | %3o | ", i, i, i);
        if(i < 32 || i == 127) {
            printf("[CTRL]\n");
        } else {
            printf("  %c\n", (char)i);
        }
    }
}

void printFullASCIITable() {
    printASCIITable(0, 127);
}

void characterInfo(char ch) {
    printf("\n╔═══════════════════════════════════════╗\n");
    printf("║    CHARACTER INFORMATION              ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    printf("\nCharacter: '%c'\n", ch);
    printf("ASCII: %d\n", (int)ch);
    printf("─────────────────────────────────────────\n");
    printf("Is alphabetic: %s\n", isalpha(ch) ? "YES" : "NO");
    printf("Is digit: %s\n", isdigit(ch) ? "YES" : "NO");
    printf("Is alphanumeric: %s\n", isalnum(ch) ? "YES" : "NO");
    printf("Is uppercase: %s\n", isupper(ch) ? "YES" : "NO");
    printf("Is lowercase: %s\n", islower(ch) ? "YES" : "NO");
    printf("Is whitespace: %s\n", isspace(ch) ? "YES" : "NO");
    printf("Is punctuation: %s\n", ispunct(ch) ? "YES" : "NO");
    printf("Is printable: %s\n", isprint(ch) ? "YES" : "NO");
    printf("Is control char: %s\n", iscntrl(ch) ? "YES" : "NO");
}

void stringASCII(char *str) {
    printf("\nString: \"%s\"\n", str);
    printf("ASCII values:\n");
    for(int i = 0; str[i] != '\0'; i++) {
        printf("'%c' = %d ", str[i], (int)str[i]);
        if((i + 1) % 5 == 0) printf("\n");
    }
    printf("\n");
}

void convertCase(char ch) {
    printf("\nOriginal: '%c' (ASCII %d)\n", ch, (int)ch);
    if(isalpha(ch)) {
        if(isupper(ch)) {
            printf("Lowercase: '%c' (ASCII %d)\n", tolower(ch), (int)tolower(ch));
        } else {
            printf("Uppercase: '%c' (ASCII %d)\n", toupper(ch), (int)toupper(ch));
        }
    } else {
        printf("Not an alphabetic character.\n");
    }
}

void printControlChars() {
    printf("\n═══════════════════════════════════════════\n");
    printf("  Control Characters (0-31, 127)\n");
    printf("═══════════════════════════════════════════\n");
    printf("Dec | Hex | Name\n");
    printf("─────────────────────────────────────────\n");
    printf("  0 | 00  | NUL (Null)\n");
    printf("  7 | 07  | BEL (Bell)\n");
    printf("  8 | 08  | BS  (Backspace)\n");
    printf("  9 | 09  | HT  (Tab)\n");
    printf(" 10 | 0A  | LF  (Line Feed)\n");
    printf(" 13 | 0D  | CR  (Carriage Return)\n");
    printf(" 27 | 1B  | ESC (Escape)\n");
    printf("127 | 7F  | DEL (Delete)\n");
}

void printPrintableChars() {
    printf("\nPrintable Characters (32-126):\n");
    for(int i = 32; i <= 126; i++) {
        printf("%c ", (char)i);
        if((i - 31) % 20 == 0) printf("\n");
    }
    printf("\n");
}

void printAlphabet() {
    printf("\n═══════════════════════════════════════\n");
    printf("       ALPHABET ASCII TABLE\n");
    printf("═══════════════════════════════════════\n");
    printf("Upper | Dec | Lower | Dec\n");
    printf("───────────────────────────────────────\n");
    for(int i = 0; i < 26; i++) {
        printf("  %c   | %3d |   %c   | %3d\n", 
               'A' + i, 65 + i, 'a' + i, 97 + i);
    }
}

void printDigits() {
    printf("\n═══════════════════════════\n");
    printf("   DIGIT ASCII TABLE\n");
    printf("═══════════════════════════\n");
    printf("Digit | ASCII\n");
    printf("───────────────────────────\n");
    for(int i = 0; i <= 9; i++) {
        printf("  %d   |  %d\n", i, '0' + i);
    }
}

void printSpecialChars() {
    printf("\nCommon Special Characters:\n");
    printf("─────────────────────────────\n");
    printf("'!' = %d\n", '!');
    printf("'@' = %d\n", '@');
    printf("'#' = %d\n", '#');
    printf("'$' = %d\n", '$');
    printf("'%%' = %d\n", '%');
    printf("'&' = %d\n", '&');
    printf("'*' = %d\n", '*');
    printf("'+' = %d\n", '+');
    printf("'-' = %d\n", '-');
    printf("'/' = %d\n", '/');
    printf("'=' = %d\n", '=');
}

void asciiArt(char ch) {
    printf("\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%c ", ch);
        }
        printf("\n");
    }
}

void caesarCipher(char *str, int shift) {
    printf("\nOriginal: %s\n", str);
    printf("Encrypted: ");
    for(int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if(isalpha(ch)) {
            if(isupper(ch)) {
                ch = ((ch - 'A' + shift) % 26) + 'A';
            } else {
                ch = ((ch - 'a' + shift) % 26) + 'a';
            }
        }
        printf("%c", ch);
    }
    printf("\n");
}

void characterClassification() {
    printf("\n═══════════════════════════════════════════\n");
    printf("   CHARACTER CLASSIFICATION GUIDE\n");
    printf("═══════════════════════════════════════════\n");
    printf("\nControl Characters:  0-31, 127\n");
    printf("Printable:           32-126\n");
    printf("Space:               32\n");
    printf("Digits:              48-57  ('0'-'9')\n");
    printf("Uppercase Letters:   65-90  ('A'-'Z')\n");
    printf("Lowercase Letters:   97-122 ('a'-'z')\n");
    printf("Special Characters:  33-47, 58-64, 91-96, 123-126\n");
    printf("═══════════════════════════════════════════\n");
}