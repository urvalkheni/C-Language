#include <stdio.h>
#include <math.h>

void decimalToOctal(int decimal) {
    int octal[32];
    int i = 0;

    // Convert integer part to octal
    while (decimal != 0) {
        octal[i] = decimal % 8;
        decimal /= 8;
        i++;
    }

    // Print octal in reverse order
    printf("Octal equivalent of the integer part: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

int main() {
    float input;
    int integerPart;

    printf("Enter a decimal number (floating-point allowed): ");
    scanf("%f", &input);

    // Extract the integer part of the input
    integerPart = (int)input;

    if (integerPart < 0) {
        printf("Please enter a non-negative number.\n");
    } else {
        decimalToOctal(integerPart);
    }

    return 0;
}
