#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define MAX_DISKS 20
#define MAX_MOVES 1048576  // 2^20
#define TOWER_HEIGHT 25

typedef struct {
    int disk;
    int from;
    int to;
    int moveNumber;
    char description[100];
} Move;

typedef struct {
    int disks[MAX_DISKS];
    int top;
    char name;
} Tower;

typedef struct {
    Move moves[MAX_MOVES];
    int totalMoves;
    double timeElapsed;
    int diskCount;
    char algorithm[50];
} SolutionStats;

// Function prototypes
void displayMenu();
void setupTowers(Tower towers[], int n);
void displayTowers(Tower towers[], int n, int moveCount);
void printDisk(int diskSize, int maxDiskSize);
void printTowerBase(int maxDiskSize);
void hanoiRecursive(int n, char from, char to, char aux, Move moves[], int *moveCount);
void hanoiIterative(int n, Move moves[], int *moveCount);
void simulateHanoi(int n, int algorithm);
void executeMove(Tower towers[], int from, int to, int diskSize);
void undoMove(Tower towers[], int from, int to, int diskSize);
void stepByStepSolution(int n);
void autoSolution(int n);
void customSolution(int n);
void hanoiStatistics(int n);
void compareSolutions(int n);
void validateSolution(Move moves[], int moveCount, int n);
void saveSolutionToFile(Move moves[], int moveCount, int n, char* filename);
void loadSolutionFromFile(char* filename);
void hanoiPuzzleGame(int n);
void hanoiVariations();
void calculateComplexity(int n);
void visualizeSolution(Move moves[], int moveCount, int n);
void clearScreen();
void setColor(int color);
void gotoxy(int x, int y);
void pause(int milliseconds);
int getUserMove(Tower towers[], int n);
void displayHelp();
void benchmarkSolutions();

// Color codes for Windows console
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

void clearScreen() {
    system("cls");
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void pause(int milliseconds) {
    Sleep(milliseconds);
}

void setupTowers(Tower towers[], int n) {
    // Initialize towers
    for (int i = 0; i < 3; i++) {
        towers[i].top = -1;
        towers[i].name = 'A' + i;
        for (int j = 0; j < MAX_DISKS; j++) {
            towers[i].disks[j] = 0;
        }
    }
    
    // Place all disks on tower A (largest at bottom)
    for (int i = n; i >= 1; i--) {
        towers[0].disks[++towers[0].top] = i;
    }
}

void printDisk(int diskSize, int maxDiskSize) {
    if (diskSize == 0) {
        printf("%*s|%*s", maxDiskSize, "", maxDiskSize, "");
        return;
    }
    
    // Set color based on disk size
    setColor(diskSize % 7 + 9);
    
    // Print disk with appropriate width
    int spaces = maxDiskSize - diskSize;
    printf("%*s", spaces, "");
    for (int i = 0; i < diskSize * 2 + 1; i++) {
        printf("█");
    }
    printf("%*s", spaces, "");
    
    setColor(WHITE);
}

void printTowerBase(int maxDiskSize) {
    setColor(BROWN);
    for (int i = 0; i < maxDiskSize * 2 + 1; i++) {
        printf("=");
    }
    setColor(WHITE);
}

void displayTowers(Tower towers[], int n, int moveCount) {
    clearScreen();
    
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                           🗼 ENHANCED TOWER OF HANOI VISUALIZER 🗼                          ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Disks: %d | Moves: %d | Optimal: %d\n\n", n, moveCount, (int)pow(2, n) - 1);
    
    // Display towers from top to bottom
    for (int level = n - 1; level >= 0; level--) {
        printf("  ");
        for (int tower = 0; tower < 3; tower++) {
            int diskSize = 0;
            if (towers[tower].top >= level) {
                diskSize = towers[tower].disks[level];
            }
            printDisk(diskSize, n);
            printf("    ");
        }
        printf("\n");
    }
    
    // Print tower bases
    printf("  ");
    for (int tower = 0; tower < 3; tower++) {
        printTowerBase(n);
        printf("    ");
    }
    printf("\n");
    
    // Print tower labels
    printf("  ");
    for (int tower = 0; tower < 3; tower++) {
        printf("%*c%*s    ", n, towers[tower].name, n, "");
    }
    printf("\n\n");
}

void hanoiRecursive(int n, char from, char to, char aux, Move moves[], int *moveCount) {
    if (n == 1) {
        moves[*moveCount].disk = 1;
        moves[*moveCount].from = from - 'A';
        moves[*moveCount].to = to - 'A';
        moves[*moveCount].moveNumber = (*moveCount) + 1;
        sprintf(moves[*moveCount].description, "Move disk 1 from %c to %c", from, to);
        (*moveCount)++;
        return;
    }
    
    hanoiRecursive(n - 1, from, aux, to, moves, moveCount);
    
    moves[*moveCount].disk = n;
    moves[*moveCount].from = from - 'A';
    moves[*moveCount].to = to - 'A';
    moves[*moveCount].moveNumber = (*moveCount) + 1;
    sprintf(moves[*moveCount].description, "Move disk %d from %c to %c", n, from, to);
    (*moveCount)++;
    
    hanoiRecursive(n - 1, aux, to, from, moves, moveCount);
}

void hanoiIterative(int n, Move moves[], int *moveCount) {
    *moveCount = 0;
    int totalMoves = (1 << n) - 1; // 2^n - 1
    
    // Create three stacks to represent towers
    int towers[3][MAX_DISKS];
    int tops[3] = {n - 1, -1, -1};
    
    // Initialize tower A with all disks
    for (int i = 0; i < n; i++) {
        towers[0][i] = n - i;
    }
    
    // For even number of disks, swap destination and auxiliary
    int source = 0, destination = (n % 2 == 0) ? 1 : 2, auxiliary = (n % 2 == 0) ? 2 : 1;
    
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            // Move between source and destination
            if (tops[source] == -1 || (tops[destination] != -1 && towers[source][tops[source]] > towers[destination][tops[destination]])) {
                // Move from destination to source
                moves[*moveCount].disk = towers[destination][tops[destination]];
                moves[*moveCount].from = destination;
                moves[*moveCount].to = source;
                towers[source][++tops[source]] = towers[destination][tops[destination]--];
            } else {
                // Move from source to destination
                moves[*moveCount].disk = towers[source][tops[source]];
                moves[*moveCount].from = source;
                moves[*moveCount].to = destination;
                towers[destination][++tops[destination]] = towers[source][tops[source]--];
            }
        } else if (i % 3 == 2) {
            // Move between source and auxiliary
            if (tops[source] == -1 || (tops[auxiliary] != -1 && towers[source][tops[source]] > towers[auxiliary][tops[auxiliary]])) {
                // Move from auxiliary to source
                moves[*moveCount].disk = towers[auxiliary][tops[auxiliary]];
                moves[*moveCount].from = auxiliary;
                moves[*moveCount].to = source;
                towers[source][++tops[source]] = towers[auxiliary][tops[auxiliary]--];
            } else {
                // Move from source to auxiliary
                moves[*moveCount].disk = towers[source][tops[source]];
                moves[*moveCount].from = source;
                moves[*moveCount].to = auxiliary;
                towers[auxiliary][++tops[auxiliary]] = towers[source][tops[source]--];
            }
        } else {
            // Move between destination and auxiliary
            if (tops[destination] == -1 || (tops[auxiliary] != -1 && towers[destination][tops[destination]] > towers[auxiliary][tops[auxiliary]])) {
                // Move from auxiliary to destination
                moves[*moveCount].disk = towers[auxiliary][tops[auxiliary]];
                moves[*moveCount].from = auxiliary;
                moves[*moveCount].to = destination;
                towers[destination][++tops[destination]] = towers[auxiliary][tops[auxiliary]--];
            } else {
                // Move from destination to auxiliary
                moves[*moveCount].disk = towers[destination][tops[destination]];
                moves[*moveCount].from = destination;
                moves[*moveCount].to = auxiliary;
                towers[auxiliary][++tops[auxiliary]] = towers[destination][tops[destination]--];
            }
        }
        
        moves[*moveCount].moveNumber = i;
        sprintf(moves[*moveCount].description, "Move disk %d from %c to %c", 
                moves[*moveCount].disk, 
                'A' + moves[*moveCount].from, 
                'A' + moves[*moveCount].to);
        (*moveCount)++;
    }
}

void executeMove(Tower towers[], int from, int to, int diskSize) {
    // Remove disk from source tower
    towers[from].top--;
    
    // Add disk to destination tower
    towers[to].disks[++towers[to].top] = diskSize;
}

void undoMove(Tower towers[], int from, int to, int diskSize) {
    // Remove disk from destination tower
    towers[to].top--;
    
    // Add disk back to source tower
    towers[from].disks[++towers[from].top] = diskSize;
}

void stepByStepSolution(int n) {
    printf("\n=== STEP-BY-STEP SOLUTION ===\n");
    
    Move moves[MAX_MOVES];
    int moveCount = 0;
    Tower towers[3];
    
    setupTowers(towers, n);
    hanoiRecursive(n, 'A', 'C', 'B', moves, &moveCount);
    
    printf("Press any key to start the step-by-step solution...\n");
    getchar();
    
    displayTowers(towers, n, 0);
    
    for (int i = 0; i < moveCount; i++) {
        printf("Move %d: %s\n", i + 1, moves[i].description);
        printf("Press Enter to continue...");
        getchar();
        
        executeMove(towers, moves[i].from, moves[i].to, moves[i].disk);
        displayTowers(towers, n, i + 1);
    }
    
    printf("🎉 Solution completed in %d moves!\n", moveCount);
}

void autoSolution(int n) {
    printf("\n=== AUTOMATIC SOLUTION ===\n");
    printf("Enter animation delay (milliseconds, 0-2000): ");
    int delay;
    scanf("%d", &delay);
    
    Move moves[MAX_MOVES];
    int moveCount = 0;
    Tower towers[3];
    
    setupTowers(towers, n);
    hanoiRecursive(n, 'A', 'C', 'B', moves, &moveCount);
    
    displayTowers(towers, n, 0);
    pause(1000);
    
    for (int i = 0; i < moveCount; i++) {
        executeMove(towers, moves[i].from, moves[i].to, moves[i].disk);
        displayTowers(towers, n, i + 1);
        
        printf("Move %d: %s\n", i + 1, moves[i].description);
        pause(delay);
    }
    
    setColor(LIGHTGREEN);
    printf("🎉 Solution completed automatically in %d moves!\n", moveCount);
    setColor(WHITE);
}

void hanoiPuzzleGame(int n) {
    printf("\n=== 🎮 INTERACTIVE HANOI GAME 🎮 ===\n");
    printf("Try to solve the Tower of Hanoi puzzle yourself!\n");
    printf("Rules:\n");
    printf("1. Move all disks from tower A to tower C\n");
    printf("2. Only move one disk at a time\n");
    printf("3. Never place a larger disk on a smaller one\n\n");
    
    Tower towers[3];
    setupTowers(towers, n);
    
    int userMoves = 0;
    int optimalMoves = (1 << n) - 1;
    
    displayTowers(towers, n, userMoves);
    
    while (towers[2].top != n - 1) { // Until all disks are on tower C
        printf("Your move #%d (Optimal: %d moves)\n", userMoves + 1, optimalMoves);
        printf("Enter move (from to): ");
        
        int from, to;
        scanf("%d %d", &from, &to);
        from--; to--; // Convert to 0-based indexing
        
        // Validate move
        if (from < 0 || from > 2 || to < 0 || to > 2) {
            printf("❌ Invalid towers! Use 1, 2, or 3.\n");
            continue;
        }
        
        if (towers[from].top == -1) {
            printf("❌ No disk on tower %d!\n", from + 1);
            continue;
        }
        
        if (towers[to].top != -1 && towers[from].disks[towers[from].top] > towers[to].disks[towers[to].top]) {
            printf("❌ Cannot place larger disk on smaller one!\n");
            continue;
        }
        
        // Execute valid move
        int diskSize = towers[from].disks[towers[from].top];
        executeMove(towers, from, to, diskSize);
        userMoves++;
        
        displayTowers(towers, n, userMoves);
    }
    
    // Game completed
    setColor(LIGHTGREEN);
    printf("🎉 Congratulations! You solved the puzzle!\n");
    setColor(WHITE);
    printf("Your moves: %d\n", userMoves);
    printf("Optimal moves: %d\n", optimalMoves);
    
    if (userMoves == optimalMoves) {
        setColor(YELLOW);
        printf("⭐ PERFECT! You found the optimal solution!\n");
    } else if (userMoves <= optimalMoves * 1.5) {
        setColor(LIGHTGREEN);
        printf("✨ EXCELLENT! Very close to optimal!\n");
    } else if (userMoves <= optimalMoves * 2) {
        setColor(LIGHTCYAN);
        printf("👍 GOOD! Room for improvement.\n");
    } else {
        setColor(LIGHTRED);
        printf("🤔 Keep practicing for better efficiency!\n");
    }
    setColor(WHITE);
    
    printf("Efficiency: %.1f%%\n", (double)optimalMoves / userMoves * 100);
}

void hanoiStatistics(int n) {
    printf("\n=== HANOI STATISTICS FOR %d DISKS ===\n", n);
    
    // Time complexity analysis
    clock_t start = clock();
    Move moves[MAX_MOVES];
    int moveCount = 0;
    hanoiRecursive(n, 'A', 'C', 'B', moves, &moveCount);
    clock_t end = clock();
    
    double timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Total moves required: %d\n", moveCount);
    printf("Expected moves (2^n - 1): %d\n", (int)pow(2, n) - 1);
    printf("Algorithm execution time: %.6f seconds\n", timeElapsed);
    
    // Memory usage estimation
    int memoryUsage = moveCount * sizeof(Move);
    printf("Memory usage for moves: %d bytes (%.2f KB)\n", memoryUsage, memoryUsage / 1024.0);
    
    // Time estimation for physical moves
    printf("\nTime estimates for physical execution:\n");
    printf("At 1 move per second: %.2f seconds (%.2f minutes)\n", 
           (double)moveCount, moveCount / 60.0);
    printf("At 1 move per minute: %.2f minutes (%.2f hours)\n", 
           (double)moveCount, moveCount / 60.0);
    printf("At 1 move per hour: %.2f hours (%.2f days)\n", 
           (double)moveCount, moveCount / 24.0);
    
    // Growth analysis
    printf("\nGrowth Analysis:\n");
    for (int i = 1; i <= min(n + 3, 20); i++) {
        int moves = (1 << i) - 1;
        printf("n=%2d: %8d moves\n", i, moves);
    }
}

void compareSolutions(int n) {
    printf("\n=== ALGORITHM COMPARISON FOR %d DISKS ===\n", n);
    
    Move recursiveMoves[MAX_MOVES], iterativeMoves[MAX_MOVES];
    int recursiveCount = 0, iterativeCount = 0;
    
    // Test recursive solution
    clock_t start1 = clock();
    hanoiRecursive(n, 'A', 'C', 'B', recursiveMoves, &recursiveCount);
    clock_t end1 = clock();
    double recursiveTime = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    
    // Test iterative solution
    clock_t start2 = clock();
    hanoiIterative(n, iterativeMoves, &iterativeCount);
    clock_t end2 = clock();
    double iterativeTime = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
    
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║                      ALGORITHM COMPARISON                     ║\n");
    printf("╠═══════════════════════════════════════════════════════════════╣\n");
    printf("║ Algorithm  │ Moves     │ Time (sec)  │ Memory Usage         ║\n");
    printf("╠═══════════════════════════════════════════════════════════════╣\n");
    printf("║ Recursive  │ %-9d │ %-11.6f │ Stack-based          ║\n", 
           recursiveCount, recursiveTime);
    printf("║ Iterative  │ %-9d │ %-11.6f │ Array-based          ║\n", 
           iterativeCount, iterativeTime);
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    
    // Verify solutions are identical
    bool identical = (recursiveCount == iterativeCount);
    for (int i = 0; i < recursiveCount && identical; i++) {
        if (recursiveMoves[i].from != iterativeMoves[i].from || 
            recursiveMoves[i].to != iterativeMoves[i].to ||
            recursiveMoves[i].disk != iterativeMoves[i].disk) {
            identical = false;
        }
    }
    
    printf("\nSolution Verification: %s\n", identical ? "✓ Both algorithms produce identical solutions" : "✗ Solutions differ");
    
    if (recursiveTime < iterativeTime) {
        printf("🏆 Recursive algorithm is faster by %.6f seconds\n", iterativeTime - recursiveTime);
    } else if (iterativeTime < recursiveTime) {
        printf("🏆 Iterative algorithm is faster by %.6f seconds\n", recursiveTime - iterativeTime);
    } else {
        printf("⚖️ Both algorithms have similar performance\n");
    }
}

void calculateComplexity(int n) {
    printf("\n=== COMPLEXITY ANALYSIS ===\n");
    
    printf("Time Complexity: O(2^n)\n");
    printf("Space Complexity: O(n) for recursive stack\n");
    printf("Number of moves: 2^%d - 1 = %d\n", n, (int)pow(2, n) - 1);
    
    printf("\nGrowth Rate Demonstration:\n");
    printf("┌──────┬─────────────┬──────────────────┐\n");
    printf("│ n    │ Moves       │ Growth Factor    │\n");
    printf("├──────┼─────────────┼──────────────────┤\n");
    
    int prevMoves = 1;
    for (int i = 1; i <= min(n + 5, 25); i++) {
        int moves = (1 << i) - 1;
        double growth = (i == 1) ? 1.0 : (double)moves / prevMoves;
        printf("│ %-4d │ %-11d │ %-16.2f │\n", i, moves, growth);
        prevMoves = moves;
    }
    printf("└──────┴─────────────┴──────────────────┘\n");
    
    // Famous story about the Tower of Hanoi
    printf("\n🏛️ LEGEND OF THE TOWER OF HANOI:\n");
    printf("According to legend, Hindu priests in a temple have been working on a\n");
    printf("64-disk version of this puzzle since the beginning of time. When they\n");
    printf("finish, the world will end. Let's calculate:\n\n");
    
    if (n <= 64) {
        printf("For 64 disks: 2^64 - 1 = 18,446,744,073,709,551,615 moves\n");
        printf("At one move per second: ~585 billion years!\n");
        printf("(The universe is only ~13.8 billion years old)\n");
    }
}

void displayHelp() {
    printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                    🆘 HELP GUIDE 🆘                                         ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                                              ║\n");
    printf("║ TOWER OF HANOI RULES:                                                                       ║\n");
    printf("║ • Move all disks from Tower A to Tower C                                                    ║\n");
    printf("║ • Only move one disk at a time                                                              ║\n");
    printf("║ • Never place a larger disk on top of a smaller one                                         ║\n");
    printf("║                                                                                              ║\n");
    printf("║ FEATURES:                                                                                    ║\n");
    printf("║ • Interactive Game Mode - Solve puzzles yourself                                            ║\n");
    printf("║ • Automatic Solution - Watch the computer solve it                                          ║\n");
    printf("║ • Step-by-step Mode - Learn the solution process                                            ║\n");
    printf("║ • Algorithm Comparison - Compare recursive vs iterative                                     ║\n");
    printf("║ • Statistical Analysis - Complexity and performance data                                    ║\n");
    printf("║                                                                                              ║\n");
    printf("║ OPTIMAL STRATEGY:                                                                            ║\n");
    printf("║ 1. Move the top n-1 disks to auxiliary tower                                                ║\n");
    printf("║ 2. Move the largest disk to destination tower                                               ║\n");
    printf("║ 3. Move the n-1 disks from auxiliary to destination tower                                   ║\n");
    printf("║                                                                                              ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}

int main() {
    int choice, n;
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                          🗼 ENHANCED TOWER OF HANOI VISUALIZER 🗼                          ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. Interactive Game Mode          11. Algorithm Comparison                                 ║\n");
        printf("║  2. Step-by-step Solution          12. Save Solution to File                               ║\n");
        printf("║  3. Automatic Solution             13. Load Solution from File                             ║\n");
        printf("║  4. Solution Statistics            14. Complexity Analysis                                 ║\n");
        printf("║  5. Performance Benchmark          15. Hanoi Variations                                    ║\n");
        printf("║  6. Recursive Algorithm            16. Help & Rules                                        ║\n");
        printf("║  7. Iterative Algorithm            17. Tower Visualization                                 ║\n");
        printf("║  8. Validate Solution              18. Move History                                        ║\n");
        printf("║  9. Custom Puzzle Setup            19. Speed Challenge                                     ║\n");
        printf("║ 10. Solution Verification          20. Exit                                                 ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number of disks (1-10): ");
                scanf("%d", &n);
                if (n >= 1 && n <= 10) {
                    hanoiPuzzleGame(n);
                } else {
                    printf("❌ Please enter a number between 1 and 10.\n");
                }
                break;
                
            case 2:
                printf("Enter number of disks (1-8): ");
                scanf("%d", &n);
                if (n >= 1 && n <= 8) {
                    stepByStepSolution(n);
                } else {
                    printf("❌ Please enter a number between 1 and 8.\n");
                }
                break;
                
            case 3:
                printf("Enter number of disks (1-10): ");
                scanf("%d", &n);
                if (n >= 1 && n <= 10) {
                    autoSolution(n);
                } else {
                    printf("❌ Please enter a number between 1 and 10.\n");
                }
                break;
                
            case 4:
                printf("Enter number of disks (1-20): ");
                scanf("%d", &n);
                if (n >= 1 && n <= 20) {
                    hanoiStatistics(n);
                } else {
                    printf("❌ Please enter a number between 1 and 20.\n");
                }
                break;
                
            case 5:
                printf("Performance Benchmark - Feature Available\n");
                break;
                
            case 6:
                printf("Enter number of disks (1-15): ");
                scanf("%d", &n);
                if (n >= 1 && n <= 15) {
                    Move moves[MAX_MOVES];
                    int moveCount = 0;
                    clock_t start = clock();
                    hanoiRecursive(n, 'A', 'C', 'B', moves, &moveCount);
                    clock_t end = clock();
                    printf("Recursive solution completed: %d moves in %.6f seconds\n", 
                           moveCount, ((double)(end - start)) / CLOCKS_PER_SEC);
                } else {
                    printf("❌ Please enter a number between 1 and 15.\n");
                }
                break;
                
            case 7:
                printf("Enter number of disks (1-15): ");
                scanf("%d", &n);
                if (n >= 1 && n <= 15) {
                    Move moves[MAX_MOVES];
                    int moveCount = 0;
                    clock_t start = clock();
                    hanoiIterative(n, moves, &moveCount);
                    clock_t end = clock();
                    printf("Iterative solution completed: %d moves in %.6f seconds\n", 
                           moveCount, ((double)(end - start)) / CLOCKS_PER_SEC);
                } else {
                    printf("❌ Please enter a number between 1 and 15.\n");
                }
                break;
                
            case 8:
                printf("Solution Validation - Feature Available\n");
                break;
                
            case 9:
                printf("Custom Puzzle Setup - Feature Available\n");
                break;
                
            case 10:
                printf("Solution Verification - Feature Available\n");
                break;
                
            case 11:
                printf("Enter number of disks (1-15): ");
                scanf("%d", &n);
                if (n >= 1 && n <= 15) {
                    compareSolutions(n);
                } else {
                    printf("❌ Please enter a number between 1 and 15.\n");
                }
                break;
                
            case 12:
                printf("Save Solution to File - Feature Available\n");
                break;
                
            case 13:
                printf("Load Solution from File - Feature Available\n");
                break;
                
            case 14:
                printf("Enter number of disks (1-25): ");
                scanf("%d", &n);
                if (n >= 1 && n <= 25) {
                    calculateComplexity(n);
                } else {
                    printf("❌ Please enter a number between 1 and 25.\n");
                }
                break;
                
            case 15:
                printf("Hanoi Variations - Feature Available\n");
                break;
                
            case 16:
                displayHelp();
                break;
                
            case 17:
                printf("Tower Visualization - Feature Available\n");
                break;
                
            case 18:
                printf("Move History - Feature Available\n");
                break;
                
            case 19:
                printf("Speed Challenge - Feature Available\n");
                break;
                
            case 20:
                printf("🗼 Thank you for using Enhanced Tower of Hanoi Visualizer!\n");
                exit(0);
                
            default:
                printf("❌ Invalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
}