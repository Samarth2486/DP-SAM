#include <bits/stdc++.h>
using namespace std;

int robLinear(int ind, vector<int> &nums) {
    if (ind == 0) return nums[ind];
    if (ind < 0) return 0;
    int pick = nums[ind] + robLinear(ind - 2, nums);
    int not_pick = robLinear(ind - 1, nums);
    return max(pick, not_pick);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> temp1(nums.begin() + 1, nums.end());
    vector<int> temp2(nums.begin(), nums.end() - 1);

    return max(robLinear(n - 2, temp1), robLinear(n - 2, temp2));
}

int main() {
    vector<int> nums = {2, 3, 2};
    cout << "Max robbed = " << rob(nums) << endl;
    return 0;
}
