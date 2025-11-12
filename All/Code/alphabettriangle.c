/*
 * Advanced Alphabet Triangle Pattern Generator v2.0
 * Features: Multiple alphabet triangle patterns, customizations,
 *           inversions, mirror effects, and decorative borders
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Function prototypes
void basicAlphabetTriangle();
void invertedAlphabetTriangle();
void mirrorAlphabetTriangle();
void palindromeAlphabetTriangle();
void continuousAlphabetTriangle();
void numberAlphabetCombination();
void repeatingLetterTriangle();
void alternatingCaseTriangle();
void centeredAlphabetTriangle();
void hollowAlphabetTriangle();
void rightAngledAlphabetTriangle();
void doubleAlphabetTriangle();
void diagonalAlphabetPattern();
void zigzagAlphabetTriangle();
void customAlphabetTriangle();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║    Advanced Alphabet Triangle Pattern Generator v2.0      ║\n");
    printf("║         Comprehensive Alphabet Pattern Designer           ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                basicAlphabetTriangle();
                break;
            case 2:
                invertedAlphabetTriangle();
                break;
            case 3:
                mirrorAlphabetTriangle();
                break;
            case 4:
                palindromeAlphabetTriangle();
                break;
            case 5:
                continuousAlphabetTriangle();
                break;
            case 6:
                numberAlphabetCombination();
                break;
            case 7:
                repeatingLetterTriangle();
                break;
            case 8:
                alternatingCaseTriangle();
                break;
            case 9:
                centeredAlphabetTriangle();
                break;
            case 10:
                hollowAlphabetTriangle();
                break;
            case 11:
                rightAngledAlphabetTriangle();
                break;
            case 12:
                doubleAlphabetTriangle();
                break;
            case 13:
                diagonalAlphabetPattern();
                break;
            case 14:
                zigzagAlphabetTriangle();
                break;
            case 15:
                customAlphabetTriangle();
                break;
            case 16:
                printf("\n--- Pattern Guide ---\n");
                printf("\n• Basic: Standard A B C pattern\n");
                printf("• Continuous: Sequential alphabets\n");
                printf("• Palindrome: Mirrored letter arrangement\n");
                printf("• Hollow: Border-only letters\n");
                printf("• Zigzag: Alternating direction pattern\n");
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
    
    printf("\n✓ Thank you for using Alphabet Triangle Generator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC PATTERNS                                         │\n");
    printf("│  [1]  Basic Alphabet Triangle (A B C)                   │\n");
    printf("│  [2]  Inverted Alphabet Triangle                        │\n");
    printf("│  [3]  Mirror Alphabet Triangle                          │\n");
    printf("│  [4]  Palindrome Alphabet Triangle                      │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED PATTERNS                                      │\n");
    printf("│  [5]  Continuous Alphabet Triangle                      │\n");
    printf("│  [6]  Number-Alphabet Combination                       │\n");
    printf("│  [7]  Repeating Letter Triangle                         │\n");
    printf("│  [8]  Alternating Case Triangle                         │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL PATTERNS                                       │\n");
    printf("│  [9]  Centered Alphabet Triangle                        │\n");
    printf("│  [10] Hollow Alphabet Triangle                          │\n");
    printf("│  [11] Right-Angled Alphabet Triangle                    │\n");
    printf("│  [12] Double Alphabet Triangle                          │\n");
    printf("│  [13] Diagonal Alphabet Pattern                         │\n");
    printf("│  [14] Zigzag Alphabet Triangle                          │\n");
    printf("│  [15] Custom Alphabet Triangle                          │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Pattern Guide                                     │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void basicAlphabetTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Basic Alphabet Triangle ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= i; k++) {
            printf("%c ", k + 64);
        }
        printf("\n");
    }
}

void invertedAlphabetTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Inverted Alphabet Triangle ---\n\n");
    
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= i; k++) {
            printf("%c ", k + 64);
        }
        printf("\n");
    }
}

void mirrorAlphabetTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Mirror Alphabet Triangle ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%c ", j + 64);
        }
        printf("\n");
    }
    
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            printf("%c ", j + 64);
        }
        printf("\n");
    }
}

void palindromeAlphabetTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Palindrome Alphabet Triangle ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        for(int k = 1; k <= i; k++) {
            printf("%c ", k + 64);
        }
        
        for(int k = i - 1; k >= 1; k--) {
            printf("%c ", k + 64);
        }
        printf("\n");
    }
}

void continuousAlphabetTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Continuous Alphabet Triangle ---\n\n");
    
    char ch = 'A';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= i; k++) {
            printf("%c ", ch);
            ch++;
            if(ch > 'Z') ch = 'A';
        }
        printf("\n");
    }
}

void numberAlphabetCombination() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Number-Alphabet Combination ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= i; k++) {
            if(k % 2 == 1) {
                printf("%d ", k);
            } else {
                printf("%c ", k + 64);
            }
        }
        printf("\n");
    }
}

void repeatingLetterTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Repeating Letter Triangle ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        char ch = 'A' + i - 1;
        for(int k = 1; k <= i; k++) {
            printf("%c ", ch);
        }
        printf("\n");
    }
}

void alternatingCaseTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Alternating Case Triangle ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= i; k++) {
            if((i + k) % 2 == 0) {
                printf("%c ", (k + 64));
            } else {
                printf("%c ", (k + 96));
            }
        }
        printf("\n");
    }
}

void centeredAlphabetTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Centered Alphabet Triangle ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= 2 * i - 1; k++) {
            printf("%c ", ((k - 1) % 26) + 65);
        }
        printf("\n");
    }
}

void hollowAlphabetTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Hollow Alphabet Triangle ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= i; k++) {
            if(k == 1 || k == i || i == n) {
                printf("%c ", k + 64);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void rightAngledAlphabetTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Right-Angled Alphabet Triangle ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int k = 1; k <= i; k++) {
            printf("%c ", k + 64);
        }
        printf("\n");
    }
}

void doubleAlphabetTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Double Alphabet Triangle ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= i; k++) {
            printf("%c ", k + 64);
        }
        printf("  ");
        for(int k = i; k >= 1; k--) {
            printf("%c ", k + 64);
        }
        printf("\n");
    }
}

void diagonalAlphabetPattern() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Diagonal Alphabet Pattern ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                printf("%c ", (i % 26) + 65);
            } else if(i + j == n - 1) {
                printf("%c ", (j % 26) + 65);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void zigzagAlphabetTriangle() {
    int n;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    
    printf("\n--- Zigzag Alphabet Triangle ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 1) {
            for(int j = 1; j <= n - i; j++) {
                printf("  ");
            }
            for(int k = 1; k <= i; k++) {
                printf("%c ", k + 64);
            }
        } else {
            for(int j = 1; j <= n - i; j++) {
                printf("  ");
            }
            for(int k = i; k >= 1; k--) {
                printf("%c ", k + 64);
            }
        }
        printf("\n");
    }
}

void customAlphabetTriangle() {
    int n;
    char start;
    printf("\nEnter number of rows: ");
    scanf("%d", &n);
    printf("Enter starting character: ");
    scanf(" %c", &start);
    
    start = toupper(start);
    
    printf("\n--- Custom Alphabet Triangle ---\n\n");
    
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
        printf("\n");
    }
}