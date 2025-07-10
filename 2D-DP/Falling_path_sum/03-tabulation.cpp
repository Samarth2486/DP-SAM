#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize first row
    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Build the table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = dp[i - 1][j];
            int left_diag = (j > 0) ? dp[i - 1][j - 1] : INT_MIN;
            int right_diag = (j < m - 1) ? dp[i - 1][j + 1] : INT_MIN;

            dp[i][j] = matrix[i][j] + max({up, left_diag, right_diag});
        }
    }

    // Maximum from the last row
    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}

int main() {
    vector<vector<int>> matrix = {
        {10, 10, 2, 0, 20, 4},
        {1, 0, 0, 30, 2, 5},
        {0, 10, 4, 0, 2, 0},
        {1, 0, 2, 20, 0, 4}
    };
    cout << "Tabulation: " << getMaxPathSum(matrix) << endl;
    return 0;
}
