/*
 * =====================================================================================
 *
 * Program:  Bill Split Calculator
 *
 * Problem Statement:
 * A utility to calculate the total bill including a tip and then split it
 * equally among a specified number of people.
 * Localized for Indian Rupees (Rs.).
 *
 * Complexity: O(1)
 *
 * Example Run (Input/Output):
 *
 * Input:
 * Enter total bill amount (in Rs.): 2500
 * Enter tip percentage (e.g., 10 for 10%): 10
 * Enter number of people: 5
 *
 * Output:
 *
 * --- Bill Summary ---
 * Base Bill:      Rs. 2500.00
 * Tip (10%):      Rs. 250.00
 * --------------------------
 * Grand Total:    Rs. 2750.00
 *
 * Each person should pay: Rs. 550.00
 *
 * =====================================================================================
 */

#include <stdio.h> // For standard input/output functions

int main(void) {
    // Use 'double' for currency and 'int' for counts
    double bill_amount;
    int tip_percentage;
    int num_people;

    // --- Get User Input ---
    printf("Enter total bill amount (in Rs.): ");
    scanf("%lf", &bill_amount);

    printf("Enter tip percentage (e.g., 10 for 10%%): ");
    scanf("%d", &tip_percentage);

    printf("Enter number of people: ");
    scanf("%d", &num_people);

    // --- Validate Input ---
    // A simple check to prevent division by zero or negative numbers.
    if (num_people <= 0) {
        printf("\nError: Number of people must be a positive number.\n");
        return 1; // Exit with a non-zero status to indicate an error
    }

    // --- Perform Calculations ---
    double tip_amount = bill_amount * (tip_percentage / 100.0);
    double total_bill = bill_amount + tip_amount;
    double amount_per_person = total_bill / num_people;

    // --- Display Results ---
    printf("\n--- Bill Summary ---\n");
    printf("Base Bill:      Rs. %.2f\n", bill_amount);
    printf("Tip (%d%%):      Rs. %.2f\n", tip_percentage, tip_amount);
    printf("--------------------------\n");
    printf("Grand Total:    Rs. %.2f\n\n", total_bill);

    printf("Each person should pay: Rs. %.2f\n", amount_per_person);

    return 0; // Indicate successful execution
}