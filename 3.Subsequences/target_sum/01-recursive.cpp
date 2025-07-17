// 01 Recursive solution for Target Sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(int ind, int sum, vector<int>& nums) {
        if (ind == 0) {
            if (sum == 0 && nums[0] == 0) return 2;
            if (sum == 0 || sum == nums[0]) return 1;
            return 0;
        }

        int notTake = countWays(ind - 1, sum, nums);
        int take = 0;
        if (nums[ind] <= sum)
            take = countWays(ind - 1, sum - nums[ind], nums);

        return take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((target + total) % 2 != 0 || total < abs(target)) return 0;
        int sum = (target + total) / 2;
        return countWays(nums.size() - 1, sum, nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << "Target Sum Ways (Recursive): " << sol.findTargetSumWays(nums, target) << endl;
    return 0;
}
