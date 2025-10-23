/*
Program Name: Longest Common Prefix (LCP)
Problem Statement:
Given an array of strings, find the longest common prefix among them.
If there is no common prefix, return an empty string.

Example:
Input:
Enter number of strings: 3
Enter the strings:
flower
flow
flight

Output:
Longest Common Prefix: fl

Approach:
1. Take the first string as the initial prefix.
2. Compare the prefix with each string one by one.
3. Trim the prefix until it matches the start of all strings.
4. If the prefix becomes empty, there is no common prefix.

Time Complexity: O(n × m)
    where n = number of strings, m = average string length
Space Complexity: O(1)

Compilation Command:
gcc longest_common_prefix.c -o longest_common_prefix
Run:
./longest_common_prefix
*/

#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

// Function to find the longest common prefix among n strings
void findLongestCommonPrefix(char arr[][MAX_LENGTH], int n) {
    char prefix[MAX_LENGTH];
    strcpy(prefix, arr[0]); // Assume first string as prefix

    for (int i = 1; i < n; i++) {
        int j = 0;
        // Compare prefix with the current string
        while (prefix[j] && arr[i][j] && prefix[j] == arr[i][j]) {
            j++;
        }
        prefix[j] = '\0'; // Truncate non-matching part

        // If prefix becomes empty, no common prefix exists
        if (strlen(prefix) == 0) {
            printf("No common prefix found.\n");
            return;
        }
    }

    printf("Longest Common Prefix: %s\n", prefix);
}

int main() {
    int n;
    char arr[MAX_STRINGS][MAX_LENGTH];

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    findLongestCommonPrefix(arr, n);
    return 0;
}
