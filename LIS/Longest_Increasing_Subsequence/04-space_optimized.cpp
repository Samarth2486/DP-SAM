// Space_optimized approach for DP-41 Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> next(n + 1, 0), curr(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev = ind - 1; prev >= -1; prev--) {
            int notTake = next[prev + 1];
            int take = 0;
            if (prev == -1 || nums[ind] > nums[prev]) {
                take = 1 + next[ind + 1];
            }
            curr[prev + 1] = max(take, notTake);
        }
        next = curr;
    }

    return curr[0];
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS Length: " << lengthOfLIS(nums) << endl;
}
