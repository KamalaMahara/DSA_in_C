//Student Marks Calculator using malloc()
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float *marks, sum = 0, average;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for n students' marks
    marks = (float*) malloc(n * sizeof(float));

    // Check if malloc() returned NULL
    if (marks == NULL) {
        printf("Memory allocation failed! Exiting.\n");
        return 1;  // Exit the program
    }

    // Taking input for marks
    for (int i = 0; i < n; i++) {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%f", &marks[i]);
        sum += marks[i];
    }

    // Calculating average
    average = sum / n;
    printf("\nThe average marks of %d students is: %.2f\n", n, average);

    // Freeing allocated memory
    free(marks);

    return 0;
}
