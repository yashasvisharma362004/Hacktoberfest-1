#include <stdio.h>

int maxWater(int arr[], int n) {
    int left[n], right[n];
    int res = 0;

    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = (arr[i] > left[i - 1]) ? arr[i] : left[i - 1];

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = (arr[i] > right[i + 1]) ? arr[i] : right[i + 1];

    for (int i = 0; i < n; i++) {
        int water = (left[i] < right[i] ? left[i] : right[i]) - arr[i];
        res += (water > 0) ? water : 0;
    }

    return res;
}

int main() {
    int arr[] = {2, 1, 5, 3, 1, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", maxWater(arr, n));
    return 0;
}
