#include <stdio.h>
#include <stdlib.h>

// Function to create a Fenwick Tree (BIT) of given size
int* createFenwickTree(int n) {
    int* BIT = (int*)calloc(n + 1, sizeof(int)); // 1-indexed tree
    return BIT;
}

// Function to update the BIT at a given index by a given value
void updateBIT(int* BIT, int n, int index, int value) {
    // Fenwick tree is 1-indexed
    for (; index <= n; index += index & (-index))
        BIT[index] += value;
}

// Function to get prefix sum up to a given index
int getPrefixSum(int* BIT, int index) {
    int sum = 0;
    for (; index > 0; index -= index & (-index))
        sum += BIT[index];
    return sum;
}

// Function to get the sum of elements in a given range [l, r]
int getRangeSum(int* BIT, int l, int r) {
    return getPrefixSum(BIT, r) - getPrefixSum(BIT, l - 1);
}

// Function to build the Fenwick Tree from an input array
void buildBIT(int* BIT, int* arr, int n) {
    for (int i = 1; i <= n; i++)
        updateBIT(BIT, n, i, arr[i - 1]);
}


int main() {
    int arr[] = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* BIT = createFenwickTree(n);
    buildBIT(BIT, arr, n);

    printf("Prefix sum up to index 5: %d\n", getPrefixSum(BIT, 5));
    printf("Sum of range [3, 7]: %d\n", getRangeSum(BIT, 3, 7));

    printf("Updating index 4 by +2\n");
    updateBIT(BIT, n, 4, 2);

    printf("Prefix sum up to index 5 after update: %d\n", getPrefixSum(BIT, 5));

    free(BIT);
    return 0;
}
