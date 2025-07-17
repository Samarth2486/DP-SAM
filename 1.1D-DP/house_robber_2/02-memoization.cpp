#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int>& nums, vector<int>& dp) {
    if (ind == 0) return nums[ind];
    if (ind < 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + solve(ind - 2, nums, dp);
    int not_pick = solve(ind - 1, nums, dp);

    return dp[ind] = max(pick, not_pick);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> temp1(nums.begin() + 1, nums.end());
    vector<int> temp2(nums.begin(), nums.end() - 1);
    vector<int> dp1(n - 1, -1), dp2(n - 1, -1);

    return max(solve(n - 2, temp1, dp1), solve(n - 2, temp2, dp2));
}

int main() {
    vector<int> nums = {2, 3, 2};
    cout << "Max robbed = " << rob(nums) << endl;
    return 0;
}