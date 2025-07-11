// 03 Tabulation solution for Target Sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((target + total) % 2 != 0 || total < abs(target)) return 0;
        int sum = (target + total) / 2;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        if (nums[0] == 0)
            dp[0][0] = 2;
        else {
            dp[0][0] = 1;
            if (nums[0] <= sum)
                dp[0][nums[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= sum; j++) {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (nums[i] <= j)
                    take = dp[i - 1][j - nums[i]];
                dp[i][j] = take + notTake;
            }
        }

        return dp[n - 1][sum];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << "Target Sum Ways (Tabulation): " << sol.findTargetSumWays(nums, target) << endl;
    return 0;
}
