#include <stdio.h>

// Function to solve Tower of Hanoi
void HANOI(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    // Move n-1 disks from source to auxiliary
    HANOI(n - 1, source, auxiliary, destination);

    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move the n-1 disks from auxiliary to destination
    HANOI(n - 1, auxiliary, destination, source);
}

int main() {
    int n;

    // Input the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Solve Tower of Hanoi
    printf("Steps to solve Tower of Hanoi with %d disks:\n", n);
    HANOI(n, 'A', 'C', 'B'); // A = source, C = destination, B = auxiliary

    return 0;
}
