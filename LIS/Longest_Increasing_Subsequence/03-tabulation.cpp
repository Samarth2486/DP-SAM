// Tabulation approach for DP-41 Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev = ind - 1; prev >= -1; prev--) {
            int notTake = dp[ind + 1][prev + 1];
            int take = 0;
            if (prev == -1 || nums[ind] > nums[prev]) {
                take = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prev + 1] = max(take, notTake);
        }
    }

    return dp[0][0];
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS Length: " << lengthOfLIS(nums) << endl;
}
