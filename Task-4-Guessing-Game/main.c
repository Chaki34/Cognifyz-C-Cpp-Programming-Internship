
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100

// Function declarations
void displayHeader(void);
void playGame(void);
int getValidGuess(void);

int main(void) {

    int playAgain;

    // Initialize random number generator
    srand((unsigned int)time(NULL));

    displayHeader();

    do {
        playGame();

        printf("\nDo you want to play again? (1 = Yes, 0 = No): ");

        if (scanf("%d", &playAgain) != 1) {
            printf("\nInvalid input. Exiting game.\n");
            break;
        }

        if (playAgain != 0 && playAgain != 1) {
            printf("\nInvalid choice. Exiting game.\n");
            break;
        }

    } while (playAgain == 1);

    printf("\nThank you for playing!\n");
    printf("========================================\n");

    return 0;
}

// Display game header
void displayHeader(void) {

    printf("\n");
    printf("========================================\n");
    printf("          NUMBER GUESSING GAME          \n");
    printf("========================================\n");
    printf("Guess a number between %d and %d.\n",
           MIN_NUMBER, MAX_NUMBER);
    printf("========================================\n");
}

// Get and validate user input
int getValidGuess(void) {

    int guess;

    while (1) {

        printf("\nEnter your guess: ");

        if (scanf("%d", &guess) != 1) {

            printf("Error: Please enter a valid integer.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            continue;
        }

        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {

            printf("Error: Enter a number between %d and %d.\n",
                   MIN_NUMBER, MAX_NUMBER);

            continue;
        }

        return guess;
    }
}

// Main game logic
void playGame(void) {

    int randomNumber;
    int guess;
    int attempts = 0;

    // Generate random number
    randomNumber = rand() % MAX_NUMBER + MIN_NUMBER;

    printf("\nA new game has started!\n");

    while (1) {

        guess = getValidGuess();
        attempts++;

        if (guess > randomNumber) {

            printf("Too High! Try a lower number.");

        } else if (guess < randomNumber) {

            printf("Too Low! Try a higher number.");

        } else {

            printf("\n\nCongratulations! You guessed correctly.\n");
            printf("The correct number was: %d\n", randomNumber);
            printf("Total attempts: %d\n", attempts);

            break;
        }
    }
}
