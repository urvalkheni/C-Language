#include <stdio.h>
#include <stdlib.h>

void fillLayer(int** a, int top, int left, int bottom, int right, int val) {
    for (int j = left; j <= right; ++j) a[top][j] = val;
    for (int j = left; j <= right; ++j) a[bottom][j] = val;
    for (int i = top; i <= bottom; ++i) a[i][left] = val;
    for (int i = top; i <= bottom; ++i) a[i][right] = val;

    // Recurse for next inner layer
    if (val > 1) {
        fillLayer(a, top + 1, left + 1, bottom - 1, right - 1, val - 1);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) return 0;
    
    int size = 2 * n - 1;
    
    // Allocate 2D array
    int** a = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        a[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            a[i][j] = 0;
        }
    }

    fillLayer(a, 0, 0, size - 1, size - 1, n);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j) printf(" ");
            printf("%d", a[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(a[i]);
    }
    free(a);
    
    return 0;
}