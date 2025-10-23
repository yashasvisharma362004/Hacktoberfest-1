/*
 * =====================================================================================
 *
 * Program:  Longest Balanced Substring
 *
 * Problem Statement:
 * Given a lowercase English string s, find the length of the longest substring
 * where all distinct characters appear the same number of times.
 *
 * Approach:
 * - For each substring (i, j), use a frequency map (array of size 26)
 *   to count occurrences of each character.
 * - Check if the substring is "balanced" by verifying if all non-zero
 *   frequencies are equal.
 * - Track the maximum balanced substring length.
 *
 * Time Complexity:  O(n^2 * 26)
 * Space Complexity: O(26)
 *
 * Example Run (Input/Output):
 *
 * Input:
 * Enter string: abbac
 *
 * Output:
 * Longest balanced substring length: 4
 *
 * Explanation:
 * "abba" is the longest balanced substring since 'a' and 'b'
 * both appear exactly 2 times.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

int isBalanced(int freq[26])
{
    int mini = INT_MAX, maxi = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            if (freq[i] < mini)
                mini = freq[i];
            if (freq[i] > maxi)
                maxi = freq[i];
        }
    }
    return mini == maxi;
}

int longestBalanced(char *s)
{
    int n = strlen(s);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int freq[26] = {0};
        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;
            if (isBalanced(freq))
            {
                int len = j - i + 1;
                if (len > ans)
                    ans = len;
            }
        }
    }
    return ans;
}

int main(void)
{
    char s[1005];

    printf("Enter string: ");
    scanf("%s", s);

    int result = longestBalanced(s);
    printf("Longest balanced substring length: %d\n", result);

    return 0;
}
