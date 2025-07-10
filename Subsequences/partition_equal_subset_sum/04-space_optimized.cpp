// 04 Space Optimized solution for Partition Equal Subset Sum
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& nums, int target) {
    if (target % 2 == 1) return false;

    int sub_target = target / 2;
    int n = nums.size();
    vector<bool> prev(sub_target + 1, false);
    prev[0] = true;

    if (nums[0] <= sub_target) prev[nums[0]] = true;

    for (int i = 1; i < n; i++) {
        vector<bool> curr(sub_target + 1, false);
        curr[0] = true;
        for (int j = 1; j <= sub_target; j++) {
            bool not_pick = prev[j];
            bool pick = false;
            if (nums[i] <= j) {
                pick = prev[j - nums[i]];
            }
            curr[j] = pick || not_pick;
        }
        prev = curr;
    }

    return prev[sub_target];
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
