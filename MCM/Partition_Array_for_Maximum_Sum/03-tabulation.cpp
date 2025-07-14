// Tabulation approach for DP-54 Partition Array for Maximum Sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);  // dp[i] = max sum from i to end

        for (int i = n - 1; i >= 0; i--) {
            int len = 0;
            int maxi = INT_MIN;
            int final = 0;

            for (int j = i; j < min(i + k, n); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j + 1];
                final = max(final, sum);
            }

            dp[i] = final;
        }

        return dp[0];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;
    cout << sol.maxSumAfterPartitioning(arr, k) << endl;  // Output: 84
    return 0;
}
