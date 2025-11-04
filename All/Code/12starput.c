/*
 * Advanced Star Pattern Generator v2.0
 * Features: Multiple star patterns, diamonds, pyramids,
 *           custom shapes, and creative ASCII art
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void diamondPattern();
void pyramidPattern();
void invertedPyramid();
void hollowDiamond();
void butterflyPattern();
void hourglassPattern();
void rectanglePattern();
void trianglePattern();
void hollowSquare();
void crossPattern();
void heartPattern();
void arrowPattern();
void zigzagPattern();
void pascalStarTriangle();
void customCharPattern();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║       Advanced Star Pattern Generator v2.0                ║\n");
    printf("║         Comprehensive Pattern Design System                ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                diamondPattern();
                break;
            case 2:
                pyramidPattern();
                break;
            case 3:
                invertedPyramid();
                break;
            case 4:
                hollowDiamond();
                break;
            case 5:
                butterflyPattern();
                break;
            case 6:
                hourglassPattern();
                break;
            case 7:
                rectanglePattern();
                break;
            case 8:
                trianglePattern();
                break;
            case 9:
                hollowSquare();
                break;
            case 10:
                crossPattern();
                break;
            case 11:
                heartPattern();
                break;
            case 12:
                arrowPattern();
                break;
            case 13:
                zigzagPattern();
                break;
            case 14:
                pascalStarTriangle();
                break;
            case 15:
                customCharPattern();
                break;
            case 16:
                printf("\n--- Pattern Types ---\n");
                printf("\n• Diamond: Star diamond shape\n");
                printf("• Pyramid: Centered triangle\n");
                printf("• Butterfly: Symmetric wings\n");
                printf("• Hourglass: Inverse diamonds\n");
                printf("• Heart: Love symbol\n");
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Pattern Generator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  CLASSIC PATTERNS                                       │\n");
    printf("│  [1]  Star Diamond                                      │\n");
    printf("│  [2]  Pyramid Pattern                                   │\n");
    printf("│  [3]  Inverted Pyramid                                  │\n");
    printf("│  [4]  Hollow Diamond                                    │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED PATTERNS                                      │\n");
    printf("│  [5]  Butterfly Pattern                                 │\n");
    printf("│  [6]  Hourglass Pattern                                 │\n");
    printf("│  [7]  Rectangle Pattern                                 │\n");
    printf("│  [8]  Triangle Pattern                                  │\n");
    printf("│  [9]  Hollow Square                                     │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  CREATIVE PATTERNS                                      │\n");
    printf("│  [10] Cross Pattern                                     │\n");
    printf("│  [11] Heart Pattern                                     │\n");
    printf("│  [12] Arrow Pattern                                     │\n");
    printf("│  [13] Zigzag Pattern                                    │\n");
    printf("│  [14] Pascal Star Triangle                              │\n");
    printf("│  [15] Custom Character Pattern                          │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Pattern Reference                                 │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void diamondPattern() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Star Diamond ---\n\n");
    
    int nsp = n / 2;
    int nst = 1;
    int ml = (n / 2) + 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= nsp; j++) {
            printf("  ");
        }
        for(int k = 1; k <= nst; k++) {
            printf("* ");
        }
        if(i < ml) {
            nsp--;
            nst += 2;
        } else {
            nsp++;
            nst -= 2;
        }
        printf("\n");
    }
}

void pyramidPattern() {
    int n;
    printf("\nEnter height: ");
    scanf("%d", &n);
    
    printf("\n--- Pyramid Pattern ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

void invertedPyramid() {
    int n;
    printf("\nEnter height: ");
    scanf("%d", &n);
    
    printf("\n--- Inverted Pyramid ---\n\n");
    
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

void hollowDiamond() {
    int n;
    printf("\nEnter size (odd number): ");
    scanf("%d", &n);
    
    printf("\n--- Hollow Diamond ---\n\n");
    
    int mid = n / 2 + 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i <= mid) {
                if(j == mid - i + 1 || j == mid + i - 1)
                    printf("* ");
                else
                    printf("  ");
            } else {
                if(j == i - mid + 1 || j == n - i + mid)
                    printf("* ");
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
}

void butterflyPattern() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Butterfly Pattern ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        for(int j = 1; j <= 2 * (n - i); j++) {
            printf("  ");
        }
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        for(int j = 1; j <= 2 * (n - i); j++) {
            printf("  ");
        }
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void hourglassPattern() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Hourglass Pattern ---\n\n");
    
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }
    
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

void rectanglePattern() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    
    printf("\n--- Rectangle Pattern ---\n\n");
    
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= cols; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void trianglePattern() {
    int n;
    printf("\nEnter height: ");
    scanf("%d", &n);
    
    printf("\n--- Right Triangle ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void hollowSquare() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Hollow Square ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || i == n || j == 1 || j == n)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void crossPattern() {
    int n;
    printf("\nEnter size (odd number): ");
    scanf("%d", &n);
    
    printf("\n--- Cross Pattern ---\n\n");
    
    int mid = n / 2 + 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == mid || j == mid)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void heartPattern() {
    int n = 6;
    
    printf("\n--- Heart Pattern ---\n\n");
    
    // Upper part
    for(int i = n/2; i <= n; i += 2) {
        for(int j = 1; j < n-i; j += 2) {
            printf("  ");
        }
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        for(int j = 1; j <= n-i; j++) {
            printf("  ");
        }
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    // Lower part
    for(int i = n; i >= 1; i--) {
        for(int j = i; j < n; j++) {
            printf("  ");
        }
        for(int j = 1; j <= (i*2)-1; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void arrowPattern() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    
    printf("\n--- Arrow Pattern ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    for(int i = n-1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void zigzagPattern() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    
    printf("\n--- Zigzag Pattern ---\n\n");
    
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= cols; j++) {
            if((i + j) % 4 == 0 || (i == 2 && j % 4 == 0))
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void pascalStarTriangle() {
    int n;
    printf("\nEnter rows: ");
    scanf("%d", &n);
    
    printf("\n--- Pascal Star Triangle ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            printf("  ");
        }
        
        int val = 1;
        for(int j = 0; j <= i; j++) {
            printf("*   ");
            val = val * (i - j) / (j + 1);
        }
        printf("\n");
    }
}

void customCharPattern() {
    int n;
    char ch;
    
    printf("\nEnter character to use: ");
    scanf(" %c", &ch);
    printf("Enter height: ");
    scanf("%d", &n);
    
    printf("\n--- Custom Character Pyramid ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(int k = 1; k <= 2 * i - 1; k++) {
            printf("%c ", ch);
        }
        printf("\n");
    }
}