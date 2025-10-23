#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY 5  // constant key value

void encrypt(char text[]) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isupper(ch)) {
            int P = ch - 'A' + 1; // convert A-Z -> 1-26
            int C = (P + KEY - 1) % 26 + 1;
            text[i] = 'A' + (C - 1);
        } 
        else if (islower(ch)) {
            int P = ch - 'a' + 1; // convert a-z -> 1-26
            int C = (P + KEY - 1) % 26 + 1;
            text[i] = 'a' + (C - 1);
        }
        // Non-alphabetic characters remain unchanged
    }
}

void decrypt(char text[]) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isupper(ch)) {
            int C = ch - 'A' + 1;
            int P = (C - KEY + 25) % 26 + 1;
            text[i] = 'A' + (P - 1);
        } 
        else if (islower(ch)) {
            int C = ch - 'a' + 1;
            int P = (C - KEY + 25) % 26 + 1;
            text[i] = 'a' + (P - 1);
        }
    }
}

int main() {
    int choice;
    char text[100];

    do {
        printf("\n=== Encryption / Decryption Menu ===\n");
        printf("1. Encrypt Text\n");
        printf("2. Decrypt Text\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter text to Encrypt: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0'; // remove newline
                encrypt(text);
                printf("Encrypted Text: %s\n", text);
                break;

            case 2:
                printf("Enter text to Decrypt: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                decrypt(text);
                printf("Decrypted Text: %s\n", text);
                break;

            case 0:
                printf("Exiting... Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}
