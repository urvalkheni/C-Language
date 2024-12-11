#include <stdio.h>

// Function to calculate GCD using the Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;

    // Input two numbers
    printf("Enter First number: ");
    scanf("%d", &a);
    printf("Enter Second number: ");
    scanf("%d", &b);

    // Calculate GCD
    int hcf = gcd(a, b);

    // Output the result
    printf("The HCF/GCD of %d and %d is: %d\n", a, b, hcf);
    return 0;
}
