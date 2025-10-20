/*
 * =====================================================================================
 *
 * Program:  Simple Age Calculator
 *
 * Problem Statement:
 * A simple utility to calculate a user's approximate age based on their
 * provided birth year and the current year.
 *
 * Complexity: O(1)
 *
 * Example Run (Input/Output):
 *
 * Input:
 * Enter your birth year: 1999
 * Enter the current year: 2025
 *
 * Output:
 *
 * You are approximately 26 years old.
 *
 * =====================================================================================
 */

#include <stdio.h> // For standard input/output functions

int main(void) {
    // Use integers for years
    int birth_year;
    int current_year;

    // --- Get User Input ---
    printf("Enter your birth year: ");
    scanf("%d", &birth_year);

    printf("Enter the current year: ");
    scanf("%d", &current_year);

    // --- Validate Input and Perform Calculation ---
    if (current_year < birth_year) {
        // Add a simple check for invalid input
        printf("\nError: The current year cannot be before the birth year.\n");
    } else {
        int age = current_year - birth_year;

        // --- Display Result ---
        printf("\n"); // Add a newline for clean formatting
        printf("You are approximately %d years old.\n", age);
    }

    return 0; // Indicate successful execution
}