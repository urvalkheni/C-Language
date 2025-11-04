/*
 * Advanced Character Classification & Analysis Tool v2.0
 * Features: Character type detection, ASCII analysis,
 *           string operations, and comprehensive character testing
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING 1000

// Function prototypes
void classifyCharacter(char ch);
void analyzeString();
void asciiTable();
void characterConversion();
void vowelConsonantCheck();
void caseAnalysis();
void specialCharacterList();
void characterFrequency();
void alphanumericTest();
void characterComparison();
void stringCharacterStats();
void whitespaceAnalysis();
void digitExtraction();
void alphabetFilter();
void characterEncoding();
void displayMenu();

int main() {
    int choice;
    char ch;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║  Advanced Character Classification & Analysis Tool v2.0   ║\n");
    printf("║         Comprehensive Character Operations System         ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        getchar(); // Clear newline
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                printf("\nEnter a character: ");
                scanf("%c", &ch);
                classifyCharacter(ch);
                break;
            case 2:
                analyzeString();
                break;
            case 3:
                asciiTable();
                break;
            case 4:
                characterConversion();
                break;
            case 5:
                vowelConsonantCheck();
                break;
            case 6:
                caseAnalysis();
                break;
            case 7:
                specialCharacterList();
                break;
            case 8:
                characterFrequency();
                break;
            case 9:
                alphanumericTest();
                break;
            case 10:
                characterComparison();
                break;
            case 11:
                stringCharacterStats();
                break;
            case 12:
                whitespaceAnalysis();
                break;
            case 13:
                digitExtraction();
                break;
            case 14:
                alphabetFilter();
                break;
            case 15:
                characterEncoding();
                break;
            case 16:
                printf("\n--- Quick Reference ---\n");
                printf("\nCharacter Types:\n");
                printf("• Alphabet: A-Z, a-z\n");
                printf("• Digit: 0-9\n");
                printf("• Special: !@#$%% etc.\n");
                printf("• Whitespace: space, tab, newline\n");
                printf("• Control: ASCII 0-31, 127\n");
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Character Analyzer!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  CHARACTER ANALYSIS                                     │\n");
    printf("│  [1]  Classify Single Character                         │\n");
    printf("│  [2]  Analyze String                                    │\n");
    printf("│  [3]  Display ASCII Table                               │\n");
    printf("│  [4]  Character Conversion                              │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIFIC CHECKS                                        │\n");
    printf("│  [5]  Vowel/Consonant Check                             │\n");
    printf("│  [6]  Case Analysis                                     │\n");
    printf("│  [7]  Special Character List                            │\n");
    printf("│  [8]  Character Frequency                               │\n");
    printf("│  [9]  Alphanumeric Test                                 │\n");
    printf("│  [10] Character Comparison                              │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  STRING OPERATIONS                                      │\n");
    printf("│  [11] String Character Statistics                       │\n");
    printf("│  [12] Whitespace Analysis                               │\n");
    printf("│  [13] Digit Extraction                                  │\n");
    printf("│  [14] Alphabet Filter                                   │\n");
    printf("│  [15] Character Encoding Info                           │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Quick Reference                                   │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void classifyCharacter(char ch) {
    printf("\n--- Character Classification ---\n");
    printf("Character: '%c'\n", ch);
    printf("ASCII Value: %d\n", (int)ch);
    printf("Hexadecimal: 0x%X\n", (unsigned char)ch);
    printf("Octal: %o\n\n", (unsigned char)ch);
    
    printf("Type: ");
    if(isalpha(ch)) {
        printf("ALPHABET ");
        if(isupper(ch)) printf("(Uppercase)");
        else printf("(Lowercase)");
        printf("\n");
        
        char vowels[] = "AEIOUaeiou";
        if(strchr(vowels, ch)) {
            printf("Category: VOWEL\n");
        } else {
            printf("Category: CONSONANT\n");
        }
    } else if(isdigit(ch)) {
        printf("DIGIT\n");
        printf("Numeric Value: %d\n", ch - '0');
    } else if(isspace(ch)) {
        printf("WHITESPACE");
        if(ch == ' ') printf(" (Space)");
        else if(ch == '\t') printf(" (Tab)");
        else if(ch == '\n') printf(" (Newline)");
        printf("\n");
    } else if(iscntrl(ch)) {
        printf("CONTROL CHARACTER\n");
    } else {
        printf("SPECIAL CHARACTER\n");
    }
    
    printf("\nProperties:\n");
    printf("• Printable: %s\n", isprint(ch) ? "Yes" : "No");
    printf("• Alphanumeric: %s\n", isalnum(ch) ? "Yes" : "No");
    printf("• Punctuation: %s\n", ispunct(ch) ? "Yes" : "No");
    printf("• Graphical: %s\n", isgraph(ch) ? "Yes" : "No");
}

void analyzeString() {
    char str[MAX_STRING];
    printf("\nEnter a string: ");
    fgets(str, MAX_STRING, stdin);
    str[strcspn(str, "\n")] = 0;
    
    int alphabets = 0, digits = 0, special = 0, spaces = 0;
    int upper = 0, lower = 0, vowels = 0, consonants = 0;
    
    printf("\n--- String Analysis ---\n");
    printf("String: \"%s\"\n", str);
    printf("Length: %zu\n\n", strlen(str));
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            alphabets++;
            if(isupper(str[i])) upper++;
            else lower++;
            
            char vowelList[] = "AEIOUaeiou";
            if(strchr(vowelList, str[i])) vowels++;
            else consonants++;
        } else if(isdigit(str[i])) {
            digits++;
        } else if(isspace(str[i])) {
            spaces++;
        } else {
            special++;
        }
    }
    
    printf("Alphabets: %d\n", alphabets);
    printf("  - Uppercase: %d\n", upper);
    printf("  - Lowercase: %d\n", lower);
    printf("  - Vowels: %d\n", vowels);
    printf("  - Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
    printf("Special Characters: %d\n", special);
}

void asciiTable() {
    printf("\n--- ASCII Table ---\n\n");
    printf("┌──────┬──────┬──────────┐\n");
    printf("│ Dec  │ Hex  │   Char   │\n");
    printf("├──────┼──────┼──────────┤\n");
    
    for(int i = 32; i < 127; i++) {
        printf("│ %3d  │ 0x%02X │    %c     │\n", i, i, (char)i);
        if((i - 31) % 20 == 0 && i != 126) {
            printf("├──────┼──────┼──────────┤\n");
        }
    }
    printf("└──────┴──────┴──────────┘\n");
}

void characterConversion() {
    char ch;
    printf("\nEnter a character: ");
    scanf("%c", &ch);
    
    printf("\n--- Character Conversion ---\n");
    printf("Original: '%c' (ASCII: %d)\n\n", ch, (int)ch);
    
    if(isalpha(ch)) {
        printf("Uppercase: '%c' (ASCII: %d)\n", toupper(ch), toupper(ch));
        printf("Lowercase: '%c' (ASCII: %d)\n", tolower(ch), tolower(ch));
        
        // Toggle case
        char toggled = isupper(ch) ? tolower(ch) : toupper(ch);
        printf("Toggled: '%c' (ASCII: %d)\n", toggled, toggled);
    } else if(isdigit(ch)) {
        printf("Numeric value: %d\n", ch - '0');
        printf("As character: '%c'\n", ch);
    }
    
    printf("\nNext character: '%c' (ASCII: %d)\n", ch + 1, ch + 1);
    printf("Previous character: '%c' (ASCII: %d)\n", ch - 1, ch - 1);
}

void vowelConsonantCheck() {
    char ch;
    printf("\nEnter a character: ");
    scanf("%c", &ch);
    
    printf("\n--- Vowel/Consonant Check ---\n");
    printf("Character: '%c'\n\n", ch);
    
    if(!isalpha(ch)) {
        printf("Not an alphabet character!\n");
        return;
    }
    
    char vowels[] = "AEIOUaeiou";
    if(strchr(vowels, ch)) {
        printf("Result: VOWEL\n");
        printf("Position in vowels: %ld\n", strchr(vowels, ch) - vowels + 1);
    } else {
        printf("Result: CONSONANT\n");
    }
    
    printf("Position in alphabet: %d\n", toupper(ch) - 'A' + 1);
}

void caseAnalysis() {
    char ch;
    printf("\nEnter a character: ");
    scanf("%c", &ch);
    
    printf("\n--- Case Analysis ---\n");
    printf("Character: '%c'\n\n", ch);
    
    if(!isalpha(ch)) {
        printf("Not an alphabet character!\n");
        return;
    }
    
    if(isupper(ch)) {
        printf("Case: UPPERCASE\n");
        printf("Position: %d (A=1)\n", ch - 'A' + 1);
        printf("Lowercase equivalent: '%c'\n", tolower(ch));
        printf("ASCII difference: %d\n", ch - tolower(ch));
    } else {
        printf("Case: LOWERCASE\n");
        printf("Position: %d (a=1)\n", ch - 'a' + 1);
        printf("Uppercase equivalent: '%c'\n", toupper(ch));
        printf("ASCII difference: %d\n", toupper(ch) - ch);
    }
}

void specialCharacterList() {
    printf("\n--- Common Special Characters ---\n\n");
    printf("Punctuation: . , ; : ! ? ' \" - ( ) [ ] { }\n");
    printf("Mathematical: + - * / %% = < > ^\n");
    printf("Symbols: @ # $ & ~ ` | \\ / _\n");
    printf("Currency: $ € £ ¥\n");
    
    printf("\nASCII Special Characters:\n");
    char specials[] = "!@#$%^&*()_+-=[]{}|;':\",./<>?`~\\";
    for(int i = 0; specials[i] != '\0'; i++) {
        printf("'%c' (%3d)  ", specials[i], specials[i]);
        if((i + 1) % 6 == 0) printf("\n");
    }
    printf("\n");
}

void characterFrequency() {
    char str[MAX_STRING];
    printf("\nEnter a string: ");
    fgets(str, MAX_STRING, stdin);
    str[strcspn(str, "\n")] = 0;
    
    int freq[256] = {0};
    
    for(int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    
    printf("\n--- Character Frequency ---\n\n");
    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0 && isprint(i)) {
            printf("'%c': %d time(s)\n", (char)i, freq[i]);
        }
    }
}

void alphanumericTest() {
    char ch;
    printf("\nEnter a character: ");
    scanf("%c", &ch);
    
    printf("\n--- Alphanumeric Test ---\n");
    printf("Character: '%c'\n\n", ch);
    
    printf("Is Alphanumeric: %s\n", isalnum(ch) ? "YES" : "NO");
    printf("Is Alphabet: %s\n", isalpha(ch) ? "YES" : "NO");
    printf("Is Digit: %s\n", isdigit(ch) ? "YES" : "NO");
    printf("Is Hexadecimal: %s\n", isxdigit(ch) ? "YES" : "NO");
    printf("Is Printable: %s\n", isprint(ch) ? "YES" : "NO");
}

void characterComparison() {
    char ch1, ch2;
    printf("\nEnter first character: ");
    scanf("%c", &ch1);
    getchar();
    printf("Enter second character: ");
    scanf("%c", &ch2);
    
    printf("\n--- Character Comparison ---\n");
    printf("First: '%c' (ASCII: %d)\n", ch1, ch1);
    printf("Second: '%c' (ASCII: %d)\n\n", ch2, ch2);
    
    if(ch1 == ch2) {
        printf("Characters are EQUAL\n");
    } else if(ch1 < ch2) {
        printf("'%c' comes BEFORE '%c'\n", ch1, ch2);
        printf("Difference: %d\n", ch2 - ch1);
    } else {
        printf("'%c' comes AFTER '%c'\n", ch1, ch2);
        printf("Difference: %d\n", ch1 - ch2);
    }
}

void stringCharacterStats() {
    char str[MAX_STRING];
    printf("\nEnter a string: ");
    fgets(str, MAX_STRING, stdin);
    str[strcspn(str, "\n")] = 0;
    
    printf("\n--- String Character Statistics ---\n");
    printf("String: \"%s\"\n\n", str);
    
    printf("First character: '%c'\n", str[0]);
    printf("Last character: '%c'\n", str[strlen(str) - 1]);
    
    char min = str[0], max = str[0];
    for(int i = 1; str[i] != '\0'; i++) {
        if(str[i] < min) min = str[i];
        if(str[i] > max) max = str[i];
    }
    
    printf("Smallest ASCII: '%c' (%d)\n", min, min);
    printf("Largest ASCII: '%c' (%d)\n", max, max);
}

void whitespaceAnalysis() {
    char str[MAX_STRING];
    printf("\nEnter a string (can include spaces): ");
    fgets(str, MAX_STRING, stdin);
    
    int spaces = 0, tabs = 0, newlines = 0, total = 0;
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ') spaces++;
        else if(str[i] == '\t') tabs++;
        else if(str[i] == '\n') newlines++;
        if(isspace(str[i])) total++;
    }
    
    printf("\n--- Whitespace Analysis ---\n");
    printf("Spaces: %d\n", spaces);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);
    printf("Total whitespace: %d\n", total);
}

void digitExtraction() {
    char str[MAX_STRING];
    printf("\nEnter a string: ");
    fgets(str, MAX_STRING, stdin);
    str[strcspn(str, "\n")] = 0;
    
    printf("\n--- Digit Extraction ---\n");
    printf("Original: \"%s\"\n", str);
    printf("Digits found: ");
    
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(isdigit(str[i])) {
            printf("%c ", str[i]);
            count++;
        }
    }
    
    if(count == 0) {
        printf("(none)");
    }
    printf("\nTotal digits: %d\n", count);
}

void alphabetFilter() {
    char str[MAX_STRING];
    printf("\nEnter a string: ");
    fgets(str, MAX_STRING, stdin);
    str[strcspn(str, "\n")] = 0;
    
    printf("\n--- Alphabet Filter ---\n");
    printf("Original: \"%s\"\n", str);
    printf("Alphabets only: ");
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

void characterEncoding() {
    char ch;
    printf("\nEnter a character: ");
    scanf("%c", &ch);
    
    printf("\n--- Character Encoding Information ---\n");
    printf("Character: '%c'\n\n", ch);
    
    printf("Decimal (ASCII): %d\n", (unsigned char)ch);
    printf("Hexadecimal: 0x%02X\n", (unsigned char)ch);
    printf("Octal: %03o\n", (unsigned char)ch);
    printf("Binary: ");
    
    for(int i = 7; i >= 0; i--) {
        printf("%d", (ch >> i) & 1);
        if(i == 4) printf(" ");
    }
    printf("\n");
} 