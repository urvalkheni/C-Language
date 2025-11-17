/*
 * Advanced Alphabet Pyramid Generator v2.0
 * Features: Multiple pyramid styles, diamond patterns,
 *           hollow pyramids, customizable designs
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
void standardAlphabetPyramid();
void invertedAlphabetPyramid();
void alphabetDiamond();
void hollowAlphabetPyramid();
void fullAlphabetPyramid();
void reversedAlphabetPyramid();
void doubleAlphabetPyramid();
void numberLetterPyramid();
void centeredLetterPyramid();
void compressedAlphabetPyramid();
void expandingAlphabetPyramid();
void alternatingPyramid();
void waveAlphabetPyramid();
void spiralAlphabetPyramid();
void customStartPyramid();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║       Advanced Alphabet Pyramid Generator v2.0            ║\n");
    printf("║          Professional Pattern Design System                ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                standardAlphabetPyramid();
                break;
            case 2:
                invertedAlphabetPyramid();
                break;
            case 3:
                alphabetDiamond();
                break;
            case 4:
                hollowAlphabetPyramid();
                break;
            case 5:
                fullAlphabetPyramid();
                break;
            case 6:
                reversedAlphabetPyramid();
                break;
            case 7:
                doubleAlphabetPyramid();
                break;
            case 8:
                numberLetterPyramid();
                break;
            case 9:
                centeredLetterPyramid();
                break;
            case 10:
                compressedAlphabetPyramid();
                break;
            case 11:
                expandingAlphabetPyramid();
                break;
            case 12:
                alternatingPyramid();
                break;
            case 13:
                waveAlphabetPyramid();
                break;
            case 14:
                spiralAlphabetPyramid();
                break;
            case 15:
                customStartPyramid();
                break;
            case 16:
                printf("\n--- Pyramid Patterns Info ---\n");
                printf("\n• Standard: Classic A B C pattern\n");
                printf("• Diamond: Combined pyramids\n");
                printf("• Hollow: Border letters only\n");
                printf("• Wave: Oscillating letters\n");
                printf("• Spiral: Circular arrangement\n");
                break;
            case 0:
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Alphabet Pyramid Generator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC PYRAMIDS                                         │\n");
    printf("│  [1]  Standard Alphabet Pyramid                         │\n");
    printf("│  [2]  Inverted Alphabet Pyramid                         │\n");
    printf("│  [3]  Alphabet Diamond                                  │\n");
    printf("│  [4]  Hollow Alphabet Pyramid                           │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED PYRAMIDS                                      │\n");
    printf("│  [5]  Full Alphabet Pyramid                             │\n");
    printf("│  [6]  Reversed Alphabet Pyramid                         │\n");
    printf("│  [7]  Double Alphabet Pyramid                           │\n");
    printf("│  [8]  Number-Letter Pyramid                             │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL PYRAMIDS                                       │\n");
    printf("│  [9]  Centered Letter Pyramid                           │\n");
    printf("│  [10] Compressed Alphabet Pyramid                       │\n");
    printf("│  [11] Expanding Alphabet Pyramid                        │\n");
    printf("│  [12] Alternating Pyramid                               │\n");
    printf("│  [13] Wave Alphabet Pyramid                             │\n");
    printf("│  [14] Spiral Alphabet Pyramid                           │\n");
    printf("│  [15] Custom Start Pyramid                              │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Pyramid Patterns Info                             │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void standardAlphabetPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Standard Alphabet Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        int a = 65;
        for(int k = 1; k <= i; k++) {
            printf("%c ", a);
            a = a + 1;
        }
        
        int b = (i + 64) - 1;
        for(int o = 1; o <= i - 1; o++) {
            printf("%c ", b);
            b--;
        }
        
        printf("\n");
    }
}

void invertedAlphabetPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Inverted Alphabet Pyramid ---\n\n");
    
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        int a = 65;
        for(int k = 1; k <= i; k++) {
            printf("%c ", a);
            a = a + 1;
        }
        
        int b = (i + 64) - 1;
        for(int o = 1; o <= i - 1; o++) {
            printf("%c ", b);
            b--;
        }
        
        printf("\n");
    }
}

void alphabetDiamond() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Alphabet Diamond ---\n\n");
    
    // Upper pyramid
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        for(int k = 1; k <= i; k++) {
            printf("%c ", (k + 64));
        }
        
        for(int k = i - 1; k >= 1; k--) {
            printf("%c ", (k + 64));
        }
        
        printf("\n");
    }
    
    // Lower inverted pyramid
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        for(int k = 1; k <= i; k++) {
            printf("%c ", (k + 64));
        }
        
        for(int k = i - 1; k >= 1; k--) {
            printf("%c ", (k + 64));
        }
        
        printf("\n");
    }
}

void hollowAlphabetPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Hollow Alphabet Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        for(int k = 1; k <= 2 * i - 1; k++) {
            if(k == 1 || k == 2 * i - 1 || i == n) {
                printf("%c ", ((k - 1) % 26) + 65);
            } else {
                printf("  ");
            }
        }
        
        printf("\n");
    }
}

void fullAlphabetPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Full Alphabet Pyramid ---\n\n");
    
    char ch = 'A';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        for(int k = 1; k <= 2 * i - 1; k++) {
            printf("%c ", ch);
            ch++;
            if(ch > 'Z') ch = 'A';
        }
        
        printf("\n");
    }
}

void reversedAlphabetPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Reversed Alphabet Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        for(int k = i; k >= 1; k--) {
            printf("%c ", (k + 64));
        }
        
        for(int k = 2; k <= i; k++) {
            printf("%c ", (k + 64));
        }
        
        printf("\n");
    }
}

void doubleAlphabetPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Double Alphabet Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        for(int k = 1; k <= i; k++) {
            printf("%c ", (k + 64));
        }
        
        printf("   ");
        
        for(int k = 1; k <= i; k++) {
            printf("%c ", (k + 64));
        }
        
        printf("\n");
    }
}

void numberLetterPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Number-Letter Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        for(int k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        
        for(int k = i - 1; k >= 1; k--) {
            printf("%c ", (k + 64));
        }
        
        printf("\n");
    }
}

void centeredLetterPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Centered Letter Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        int spaces = 2 * (n - i);
        for(int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        
        char ch = 'A' + i - 1;
        for(int k = 1; k <= 2 * i - 1; k++) {
            printf("%c ", ch);
        }
        
        printf("\n");
    }
}

void compressedAlphabetPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Compressed Alphabet Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        
        for(int k = 1; k <= i; k++) {
            printf("%c", (k + 64));
        }
        
        for(int k = i - 1; k >= 1; k--) {
            printf("%c", (k + 64));
        }
        
        printf("\n");
    }
}

void expandingAlphabetPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Expanding Alphabet Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("   ");
        }
        
        for(int k = 1; k <= i; k++) {
            printf("%c   ", (k + 64));
        }
        
        for(int k = i - 1; k >= 1; k--) {
            printf("%c   ", (k + 64));
        }
        
        printf("\n");
    }
}

void alternatingPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Alternating Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        for(int k = 1; k <= i; k++) {
            if(k % 2 == 1) {
                printf("%c ", (k + 64));
            } else {
                printf("%c ", (k + 96));
            }
        }
        
        for(int k = i - 1; k >= 1; k--) {
            if(k % 2 == 1) {
                printf("%c ", (k + 64));
            } else {
                printf("%c ", (k + 96));
            }
        }
        
        printf("\n");
    }
}

void waveAlphabetPyramid() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Wave Alphabet Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        if(i % 2 == 1) {
            for(int k = 1; k <= i; k++) {
                printf("%c ", (k + 64));
            }
            for(int k = i - 1; k >= 1; k--) {
                printf("%c ", (k + 64));
            }
        } else {
            for(int k = i; k >= 1; k--) {
                printf("%c ", (k + 64));
            }
            for(int k = 2; k <= i; k++) {
                printf("%c ", (k + 64));
            }
        }
        
        printf("\n");
    }
}

void spiralAlphabetPyramid() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Spiral Alphabet Pyramid ---\n\n");
    
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
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void customStartPyramid() {
    int n;
    char start;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    printf("Enter starting character: ");
    scanf(" %c", &start);
    
    start = toupper(start);
    
    printf("\n--- Custom Start Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        char ch = start;
        for(int k = 1; k <= i; k++) {
            printf("%c ", ch);
            ch++;
            if(ch > 'Z') ch = 'A';
        }
        
        ch = start + i - 2;
        if(ch < 'A') ch = 'Z';
        for(int k = 1; k <= i - 1; k++) {
            printf("%c ", ch);
            ch--;
            if(ch < 'A') ch = 'Z';
        }
        
        printf("\n");
    }
}

/* Version note: updated 2025-11-17 — minor header/metadata bump */