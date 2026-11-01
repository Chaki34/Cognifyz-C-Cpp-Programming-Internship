
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50
#define INPUT_LENGTH 256

// Structure to store item details
struct Item {
    int id;
    char name[NAME_LENGTH];
    int quantity;
};

// Function declarations
int readInteger(const char *prompt, int min, int max, int *value);
int readItemName(char *name, int size);
int findItemById(struct Item items[], int count, int id);
int addItem(struct Item items[], int *count);
void displayItems(struct Item items[], int count);
void searchById(struct Item items[], int count);
void searchByName(struct Item items[], int count);
int equalsIgnoreCase(const char *a, const char *b);

// Read and validate an integer
int readInteger(const char *prompt, int min, int max, int *value) {
    char input[INPUT_LENGTH];
    char *end;
    long number;

    while (1) {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            return 0;
        }

        if (strchr(input, '\n') == NULL && !feof(stdin)) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                // Clear remaining input
            }
            printf("Input is too long. Try again.\n");
            continue;
        }

        errno = 0;
        number = strtol(input, &end, 10);

        while (isspace((unsigned char)*end)) {
            end++;
        }

        if (end == input || *end != '\0' ||
            errno == ERANGE || number < min || number > max) {
            printf("Invalid input! Enter a number between %d and %d.\n",
                   min, max);
            continue;
        }

        *value = (int)number;
        return 1;
    }
}

// Read and validate an item name
int readItemName(char *name, int size) {
    char input[INPUT_LENGTH];
    char *start;
    size_t length;

    while (1) {
        printf("Enter item name: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            return 0;
        }

        if (strchr(input, '\n') == NULL && !feof(stdin)) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                // Clear remaining input
            }
            printf("Name is too long. Try again.\n");
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        // Remove leading spaces
        start = input;
        while (isspace((unsigned char)*start)) {
            start++;
        }

        // Remove trailing spaces
        length = strlen(start);
        while (length > 0 &&
               isspace((unsigned char)start[length - 1])) {
            start[--length] = '\0';
        }

        if (length == 0) {
            printf("Item name cannot be empty.\n");
            continue;
        }

        if (length >= (size_t)size) {
            printf("Item name must be shorter than %d characters.\n",
                   size);
            continue;
        }

        strcpy(name, start);
        return 1;
    }
}

// Find an item using its ID
int findItemById(struct Item items[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            return i;
        }
    }

    return -1;
}

// Compare two strings without case sensitivity
int equalsIgnoreCase(const char *a, const char *b) {
    while (*a && *b) {
        if (tolower((unsigned char)*a) !=
            tolower((unsigned char)*b)) {
            return 0;
        }

        a++;
        b++;
    }

    return *a == '\0' && *b == '\0';
}

// Add a new item
int addItem(struct Item items[], int *count) {
    int id, quantity;

    if (*count >= MAX_ITEMS) {
        printf("\nInventory is full! Cannot add more items.\n");
        return 1;
    }

    printf("\n========== ADD NEW ITEM ==========\n");

    if (!readInteger("Enter item ID: ", 1, INT_MAX, &id)) {
        return 0;
    }

    if (findItemById(items, *count, id) != -1) {
        printf("An item with this ID already exists!\n");
        return 1;
    }

    if (!readItemName(items[*count].name, NAME_LENGTH)) {
        return 0;
    }

    if (!readInteger("Enter item quantity: ", 0, INT_MAX, &quantity)) {
        return 0;
    }

    items[*count].id = id;
    items[*count].quantity = quantity;

    (*count)++;

    printf("\nItem added successfully!\n");

    return 1;
}

// Display all inventory items
void displayItems(struct Item items[], int count) {
    printf("\n========== INVENTORY LIST ==========\n");

    if (count == 0) {
        printf("Inventory is currently empty.\n");
        return;
    }

    printf("%-10s %-25s %-10s\n",
           "Item ID", "Item Name", "Quantity");

    printf("-----------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10d\n",
               items[i].id,
               items[i].name,
               items[i].quantity);
    }

    printf("-----------------------------------------------\n");
    printf("Total different items: %d\n", count);
}

// Search for an item using ID
void searchById(struct Item items[], int count) {
    int id;
    int index;

    printf("\n========== SEARCH BY ID ==========\n");

    if (!readInteger("Enter item ID to search: ", 1, INT_MAX, &id)) {
        return;
    }

    index = findItemById(items, count, id);

    if (index == -1) {
        printf("\nItem not found!\n");
    } else {
        printf("\nItem found successfully!\n");
        printf("Item ID   : %d\n", items[index].id);
        printf("Item Name : %s\n", items[index].name);
        printf("Quantity  : %d\n", items[index].quantity);
    }
}

// Search for an item using its name
void searchByName(struct Item items[], int count) {
    char name[NAME_LENGTH];
    int found = 0;

    printf("\n========== SEARCH BY NAME ==========\n");

    if (!readItemName(name, NAME_LENGTH)) {
        return;
    }

    for (int i = 0; i < count; i++) {
        if (equalsIgnoreCase(items[i].name, name)) {
            printf("\nItem found successfully!\n");
            printf("Item ID   : %d\n", items[i].id);
            printf("Item Name : %s\n", items[i].name);
            printf("Quantity  : %d\n", items[i].quantity);

            found = 1;
        }
    }

    if (!found) {
        printf("\nItem not found!\n");
    }
}

// Main function
int main(void) {
    struct Item items[MAX_ITEMS];
    int count = 0;
    int choice;

    printf("========================================\n");
    printf("   SIMPLE INVENTORY MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    while (1) {
        printf("\n--------------- MAIN MENU ---------------\n");
        printf("1. Add Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Search Item by Name\n");
        printf("5. Exit\n");
        printf("-----------------------------------------\n");

        if (!readInteger("Enter your choice (1-5): ",
                         1, 5, &choice)) {
            printf("\nInput ended. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                if (!addItem(items, &count)) {
                    printf("\nInput ended. Exiting program.\n");
                    return 0;
                }
                break;

            case 2:
                displayItems(items, count);
                break;

            case 3:
                searchById(items, count);
                break;

            case 4:
                searchByName(items, count);
                break;

            case 5:
                printf("\nThank you for using the Inventory System!\n");
                printf("Exiting program...\n");
                return 0;
        }
    }

    return 0;
}
