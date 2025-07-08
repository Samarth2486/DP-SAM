// 01 memoization solution for House robber
#include <bits/stdc++.h>
using namespace std;

// Recursive helper function
int solve(int ind, vector<int>& nums,vector<int>&dp) {
    if (ind == 0) return nums[ind];
    if (ind < 0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick = nums[ind] + solve(ind - 2, nums,dp);
    int not_pick = solve(ind - 1, nums,dp);

    return dp[ind]= max(pick, not_pick);
}

// Main function that calls solve
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,-1);
    return solve(n - 1, nums,dp);
}

int main() {
    // Example input
    vector<int> nums = {2, 7, 9, 3, 1};

    int maxRobbed = rob(nums);
    cout << "Maximum money the robber can steal: " << maxRobbed << endl;

    return 0;
}

