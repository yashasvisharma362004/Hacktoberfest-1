#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int ans = nums[0];
    int minP = nums[0];
    int maxP = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) swap(minP, maxP);
        
        maxP = max(nums[i], nums[i] * maxP);
        minP = min(nums[i], nums[i] * minP);
        
        ans = max(ans, maxP);
    }
    return ans;
}

int main() {
    vector<int> a = {2, 3, -2, 4};
    cout << maxProduct(a);  // Output: 6
    return 0;
}