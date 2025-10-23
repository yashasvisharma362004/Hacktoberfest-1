#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int>& arr, int K) {
    unordered_map<int, int> prefixSumIndex;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum == K)
            maxLen = i + 1;

        if (prefixSumIndex.find(sum - K) != prefixSumIndex.end())
            maxLen = max(maxLen, i - prefixSumIndex[sum - K]);

        if (prefixSumIndex.find(sum) == prefixSumIndex.end())
            prefixSumIndex[sum] = i;
    }

    return maxLen;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int K = 15;

    cout << "Longest subarray length = " << longestSubarrayWithSumK(arr, K);
    return 0;
}
