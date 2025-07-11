// 04 Space Optimized solution for Target Sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((target + total) % 2 != 0 || total < abs(target)) return 0;
        int sum = (target + total) / 2;

        vector<int> dp(sum + 1, 0);
        if (nums[0] == 0)
            dp[0] = 2;
        else {
            dp[0] = 1;
            if (nums[0] <= sum)
                dp[nums[0]] = 1;
        }

        for (int i = 1; i < nums.size(); i++) {
            vector<int> new_dp(sum + 1, 0);
            for (int j = 0; j <= sum; j++) {
                int notTake = dp[j];
                int take = 0;
                if (nums[i] <= j)
                    take = dp[j - nums[i]];
                new_dp[j] = take + notTake;
            }
            dp = new_dp;
        }

        return dp[sum];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << "Target Sum Ways (Space Optimized): " << sol.findTargetSumWays(nums, target) << endl;
    return 0;
}

