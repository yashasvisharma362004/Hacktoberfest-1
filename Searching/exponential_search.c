#include <stdio.h>

// Exponential Search is an algorithm for searching sorted arrays.
// It works by finding a range where the element may exist, 
// then performing a Binary Search within that range.
//
// Complexity:
// Time: O(log n)
// Space: O(1)

// Function to perform Binary Search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is at mid
        if (arr[mid] == target)
            return mid;

        // If target greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Element not found
}

// Function to perform Exponential Search
int exponentialSearch(int arr[], int n, int target) {
    // If target is the first element
    if (arr[0] == target)
        return 0;

    // Find range for binary search by repeated doubling
    int i = 1;
    while (i < n && arr[i] <= target)
        i *= 2;

    // Perform binary search between i/2 and min(i, n-1)
    int left = i / 2;
    int right = (i < n) ? i : n - 1;

    return binarySearch(arr, left, right, target);
}

// Main function to test Exponential Search
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 18, 21, 24, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 18;

    int result = exponentialSearch(arr, n, target);
    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
