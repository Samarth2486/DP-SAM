// 03 Tabulation solution for Partition Equal Subset Sum
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& nums, int target) {
    if (target % 2 == 1) return false;

    int sub_target = target / 2;
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(sub_target + 1, false));

    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (nums[0] <= sub_target) dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= sub_target; j++) {
            bool not_pick = dp[i - 1][j];
            bool pick = false;
            if (nums[i] <= j) {
                pick = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = pick || not_pick;
        }
    }

    return dp[n - 1][sub_target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }

    cout << "can we partition:" << (solve(nums, sum) ? "haan bhai" : "nahi bhai") << endl;

    return 0;
}

