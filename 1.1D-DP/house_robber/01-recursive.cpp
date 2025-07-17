#include <bits/stdc++.h>
using namespace std;

// Recursive helper function
int solve(int ind, vector<int>& nums) {
    if (ind == 0) return nums[ind];
    if (ind < 0) return 0;

    int pick = nums[ind] + solve(ind - 2, nums);
    int not_pick = solve(ind - 1, nums);

    return max(pick, not_pick);
}

// Main function that calls solve
int rob(vector<int>& nums) {
    int n = nums.size();
    return solve(n - 1, nums);
}

int main() {
    // Example input
    vector<int> nums = {2, 7, 9, 3, 1};

    int maxRobbed = rob(nums);
    cout << "Maximum money the robber can steal: " << maxRobbed << endl;

    return 0;
}
