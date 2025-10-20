/*
 * =====================================================================================
 *
 * Program:  Leap Year Checker
 *
 * Problem Statement:
 * A utility to determine if a given year is a leap year according to
 * the Gregorian calendar rules.
 *
 * Rules:
 * 1. A year is a leap year if it is divisible by 4.
 * 2. EXCEPT if it is divisible by 100, then it is NOT a leap year.
 * 3. UNLESS it is also divisible by 400, then it IS a leap year.
 *
 * Complexity: O(1)
 *
 * Example Run 1 (Divisible by 400):
 * Input:  Enter a year: 2000
 * Output: 2000 is a leap year.
 *
 * Example Run 2 (Divisible by 100 but not 400):
 * Input:  Enter a year: 1900
 * Output: 1900 is not a leap year.
 *
 * Example Run 3 (Divisible by 4 but not 100):
 * Input:  Enter a year: 2024
 * Output: 2024 is a leap year.
 *
 * Example Run 4 (Not divisible by 4):
 * Input:  Enter a year: 2023
 * Output: 2023 is not a leap year.
 *
 * =====================================================================================
 */

#include <stdio.h> // For standard input/output functions

int main(void) {
    int year;

    // --- Get User Input ---
    printf("Enter a year: ");
    scanf("%d", &year);

    // --- Perform Logic Check ---
    
    // This single line implements all three rules:
    // (Divisible by 4 AND not by 100) OR (Divisible by 400)
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        // --- Display Result (Leap Year) ---
        printf("%d is a leap year.\n", year);
    } else {
        // --- Display Result (Not a Leap Year) ---
        printf("%d is not a leap year.\n", year);
    }

    return 0; // Indicate successful execution
}