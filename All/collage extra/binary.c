#include <stdio.h>

void convertIntegerPartToBinary(long integerPart, char binary[]) {
    int index = 0;

    // Handle special case for 0
    if (integerPart == 0) {
        binary[index++] = '0';
    } else {
        // Convert integer part to binary
        while (integerPart > 0) {
            binary[index++] = (integerPart % 2) + '0'; // Remainder -> binary digit
            integerPart /= 2;
        }
    }
    binary[index] = '\0';

    // Reverse the binary string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - 1 - i];
        binary[index - 1 - i] = temp;
    }
}

void convertFractionPartToBinary(double fractionPart, char binary[], int precision) {
    int index = 0;

    // Convert fraction part to binary with the given precision
    while (fractionPart > 0 && index < precision) {
        fractionPart *= 2;
        if (fractionPart >= 1) {
            binary[index++] = '1';
            fractionPart -= 1;
        } else {
            binary[index++] = '0';
        }
    }
    binary[index] = '\0';
}

int main() {
    double num;
    char binaryInteger[100], binaryFraction[100];
    long integerPart;
    double fractionPart;

    // Input the floating-point number
    printf("Enter a floating-point number: ");
    scanf("%lf", &num);

    // Separate integer and fraction parts
    integerPart = (long)num;
    fractionPart = num - integerPart;

    // Convert integer and fractional parts to binary
    convertIntegerPartToBinary(integerPart, binaryInteger);
    convertFractionPartToBinary(fractionPart, binaryFraction, 10); // Precision: 10 binary digits

    // Print the result
    printf("Binary representation of %.10f is: %s.%s\n", num, binaryInteger, binaryFraction);

    return 0;
}
