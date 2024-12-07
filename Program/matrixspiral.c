#include<stdio.h>

int main(){
    int n, m, i, j, a;
    printf("Enter The Row Number :: ");
    scanf("%d", &m);
    printf("Enter The Column Number :: ");
    scanf("%d", &n);
    
    int x[m][n];
    
    // Fill the matrix with sequential numbers
    for (i = 0, a = 1; i < m; i++) {
        for (j = 0; j < n; j++) {
            x[i][j] = a++;
        }
    }
    
    // Print the matrix
    printf("Matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
    
    // Spiral Print
    printf("\nSpiral Order:\n");
    int minr = 0;
    int maxc = n - 1;
    int maxr = m - 1;
    int minc = 0;
    int count = 0;
    int tne = m * n; // Total number of elements
    
    while (count < tne) {
        // Traverse from left to right
        for (j = minc; j <= maxc && count < tne; j++) {
            printf("%d ", x[minr][j]);
            count++;
        }
        minr++;
        
        // Traverse from top to bottom
        for (i = minr; i <= maxr && count < tne; i++) {
            printf("%d ", x[i][maxc]);
            count++;
        }
        maxc--;
        
        // Traverse from right to left
        for (j = maxc; j >= minc && count < tne; j--) {
            printf("%d ", x[maxr][j]);
            count++;
        }
        maxr--;
        
        // Traverse from bottom to top
        for (i = maxr; i >= minr && count < tne; i--) {
            printf("%d ", x[i][minc]);
            count++;
        }
        minc++;
    }
    
    return 0;
}
