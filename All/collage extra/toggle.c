#include <stdio.h>

int main() {
    char str[100];
    int i = 0;

    // Input the string
    printf("Enter a string: ");
    gets(str);  // Use fgets for safer input in real programs.

    // Toggle each character
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;  // Convert uppercase to lowercase
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;  // Convert lowercase to uppercase
        }
        i++;
    }

    // Print the toggled string
    printf("Toggled string: %s\n", str);

    return 0;
}
