#include <stdio.h>

void upperRightFull(int n) {
    printf("\n=== Upper Right Full Triangle ===\n");
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void upperLeftFull(int n) {
    printf("\n=== Upper Left Full Triangle ===\n");
    for (int i = 1; i <= n; i++) {
        // Print stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void lowerRightFull(int n) {
    printf("\n=== Lower Right Full Triangle ===\n");
    for (int i = n; i >= 1; i--) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void lowerLeftFull(int n) {
    printf("\n=== Lower Left Full Triangle ===\n");
    for (int i = n; i >= 1; i--) {
        // Print stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void upperRightHollow(int n) {
    printf("\n=== Upper Right Hollow Triangle ===\n");
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void upperLeftHollow(int n) {
    printf("\n=== Upper Left Hollow Triangle ===\n");
    for (int i = 1; i <= n; i++) {
        // Print stars
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void lowerRightHollow(int n) {
    printf("\n=== Lower Right Hollow Triangle ===\n");
    for (int i = n; i >= 1; i--) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void lowerLeftHollow(int n) {
    printf("\n=== Lower Left Hollow Triangle ===\n");
    for (int i = n; i >= 1; i--) {
        // Print stars
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, size;

    printf("\n**************************************\n");
    printf("*    TRIANGLE PATTERN MENU PROGRAM   *\n");
    printf("**************************************\n");
    printf("\n1. Upper Right Full Triangle\n");
    printf("2. Upper Left Full Triangle\n");
    printf("3. Lower Right Full Triangle\n");
    printf("4. Lower Left Full Triangle\n");
    printf("5. Upper Right Hollow Triangle\n");
    printf("6. Upper Left Hollow Triangle\n");
    printf("7. Lower Right Hollow Triangle\n");
    printf("8. Lower Left Hollow Triangle\n");
    printf("0. Exit\n");
    printf("\nEnter your choice (0-8): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 8) {
        printf("Enter the size of the triangle: ");
        scanf("%d", &size);
    }

    switch (choice) {
        case 1:
            upperRightFull(size);
            break;
        case 2:
            upperLeftFull(size);
            break;
        case 3:
            lowerRightFull(size);
            break;
        case 4:
            lowerLeftFull(size);
            break;
        case 5:
            upperRightHollow(size);
            break;
        case 6:
            upperLeftHollow(size);
            break;
        case 7:
            lowerRightHollow(size);
            break;
        case 8:
            lowerLeftHollow(size);
            break;
        case 0:
            printf("\nExiting program. Goodbye!\n");
            break;
        default:
            printf("\n*** Invalid choice! Please enter a number between 0 and 8. ***\n");
            break;
    }

    return 0;
}
