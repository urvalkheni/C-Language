/*
 * Advanced Box & Border Pattern Generator v2.1
 * Modified: 2025-11-15
 * Features: Various box patterns, borders, frames,
 *           customizable designs, ASCII art boxes
 */

#include <stdio.h>
#include <stdlib.h>

void normalBox();
void hollowBox();
void doubleBox();
void borderedBox();
void nestedBoxes();
void diamondBox();
void pyramidBox();
void customBox();
void asciiBox();
void numberedBox();
void patternFilledBox();
void crossBox();
void diagonalBox();
void spiralBox();
void fancyBorder();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║   Advanced Box & Border Pattern Generator v2.0            ║\n");
    printf("║        Professional ASCII Art & Pattern System            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: normalBox(); break;
            case 2: hollowBox(); break;
            case 3: doubleBox(); break;
            case 4: borderedBox(); break;
            case 5: nestedBoxes(); break;
            case 6: diamondBox(); break;
            case 7: pyramidBox(); break;
            case 8: customBox(); break;
            case 9: asciiBox(); break;
            case 10: numberedBox(); break;
            case 11: patternFilledBox(); break;
            case 12: crossBox(); break;
            case 13: diagonalBox(); break;
            case 14: spiralBox(); break;
            case 15: fancyBorder(); break;
            case 16:
                printf("\n--- Box Pattern Info ---\n");
                printf("• Creates various box patterns\n");
                printf("• Hollow and filled boxes\n");
                printf("• ASCII art borders\n");
                printf("• Custom designs available\n");
                break;
            case 0: break;
            default: printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Box Pattern Generator!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC BOXES                                            │\n");
    printf("│  [1]  Normal Filled Box                                 │\n");
    printf("│  [2]  Hollow Box                                        │\n");
    printf("│  [3]  Double Border Box                                 │\n");
    printf("│  [4]  Bordered Box (Custom)                             │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED PATTERNS                                      │\n");
    printf("│  [5]  Nested Boxes                                      │\n");
    printf("│  [6]  Diamond Box                                       │\n");
    printf("│  [7]  Pyramid Box                                       │\n");
    printf("│  [8]  Custom Size Box                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SPECIAL DESIGNS                                        │\n");
    printf("│  [9]  ASCII Art Box                                     │\n");
    printf("│  [10] Numbered Box                                      │\n");
    printf("│  [11] Pattern Filled Box                                │\n");
    printf("│  [12] Cross Box                                         │\n");
    printf("│  [13] Diagonal Box                                      │\n");
    printf("│  [14] Spiral Box                                        │\n");
    printf("│  [15] Fancy Border                                      │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Box Pattern Info                                  │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void normalBox() {
    int i, j;
    
    printf("\n--- Normal Filled Box (5x6) ---\n\n");
    
    for(i = 0; i <= 4; i++) {
        for(j = 0; j <= 5; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void hollowBox() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    if(rows < 2 || cols < 2) {
        printf("Rows and columns must be >= 2 for a hollow box.\n");
        return;
    }
    
    printf("\n--- Hollow Box ---\n\n");
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i == 0 || i == rows-1 || j == 0 || j == cols-1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void doubleBox() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    if(n < 3) {
        printf("Size must be >= 3 for double border.\n");
        return;
    }
    
    printf("\n--- Double Border Box ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n-1 || j == 0 || j == n-1)
                printf("# ");
            else if(i == 1 || i == n-2 || j == 1 || j == n-2)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void borderedBox() {
    int rows, cols;
    char border;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    printf("Enter border character: ");
    scanf(" %c", &border);
    if(rows < 1 || cols < 1) {
        printf("Rows and columns must be positive.\n");
        return;
    }
    
    printf("\n--- Bordered Box ---\n\n");
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i == 0 || i == rows-1 || j == 0 || j == cols-1)
                printf("%c ", border);
            else
                printf("  ");
        }
        printf("\n");
    }
}

void nestedBoxes() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    if(n <= 0 || n > 50) {
        printf("Size must be in range 1..50.\n");
        return;
    }
    
    printf("\n--- Nested Boxes ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int min = i < j ? i : j;
            min = min < n-1-i ? min : n-1-i;
            min = min < n-1-j ? min : n-1-j;
            printf("%d ", min + 1);
        }
        printf("\n");
    }
}

void diamondBox() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    if(n <= 0 || n > 40) {
        printf("Size must be in range 1..40.\n");
        return;
    }
    
    printf("\n--- Diamond Box ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) printf("  ");
        for(int k = 1; k <= 2*i-1; k++) printf("* ");
        printf("\n");
    }
    
    for(int i = n-1; i >= 1; i--) {
        for(int j = 1; j <= n-i; j++) printf("  ");
        for(int k = 1; k <= 2*i-1; k++) printf("* ");
        printf("\n");
    }
}

void pyramidBox() {
    int n;
    printf("\nEnter rows: ");
    scanf("%d", &n);
    if(n <= 0 || n > 50) {
        printf("Rows must be in range 1..50.\n");
        return;
    }
    
    printf("\n--- Pyramid Box ---\n\n");
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) printf("  ");
        for(int k = 1; k <= 2*i-1; k++) printf("* ");
        printf("\n");
    }
}

void customBox() {
    int rows, cols;
    char fill, border;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    printf("Enter border character: ");
    scanf(" %c", &border);
    printf("Enter fill character: ");
    scanf(" %c", &fill);
    if(rows <= 0 || cols <= 0) {
        printf("Rows and columns must be positive.\n");
        return;
    }
    
    printf("\n--- Custom Box ---\n\n");
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i == 0 || i == rows-1 || j == 0 || j == cols-1)
                printf("%c ", border);
            else
                printf("%c ", fill);
        }
        printf("\n");
    }
}

void asciiBox() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    if(rows < 2 || cols < 2) {
        printf("Rows and columns must be >= 2 for framed box.\n");
        return;
    }
    
    printf("\n--- ASCII Art Box ---\n\n");
    
    printf("╔");
    for(int i = 0; i < cols-2; i++) printf("═");
    printf("╗\n");
    
    for(int i = 0; i < rows-2; i++) {
        printf("║");
        for(int j = 0; j < cols-2; j++) printf(" ");
        printf("║\n");
    }
    
    printf("╚");
    for(int i = 0; i < cols-2; i++) printf("═");
    printf("╝\n");
}

void numberedBox() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    if(n <= 0 || n > 50) {
        printf("Size must be in range 1..50.\n");
        return;
    }
    
    printf("\n--- Numbered Box ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", (i + j) % 10);
        }
        printf("\n");
    }
}

void patternFilledBox() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    if(n <= 0 || n > 50) {
        printf("Size must be in range 1..50.\n");
        return;
    }
    
    printf("\n--- Pattern Filled Box ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i + j) % 2 == 0)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void crossBox() {
    int n;
    printf("\nEnter size (odd): ");
    scanf("%d", &n);
    if(n <= 0 || n % 2 == 0) {
        printf("Size must be a positive odd number.\n");
        return;
    }
    
    printf("\n--- Cross Box ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j || i + j == n - 1 || i == n/2 || j == n/2)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void diagonalBox() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    if(n <= 0 || n > 60) {
        printf("Size must be in range 1..60.\n");
        return;
    }
    
    printf("\n--- Diagonal Box ---\n\n");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n-1 || j == 0 || j == n-1 || i == j || i + j == n - 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void spiralBox() {
    int n;
    printf("\nEnter size: ");
    scanf("%d", &n);
    if(n <= 0 || n > 20) {
        printf("Size must be in range 1..20.\n");
        return;
    }
    
    int matrix[20][20] = {0};
    int top = 0, bottom = n-1, left = 0, right = n-1;
    int num = 1;
    
    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++)
            matrix[top][i] = num++;
        top++;
        
        for(int i = top; i <= bottom; i++)
            matrix[i][right] = num++;
        right--;
        
        if(top <= bottom) {
            for(int i = right; i >= left; i--)
                matrix[bottom][i] = num++;
            bottom--;
        }
        
        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                matrix[i][left] = num++;
            left++;
        }
    }
    
    printf("\n--- Spiral Box ---\n\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fancyBorder() {
    int rows, cols;
    printf("\nEnter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);
    if(rows < 2 || cols < 2) {
        printf("Rows and columns must be >= 2 for framed border.\n");
        return;
    }
    
    printf("\n--- Fancy Border ---\n\n");
    
    printf("┌");
    for(int i = 0; i < cols-2; i++) printf("─");
    printf("┐\n");
    
    for(int i = 0; i < rows-2; i++) {
        printf("│");
        for(int j = 0; j < cols-2; j++) {
            if(i % 2 == j % 2)
                printf("░");
            else
                printf("▒");
        }
        printf("│\n");
    }
    
    printf("└");
    for(int i = 0; i < cols-2; i++) printf("─");
    printf("┘\n");
}
