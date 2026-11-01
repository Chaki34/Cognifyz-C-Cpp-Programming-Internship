
#include <stdio.h>

int main(void) {

    int arr[100];
    int n, temp;

    printf("========================================\n");
    printf("          ARRAY SORTING PROGRAM\n");
    printf("========================================\n");

    // Get the number of elements
    printf("Enter the number of elements (1-100): ");

    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        printf("Invalid input! Enter a number between 1 and 100.\n");
        return 1;
    }

    // Accept array elements
    printf("\nEnter %d elements:\n", n);

    for (int i = 0; i < n; i++) {

        printf("Element %d: ", i + 1);

        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input! Please enter integers only.\n");
            return 1;
        }
    }

    // Display original array
    printf("\nOriginal Array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Bubble Sort in ascending order
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display sorted array
    printf("\n\nSorted Array (Ascending Order): ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\n========================================\n");
    printf("       ARRAY SORTING COMPLETED\n");
    printf("========================================\n");

    return 0;
}
