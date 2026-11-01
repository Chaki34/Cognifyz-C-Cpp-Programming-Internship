
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    int userChoice, computerChoice;
    int userScore = 0, computerScore = 0;
    char playAgain;

    // Initialize random number generator
    srand((unsigned int)time(NULL));

    printf("========================================\n");
    printf("       ROCK PAPER SCISSORS GAME\n");
    printf("========================================\n");

    do {

        printf("\nChoose your option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");

        printf("\nEnter your choice (1-3): ");

        if (scanf("%d", &userChoice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            return 1;
        }

        if (userChoice < 1 || userChoice > 3) {
            printf("Invalid choice! Please select 1, 2, or 3.\n");
            continue;
        }

        // Generate computer's random choice
        computerChoice = (rand() % 3) + 1;

        printf("\nYou selected: ");

        switch (userChoice) {
            case 1:
                printf("Rock\n");
                break;
            case 2:
                printf("Paper\n");
                break;
            case 3:
                printf("Scissors\n");
                break;
        }

        printf("Computer selected: ");

        switch (computerChoice) {
            case 1:
                printf("Rock\n");
                break;
            case 2:
                printf("Paper\n");
                break;
            case 3:
                printf("Scissors\n");
                break;
        }

        // Determine the winner
        if (userChoice == computerChoice) {

            printf("\nResult: It's a DRAW!\n");

        }
        else if ((userChoice == 1 && computerChoice == 3) ||
                 (userChoice == 2 && computerChoice == 1) ||
                 (userChoice == 3 && computerChoice == 2)) {

            printf("\nResult: YOU WIN!\n");
            userScore++;

        }
        else {

            printf("\nResult: COMPUTER WINS!\n");
            computerScore++;

        }

        // Display scores
        printf("\n----------- SCOREBOARD -----------\n");
        printf("Your Score     : %d\n", userScore);
        printf("Computer Score : %d\n", computerScore);
        printf("----------------------------------\n");

        // Ask whether to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\n========================================\n");
    printf("              FINAL RESULT\n");
    printf("========================================\n");

    printf("Your Final Score     : %d\n", userScore);
    printf("Computer Final Score : %d\n", computerScore);

    if (userScore > computerScore) {
        printf("\nCongratulations! You won the game!\n");
    }
    else if (userScore < computerScore) {
        printf("\nComputer won the game. Better luck next time!\n");
    }
    else {
        printf("\nThe game ended in a draw!\n");
    }

    printf("\nThank you for playing!\n");
    printf("========================================\n");

    return 0;
}
