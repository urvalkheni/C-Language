#include <stdio.h>

int main() {
    char str[100];
    int length = 0;

    // Input the string
    printf("Enter a string: ");
    gets(str);  // Note: Use fgets() for safer input in real programs.

    // Calculate length manually
    while (str[length] != '\0') {
        length++;
    }

    // Print the length
    printf("The length of the string is: %d\n", length);

    return 0;
}
