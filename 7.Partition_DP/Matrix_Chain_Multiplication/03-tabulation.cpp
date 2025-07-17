// Tabulation approach for DP-48 Matrix Chain Multiplication
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // ace this aur isme space optimization useful nahi hai since solution depends on submatrices
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j < n; j++) {
                int mini = INT_MAX;
                for (int k = i; k < j; k++) {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
    }
};

int main() {
    Solution sol;

    // Example input: dimensions of matrices
    vector<int> arr = {10 ,30 ,5 ,60};

    int result = sol.matrixMultiplication(arr);
    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}
