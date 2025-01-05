#include <stdio.h>
#include <math.h>

void decimalToHexadecimal(int decimal) {
    char hex[32];
    int i = 0;

    // Convert integer part to hexadecimal
    while (decimal != 0) {
        int remainder = decimal % 16;

        // Convert remainder to hexadecimal digit
        if (remainder < 10) {
            hex[i] = '0' + remainder;
        } else {
            hex[i] = 'A' + (remainder - 10);
        }

        decimal /= 16;
        i++;
    }

    // Print hexadecimal in reverse order
    printf("Hexadecimal equivalent of the integer part: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
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
    } else if (integerPart == 0) {
        printf("Hexadecimal equivalent of the integer part: 0\n");
    } else {
        decimalToHexadecimal(integerPart);
    }

    return 0;
}
