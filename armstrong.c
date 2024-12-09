#include <stdio.h>
#include <math.h>

// Custom power function for integers
int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

// Function to count the number of digits in a number
int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;

    // Count the number of digits
    int digits = countDigits(num);

    // Calculate the sum of the digits raised to the power of `digits`
    while (num > 0) {
        int digit = num % 10;
        sum += power(digit, digits);
        num /= 10;
    }

    // Check if the sum equals the original number
    return sum == originalNum;
}

int main() {
    int num;

    // Input from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check for negative numbers
    if (num < 0) {
        printf("Negative numbers cannot be Armstrong numbers.\n");
        return 0;
    }

    // Check and display the result
    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}
