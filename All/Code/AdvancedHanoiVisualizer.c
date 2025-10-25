#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_DISKS 20
#define MAX_MOVES 1048576

// Structure for a move
typedef struct {
    int disk;
    char from;
    char to;
    int moveNumber;
    clock_t timestamp;
} Move;

// Structure for game state
typedef struct {
    int towers[3][MAX_DISKS];
    int heights[3];
    int numDisks;
    int totalMoves;
    clock_t startTime;
    Move moves[MAX_MOVES];
    int optimal;
} HanoiGame;

// Function prototypes
void initializeGame(HanoiGame *game, int n);
void displayTowers(HanoiGame *game);
void displayAdvancedTowers(HanoiGame *game);
void solveHanoi(HanoiGame *game, int n, int from, int to, int aux);
void solveHanoiIterative(HanoiGame *game);
void playInteractive(HanoiGame *game);
void recordMove(HanoiGame *game, int disk, char from, char to);
void displayMoveHistory(HanoiGame *game);
void analyzeComplexity();
void demonstratePatterns();
void visualizeSolution(int n);
void speedComparison();
void educationalMode();
void challengeMode();
void algorithmComparison();
void hanoiVariations();
void hanoiMath();
void saveGame(HanoiGame *game);
void loadGame(HanoiGame *game);
int isValidMove(HanoiGame *game, int from, int to);
void makeMove(HanoiGame *game, int from, int to);
void undoMove(HanoiGame *game);
void displayStatistics(HanoiGame *game);
void exportSolution(HanoiGame *game);
void animateMove(HanoiGame *game, int from, int to);
void generateOptimalSequence(int n);

void initializeGame(HanoiGame *game, int n) {
    game->numDisks = n;
    game->totalMoves = 0;
    game->startTime = clock();
    game->optimal = (int)pow(2, n) - 1;
    
    // Initialize towers
    for (int i = 0; i < 3; i++) {
        game->heights[i] = 0;
        for (int j = 0; j < MAX_DISKS; j++) {
            game->towers[i][j] = 0;
        }
    }
    
    // Place all disks on first tower (largest at bottom)
    for (int i = 0; i < n; i++) {
        game->towers[0][i] = n - i;
    }
    game->heights[0] = n;
}

void displayTowers(HanoiGame *game) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                      TOWER OF HANOI                       ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");
    printf("║    Tower A           Tower B           Tower C            ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");
    
    int maxHeight = 0;
    for (int i = 0; i < 3; i++) {
        if (game->heights[i] > maxHeight) {
            maxHeight = game->heights[i];
        }
    }
    
    // Display from top to bottom
    for (int level = maxHeight - 1; level >= 0; level--) {
        printf("║");
        
        for (int tower = 0; tower < 3; tower++) {
            printf("    ");
            
            if (level < game->heights[tower]) {
                int diskSize = game->towers[tower][level];
                
                // Create disk representation
                int spaces = (8 - diskSize) / 2;
                for (int i = 0; i < spaces; i++) printf(" ");
                for (int i = 0; i < diskSize; i++) printf("█");
                for (int i = 0; i < 8 - diskSize - spaces; i++) printf(" ");
            } else {
                printf("   |    ");
            }
            
            printf("    ");
        }
        printf("║\n");
    }
    
    // Base
    printf("║ ════════════  ════════════  ════════════ ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    
    printf("Moves: %d/%d | Time: %.2fs\n", 
           game->totalMoves, game->optimal, 
           (double)(clock() - game->startTime) / CLOCKS_PER_SEC);
}

void displayAdvancedTowers(HanoiGame *game) {
    system("cls"); // Clear screen on Windows
    
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          🗼 ADVANCED TOWER OF HANOI 🗼                       ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════╣\n");
    
    int maxHeight = game->numDisks + 2;
    
    // Display towers with colors and enhanced visualization
    for (int level = maxHeight - 1; level >= 0; level--) {
        printf("║  ");
        
        for (int tower = 0; tower < 3; tower++) {
            if (level < game->heights[tower]) {
                int diskSize = game->towers[tower][level];
                
                // Enhanced disk display with numbers
                int padding = (12 - diskSize * 2) / 2;
                for (int i = 0; i < padding; i++) printf(" ");
                
                printf("┌");
                for (int i = 0; i < diskSize * 2 - 2; i++) printf("─");
                printf("%d", diskSize);
                for (int i = 0; i < diskSize * 2 - 2; i++) printf("─");
                printf("┐");
                
                for (int i = 0; i < 12 - diskSize * 2 - padding; i++) printf(" ");
            } else if (level == 0) {
                printf("═══════█═════");
            } else {
                printf("      █      ");
            }
            printf("    ");
        }
        printf("║\n");
    }
    
    printf("║     Tower A        Tower B        Tower C     ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════╝\n");
    
    // Status information
    printf("\n📊 GAME STATUS\n");
    printf("Disks: %d | Moves: %d | Optimal: %d | Efficiency: %.1f%%\n", 
           game->numDisks, game->totalMoves, game->optimal,
           game->optimal > 0 ? 100.0 * game->optimal / (game->totalMoves > 0 ? game->totalMoves : 1) : 100.0);
    
    printf("Time Elapsed: %.2f seconds\n", 
           (double)(clock() - game->startTime) / CLOCKS_PER_SEC);
    
    // Tower heights
    printf("\nTower Heights: A=%d, B=%d, C=%d\n", 
           game->heights[0], game->heights[1], game->heights[2]);
}

void recordMove(HanoiGame *game, int disk, char from, char to) {
    if (game->totalMoves < MAX_MOVES) {
        game->moves[game->totalMoves].disk = disk;
        game->moves[game->totalMoves].from = from;
        game->moves[game->totalMoves].to = to;
        game->moves[game->totalMoves].moveNumber = game->totalMoves + 1;
        game->moves[game->totalMoves].timestamp = clock();
    }
    game->totalMoves++;
}

void solveHanoi(HanoiGame *game, int n, int from, int to, int aux) {
    if (n == 1) {
        // Move disk from source to destination
        int disk = game->towers[from][game->heights[from] - 1];
        game->towers[from][game->heights[from] - 1] = 0;
        game->heights[from]--;
        
        game->towers[to][game->heights[to]] = disk;
        game->heights[to]++;
        
        recordMove(game, disk, 'A' + from, 'A' + to);
        
        printf("Move disk %d from %c to %c\n", disk, 'A' + from, 'A' + to);
        displayTowers(game);
        
        // Small delay for visualization
        for (volatile int i = 0; i < 50000000; i++);
        
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    solveHanoi(game, n - 1, from, aux, to);
    
    // Move largest disk from source to destination
    solveHanoi(game, 1, from, to, aux);
    
    // Move n-1 disks from auxiliary to destination
    solveHanoi(game, n - 1, aux, to, from);
}

void solveHanoiIterative(HanoiGame *game) {
    printf("\n=== ITERATIVE SOLUTION ===\n");
    
    int n = game->numDisks;
    int totalMoves = (1 << n) - 1; // 2^n - 1
    
    // Determine which direction to move the smallest disk
    int direction = (n % 2 == 0) ? -1 : 1;
    
    for (int i = 1; i <= totalMoves; i++) {
        int fromTower, toTower;
        
        if (i % 3 == 1) {
            // Move smallest disk
            fromTower = 0;
            for (int j = 0; j < 3; j++) {
                if (game->heights[j] > 0 && game->towers[j][game->heights[j] - 1] == 1) {
                    fromTower = j;
                    break;
                }
            }
            toTower = (fromTower + direction + 3) % 3;
        } else {
            // Move other disk
            fromTower = -1;
            toTower = -1;
            
            for (int j = 0; j < 3; j++) {
                if (game->heights[j] > 0 && game->towers[j][game->heights[j] - 1] != 1) {
                    if (fromTower == -1) {
                        fromTower = j;
                    } else {
                        toTower = j;
                        break;
                    }
                }
            }
            
            // Determine correct direction
            if (game->towers[fromTower][game->heights[fromTower] - 1] > 
                game->towers[toTower][game->heights[toTower] - 1]) {
                int temp = fromTower;
                fromTower = toTower;
                toTower = temp;
            }
        }
        
        // Make the move
        int disk = game->towers[fromTower][game->heights[fromTower] - 1];
        game->towers[fromTower][game->heights[fromTower] - 1] = 0;
        game->heights[fromTower]--;
        
        game->towers[toTower][game->heights[toTower]] = disk;
        game->heights[toTower]++;
        
        recordMove(game, disk, 'A' + fromTower, 'A' + toTower);
        
        printf("Move %d: Disk %d from %c to %c\n", i, disk, 'A' + fromTower, 'A' + toTower);
        
        if (i % 5 == 0) {
            displayTowers(game);
            printf("Press Enter to continue...");
            getchar();
        }
    }
    
    displayTowers(game);
}

int isValidMove(HanoiGame *game, int from, int to) {
    if (from < 0 || from > 2 || to < 0 || to > 2) return 0;
    if (from == to) return 0;
    if (game->heights[from] == 0) return 0;
    
    if (game->heights[to] == 0) return 1;
    
    return game->towers[from][game->heights[from] - 1] < 
           game->towers[to][game->heights[to] - 1];
}

void makeMove(HanoiGame *game, int from, int to) {
    if (!isValidMove(game, from, to)) {
        printf("❌ Invalid move!\n");
        return;
    }
    
    int disk = game->towers[from][game->heights[from] - 1];
    game->towers[from][game->heights[from] - 1] = 0;
    game->heights[from]--;
    
    game->towers[to][game->heights[to]] = disk;
    game->heights[to]++;
    
    recordMove(game, disk, 'A' + from, 'A' + to);
    
    printf("✓ Moved disk %d from Tower %c to Tower %c\n", disk, 'A' + from, 'A' + to);
}

void playInteractive(HanoiGame *game) {
    printf("\n=== INTERACTIVE MODE ===\n");
    printf("Commands: move <from> <to> (e.g., move A B), help, quit, undo, hint\n\n");
    
    char command[100];
    char from, to;
    
    while (1) {
        displayAdvancedTowers(game);
        
        // Check if solved
        if (game->heights[2] == game->numDisks) {
            printf("\n🎉 CONGRATULATIONS! You solved the puzzle!\n");
            printf("Total moves: %d (Optimal: %d)\n", game->totalMoves, game->optimal);
            if (game->totalMoves == game->optimal) {
                printf("🏆 PERFECT! You used the optimal number of moves!\n");
            }
            break;
        }
        
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        
        if (strncmp(command, "move", 4) == 0) {
            if (sscanf(command, "move %c %c", &from, &to) == 2) {
                from = from - 'A';
                to = to - 'A';
                makeMove(game, from, to);
            } else {
                printf("❌ Invalid format! Use: move A B\n");
            }
        } else if (strncmp(command, "help", 4) == 0) {
            printf("\n📖 HELP\n");
            printf("• Move all disks from Tower A to Tower C\n");
            printf("• Only move one disk at a time\n");
            printf("• Never place a larger disk on a smaller one\n");
            printf("• Commands: move A B, quit, undo, hint\n");
        } else if (strncmp(command, "quit", 4) == 0) {
            break;
        } else if (strncmp(command, "hint", 4) == 0) {
            printf("💡 HINT: Try to expose the largest disk at the bottom of Tower A\n");
        } else {
            printf("❌ Unknown command. Type 'help' for assistance.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
    }
}

void displayMoveHistory(HanoiGame *game) {
    printf("\n=== MOVE HISTORY ===\n");
    printf("Move#  Disk  From  To    Time\n");
    printf("─────────────────────────────\n");
    
    for (int i = 0; i < game->totalMoves && i < 50; i++) {
        double timeSeconds = ((double)(game->moves[i].timestamp - game->startTime)) / CLOCKS_PER_SEC;
        printf("%3d    %2d    %c    %c   %6.2fs\n", 
               game->moves[i].moveNumber,
               game->moves[i].disk,
               game->moves[i].from,
               game->moves[i].to,
               timeSeconds);
    }
    
    if (game->totalMoves > 50) {
        printf("... (%d more moves)\n", game->totalMoves - 50);
    }
}

void analyzeComplexity() {
    printf("\n=== COMPLEXITY ANALYSIS ===\n");
    printf("📊 Time Complexity: O(2^n)\n");
    printf("📊 Space Complexity: O(n) - recursion depth\n\n");
    
    printf("Number of moves for different disk counts:\n");
    printf("Disks | Moves      | Time (approx)\n");
    printf("─────────────────────────────────────\n");
    
    for (int n = 1; n <= 20; n++) {
        long long moves = (1LL << n) - 1;
        double timeSeconds = moves / 1000.0; // Assume 1000 moves per second
        
        printf("%2d    | %-10lld | ", n, moves);
        
        if (timeSeconds < 60) {
            printf("%.2f seconds\n", timeSeconds);
        } else if (timeSeconds < 3600) {
            printf("%.2f minutes\n", timeSeconds / 60);
        } else if (timeSeconds < 86400) {
            printf("%.2f hours\n", timeSeconds / 3600);
        } else if (timeSeconds < 31536000) {
            printf("%.2f days\n", timeSeconds / 86400);
        } else {
            printf("%.2f years\n", timeSeconds / 31536000);
        }
    }
    
    printf("\n💡 Legend says it will take 2^64-1 moves for 64 disks,\n");
    printf("   which would take about 585 billion years!\n");
}

void demonstratePatterns() {
    printf("\n=== MOVEMENT PATTERNS ===\n");
    
    printf("🔄 For 3 disks, the pattern is:\n");
    printf("1. Small disk cycles: A → C → B → A → C → B → A\n");
    printf("2. Medium disk: A → B → C\n");
    printf("3. Large disk: A → C\n\n");
    
    printf("🔄 General pattern:\n");
    printf("• Smallest disk moves every turn\n");
    printf("• Direction depends on odd/even number of disks\n");
    printf("• Other moves are forced (only one legal move)\n\n");
    
    printf("🎯 Strategy:\n");
    printf("• Focus on moving the largest disk to destination\n");
    printf("• Use recursion: solve smaller subproblems\n");
    printf("• The solution is unique and optimal\n");
}

void speedComparison() {
    printf("\n=== ALGORITHM SPEED COMPARISON ===\n");
    
    for (int n = 5; n <= 15; n++) {
        HanoiGame game1, game2;
        
        // Recursive solution
        initializeGame(&game1, n);
        clock_t start1 = clock();
        solveHanoi(&game1, n, 0, 2, 1);
        clock_t end1 = clock();
        double time1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
        
        // Iterative solution
        initializeGame(&game2, n);
        clock_t start2 = clock();
        solveHanoiIterative(&game2);
        clock_t end2 = clock();
        double time2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
        
        printf("Disks: %2d | Recursive: %8.4fs | Iterative: %8.4fs | Speedup: %.2fx\n",
               n, time1, time2, time1 / time2);
    }
}

void educationalMode() {
    printf("\n=== EDUCATIONAL MODE ===\n");
    printf("Learn the Tower of Hanoi step by step!\n\n");
    
    printf("📚 BACKGROUND\n");
    printf("The Tower of Hanoi was invented by French mathematician\n");
    printf("Édouard Lucas in 1883. It's based on a legend about\n");
    printf("priests in a temple who must move 64 golden disks.\n\n");
    
    printf("🎯 OBJECTIVE\n");
    printf("Move all disks from the leftmost tower to the rightmost tower.\n\n");
    
    printf("📋 RULES\n");
    printf("1. Only one disk can be moved at a time\n");
    printf("2. Each move consists of taking the top disk from one stack\n");
    printf("   and placing it on top of another stack\n");
    printf("3. No disk may be placed on top of a smaller disk\n\n");
    
    printf("🧠 STRATEGY\n");
    printf("1. To move n disks from A to C:\n");
    printf("   - Move n-1 disks from A to B (using C as auxiliary)\n");
    printf("   - Move the largest disk from A to C\n");
    printf("   - Move n-1 disks from B to C (using A as auxiliary)\n\n");
    
    printf("🔢 MATHEMATICS\n");
    printf("• Minimum moves: 2^n - 1\n");
    printf("• Recurrence: T(n) = 2*T(n-1) + 1, T(1) = 1\n");
    printf("• Growth rate: Exponential\n");
}

int main() {
    int choice, numDisks;
    HanoiGame game;
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                           🗼 ADVANCED TOWER OF HANOI VISUALIZER 🗼                         ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. Auto Solve (Recursive)            11. Speed Comparison                                  ║\n");
        printf("║  2. Auto Solve (Iterative)            12. Educational Mode                                  ║\n");
        printf("║  3. Interactive Play                  13. Challenge Mode                                   ║\n");
        printf("║  4. Visualize Solution                14. Algorithm Comparison                             ║\n");
        printf("║  5. Display Move History              15. Hanoi Variations                                 ║\n");
        printf("║  6. Complexity Analysis               16. Mathematical Analysis                            ║\n");
        printf("║  7. Demonstrate Patterns              17. Save/Load Game                                   ║\n");
        printf("║  8. Performance Test                  18. Export Solution                                  ║\n");
        printf("║  9. Step-by-Step Tutorial             19. Generate Sequence                                ║\n");
        printf("║ 10. Advanced Visualization            20. Exit                                             ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter number of disks (1-10): ");
                scanf("%d", &numDisks);
                getchar();
                if (numDisks >= 1 && numDisks <= 10) {
                    initializeGame(&game, numDisks);
                    printf("🤖 Starting automatic recursive solution...\n");
                    displayTowers(&game);
                    solveHanoi(&game, numDisks, 0, 2, 1);
                    printf("✅ Solution completed in %d moves!\n", game.totalMoves);
                } else {
                    printf("❌ Invalid number of disks!\n");
                }
                break;
                
            case 2:
                printf("Enter number of disks (1-15): ");
                scanf("%d", &numDisks);
                getchar();
                if (numDisks >= 1 && numDisks <= 15) {
                    initializeGame(&game, numDisks);
                    solveHanoiIterative(&game);
                } else {
                    printf("❌ Invalid number of disks!\n");
                }
                break;
                
            case 3:
                printf("Enter number of disks (1-8): ");
                scanf("%d", &numDisks);
                getchar();
                if (numDisks >= 1 && numDisks <= 8) {
                    initializeGame(&game, numDisks);
                    playInteractive(&game);
                } else {
                    printf("❌ Invalid number of disks!\n");
                }
                break;
                
            case 5:
                if (game.totalMoves > 0) {
                    displayMoveHistory(&game);
                } else {
                    printf("❌ No moves recorded yet!\n");
                }
                break;
                
            case 6:
                analyzeComplexity();
                break;
                
            case 7:
                demonstratePatterns();
                break;
                
            case 11:
                speedComparison();
                break;
                
            case 12:
                educationalMode();
                break;
                
            case 20:
                printf("🗼 Thank you for using Advanced Tower of Hanoi Visualizer!\n");
                exit(0);
                
            default:
                printf("❌ Feature under development or invalid choice!\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
    }
    
    return 0;
}