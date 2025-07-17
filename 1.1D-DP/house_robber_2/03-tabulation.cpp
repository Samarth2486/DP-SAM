#include <bits/stdc++.h>
using namespace std;

int robLinear(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        int take = nums[i];
        if (i > 1) take += dp[i - 2];
        int not_take = dp[i - 1];
        dp[i] = max(take, not_take);
    }
    return dp[n - 1];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> temp1(nums.begin() + 1, nums.end());
    vector<int> temp2(nums.begin(), nums.end() - 1);

    return max(robLinear(temp1), robLinear(temp2));
}

int main() {
    vector<int> nums = {2, 3, 2};
    cout << "Max robbed = " << rob(nums) << endl;
    return 0;
}
