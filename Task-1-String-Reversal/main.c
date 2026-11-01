
#include <stdio.h>
#include <string.h>

int main() {

    char str[1000];
    int length;

    // Take input from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character
    str[strcspn(str, "\n")] = '\0';

    // Calculate the length of the string
    length = strlen(str);

    // Reverse the string
    printf("Reversed string: ");

    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");

    return 0;
}
