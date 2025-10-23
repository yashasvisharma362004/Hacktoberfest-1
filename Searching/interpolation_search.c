#include <stdio.h>

// Interpolation Search improves on Binary Search by predicting where the element might be, using the distribution of data.
// Complexity:
// Average: O(log log n)
// Worst: O(n)
// Space: O(1)

// Interpolation Search function
int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Avoid division by zero
        if (arr[high] == arr[low])
            break;

        // Estimate position using interpolation formula
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        // Check if target is found
        if (arr[pos] == target)
            return pos;

        // If target is larger, target is in upper part
        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 50;

    int result = interpolationSearch(arr, n, target);
    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
