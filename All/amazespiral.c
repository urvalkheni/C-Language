#include <stdio.h>
#include <math.h>

int main() {
    int rows = 20, cols = 40; // Size of the terminal grid
    char grid[20][40];        // 2D array for the grid

    // Initialize the grid with spaces
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = ' ';
        }
    }

    // Center point of the grid
    int centerX = rows / 2;
    int centerY = cols / 2;

    // Draw the spiral
    double angle = 0.0;
    double radius = 0.0;

    while (radius < rows / 2) {
        int x = (int)(centerX + radius * sin(angle)); // Switched to sin for vertical spacing balance
        int y = (int)(centerY + radius * cos(angle)); // Switched to cos for horizontal balance
        
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            grid[x][y] = '*'; // Plot a point on the spiral
        }

        angle += 0.1;      // Increment angle (adjust for tighter/looser spirals)
        radius += 0.05;    // Increment radius (adjust for spacing)
    }

    // Print the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            putchar(grid[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
