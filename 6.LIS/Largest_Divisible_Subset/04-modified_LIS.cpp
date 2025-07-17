// Space_optimized approach for DP-44 Largest Divisible Subset
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), parent(n, -1);
        int maxLen = 1, maxIdx = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        vector<int> result;
        while (maxIdx != -1) {
            result.push_back(nums[maxIdx]);
            maxIdx = parent[maxIdx];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 4, 8};
    vector<int> res = sol.largestDivisibleSubset(nums);
    for (int num : res) cout << num << " ";
    return 0;
}
