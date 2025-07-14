// Memoized approach for DP-54 Partition Array for Maximum Sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int k, int n, vector<int>& arr, vector<int>& dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int final = 0;
        int maxi = INT_MIN;
        int len = 0;

        for (int j = i; j < min(i + k, n); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + solve(j + 1, k, n, arr, dp);
            final = max(final, sum);
        }

        return dp[i] = final;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, k, n, arr, dp);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;
    cout << sol.maxSumAfterPartitioning(arr, k) << endl;  // Output: 84
    return 0;
}
