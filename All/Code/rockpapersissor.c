#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame() {
    char *choices[] = {"Rock", "Paper", "Scissors"};
    int userChoice, computerChoice;

    printf("Welcome to Rock-Paper-Scissors!\n");
    printf("Choose your option:\n");
    printf("1. Rock\n2. Paper\n3. Scissors\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &userChoice);

    if (userChoice < 1 || userChoice > 3) {
        printf("Invalid choice! Please select 1, 2, or 3.\n");
        return;
    }

    srand(time(0)); // Seed for randomness
    computerChoice = (rand() % 3) + 1;

    printf("\nYou chose: %s\n", choices[userChoice - 1]);
    printf("Computer chose: %s\n\n", choices[computerChoice - 1]);

    if (userChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((userChoice == 1 && computerChoice == 3) || 
               (userChoice == 2 && computerChoice == 1) || 
               (userChoice == 3 && computerChoice == 2)) {
        printf("Congratulations! You win!\n");
    } else {
        printf("Oops! You lose. Better luck next time!\n");
    }
}

int main() {
    playGame();
    return 0;
}
