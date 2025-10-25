#include <stdio.h>
#include <limits.h>


void kadane(int arr[], int n) {
    int max_so_far = INT_MIN;   // Holds the maximum sum found so far
    int max_ending_here = 0;    // Holds the current subarray sum
    int start = 0, end = 0, s = 0; // To track start and end indices of the subarray

    for (int i = 0; i < n; i++) {
        max_ending_here += arr[i];

        // Update max_so_far if we found a new maximum
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        // If current sum becomes negative, reset it and move the start index
        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    printf("\nMaximum Subarray Sum = %d\n", max_so_far);
    printf("Subarray indices: %d to %d\n", start, end);
    printf("Subarray elements: ");
    for (int i = start; i <= end; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    kadane(arr, n);

    return 0;
}
