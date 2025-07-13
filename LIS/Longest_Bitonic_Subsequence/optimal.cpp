#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n, 1), dp2(n, 1);

        // Compute LIS (Longest Increasing Subsequence) from left to right
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && dp1[i] < dp1[j] + 1) {
                    dp1[i] = dp1[j] + 1;
                }
            }
        }

        // Compute LDS (Longest Decreasing Subsequence) from right to left
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j] && dp2[i] < dp2[j] + 1) {
                    dp2[i] = dp2[j] + 1;
                }
            }
        }

        int maxLength = 0;

        // Only consider valid bitonic sequences (must increase and then decrease)
        for (int i = 0; i < n; ++i) {
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxLength = max(maxLength, dp1[i] + dp2[i] - 1);
            }
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    // Sample test case
    vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    int result = sol.LongestBitonicSequence(nums.size(), nums);

    cout << "Length of Longest Bitonic Subsequence: " << result << endl;

    return 0;
}
