#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1), count(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int number = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) number += count[i];
        }

        return number;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> nums = {1, 3, 5, 4, 7};

    // Function call
    int result = sol.findNumberOfLIS(nums);

    // Output
    cout << "Number of Longest Increasing Subsequences: " << result << endl;

    return 0;
}
