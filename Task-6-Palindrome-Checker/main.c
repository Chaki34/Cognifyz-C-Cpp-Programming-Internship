
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str[200];
    int left, right;
    int isPalindrome = 1;

    printf("====================================\n");
    printf("       PALINDROME CHECKER IN C\n");
    printf("====================================\n");

    printf("Enter a word or sentence: ");

    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error: Unable to read input.\n");
        return 1;
    }

    // Remove the newline character
    str[strcspn(str, "\n")] = '\0';

    left = 0;
    right = (int)strlen(str) - 1;

    // Compare characters from both ends
    while (left < right) {

        // Ignore spaces and punctuation
        if (!isalnum((unsigned char)str[left])) {
            left++;
            continue;
        }

        if (!isalnum((unsigned char)str[right])) {
            right--;
            continue;
        }

        // Compare characters without case sensitivity
        if (tolower((unsigned char)str[left]) !=
            tolower((unsigned char)str[right])) {
            isPalindrome = 0;
            break;
        }

        left++;
        right--;
    }

    printf("\n------------------------------------\n");

    if (isPalindrome) {
        printf("Result: The input is a PALINDROME.\n");
    } else {
        printf("Result: The input is NOT a PALINDROME.\n");
    }

    printf("------------------------------------\n");

    return 0;
}
