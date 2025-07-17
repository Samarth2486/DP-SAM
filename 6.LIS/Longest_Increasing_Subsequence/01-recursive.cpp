// Recursive approach for DP-41 Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int prev_ind, vector<int>& nums, int n) {
    if (ind == n) return 0;

    int notTake = solve(ind + 1, prev_ind, nums, n);
    int take = 0;
    if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
        take = 1 + solve(ind + 1, ind, nums, n);
    }

    return max(take, notTake);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    return solve(0, -1, nums, n);
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS Length: " << lengthOfLIS(nums) << endl;
}
