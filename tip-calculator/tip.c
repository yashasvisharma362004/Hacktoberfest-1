/*
 * =====================================================================================
 *
 * Program:  Tip Calculator (in Rupees)
 *
 * Problem Statement:
 * A simple command-line utility to calculate the tip and total bill
 * based on a user-provided bill amount and tip percentage.
 * This version is localized for Indian Rupees (Rs.).
 *
 * Complexity: O(1) - The calculations are direct and do not depend on input size.
 *
 * Example Run (Input/Output):
 *
 * Input:
 * Enter the bill amount (in Rs.): 1000.00
 * Enter the tip percentage (e.g., 10): 10
 *
 * Output:
 *
 * Bill amount:    Rs. 1000.00
 * Tip percentage: 10%
 * ------------------------
 * Tip amount:     Rs. 100.00
 * Total bill:     Rs. 1100.00
 *
 * =====================================================================================
 */

#include <stdio.h> // For standard input/output functions

int main(void) {
    // Use 'double' for floating-point numbers to handle paisa
    double bill_amount;
    int tip_percentage;

    // --- Get User Input ---
    printf("Enter the bill amount (in Rs.): ");
    // Use %lf format specifier to scan a double
    scanf("%lf", &bill_amount);

    printf("Enter the tip percentage (e.g., 10 for 10%%): ");
    // Use %d format specifier to scan an integer
    scanf("%d", &tip_percentage);

    // --- Perform Calculations ---
    // Note: 100.0 is used to ensure the division is done using floating-point math
    double tip_amount = bill_amount * (tip_percentage / 100.0);
    double total_amount = bill_amount + tip_amount;

    // --- Display Results ---
    printf("\n"); // Add a newline for clean formatting
    printf("Bill amount:    Rs. %.2f\n", bill_amount);
    printf("Tip percentage: %d%%\n", tip_percentage); // Use %% to print a single '%'
    printf("------------------------\n");
    printf("Tip amount:     Rs. %.2f\n", tip_amount);
    printf("Total bill:     Rs. %.2f\n", total_amount);

    return 0; // Indicate successful execution
}