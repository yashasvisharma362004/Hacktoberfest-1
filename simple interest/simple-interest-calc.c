/*
 * =====================================================================================
 *
 * Program:  Simple Interest Calculator
 *
 * Problem Statement:
 * A utility to calculate simple interest and the total amount based on
 * user-provided principal, annual interest rate, and time in years.
 * Localized for Indian Rupees (Rs.).
 *
 * Formula:
 * Simple Interest = (Principal * Rate * Time) / 100
 *
 * Complexity: O(1)
 *
 * Example Run (Input/Output):
 *
 * Input:
 * Enter principal amount (in Rs.): 10000
 * Enter annual interest rate (e.g., 5 for 5%): 5
 * Enter time period in years: 2
 *
 * Output:
 *
 * Principal:      Rs. 10000.00
 * Interest Rate:  5.0%
 * Time:           2.0 years
 * ---------------------------
 * Simple Interest: Rs. 1000.00
 * Total Amount:    Rs. 11000.00
 *
 * =====================================================================================
 */

#include <stdio.h> // For standard input/output functions

int main(void) {
    // Use 'double' for precision with currency and rates
    double principal;
    double rate;
    double time;
    
    // --- Get User Input ---
    printf("Enter principal amount (in Rs.): ");
    scanf("%lf", &principal);
    
    printf("Enter annual interest rate (e.g., 5 for 5%%): ");
    scanf("%lf", &rate);
    
    printf("Enter time period in years: ");
    scanf("%lf", &time);
    
    // --- Perform Calculations ---
    double interest = (principal * rate * time) / 100.0;
    double total_amount = principal + interest;
    
    // --- Display Results ---
    printf("\n"); // Add a newline for clean formatting
    printf("Principal:      Rs. %.2f\n", principal);
    printf("Interest Rate:  %.1f%%\n", rate); // Use %% to print a single '%'
    printf("Time:           %.1f years\n", time);
    printf("---------------------------\n");
    printf("Simple Interest: Rs. %.2f\n", interest);
    printf("Total Amount:    Rs. %.2f\n", total_amount);
    
    return 0; // Indicate successful execution
}