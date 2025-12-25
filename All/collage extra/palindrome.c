#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a number is palindrome
int isNumberPalindrome(int num) {
    int original = num;
    int reversed = 0;
    
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    return original == reversed;
}

// Function to check if a string is palindrome
int isStringPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(str[left]))
            left++;
        while (left < right && !isalnum(str[right]))
            right--;
        
        // Compare characters (case insensitive)
        if (tolower(str[left]) != tolower(str[right]))
            return 0;
        
        left++;
        right--;
    }
    
    return 1;
}

int main() {
    int choice;
    
    printf("=== Palindrome Checker ===\n\n");
    printf("1. Check Number Palindrome\n");
    printf("2. Check String Palindrome\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        
        if (isNumberPalindrome(num))
            printf("\n%d is a Palindrome!\n", num);
        else
            printf("\n%d is NOT a Palindrome.\n", num);
    }
    else if (choice == 2) {
        char str[100];
        printf("Enter a string: ");
        scanf(" %[^\n]", str);
        
        if (isStringPalindrome(str))
            printf("\n\"%s\" is a Palindrome!\n", str);
        else
            printf("\n\"%s\" is NOT a Palindrome.\n", str);
    }
    else {
        printf("Invalid choice!\n");
    }
    
    return 0;
}
