/*
---------------------------------------------
Program Name: Trapping Rain Water
---------------------------------------------
Problem Statement:
Given an array arr[] of non-negative integers representing elevation map where
the width of each bar is 1, compute how much water it can trap after raining.

---------------------------------------------
Example:
Input:
    arr = [2, 1, 5, 3, 1, 0, 4]
Output:
    9

Explanation:
    Water trapped between bars at different heights totals 9 units.

---------------------------------------------
Algorithm:
1. Compute the maximum height to the left of each element.
2. Compute the maximum height to the right of each element.
3. For each element, the trapped water = min(left_max, right_max) - height.
4. Sum up all trapped water values.

---------------------------------------------
Complexity:
    Time Complexity:  O(n)
    Space Complexity: O(n)
---------------------------------------------
*/


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