#include <stdio.h>
#include <string.h>

// Function to convert binary to octal
void binaryToOctal(char binary[]) {
    int length = strlen(binary);
    int remainder = length % 3;
    
    // Print leading zeros if necessary
    if (remainder != 0) {
        for (int i = 0; i < 3 - remainder; i++) {
            printf("0");
        }
    }

    printf("Octal Equivalent: ");
    
    // Process each group of 3 bits
    for (int i = 0; i < length; i += 3) {
        int groupSum = 0;
        
        // Process each bit within the group
        for (int j = 0; j < 3; j++) {
            if (i + j < length) {
                groupSum = groupSum * 2 + (binary[i + j] - '0');
            } else {
                groupSum = groupSum * 2; // Padding with 0
            }
        }
        printf("%d", groupSum);
    }
    printf("\n");
}

int main() {
    char binary[100];
    printf("Enter The Binary Number: ");
    scanf("%s", binary);
    binaryToOctal(binary);
    return 0;
}
