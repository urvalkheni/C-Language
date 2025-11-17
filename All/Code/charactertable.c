/*
 * Advanced Character Table & Pattern Generator v2.0
 * Features: Character tables, alphabetic patterns,
 *           matrix displays, custom arrangements
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void basicCharacterTable();
void reverseCharTable();
void numberCharCombo();
void diagonalCharPattern();
void spiralCharPattern();
void zigzagCharTable();
void mirrorCharTable();
void hollowCharTable();
void diamondCharPattern();
void pyramidCharTable();
void customCharTable();
void asciiCharTable();
void vowelConsonantTable();
void alternatingCharTable();
void borderedCharTable();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║   Advanced Character Table & Pattern Generator v2.0       ║\n");
    printf("║         Professional Character Display System             ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: basicCharacterTable(); break;
            case 2: reverseCharTable(); break;
            case 3: numberCharCombo(); break;
            case 4: diagonalCharPattern(); break;
            case 5: spiralCharPattern(); break;
            case 6: zigzagCharTable(); break;
            case 7: mirrorCharTable(); break;
            case 8: hollowCharTable(); break;
            case 9: diamondCharPattern(); break;
            case 10: pyramidCharTable(); break;
            case 11: customCharTable(); break;
            case 12: asciiCharTable(); break;
            case 13: vowelConsonantTable(); break;
            case 14: alternatingCharTable(); break;
            case 15: borderedCharTable(); break;
            case 16:
                printf("\n--- Character Table Info ---\n");
                printf("• Displays alphabetic patterns\n");
                printf("• Various table formations\n");
                printf("• Geometric arrangements\n");
                printf("• Custom character displays\n");
                break;
            case 0: break;
            default: printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Character Table Generator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC TABLES                                           │\n");
    printf("│  [1]  Basic Character Table                             │\n");
    printf("│  [2]  Reverse Character Table                           │\n");
    printf("│  [3]  Number-Character Combo                            │\n");
    printf("│  [4]  Diagonal Character Pattern                        │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED PATTERNS                                      │\n");
    printf("│  [5]  Spiral Character Pattern                          │\n");
    printf("│  [6]  Zigzag Character Table                            │\n");
    printf("│  [7]  Mirror Character Table                            │\n");
    printf("│  [8]  Hollow Character Table                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL PATTERNS                                       │\n");
    printf("│  [9]  Diamond Character Pattern                         │\n");
    printf("│  [10] Pyramid Character Table                           │\n");
    printf("│  [11] Custom Character Table                            │\n");
    printf("│  [12] ASCII Character Table                             │\n");
    printf("│  [13] Vowel-Consonant Table                             │\n");
    printf("│  [14] Alternating Character Table                       │\n");
    printf("│  [15] Bordered Character Table                          │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Character Table Info                              │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void basicCharacterTable() {
    int n;
    printf("\nEnter the number :: ");
    scanf("%d", &n);
    
    printf("\n--- Basic Character Table ---\n\n");
    
    int nst = n;
    int nsp = 1;
    
    for(int s = 1; s <= 2 * n + 1; s++) {
        printf("%c ", s + 64);
    }
    printf("\n");
    
    for(int i = 1; i <= n; i++) {
        int a = 65;
        for(int j = 1; j <= nst; j++) {
            printf("%c ", a);
            a++;
        }
        for(int k = 1; k <= nsp; k++) {
            printf("  ");
            a++;
        }
        for(int j = 1; j <= nst; j++) {
            printf("%c ", a);
            a++;
        }
        nsp = nsp + 2;
        nst--;
        printf("\n");
    }
}

void reverseCharTable() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Reverse Character Table ---\n\n");
    
    for(int i = n; i >= 1; i--) {
        char ch = 'A' + i - 1;
        for(int j = 1; j <= i; j++) {
            printf("%c ", ch);
            ch++;
        }
        printf("\n");
    }
}

void numberCharCombo() {
    int n;
    printf("\nEnter rows: ");
    scanf("%d", &n);
    
    printf("\n--- Number-Character Combination ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(j % 2 == 1)
                printf("%d ", j);
            else
                printf("%c ", 'A' + j - 1);
        }
        printf("\n");
    }
}

void diagonalCharPattern() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Diagonal Character Pattern ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                printf("%c ", 'A' + i);
            else
                printf("  ");
        }
        printf("\n");
    }
}

void spiralCharPattern() {
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
    
    printf("\n--- Spiral Character Pattern ---\n\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void zigzagCharTable() {
    int n;
    printf("\nEnter rows: ");
    scanf("%d", &n);
    
    printf("\n--- Zigzag Character Table ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 1) {
            for(int j = 0; j < i; j++)
                printf("%c ", 'A' + j);
        } else {
            for(int j = i - 1; j >= 0; j--)
                printf("%c ", 'A' + j);
        }
        printf("\n");
    }
}

void mirrorCharTable() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Mirror Character Table ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            printf("%c ", 'A' + j - 1);
        printf("   ");
        for(int j = i; j >= 1; j--)
            printf("%c ", 'A' + j - 1);
        printf("\n");
    }
}

void hollowCharTable() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Hollow Character Table ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n-1 || j == 0 || j == n-1)
                printf("%c ", 'A' + (i + j) % 26);
            else
                printf("  ");
        }
        printf("\n");
    }
}

void diamondCharPattern() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Diamond Character Pattern ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) printf("  ");
        for(int k = 1; k <= i; k++) printf("%c ", 'A' + k - 1);
        printf("\n");
    }
    
    for(int i = n-1; i >= 1; i--) {
        for(int j = 1; j <= n-i; j++) printf("  ");
        for(int k = 1; k <= i; k++) printf("%c ", 'A' + k - 1);
        printf("\n");
    }
}

void pyramidCharTable() {
    int n;
    printf("\nEnter rows: ");
    scanf("%d", &n);
    
    printf("\n--- Pyramid Character Table ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) printf("  ");
        char ch = 'A';
        for(int k = 1; k <= 2*i-1; k++) {
            printf("%c ", ch);
            if(k < i) ch++;
            else ch--;
        }
        printf("\n");
    }
}

void customCharTable() {
    int rows, cols;
    char start;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    printf("Enter starting character: ");
    scanf(" %c", &start);
    
    start = toupper(start);
    
    printf("\n--- Custom Character Table ---\n\n");
    
    char ch = start;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c ", ch);
            ch++;
            if(ch > 'Z') ch = 'A';
        }
        printf("\n");
    }
}

void asciiCharTable() {
    printf("\n--- ASCII Character Table ---\n\n");
    
    for(int i = 65; i <= 90; i++) {
        printf("%c:%d  ", i, i);
        if((i - 64) % 6 == 0) printf("\n");
    }
    printf("\n");
    
    for(int i = 97; i <= 122; i++) {
        printf("%c:%d  ", i, i);
        if((i - 96) % 6 == 0) printf("\n");
    }
    printf("\n");
}

void vowelConsonantTable() {
    printf("\n--- Vowel-Consonant Table ---\n\n");
    
    printf("Vowels: ");
    char vowels[] = "AEIOU";
    for(int i = 0; i < 5; i++)
        printf("%c ", vowels[i]);
    
    printf("\n\nConsonants:\n");
    for(char c = 'A'; c <= 'Z'; c++) {
        if(c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            printf("%c ", c);
        }
    }
    printf("\n");
}

void alternatingCharTable() {
    int n;
    printf("\nEnter rows: ");
    scanf("%d", &n);
    
    printf("\n--- Alternating Character Table ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if((i + j) % 2 == 0)
                printf("%c ", 'A' + j - 1);
            else
                printf("%c ", 'a' + j - 1);
        }
        printf("\n");
    }
}

void borderedCharTable() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Bordered Character Table ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n-1 || j == 0 || j == n-1)
                printf("* ");
            else
                printf("%c ", 'A' + (i + j - 2) % 26);
        }
        printf("\n");
    }
}

/* Version note: updated 2025-11-17 — minor header/metadata bump */