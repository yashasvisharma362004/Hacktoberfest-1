/*
Program Name: Segment Tree Implementation
Problem Statement: a Segment Tree for range sum queries and perform point updates.

Input Example:
Enter size of array: 6
Enter array elements: 1 3 5 7 9 11

Sample Output:
Sum of values in range [1, 3]: 15
After updating index 1 to 10:
New sum of values in range [1, 3]: 22
*/

#include <stdio.h>
#include <math.h>

#define MAX 1000

int segTree[4 * MAX]; // Segment Tree array
int arr[MAX];         // Input 
int n;                // Size

// build the segment tree
void buildTree(int index, int start, int end) {
    if (start == end) {
        segTree[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(2 * index + 1, start, mid);
    buildTree(2 * index + 2, mid + 1, end);
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
}

// range sum query
int query(int index, int start, int end, int l, int r) {
    // If segment is outside the range
    if (r < start || end < l)
        return 0;
    // If segment is inside the range
    if (l <= start && end <= r)
        return segTree[index];
    // Partial overlap 
    int mid = (start + end) / 2;
    int leftSum = query(2 * index + 1, start, mid, l, r);
    int rightSum = query(2 * index + 2, mid + 1, end, l, r);
    return leftSum + rightSum;
}

// update a value
void update(int index, int start, int end, int pos, int newValue) {
    if (start == end) {
        arr[pos] = newValue;
        segTree[index] = newValue;
        return;
    }
    int mid = (start + end) / 2;
    if (pos <= mid)
        update(2 * index + 1, start, mid, pos, newValue);
    else
        update(2 * index + 2, mid + 1, end, pos, newValue);

    // Recalculate 
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
}

int main() {
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    buildTree(0, 0, n - 1);

    int l = 1, r = 3; // example 
    printf("Sum of values in range [%d, %d]: %d\n", l, r, query(0, 0, n - 1, l, r));

    // Example 
    printf("After updating index 1 to 10:\n");
    update(0, 0, n - 1, 1, 10);

    printf("New sum of values in range [%d, %d]: %d\n", l, r, query(0, 0, n - 1, l, r));

    return 0;
}
