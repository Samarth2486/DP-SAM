// Memoized approach for DP-48 Matrix Chain Multiplication
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k = i; k < j; k++) {
            int steps = arr[i - 1] * arr[k] * arr[j]
                        + solve(i, k, arr, dp)
                        + solve(k + 1, j, arr, dp);
            mini = min(mini, steps);
        }

        return dp[i][j] = mini;
    }

    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, n - 1, arr, dp);
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> arr = {10 ,30 ,5 ,60};
    
    int result = sol.matrixMultiplication(arr);
    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}
