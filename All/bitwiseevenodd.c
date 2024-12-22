#include<stdio.h>

int main() {
    int num;

    // Input from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the number is even or odd using bitwise AND
    if (num & 1) {
        printf("%d is Odd\n", num);
    } else {
        printf("%d is Even\n", num);
    }

    return 0;
}
