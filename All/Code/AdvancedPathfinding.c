#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#define MAX_SIZE 50
#define MAX_PATHS 10000
#define INF 999999

// Direction vectors for 4-directional movement
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dirChar[] = {'U', 'D', 'L', 'R'};

// Direction vectors for 8-directional movement
int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Structure for coordinates
typedef struct {
    int x, y;
    int g, h, f; // For A* algorithm
    struct Node* parent;
} Node;

// Structure for path
typedef struct {
    Node points[MAX_SIZE * MAX_SIZE];
    int length;
    int cost;
    char moves[MAX_SIZE * MAX_SIZE];
} Path;

// Structure for maze
typedef struct {
    int grid[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    int startX, startY;
    int endX, endY;
    int visited[MAX_SIZE][MAX_SIZE];
    int distance[MAX_SIZE][MAX_SIZE];
    Path paths[MAX_PATHS];
    int pathCount;
    int totalPaths;
    int weights[MAX_SIZE][MAX_SIZE]; // For weighted pathfinding
} Maze;

// Function prototypes
void initializeMaze(Maze *maze, int rows, int cols);
void displayMaze(Maze *maze);
void displayMazeWithPath(Maze *maze, Path *path);
void generateRandomMaze(Maze *maze);
void setCustomMaze(Maze *maze);
int countPaths(Maze *maze, int x, int y);
int countPathsDynamic(Maze *maze);
void findAllPaths(Maze *maze, int x, int y, Path *currentPath, int pathIndex);
void dijkstraAlgorithm(Maze *maze);
void aStarAlgorithm(Maze *maze);
void breadthFirstSearch(Maze *maze);
void depthFirstSearch(Maze *maze, int x, int y, Path *path);
void floodFill(Maze *maze);
void analyzePathComplexity();
void benchmarkAlgorithms(Maze *maze);
void visualizePath(Maze *maze, Path *path);
void generateMazePatterns();
void solveMazeInteractive(Maze *maze);
void exportMazeAndSolution(Maze *maze);
void mazeStatistics(Maze *maze);
int isValid(Maze *maze, int x, int y);
int isValidWeighted(Maze *maze, int x, int y);
int manhattanDistance(int x1, int y1, int x2, int y2);
int euclideanDistance(int x1, int y1, int x2, int y2);
void resetVisited(Maze *maze);
void copyPath(Path *dest, Path *src);
void printPath(Path *path);
void generateWeightedMaze(Maze *maze);
void compareAlgorithms();
void mazeGenerationAlgorithms();

void initializeMaze(Maze *maze, int rows, int cols) {
    maze->rows = rows;
    maze->cols = cols;
    maze->pathCount = 0;
    maze->totalPaths = 0;
    
    // Initialize grid with walls (1) and paths (0)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze->grid[i][j] = 0; // 0 = path, 1 = wall
            maze->visited[i][j] = 0;
            maze->distance[i][j] = INF;
            maze->weights[i][j] = 1; // Default weight
        }
    }
    
    // Set default start and end positions
    maze->startX = 0;
    maze->startY = 0;
    maze->endX = rows - 1;
    maze->endY = cols - 1;
}

void displayMaze(Maze *maze) {
    printf("\n╔");
    for (int j = 0; j < maze->cols; j++) {
        printf("══");
    }
    printf("╗\n");
    
    for (int i = 0; i < maze->rows; i++) {
        printf("║");
        for (int j = 0; j < maze->cols; j++) {
            if (i == maze->startX && j == maze->startY) {
                printf("S ");
            } else if (i == maze->endX && j == maze->endY) {
                printf("E ");
            } else if (maze->grid[i][j] == 1) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("║\n");
    }
    
    printf("╚");
    for (int j = 0; j < maze->cols; j++) {
        printf("══");
    }
    printf("╝\n");
    
    printf("Legend: S=Start, E=End, ██=Wall, (space)=Path\n");
}

void displayMazeWithPath(Maze *maze, Path *path) {
    int pathGrid[MAX_SIZE][MAX_SIZE];
    
    // Copy original grid
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            pathGrid[i][j] = maze->grid[i][j];
        }
    }
    
    // Mark path
    for (int i = 0; i < path->length; i++) {
        int x = path->points[i].x;
        int y = path->points[i].y;
        if (!(x == maze->startX && y == maze->startY) && 
            !(x == maze->endX && y == maze->endY)) {
            pathGrid[x][y] = 2; // 2 = path marker
        }
    }
    
    printf("\n╔");
    for (int j = 0; j < maze->cols; j++) {
        printf("══");
    }
    printf("╗\n");
    
    for (int i = 0; i < maze->rows; i++) {
        printf("║");
        for (int j = 0; j < maze->cols; j++) {
            if (i == maze->startX && j == maze->startY) {
                printf("S ");
            } else if (i == maze->endX && j == maze->endY) {
                printf("E ");
            } else if (pathGrid[i][j] == 1) {
                printf("██");
            } else if (pathGrid[i][j] == 2) {
                printf("●●");
            } else {
                printf("  ");
            }
        }
        printf("║\n");
    }
    
    printf("╚");
    for (int j = 0; j < maze->cols; j++) {
        printf("══");
    }
    printf("╝\n");
    
    printf("Path Length: %d | Cost: %d\n", path->length, path->cost);
    printf("Legend: S=Start, E=End, ██=Wall, ●●=Path\n");
}

void generateRandomMaze(Maze *maze) {
    printf("Enter maze density (0-50, higher = more walls): ");
    int density;
    scanf("%d", &density);
    
    srand(time(NULL));
    
    // Clear the maze first
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            maze->grid[i][j] = 0;
        }
    }
    
    // Add random walls
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if ((i != maze->startX || j != maze->startY) && 
                (i != maze->endX || j != maze->endY)) {
                if (rand() % 100 < density) {
                    maze->grid[i][j] = 1;
                }
            }
        }
    }
    
    printf("✓ Random maze generated with %d%% wall density\n", density);
}

void setCustomMaze(Maze *maze) {
    printf("Enter custom maze (0=path, 1=wall):\n");
    
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            scanf("%d", &maze->grid[i][j]);
        }
    }
    
    printf("Enter start position (row col): ");
    scanf("%d %d", &maze->startX, &maze->startY);
    
    printf("Enter end position (row col): ");
    scanf("%d %d", &maze->endX, &maze->endY);
}

int isValid(Maze *maze, int x, int y) {
    return (x >= 0 && x < maze->rows && y >= 0 && y < maze->cols && 
            maze->grid[x][y] == 0);
}

void resetVisited(Maze *maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            maze->visited[i][j] = 0;
            maze->distance[i][j] = INF;
        }
    }
}

int countPaths(Maze *maze, int x, int y) {
    // Base case: reached destination
    if (x == maze->endX && y == maze->endY) {
        return 1;
    }
    
    // Mark current cell as visited
    maze->visited[x][y] = 1;
    
    int totalPaths = 0;
    
    // Try all 4 directions
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if (isValid(maze, newX, newY) && !maze->visited[newX][newY]) {
            totalPaths += countPaths(maze, newX, newY);
        }
    }
    
    // Backtrack
    maze->visited[x][y] = 0;
    
    return totalPaths;
}

int countPathsDynamic(Maze *maze) {
    int dp[MAX_SIZE][MAX_SIZE];
    
    // Initialize DP table
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            dp[i][j] = 0;
        }
    }
    
    // Base case
    dp[maze->startX][maze->startY] = 1;
    
    // Fill DP table
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->grid[i][j] == 1) continue; // Skip walls
            
            for (int d = 0; d < 4; d++) {
                int prevX = i - dx[d];
                int prevY = j - dy[d];
                
                if (prevX >= 0 && prevX < maze->rows && 
                    prevY >= 0 && prevY < maze->cols && 
                    maze->grid[prevX][prevY] == 0) {
                    dp[i][j] += dp[prevX][prevY];
                }
            }
        }
    }
    
    return dp[maze->endX][maze->endY];
}

void breadthFirstSearch(Maze *maze) {
    printf("\n=== BREADTH-FIRST SEARCH ===\n");
    
    resetVisited(maze);
    
    // Queue for BFS
    Node queue[MAX_SIZE * MAX_SIZE];
    int front = 0, rear = 0;
    
    // Parent array to reconstruct path
    Node parent[MAX_SIZE][MAX_SIZE];
    
    // Start BFS
    queue[rear].x = maze->startX;
    queue[rear].y = maze->startY;
    rear++;
    
    maze->visited[maze->startX][maze->startY] = 1;
    maze->distance[maze->startX][maze->startY] = 0;
    parent[maze->startX][maze->startY].x = -1;
    parent[maze->startX][maze->startY].y = -1;
    
    int found = 0;
    clock_t startTime = clock();
    
    while (front < rear && !found) {
        Node current = queue[front++];
        
        if (current.x == maze->endX && current.y == maze->endY) {
            found = 1;
            break;
        }
        
        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            
            if (isValid(maze, newX, newY) && !maze->visited[newX][newY]) {
                maze->visited[newX][newY] = 1;
                maze->distance[newX][newY] = maze->distance[current.x][current.y] + 1;
                
                parent[newX][newY].x = current.x;
                parent[newX][newY].y = current.y;
                
                queue[rear].x = newX;
                queue[rear].y = newY;
                rear++;
            }
        }
    }
    
    clock_t endTime = clock();
    double timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    
    if (found) {
        printf("✓ Path found!\n");
        printf("Shortest path length: %d\n", maze->distance[maze->endX][maze->endY]);
        printf("Time taken: %.6f seconds\n", timeTaken);
        printf("Nodes explored: %d\n", front);
        
        // Reconstruct path
        Path shortestPath;
        shortestPath.length = 0;
        shortestPath.cost = maze->distance[maze->endX][maze->endY];
        
        int x = maze->endX, y = maze->endY;
        while (x != -1 && y != -1) {
            shortestPath.points[shortestPath.length].x = x;
            shortestPath.points[shortestPath.length].y = y;
            shortestPath.length++;
            
            int tempX = parent[x][y].x;
            int tempY = parent[x][y].y;
            x = tempX;
            y = tempY;
        }
        
        // Reverse path (it's constructed backwards)
        for (int i = 0; i < shortestPath.length / 2; i++) {
            Node temp = shortestPath.points[i];
            shortestPath.points[i] = shortestPath.points[shortestPath.length - 1 - i];
            shortestPath.points[shortestPath.length - 1 - i] = temp;
        }
        
        displayMazeWithPath(maze, &shortestPath);
    } else {
        printf("❌ No path found!\n");
        printf("Time taken: %.6f seconds\n", timeTaken);
        printf("Nodes explored: %d\n", front);
    }
}

int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void aStarAlgorithm(Maze *maze) {
    printf("\n=== A* ALGORITHM ===\n");
    
    resetVisited(maze);
    
    // Priority queue (simplified implementation)
    Node openSet[MAX_SIZE * MAX_SIZE];
    int openSize = 0;
    
    Node parent[MAX_SIZE][MAX_SIZE];
    int gScore[MAX_SIZE][MAX_SIZE];
    int fScore[MAX_SIZE][MAX_SIZE];
    
    // Initialize scores
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            gScore[i][j] = INF;
            fScore[i][j] = INF;
            parent[i][j].x = -1;
            parent[i][j].y = -1;
        }
    }
    
    // Start node
    gScore[maze->startX][maze->startY] = 0;
    fScore[maze->startX][maze->startY] = manhattanDistance(maze->startX, maze->startY, 
                                                          maze->endX, maze->endY);
    
    openSet[0].x = maze->startX;
    openSet[0].y = maze->startY;
    openSet[0].f = fScore[maze->startX][maze->startY];
    openSize = 1;
    
    int found = 0;
    int nodesExplored = 0;
    clock_t startTime = clock();
    
    while (openSize > 0 && !found) {
        // Find node with lowest f score
        int currentIndex = 0;
        for (int i = 1; i < openSize; i++) {
            if (openSet[i].f < openSet[currentIndex].f) {
                currentIndex = i;
            }
        }
        
        Node current = openSet[currentIndex];
        nodesExplored++;
        
        // Remove current from open set
        for (int i = currentIndex; i < openSize - 1; i++) {
            openSet[i] = openSet[i + 1];
        }
        openSize--;
        
        maze->visited[current.x][current.y] = 1;
        
        // Check if reached goal
        if (current.x == maze->endX && current.y == maze->endY) {
            found = 1;
            break;
        }
        
        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            
            if (!isValid(maze, newX, newY) || maze->visited[newX][newY]) {
                continue;
            }
            
            int tentativeG = gScore[current.x][current.y] + 1;
            
            if (tentativeG < gScore[newX][newY]) {
                parent[newX][newY].x = current.x;
                parent[newX][newY].y = current.y;
                gScore[newX][newY] = tentativeG;
                fScore[newX][newY] = tentativeG + manhattanDistance(newX, newY, 
                                                                   maze->endX, maze->endY);
                
                // Add to open set if not already there
                int inOpenSet = 0;
                for (int j = 0; j < openSize; j++) {
                    if (openSet[j].x == newX && openSet[j].y == newY) {
                        openSet[j].f = fScore[newX][newY];
                        inOpenSet = 1;
                        break;
                    }
                }
                
                if (!inOpenSet) {
                    openSet[openSize].x = newX;
                    openSet[openSize].y = newY;
                    openSet[openSize].f = fScore[newX][newY];
                    openSize++;
                }
            }
        }
    }
    
    clock_t endTime = clock();
    double timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    
    if (found) {
        printf("✓ Optimal path found!\n");
        printf("Path length: %d\n", gScore[maze->endX][maze->endY]);
        printf("Time taken: %.6f seconds\n", timeTaken);
        printf("Nodes explored: %d\n", nodesExplored);
        
        // Reconstruct path
        Path optimalPath;
        optimalPath.length = 0;
        optimalPath.cost = gScore[maze->endX][maze->endY];
        
        int x = maze->endX, y = maze->endY;
        while (x != -1 && y != -1) {
            optimalPath.points[optimalPath.length].x = x;
            optimalPath.points[optimalPath.length].y = y;
            optimalPath.length++;
            
            int tempX = parent[x][y].x;
            int tempY = parent[x][y].y;
            x = tempX;
            y = tempY;
        }
        
        // Reverse path
        for (int i = 0; i < optimalPath.length / 2; i++) {
            Node temp = optimalPath.points[i];
            optimalPath.points[i] = optimalPath.points[optimalPath.length - 1 - i];
            optimalPath.points[optimalPath.length - 1 - i] = temp;
        }
        
        displayMazeWithPath(maze, &optimalPath);
    } else {
        printf("❌ No path found!\n");
        printf("Time taken: %.6f seconds\n", timeTaken);
        printf("Nodes explored: %d\n", nodesExplored);
    }
}

void benchmarkAlgorithms(Maze *maze) {
    printf("\n=== ALGORITHM BENCHMARK ===\n");
    printf("Comparing BFS and A* on current maze...\n\n");
    
    // Test BFS
    printf("Testing BFS...\n");
    clock_t start = clock();
    resetVisited(maze);
    breadthFirstSearch(maze);
    clock_t end = clock();
    double bfsTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("\nTesting A*...\n");
    start = clock();
    resetVisited(maze);
    aStarAlgorithm(maze);
    end = clock();
    double astarTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("\n📊 PERFORMANCE COMPARISON\n");
    printf("BFS Time: %.6f seconds\n", bfsTime);
    printf("A* Time:  %.6f seconds\n", astarTime);
    printf("Speedup:  %.2fx\n", bfsTime / astarTime);
}

void analyzePathComplexity() {
    printf("\n=== PATHFINDING COMPLEXITY ANALYSIS ===\n");
    
    printf("🔍 ALGORITHM COMPLEXITIES\n");
    printf("┌────────────────┬─────────────────┬─────────────────┬─────────────────┐\n");
    printf("│ Algorithm      │ Time Complexity │ Space Complexity│ Optimality      │\n");
    printf("├────────────────┼─────────────────┼─────────────────┼─────────────────┤\n");
    printf("│ BFS            │ O(V + E)        │ O(V)            │ Yes (unweighted)│\n");
    printf("│ DFS            │ O(V + E)        │ O(V)            │ No              │\n");
    printf("│ A*             │ O(b^d)          │ O(b^d)          │ Yes (admissible)│\n");
    printf("│ Dijkstra       │ O((V+E)logV)    │ O(V)            │ Yes (weighted)  │\n");
    printf("│ Dynamic Prog.  │ O(V)            │ O(V)            │ Counting only   │\n");
    printf("└────────────────┴─────────────────┴─────────────────┴─────────────────┘\n");
    
    printf("\n📐 WHERE:\n");
    printf("• V = Number of vertices (cells)\n");
    printf("• E = Number of edges (connections)\n");
    printf("• b = Branching factor\n");
    printf("• d = Depth of solution\n");
    
    printf("\n🎯 ALGORITHM CHARACTERISTICS\n");
    printf("• BFS: Guarantees shortest path in unweighted graphs\n");
    printf("• DFS: Memory efficient but doesn't guarantee optimal path\n");
    printf("• A*: Uses heuristics to find optimal path faster than BFS\n");
    printf("• Dijkstra: Handles weighted graphs optimally\n");
    
    printf("\n⚡ PERFORMANCE FACTORS\n");
    printf("• Maze size: Larger mazes exponentially increase search space\n");
    printf("• Obstacle density: More walls reduce valid paths\n");
    printf("• Heuristic quality: Better heuristics improve A* performance\n");
    printf("• Goal position: Corner goals harder than center goals\n");
}

void mazeStatistics(Maze *maze) {
    printf("\n=== MAZE STATISTICS ===\n");
    
    int totalCells = maze->rows * maze->cols;
    int wallCells = 0;
    int pathCells = 0;
    
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->grid[i][j] == 1) {
                wallCells++;
            } else {
                pathCells++;
            }
        }
    }
    
    printf("📊 BASIC STATISTICS\n");
    printf("Dimensions: %d × %d\n", maze->rows, maze->cols);
    printf("Total cells: %d\n", totalCells);
    printf("Wall cells: %d (%.1f%%)\n", wallCells, 100.0 * wallCells / totalCells);
    printf("Path cells: %d (%.1f%%)\n", pathCells, 100.0 * pathCells / totalCells);
    
    printf("\nStart: (%d, %d)\n", maze->startX, maze->startY);
    printf("End: (%d, %d)\n", maze->endX, maze->endY);
    printf("Manhattan distance: %d\n", 
           manhattanDistance(maze->startX, maze->startY, maze->endX, maze->endY));
    
    // Count total possible paths
    resetVisited(maze);
    printf("\n🔢 PATH ANALYSIS\n");
    printf("Calculating total possible paths...\n");
    
    clock_t start = clock();
    int totalPaths = countPaths(maze, maze->startX, maze->startY);
    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Total possible paths: %d\n", totalPaths);
    printf("Calculation time: %.6f seconds\n", timeTaken);
    
    if (totalPaths > 0) {
        printf("✓ Maze is solvable\n");
    } else {
        printf("❌ Maze is unsolvable\n");
    }
}

int main() {
    Maze maze;
    int choice, rows, cols;
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                          🗺️  ADVANCED PATHFINDING ALGORITHMS 🗺️                           ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. Initialize Maze                   11. Weighted Pathfinding                              ║\n");
        printf("║  2. Generate Random Maze              12. Algorithm Benchmark                               ║\n");
        printf("║  3. Set Custom Maze                   13. Maze Generation Algorithms                       ║\n");
        printf("║  4. Display Maze                      14. Interactive Solver                               ║\n");
        printf("║  5. Count All Paths                   15. Export Solutions                                  ║\n");
        printf("║  6. Breadth-First Search              16. Compare Algorithms                                ║\n");
        printf("║  7. A* Algorithm                      17. Complexity Analysis                               ║\n");
        printf("║  8. Depth-First Search                18. Maze Statistics                                   ║\n");
        printf("║  9. Dijkstra's Algorithm              19. Pattern Generation                                ║\n");
        printf("║ 10. Flood Fill                        20. Exit                                             ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter maze dimensions (rows cols): ");
                scanf("%d %d", &rows, &cols);
                if (rows > 0 && rows <= MAX_SIZE && cols > 0 && cols <= MAX_SIZE) {
                    initializeMaze(&maze, rows, cols);
                    printf("✓ Maze initialized (%d×%d)\n", rows, cols);
                } else {
                    printf("❌ Invalid dimensions! Use 1-%d\n", MAX_SIZE);
                }
                break;
                
            case 2:
                if (maze.rows > 0) {
                    generateRandomMaze(&maze);
                } else {
                    printf("❌ Please initialize maze first!\n");
                }
                break;
                
            case 3:
                if (maze.rows > 0) {
                    setCustomMaze(&maze);
                } else {
                    printf("❌ Please initialize maze first!\n");
                }
                break;
                
            case 4:
                if (maze.rows > 0) {
                    displayMaze(&maze);
                } else {
                    printf("❌ Please initialize maze first!\n");
                }
                break;
                
            case 5:
                if (maze.rows > 0) {
                    resetVisited(&maze);
                    clock_t start = clock();
                    int paths = countPaths(&maze, maze.startX, maze.startY);
                    clock_t end = clock();
                    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
                    printf("Total possible paths: %d\n", paths);
                    printf("Time taken: %.6f seconds\n", time);
                } else {
                    printf("❌ Please initialize maze first!\n");
                }
                break;
                
            case 6:
                if (maze.rows > 0) {
                    breadthFirstSearch(&maze);
                } else {
                    printf("❌ Please initialize maze first!\n");
                }
                break;
                
            case 7:
                if (maze.rows > 0) {
                    aStarAlgorithm(&maze);
                } else {
                    printf("❌ Please initialize maze first!\n");
                }
                break;
                
            case 12:
                if (maze.rows > 0) {
                    benchmarkAlgorithms(&maze);
                } else {
                    printf("❌ Please initialize maze first!\n");
                }
                break;
                
            case 17:
                analyzePathComplexity();
                break;
                
            case 18:
                if (maze.rows > 0) {
                    mazeStatistics(&maze);
                } else {
                    printf("❌ Please initialize maze first!\n");
                }
                break;
                
            case 20:
                printf("🗺️ Thank you for using Advanced Pathfinding Algorithms!\n");
                exit(0);
                
            default:
                printf("❌ Feature under development or invalid choice!\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
}