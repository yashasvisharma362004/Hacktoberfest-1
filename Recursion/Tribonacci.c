#include <stdio.h>

/*
 * Function: printTribonacci
 * ------------------------
 * Prints the first n terms of the Tribonacci sequence.
 * The Tribonacci sequence starts with 0, 1, 1.
 * Each term afterwards is the sum of the previous three terms.
 *
 * n: number of terms to print
 *
 * Example usage:
 * printTribonacci(6);   // Output: 0 1 1 2 4 7
 */
void printTribonacci(int n) {
    // Handle edge cases where n is less than 1
    if (n < 1)
        return;

    // Initialize the first three terms
    int t0 = 0, t1 = 1, t2 = 1;

    // Print the terms one by one
    for (int i = 0; i < n; i++) {
        if (i == 0)
            printf("%d ", t0);  // First term
        else if (i == 1)
            printf("%d ", t1);  // Second term
        else if (i == 2)
            printf("%d ", t2);  // Third term
        else {
            // For i >= 3, next term is the sum of previous three
            int t_next = t0 + t1 + t2;
            printf("%d ", t_next);

            // Update the previous three terms for next iteration
            t0 = t1;
            t1 = t2;
            t2 = t_next;
        }
    }
    printf("\n"); // End with a newline
}

int main() {
    int num_terms = 10; // Change this for more/fewer terms
    printf("Tribonacci series up to %d terms:\n", num_terms);
    printTribonacci(num_terms);
    // Working example:
    printf("Example (first 6 Tribonacci terms):\n");
    printTribonacci(6); // Output: 0 1 1 2 4 7
    return 0;
}
