// Memoized approach for DP-44 Largest Divisible Subset
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);
        int maxi = 1, lastIndex = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> result;
        while (hash[lastIndex] != lastIndex) {
            result.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        result.push_back(nums[lastIndex]);
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
