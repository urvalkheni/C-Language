/*
 * Advanced Alphabet Pattern Generator v2.0
 * Features: Alphabet patterns, pyramids, ASCII art,
 *           custom letter sequences, and typography
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
void alphabetPyramid();
void alphabetTriangle();
void hollowAlphabetSquare();
void alphabetDiamond();
void palindromeAlphabet();
void alternatingAlphabet();
void reverseAlphabet();
void zigzagAlphabet();
void alphabetSpiral();
void vowelPattern();
void customAlphabetPattern();
void alphabetGrid();
void letterFrequency();
void caesarCipher();
void alphabetArt();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║      Advanced Alphabet Pattern Generator v2.0             ║\n");
    printf("║         Comprehensive Typography & Pattern Tool            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                alphabetPyramid();
                break;
            case 2:
                alphabetTriangle();
                break;
            case 3:
                hollowAlphabetSquare();
                break;
            case 4:
                alphabetDiamond();
                break;
            case 5:
                palindromeAlphabet();
                break;
            case 6:
                alternatingAlphabet();
                break;
            case 7:
                reverseAlphabet();
                break;
            case 8:
                zigzagAlphabet();
                break;
            case 9:
                alphabetSpiral();
                break;
            case 10:
                vowelPattern();
                break;
            case 11:
                customAlphabetPattern();
                break;
            case 12:
                alphabetGrid();
                break;
            case 13:
                letterFrequency();
                break;
            case 14:
                caesarCipher();
                break;
            case 15:
                alphabetArt();
                break;
            case 16:
                printf("\n--- Alphabet Patterns Guide ---\n");
                printf("\n• Pyramid: Centered alphabet triangle\n");
                printf("• Diamond: Double pyramid\n");
                printf("• Palindrome: Mirror letter sequence\n");
                printf("• Spiral: Circular arrangement\n");
                printf("• Caesar: Shift cipher encoding\n");
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Alphabet Pattern Generator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC PATTERNS                                         │\n");
    printf("│  [1]  Alphabet Pyramid                                  │\n");
    printf("│  [2]  Alphabet Triangle                                 │\n");
    printf("│  [3]  Hollow Alphabet Square                            │\n");
    printf("│  [4]  Alphabet Diamond                                  │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SEQUENCE PATTERNS                                      │\n");
    printf("│  [5]  Palindrome Alphabet                               │\n");
    printf("│  [6]  Alternating Alphabet                              │\n");
    printf("│  [7]  Reverse Alphabet                                  │\n");
    printf("│  [8]  Zigzag Alphabet                                   │\n");
    printf("│  [9]  Alphabet Spiral                                   │\n");
    printf("│  [10] Vowel Pattern                                     │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED FEATURES                                      │\n");
    printf("│  [11] Custom Alphabet Pattern                           │\n");
    printf("│  [12] Alphabet Grid                                     │\n");
    printf("│  [13] Letter Frequency Analyzer                         │\n");
    printf("│  [14] Caesar Cipher                                     │\n");
    printf("│  [15] Alphabet ASCII Art                                │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Patterns Guide                                    │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void alphabetPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Alphabet Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        char a = 'A';
        for(int k = 1; k <= (2 * i - 1); k++) {
            printf("%c ", a);
            a++;
        }
        printf("\n");
    }
}

void alphabetTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Alphabet Triangle ---\n\n");
    
    char ch = 'A';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%c ", ch);
            ch++;
            if(ch > 'Z') ch = 'A';
        }
        printf("\n");
    }
}

void hollowAlphabetSquare() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Hollow Alphabet Square ---\n\n");
    
    char ch = 'A';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || i == n || j == 1 || j == n) {
                printf("%c ", ch);
                ch++;
                if(ch > 'Z') ch = 'A';
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void alphabetDiamond() {
    int n;
    printf("\nEnter size (odd number): ");
    scanf("%d", &n);
    
    printf("\n--- Alphabet Diamond ---\n\n");
    
    int mid = n / 2 + 1;
    
    for(int i = 1; i <= n; i++) {
        char ch = 'A';
        if(i <= mid) {
            for(int j = 1; j <= mid - i; j++)
                printf("  ");
            for(int k = 1; k <= 2 * i - 1; k++)
                printf("%c ", ch++);
        } else {
            for(int j = 1; j <= i - mid; j++)
                printf("  ");
            for(int k = 1; k <= 2 * (n - i + 1) - 1; k++)
                printf("%c ", ch++);
        }
        printf("\n");
    }
}

void palindromeAlphabet() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Palindrome Alphabet ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++)
            printf("  ");
        
        char ch = 'A';
        for(int j = 1; j <= i; j++)
            printf("%c ", ch++);
        
        ch -= 2;
        for(int j = 1; j < i; j++)
            printf("%c ", ch--);
        
        printf("\n");
    }
}

void alternatingAlphabet() {
    int n;
    printf("\nEnter rows: ");
    scanf("%d", &n);
    
    printf("\n--- Alternating Alphabet ---\n\n");
    
    for(int i = 0; i < n; i++) {
        char ch = (i % 2 == 0) ? 'A' : 'B';
        for(int j = 0; j < 26; j++) {
            printf("%c ", ch);
            ch += 2;
            if(ch > 'Z') ch = 'A' + (ch - 'Z' - 1);
        }
        printf("\n");
    }
}

void reverseAlphabet() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Reverse Alphabet ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        char ch = 'Z';
        for(int j = 1; j <= i; j++) {
            printf("%c ", ch);
            ch--;
        }
        printf("\n");
    }
}

void zigzagAlphabet() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    
    printf("\n--- Zigzag Alphabet ---\n\n");
    
    char ch = 'A';
    for(int i = 0; i < rows; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < cols; j++) {
                printf("%c ", ch);
                ch++;
                if(ch > 'Z') ch = 'A';
            }
        } else {
            char temp[100];
            for(int j = 0; j < cols; j++) {
                temp[j] = ch;
                ch++;
                if(ch > 'Z') ch = 'A';
            }
            for(int j = cols - 1; j >= 0; j--)
                printf("%c ", temp[j]);
        }
        printf("\n");
    }
}

void alphabetSpiral() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    char matrix[20][20];
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    char ch = 'A';
    
    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) {
            matrix[top][i] = ch++;
            if(ch > 'Z') ch = 'A';
        }
        top++;
        
        for(int i = top; i <= bottom; i++) {
            matrix[i][right] = ch++;
            if(ch > 'Z') ch = 'A';
        }
        right--;
        
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                matrix[bottom][i] = ch++;
                if(ch > 'Z') ch = 'A';
            }
            bottom--;
        }
        
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                matrix[i][left] = ch++;
                if(ch > 'Z') ch = 'A';
            }
            left++;
        }
    }
    
    printf("\n--- Alphabet Spiral ---\n\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void vowelPattern() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Vowel Pattern ---\n\n");
    
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i && j < 5; j++) {
            printf("%c ", vowels[j]);
        }
        printf("\n");
    }
}

void customAlphabetPattern() {
    int n, type;
    printf("\nEnter rows: ");
    scanf("%d", &n);
    printf("Choose pattern type:\n");
    printf("1. Uppercase  2. Lowercase  3. Mixed\n");
    printf("Choice: ");
    scanf("%d", &type);
    
    printf("\n--- Custom Alphabet Pattern ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            char ch;
            if(type == 1)
                ch = 'A' + (i + j - 2) % 26;
            else if(type == 2)
                ch = 'a' + (i + j - 2) % 26;
            else
                ch = ((i + j) % 2 == 0) ? 'A' + (i + j - 2) % 26 : 'a' + (i + j - 2) % 26;
            printf("%c ", ch);
        }
        printf("\n");
    }
}

void alphabetGrid() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    
    printf("\n--- Alphabet Grid ---\n\n");
    
    char ch = 'A';
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c ", ch);
            ch++;
            if(ch > 'Z') ch = 'A';
        }
        printf("\n");
    }
}

void letterFrequency() {
    char text[1000];
    int freq[26] = {0};
    
    printf("\nEnter text: ");
    scanf(" %[^\n]s", text);
    
    for(int i = 0; text[i] != '\0'; i++) {
        if(isalpha(text[i])) {
            freq[toupper(text[i]) - 'A']++;
        }
    }
    
    printf("\n--- Letter Frequency ---\n\n");
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            printf("%c: %d  ", 'A' + i, freq[i]);
            if((i + 1) % 5 == 0) printf("\n");
        }
    }
    printf("\n");
}

void caesarCipher() {
    char text[1000], encrypted[1000];
    int shift;
    
    printf("\nEnter text: ");
    scanf(" %[^\n]s", text);
    printf("Enter shift value: ");
    scanf("%d", &shift);
    
    for(int i = 0; text[i] != '\0'; i++) {
        if(isupper(text[i])) {
            encrypted[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        } else if(islower(text[i])) {
            encrypted[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        } else {
            encrypted[i] = text[i];
        }
    }
    encrypted[strlen(text)] = '\0';
    
    printf("\n--- Caesar Cipher ---\n");
    printf("Original:  %s\n", text);
    printf("Encrypted: %s\n", encrypted);
}

void alphabetArt() {
    printf("\n--- Alphabet ASCII Art ---\n\n");
    
    printf("    A     B B B   C C C   D D D\n");
    printf("   A A    B   B   C       D   D\n");
    printf("  A   A   B B B   C       D   D\n");
    printf(" A A A A  B   B   C       D   D\n");
    printf("A       A B B B   C C C   D D D\n\n");
    
    printf("E E E E   F F F   G G G   H   H\n");
    printf("E         F       G       H   H\n");
    printf("E E E     F F F   G  GG   H H H\n");
    printf("E         F       G   G   H   H\n");
    printf("E E E E   F       G G G   H   H\n");
}