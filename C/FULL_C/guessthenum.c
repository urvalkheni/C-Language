#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;

    // Seed the random number generator
    srand(time(0));
    number = rand() % 100 + 1; // Generate a random number between 1 and 100

    printf("\nWelcome to the Guess the Number game!\n");
    printf("I have chosen a number between 1 and 100. Can you guess what it is?\n\n");

    // Game loop
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Try again.\n\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != number);

    printf("\nThanks for playing!\n");
    return 0;
}
