/*
Program Name: Kadane's Algorithm (Maximum Subarray Sum)
Problem Statement:
Given an array of integers, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

Example:
Input:
Enter number of elements: 8
Enter the elements:
-2 -3 4 -1 -2 1 5 -3

Output:
Maximum Subarray Sum: 7

Explanation:
The subarray [4, -1, -2, 1, 5] has the largest sum = 7.

Approach:
Kadane’s Algorithm (Dynamic Programming)
1. Initialize two variables:
   - max_current = max_global = arr[0]
2. Traverse through the array:
   - max_current = max(arr[i], max_current + arr[i])
   - If max_current > max_global, update max_global
3. Return max_global

Time Complexity: O(n)
Space Complexity: O(1)

Compilation Command:
g++ kadanes_algorithm.cpp -o kadane
Run Command:
./kadane
*/

#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

// Function to find maximum subarray sum using Kadane's Algorithm
int kadaneMaxSum(const vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];

    for (size_t i = 1; i < arr.size(); i++) {
        max_current = max(arr[i], max_current + arr[i]);
        if (max_current > max_global)
            max_global = max_current;
    }
    return max_global;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = kadaneMaxSum(arr);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}
