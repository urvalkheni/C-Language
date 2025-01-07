#include <stdio.h>

int isPerfectNumber(int num) {
    int sum = 0;

    // Find divisors and calculate their sum
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if the sum of divisors equals the number
    return sum == num;
}

int main() {
    int num;

    // Input number to check
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfectNumber(num)) {
        printf("%d is a Perfect Number.\n", num);
    } else {
        printf("%d is NOT a Perfect Number.\n", num);
    }

    return 0;
}
