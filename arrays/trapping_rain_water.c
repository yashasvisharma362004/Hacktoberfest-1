/*
Program: Trapping Rain Water
Problem: Calculate total trapped water given an elevation map.
Approach: Two-pointer method.
Input: [4,2,0,3,2,5]
Output: 9
Complexity: O(n)
*/

#include <stdio.h>

int trap(int height[], int n) {
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0, water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];
            right--;
        }
    }
    return water;
}

int main() {
    int arr[] = {4, 2, 0, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Trapped water: %d\n", trap(arr, n));
    return 0;
}
