#include <stdio.h>

int main() {
    int n, x, y, z;
    int sumX = 0, sumY = 0, sumZ = 0;

    // Read the number of vectors
    scanf("%d", &n);

    // Loop through each vector and compute the sums
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &z);
        sumX += x;
        sumY += y;
        sumZ += z;
    }

    // Check if the body is in equilibrium
    if (sumX == 0 && sumY == 0 && sumZ == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
