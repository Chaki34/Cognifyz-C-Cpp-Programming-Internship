
#include <stdio.h>

int main(void) {

    int numberOfSubjects;
    float marks, totalMarks = 0.0;
    float average, percentage;

    printf("========================================\n");
    printf("        STUDENT GRADE CALCULATOR\n");
    printf("========================================\n");

    // Ask for the number of subjects
    printf("Enter the number of subjects (1-10): ");

    if (scanf("%d", &numberOfSubjects) != 1 ||
        numberOfSubjects < 1 || numberOfSubjects > 10) {

        printf("Invalid number of subjects!\n");
        return 1;
    }

    // Accept marks for each subject
    for (int i = 1; i <= numberOfSubjects; i++) {

        printf("Enter marks for Subject %d (0-100): ", i);

        if (scanf("%f", &marks) != 1 ||
            marks < 0 || marks > 100) {

            printf("Invalid marks! Please enter marks between 0 and 100.\n");
            return 1;
        }

        totalMarks += marks;
    }

    // Calculate average and percentage
    average = totalMarks / numberOfSubjects;

    percentage = (totalMarks /
                 (numberOfSubjects * 100.0)) * 100.0;

    // Display result
    printf("\n========================================\n");
    printf("             RESULT SUMMARY\n");
    printf("========================================\n");

    printf("Total Subjects : %d\n", numberOfSubjects);
    printf("Total Marks    : %.2f / %.2f\n",
           totalMarks, numberOfSubjects * 100.0);

    printf("Average Marks  : %.2f\n", average);
    printf("Percentage     : %.2f%%\n", percentage);

    // Determine the grade
    printf("Final Grade    : ");

    if (average >= 90) {
        printf("A+\n");
    }
    else if (average >= 80) {
        printf("A\n");
    }
    else if (average >= 70) {
        printf("B\n");
    }
    else if (average >= 60) {
        printf("C\n");
    }
    else if (average >= 50) {
        printf("D\n");
    }
    else if (average >= 40) {
        printf("E\n");
    }
    else {
        printf("F (Fail)\n");
    }

    printf("========================================\n");

    return 0;
}
