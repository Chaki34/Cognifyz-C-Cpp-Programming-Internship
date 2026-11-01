
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

// Function declarations
void displayMenu(void);
void performCalculation(double num1, double num2, char operator);
int getIntegerInput(const char *message, int *value);

int main(void) {

    double num1, num2;
    char operator;
    int choice;

    printf("\n");
    printf("========================================\n");
    printf("          PROFESSIONAL CALCULATOR       \n");
    printf("========================================\n");

    while (1) {

        displayMenu();

        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nError: Invalid menu input!\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        if (choice < 1 || choice > 5) {
            printf("\nError: Please select a valid option (1-5).\n");
            continue;
        }

        // Clear remaining newline
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        printf("\nEnter first number: ");

        if (scanf("%lf", &num1) != 1) {
            printf("Error: Invalid first number!\n");

            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        printf("Enter second number: ");

        if (scanf("%lf", &num2) != 1) {
            printf("Error: Invalid second number!\n");

            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        // Map menu choice to arithmetic operator
        switch (choice) {
            case 1: operator = '+'; break;
            case 2: operator = '-'; break;
            case 3: operator = '*'; break;
            case 4: operator = '/'; break;
            case 5: operator = '%'; break;
            default: operator = '\0';
        }

        performCalculation(num1, num2, operator);

        printf("\n----------------------------------------\n");

        // Clear any remaining input
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    return 0;
}

void displayMenu(void) {

    printf("\n--------------- MENU ------------------\n");
    printf("1. Addition       (+)\n");
    printf("2. Subtraction    (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division       (/)\n");
    printf("5. Modulus        (%%)\n");
    printf("----------------------------------------\n");
}

void performCalculation(double num1, double num2, char operator) {

    double result;

    switch (operator) {

        case '+':
            result = num1 + num2;
            printf("\nResult: %.2lf\n", result);
            break;

        case '-':
            result = num1 - num2;
            printf("\nResult: %.2lf\n", result);
            break;

        case '*':
            result = num1 * num2;
            printf("\nResult: %.2lf\n", result);
            break;

        case '/':
            if (num2 == 0) {
                printf("\nError: Division by zero is not allowed!\n");
                return;
            }

            result = num1 / num2;
            printf("\nResult: %.2lf\n", result);
            break;

        case '%':
            if (num1 != (int)num1 || num2 != (int)num2) {
                printf("\nError: Modulus requires integer operands!\n");
                return;
            }

            if (num2 == 0) {
                printf("\nError: Modulus by zero is not allowed!\n");
                return;
            }

            if (num1 == INT_MIN && num2 == -1) {
                printf("\nError: Modulus operation overflow!\n");
                return;
            }

            printf("\nResult: %d\n", (int)num1 % (int)num2);
            break;

        default:
            printf("\nError: Unsupported operator!\n");
    }
}
