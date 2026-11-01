#include <stdio.h>
#include <limits.h>

// Function declarations
void displayHeader(void);
void generateFibonacci(int terms);

int main(void) {

    int terms;

    displayHeader();

    // Accept input from the user
    printf("Enter the number of terms: ");

    if (scanf("%d", &terms) != 1) {
        printf("\nError: Invalid input! Please enter an integer.\n");
        return 1;
    }

    // Validate the number of terms
    if (terms <= 0) {
        printf("\nError: Number of terms must be greater than zero.\n");
        return 1;
    }

    if (terms > 94) {
        printf("\nError: Maximum supported terms are 94.\n");
        return 1;
    }

    // Generate the Fibonacci series
    generateFibonacci(terms);

    printf("\n========================================\n");
    printf("       PROGRAM EXECUTED SUCCESSFULLY    \n");
    printf("========================================\n");

    return 0;
}

// Function to display the program header
void displayHeader(void) {

    printf("\n");
    printf("========================================\n");
    printf("          FIBONACCI SERIES GENERATOR    \n");
    printf("========================================\n");
}

// Function to generate Fibonacci numbers
void generateFibonacci(int terms) {

    unsigned long long first = 0;
    unsigned long long second = 1;
    unsigned long long next;

    printf("\nFibonacci Series (%d terms):\n\n", terms);

    for (int i = 1; i <= terms; i++) {

        // Display the current term
        printf("%llu", first);

        if (i < terms) {
            printf("  ");
        }

        // Calculate the next Fibonacci number
        if (i < terms) {

            // Prevent unsigned integer overflow
            if (ULLONG_MAX - second < first) {
                printf("\n\nError: Integer overflow detected.\n");
                return;
            }

            next = first + second;

            first = second;
            second = next;
        }
    }

    printf("\n");
}
