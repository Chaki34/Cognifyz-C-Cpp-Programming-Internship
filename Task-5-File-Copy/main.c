
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define MAX_FILENAME 256

// Function declarations
void displayHeader(void);
int readFilename(const char *message, char *filename);
int copyFile(const char *source, const char *destination);

int main(void) {

    char source[MAX_FILENAME];
    char destination[MAX_FILENAME];

    displayHeader();

    // Get source filename
    if (!readFilename("Enter source filename: ", source)) {
        printf("\nError: Invalid source filename.\n");
        return 1;
    }

    // Get destination filename
    if (!readFilename("Enter destination filename: ", destination)) {
        printf("\nError: Invalid destination filename.\n");
        return 1;
    }

    // Prevent copying a file onto itself by identical filename
    if (strcmp(source, destination) == 0) {
        printf("\nError: Source and destination filenames "
               "must be different.\n");
        return 1;
    }

    // Perform file copy
    if (copyFile(source, destination)) {
        printf("\n========================================\n");
        printf("          FILE COPIED SUCCESSFULLY      \n");
        printf("========================================\n");
        printf("Source      : %s\n", source);
        printf("Destination : %s\n", destination);
    } else {
        printf("\nFile copying failed. Please check the error.\n");
        return 1;
    }

    return 0;
}

// Display program header
void displayHeader(void) {

    printf("\n");
    printf("========================================\n");
    printf("          FILE COPY SYSTEM              \n");
    printf("========================================\n");
}

// Read and validate filename
int readFilename(const char *message, char *filename) {

    printf("%s", message);

    if (fgets(filename, MAX_FILENAME, stdin) == NULL) {
        return 0;
    }

    // Remove newline character
    char *newline = strchr(filename, '\n');

    if (newline != NULL) {
        *newline = '\0';
    } else {
        // Detect input longer than the buffer
        int ch = getchar();

        if (ch != '\n' && ch != EOF) {
            while ((ch = getchar()) != '\n' && ch != EOF);
            return 0;
        }
    }

    // Reject empty filenames
    if (filename[0] == '\0') {
        return 0;
    }

    return 1;
}

// Copy contents from source to destination
int copyFile(const char *source, const char *destination) {

    FILE *sourceFile;
    FILE *destinationFile;

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    int success = 1;

    // Open source file in binary read mode
    sourceFile = fopen(source, "rb");

    if (sourceFile == NULL) {
        perror("\nError opening source file");
        return 0;
    }

    // Open destination file in binary write mode
    destinationFile = fopen(destination, "wb");

    if (destinationFile == NULL) {
        perror("\nError creating destination file");
        fclose(sourceFile);
        return 0;
    }

    printf("\nCopying file contents...\n");

    // Read and write data in blocks
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE,
                              sourceFile)) > 0) {

        size_t bytesWritten = fwrite(buffer, 1, bytesRead,
                                     destinationFile);

        if (bytesWritten != bytesRead) {
            perror("\nError writing destination file");
            success = 0;
            break;
        }
    }

    // Check for source reading errors
    if (ferror(sourceFile)) {
        perror("\nError reading source file");
        success = 0;
    }

    // Check destination file closing errors
    if (fclose(destinationFile) != 0) {
        perror("\nError closing destination file");
        success = 0;
    }

    // Close source file
    if (fclose(sourceFile) != 0) {
        perror("\nError closing source file");
        success = 0;
    }

    return success;
}
