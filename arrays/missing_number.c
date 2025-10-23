/*
Program Name: Missing Number in Array
Problem Statement:
Given an array containing n-1 distinct numbers from 1 to n, find the missing number.

Example:
Input:
Enter number of elements (n-1): 7
Enter the array elements: 1 2 4 6 3 7 8
Output:
The missing number is: 5

Approach:
Use the mathematical sum formula for the first n natural numbers:
    Sum = n * (n + 1) / 2
Subtract the sum of array elements from this total to find the missing number.

Time Complexity: O(n)
Space Complexity: O(1)

Compilation Command:
gcc missing_number.c -o missing_number
Run:
./missing_number
*/

#include <stdio.h>

int main() {
    int n_minus_one;

    printf("Enter number of elements (n-1): ");
    scanf("%d", &n_minus_one);

    int arr[n_minus_one];
    printf("Enter the array elements: ");
    for (int i = 0; i < n_minus_one; i++) {
        scanf("%d", &arr[i]);
    }

    int n = n_minus_one + 1;
    int total_sum = n * (n + 1) / 2;
    int array_sum = 0;

    for (int i = 0; i < n_minus_one; i++) {
        array_sum += arr[i];
    }

    int missing = total_sum - array_sum;
    printf("The missing number is: %d\n", missing);

    return 0;
}
