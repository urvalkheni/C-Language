// Enhanced Multiplication Table Generator with Advanced Features and Visualizations
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>

#define MAX_RANGE 100
#define MAX_TABLES 20

// Function prototypes
void displayMainMenu();
void basicTable();
void customRangeTable();
void multipleTablesGrid();
void reverseTable();
void tablePatterns();
void visualTable();
void tableQuiz();
void divisibilityTable();
void primeTable();
void fibonacciTable();
void powerTable();
void factorialTable();
void pascalTriangle();
void multiplicationChart();
void tableAnalysis();
void exportTableToFile();
bool isPrime(int n);
long long factorial(int n);
long long fibonacci(int n);
void drawBox(const char* title);
void clearInputBuffer();

int main() {
    int choice;
    
    printf("===================================================\n");
    printf("   ENHANCED MULTIPLICATION TABLE GENERATOR v2.0\n");
    printf("===================================================\n");
    printf("Advanced Tables, Patterns, Visualizations & More\n");
    printf("===================================================\n\n");

    while(1) {
        displayMainMenu();
        printf("Enter your choice (1-16, 0 to exit): ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice) {
            case 0:
                printf("\nThank you for using Enhanced Table Generator!\n");
                exit(0);
            case 1:
                basicTable();
                break;
            case 2:
                customRangeTable();
                break;
            case 3:
                multipleTablesGrid();
                break;
            case 4:
                reverseTable();
                break;
            case 5:
                tablePatterns();
                break;
            case 6:
                visualTable();
                break;
            case 7:
                tableQuiz();
                break;
            case 8:
                divisibilityTable();
                break;
            case 9:
                primeTable();
                break;
            case 10:
                fibonacciTable();
                break;
            case 11:
                powerTable();
                break;
            case 12:
                factorialTable();
                break;
            case 13:
                pascalTriangle();
                break;
            case 14:
                multiplicationChart();
                break;
            case 15:
                tableAnalysis();
                break;
            case 16:
                exportTableToFile();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\nPress Enter to continue...");
        getchar();
    }

    return 0;
}

void displayMainMenu() {
    printf("\n============ TABLE GENERATOR MENU ============\n");
    printf("1.  Basic Multiplication Table\n");
    printf("2.  Custom Range Table\n");
    printf("3.  Multiple Tables Grid View\n");
    printf("4.  Reverse Table (Division)\n");
    printf("5.  Table Patterns & Sequences\n");
    printf("6.  Visual ASCII Table\n");
    printf("7.  Table Quiz Game\n");
    printf("8.  Divisibility Table\n");
    printf("9.  Prime Number Table\n");
    printf("10. Fibonacci Sequence Table\n");
    printf("11. Power Table (n^x)\n");
    printf("12. Factorial Table\n");
    printf("13. Pascal's Triangle\n");
    printf("14. Multiplication Chart (Grid)\n");
    printf("15. Table Analysis & Properties\n");
    printf("16. Export Table to File\n");
    printf("0.  Exit\n");
    printf("=============================================\n");
}

void basicTable() {
    int n, range;
    
    printf("\n=== BASIC MULTIPLICATION TABLE ===\n");
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Enter range (default 10): ");
    scanf("%d", &range);
    
    if(range <= 0) range = 10;
    if(range > 100) range = 100;
    
    drawBox("MULTIPLICATION TABLE");
    printf("\n");
    
    printf("Table of %d (up to %d):\n", n, range);
    printf("─────────────────────────────\n");
    
    for(int i = 1; i <= range; i++) {
        printf("  %3d × %-3d = %6d", n, i, n * i);
        
        // Add visual bars for small numbers
        if(n * i <= 50) {
            printf("  │");
            for(int j = 0; j < n * i / 2; j++) {
                printf("█");
            }
        }
        printf("\n");
    }
    
    // Summary statistics
    printf("\n─────────────────────────────\n");
    printf("Sum of products: %d\n", n * range * (range + 1) / 2);
    printf("Average: %.2f\n", (double)(n * range * (range + 1) / 2) / range);
}

void customRangeTable() {
    int n, start, end;
    
    printf("\n=== CUSTOM RANGE TABLE ===\n");
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Enter start range: ");
    scanf("%d", &start);
    printf("Enter end range: ");
    scanf("%d", &end);
    
    if(start > end) {
        int temp = start;
        start = end;
        end = temp;
    }
    
    printf("\nTable of %d from %d to %d:\n", n, start, end);
    printf("═══════════════════════════════\n");
    
    for(int i = start; i <= end; i++) {
        printf("%3d × %-3d = %7d", n, i, n * i);
        
        // Show if result is perfect square
        int result = n * i;
        int sqrtResult = (int)sqrt(result);
        if(sqrtResult * sqrtResult == result) {
            printf("  ✓ Perfect Square");
        }
        
        // Show if result is palindrome
        int temp = result, rev = 0;
        while(temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        if(rev == result) {
            printf("  ✓ Palindrome");
        }
        
        printf("\n");
    }
}

void multipleTablesGrid() {
    int count;
    int numbers[MAX_TABLES];
    
    printf("\n=== MULTIPLE TABLES GRID VIEW ===\n");
    printf("How many tables? (1-%d): ", MAX_TABLES);
    scanf("%d", &count);
    
    if(count < 1 || count > MAX_TABLES) {
        printf("Invalid count!\n");
        return;
    }
    
    printf("Enter %d numbers:\n", count);
    for(int i = 0; i < count; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    
    int range;
    printf("Enter range (1-20): ");
    scanf("%d", &range);
    if(range > 20) range = 20;
    
    printf("\n");
    drawBox("MULTIPLE TABLES GRID");
    printf("\n");
    
    // Header
    printf("  × │");
    for(int i = 0; i < count; i++) {
        printf(" %5d", numbers[i]);
    }
    printf("\n");
    
    printf("────┼");
    for(int i = 0; i < count; i++) {
        printf("──────");
    }
    printf("\n");
    
    // Table rows
    for(int i = 1; i <= range; i++) {
        printf("%3d │", i);
        for(int j = 0; j < count; j++) {
            printf(" %5d", numbers[j] * i);
        }
        printf("\n");
    }
}

void reverseTable() {
    int n, range;
    
    printf("\n=== REVERSE TABLE (DIVISION) ===\n");
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Enter range: ");
    scanf("%d", &range);
    
    if(n == 0) {
        printf("Cannot divide by zero!\n");
        return;
    }
    
    printf("\nDivision table (reverse of multiplication):\n");
    printf("═════════════════════════════════════\n");
    
    for(int i = 1; i <= range; i++) {
        int product = n * i;
        printf("%5d ÷ %-3d = %4d", product, n, i);
        
        if(product % n == 0) {
            printf("  ✓ Exact division");
        }
        printf("\n");
    }
}

void tablePatterns() {
    int n;
    
    printf("\n=== TABLE PATTERNS & SEQUENCES ===\n");
    printf("Enter number: ");
    scanf("%d", &n);
    
    printf("\n--- Pattern Analysis for %d ---\n", n);
    
    // Even/Odd pattern
    printf("\n1. Even/Odd Pattern:\n   ");
    for(int i = 1; i <= 10; i++) {
        printf("%d:%s ", i, (n * i) % 2 == 0 ? "E" : "O");
    }
    
    // Last digit pattern
    printf("\n\n2. Last Digit Pattern:\n   ");
    for(int i = 1; i <= 10; i++) {
        printf("%d ", (n * i) % 10);
    }
    
    // Digit sum pattern
    printf("\n\n3. Digit Sum Pattern:\n   ");
    for(int i = 1; i <= 10; i++) {
        int product = n * i;
        int sum = 0;
        while(product > 0) {
            sum += product % 10;
            product /= 10;
        }
        printf("%2d ", sum);
    }
    
    // Modulo patterns
    printf("\n\n4. Modulo 9 Pattern:\n   ");
    for(int i = 1; i <= 10; i++) {
        printf("%d ", (n * i) % 9);
    }
    
    // Perfect squares in table
    printf("\n\n5. Perfect Squares:\n   ");
    bool found = false;
    for(int i = 1; i <= 20; i++) {
        int product = n * i;
        int sqrtP = (int)sqrt(product);
        if(sqrtP * sqrtP == product) {
            printf("%d×%d=%d ", n, i, product);
            found = true;
        }
    }
    if(!found) printf("None in first 20 multiples");
    
    printf("\n");
}

void visualTable() {
    int n, range;
    
    printf("\n=== VISUAL ASCII TABLE ===\n");
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Enter range (1-10): ");
    scanf("%d", &range);
    
    if(range > 10) range = 10;
    
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║    VISUAL MULTIPLICATION TABLE         ║\n");
    printf("║         Table of %-3d                   ║\n", n);
    printf("╚════════════════════════════════════════╝\n\n");
    
    for(int i = 1; i <= range; i++) {
        int product = n * i;
        printf("║ %2d × %-2d = %-5d │ ", n, i, product);
        
        // Visual bar
        int bars = product / 5;
        if(bars > 30) bars = 30;
        for(int j = 0; j < bars; j++) {
            printf("▓");
        }
        printf("\n");
    }
    
    printf("╚═══════════════════════════════════════════╝\n");
}

void tableQuiz() {
    int n, questions, correct = 0;
    
    printf("\n=== MULTIPLICATION TABLE QUIZ ===\n");
    printf("Enter table number to practice: ");
    scanf("%d", &n);
    printf("How many questions? (1-20): ");
    scanf("%d", &questions);
    
    if(questions > 20) questions = 20;
    
    srand(time(NULL));
    
    printf("\nStarting quiz for table of %d...\n", n);
    printf("═══════════════════════════════════\n\n");
    
    for(int i = 1; i <= questions; i++) {
        int multiplier = (rand() % 12) + 1;
        int correctAnswer = n * multiplier;
        int userAnswer;
        
        printf("Question %d: %d × %d = ? ", i, n, multiplier);
        scanf("%d", &userAnswer);
        
        if(userAnswer == correctAnswer) {
            printf("✓ Correct!\n\n");
            correct++;
        } else {
            printf("✗ Wrong! The correct answer is %d\n\n", correctAnswer);
        }
    }
    
    printf("═══════════════════════════════════\n");
    printf("Quiz Results:\n");
    printf("Correct: %d/%d\n", correct, questions);
    printf("Score: %.1f%%\n", (double)correct / questions * 100);
    
    if(correct == questions) {
        printf("🌟 Perfect score! Excellent!\n");
    } else if(correct >= questions * 0.8) {
        printf("👍 Great job!\n");
    } else if(correct >= questions * 0.6) {
        printf("👌 Good effort!\n");
    } else {
        printf("📚 Keep practicing!\n");
    }
}

void divisibilityTable() {
    int n;
    
    printf("\n=== DIVISIBILITY TABLE ===\n");
    printf("Enter number: ");
    scanf("%d", &n);
    
    printf("\nDivisibility analysis for table of %d:\n", n);
    printf("═════════════════════════════════════════\n");
    printf("Product │ Divisible by\n");
    printf("────────┼─────────────────────────────\n");
    
    for(int i = 1; i <= 10; i++) {
        int product = n * i;
        printf("%-7d │ ", product);
        
        // Check divisibility by 2-10
        for(int div = 2; div <= 10; div++) {
            if(product % div == 0) {
                printf("%d ", div);
            }
        }
        printf("\n");
    }
}

void primeTable() {
    printf("\n=== PRIME NUMBER TABLE ===\n");
    printf("First 50 prime numbers:\n");
    printf("═══════════════════════════════════════\n");
    
    int count = 0;
    int num = 2;
    
    while(count < 50) {
        if(isPrime(num)) {
            printf("%4d", num);
            count++;
            if(count % 10 == 0) printf("\n");
        }
        num++;
    }
    
    printf("\n\nPrime gaps (difference between consecutive primes):\n");
    int lastPrime = 2;
    count = 0;
    num = 3;
    
    printf("Gap: ");
    while(count < 20) {
        if(isPrime(num)) {
            printf("%d ", num - lastPrime);
            lastPrime = num;
            count++;
        }
        num++;
    }
    printf("\n");
}

void fibonacciTable() {
    int range;
    
    printf("\n=== FIBONACCI SEQUENCE TABLE ===\n");
    printf("How many terms? (1-30): ");
    scanf("%d", &range);
    
    if(range > 30) range = 30;
    
    printf("\nFibonacci sequence:\n");
    printf("═══════════════════════════════════════\n");
    printf("n  │ F(n)      │ Ratio to previous\n");
    printf("───┼───────────┼──────────────────\n");
    
    long long prev = 0;
    for(int i = 0; i < range; i++) {
        long long fib = fibonacci(i);
        printf("%-2d │ %-9lld │ ", i, fib);
        
        if(prev > 0) {
            printf("%.6f", (double)fib / prev);
        } else {
            printf("─");
        }
        printf("\n");
        prev = fib;
    }
    
    printf("\nNote: Ratio converges to golden ratio φ ≈ 1.618034\n");
}

void powerTable() {
    int base, maxPower;
    
    printf("\n=== POWER TABLE ===\n");
    printf("Enter base number: ");
    scanf("%d", &base);
    printf("Enter maximum power (1-20): ");
    scanf("%d", &maxPower);
    
    if(maxPower > 20) maxPower = 20;
    
    printf("\nPowers of %d:\n", base);
    printf("═══════════════════════════════════════\n");
    printf("Power │ Result        │ Digits\n");
    printf("──────┼───────────────┼────────\n");
    
    for(int i = 0; i <= maxPower; i++) {
        long long result = (long long)pow(base, i);
        int digits = 0;
        long long temp = result;
        
        if(result == 0) digits = 1;
        else {
            while(temp > 0) {
                digits++;
                temp /= 10;
            }
        }
        
        printf("%-5d │ %-13lld │ %d\n", i, result, digits);
    }
}

void factorialTable() {
    int range;
    
    printf("\n=== FACTORIAL TABLE ===\n");
    printf("How many terms? (1-20): ");
    scanf("%d", &range);
    
    if(range > 20) range = 20;
    
    printf("\nFactorial sequence:\n");
    printf("═══════════════════════════════════════\n");
    printf("n  │ n!                  │ Digits\n");
    printf("───┼─────────────────────┼────────\n");
    
    for(int i = 0; i <= range; i++) {
        long long fact = factorial(i);
        int digits = 0;
        long long temp = fact;
        
        if(fact == 0) digits = 1;
        else {
            while(temp > 0) {
                digits++;
                temp /= 10;
            }
        }
        
        printf("%-2d │ %-19lld │ %d\n", i, fact, digits);
    }
}

void pascalTriangle() {
    int rows;
    
    printf("\n=== PASCAL'S TRIANGLE ===\n");
    printf("How many rows? (1-15): ");
    scanf("%d", &rows);
    
    if(rows > 15) rows = 15;
    
    printf("\n");
    
    for(int i = 0; i < rows; i++) {
        // Print leading spaces
        for(int j = 0; j < rows - i - 1; j++) {
            printf("   ");
        }
        
        // Calculate and print values
        long long value = 1;
        for(int j = 0; j <= i; j++) {
            printf("%5lld ", value);
            value = value * (i - j) / (j + 1);
        }
        printf("\n");
    }
    
    printf("\nProperties:\n");
    printf("- Sum of row n = 2^n\n");
    printf("- Each number is sum of two numbers above it\n");
    printf("- Contains binomial coefficients\n");
}

void multiplicationChart() {
    int size;
    
    printf("\n=== MULTIPLICATION CHART ===\n");
    printf("Enter chart size (1-20): ");
    scanf("%d", &size);
    
    if(size > 20) size = 20;
    
    printf("\n");
    
    // Header row
    printf("    │");
    for(int i = 1; i <= size; i++) {
        printf("%4d", i);
    }
    printf("\n");
    
    // Separator
    printf("────┼");
    for(int i = 1; i <= size; i++) {
        printf("────");
    }
    printf("\n");
    
    // Table rows
    for(int i = 1; i <= size; i++) {
        printf("%3d │", i);
        for(int j = 1; j <= size; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
}

void tableAnalysis() {
    int n;
    
    printf("\n=== TABLE ANALYSIS & PROPERTIES ===\n");
    printf("Enter number: ");
    scanf("%d", &n);
    
    printf("\nAnalysis for table of %d:\n", n);
    printf("═════════════════════════════════════════\n");
    
    // Basic properties
    printf("\n1. Basic Properties:\n");
    printf("   - Number: %d\n", n);
    printf("   - Even/Odd: %s\n", n % 2 == 0 ? "Even" : "Odd");
    printf("   - Prime: %s\n", isPrime(n) ? "Yes" : "No");
    
    // Perfect square check
    int sqrtN = (int)sqrt(n);
    if(sqrtN * sqrtN == n) {
        printf("   - Perfect Square: Yes (√%d = %d)\n", n, sqrtN);
    } else {
        printf("   - Perfect Square: No\n");
    }
    
    // Table statistics
    printf("\n2. Table Statistics (1-10):\n");
    int sum = 0;
    int evenCount = 0, oddCount = 0;
    
    for(int i = 1; i <= 10; i++) {
        int product = n * i;
        sum += product;
        if(product % 2 == 0) evenCount++;
        else oddCount++;
    }
    
    printf("   - Sum of products: %d\n", sum);
    printf("   - Average: %.2f\n", sum / 10.0);
    printf("   - Even results: %d\n", evenCount);
    printf("   - Odd results: %d\n", oddCount);
    
    // Patterns
    printf("\n3. Special Patterns:\n");
    printf("   - Every product divisible by: %d\n", n);
    if(n % 2 == 0) printf("   - All products are even\n");
    if(n % 5 == 0) printf("   - All products end in 0 or 5\n");
    
    // Digital root
    int digitalRoot = n;
    while(digitalRoot >= 10) {
        int temp = digitalRoot;
        digitalRoot = 0;
        while(temp > 0) {
            digitalRoot += temp % 10;
            temp /= 10;
        }
    }
    printf("   - Digital root: %d\n", digitalRoot);
}

void exportTableToFile() {
    int n, range;
    char filename[100];
    
    printf("\n=== EXPORT TABLE TO FILE ===\n");
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Enter range: ");
    scanf("%d", &range);
    printf("Enter filename (without extension): ");
    scanf("%s", filename);
    
    strcat(filename, ".txt");
    
    FILE *file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error creating file!\n");
        return;
    }
    
    fprintf(file, "MULTIPLICATION TABLE OF %d\n", n);
    fprintf(file, "===============================\n\n");
    
    for(int i = 1; i <= range; i++) {
        fprintf(file, "%3d × %-3d = %6d\n", n, i, n * i);
    }
    
    fprintf(file, "\n===============================\n");
    fprintf(file, "Sum: %d\n", n * range * (range + 1) / 2);
    
    fclose(file);
    
    printf("✓ Table exported successfully to %s\n", filename);
}

// Helper functions
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

long long factorial(int n) {
    if(n <= 1) return 1;
    long long result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long fibonacci(int n) {
    if(n <= 1) return n;
    long long a = 0, b = 1, c;
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void drawBox(const char* title) {
    int len = strlen(title);
    printf("╔");
    for(int i = 0; i < len + 4; i++) printf("═");
    printf("╗\n");
    printf("║  %s  ║\n", title);
    printf("╚");
    for(int i = 0; i < len + 4; i++) printf("═");
    printf("╝");
}

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}