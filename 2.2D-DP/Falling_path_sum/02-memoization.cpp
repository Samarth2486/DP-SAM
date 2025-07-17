#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>>& matrix, int n, int m,vector<vector<int>>&dp) {
    // Out of bounds
    if (j < 0 || j >= m) return -1e9;

    // Base case: first row
    if (i == 0) return matrix[i][j];

    if(dp[i][j]!=-1) return dp[i][j];
    int up = matrix[i][j] + solve(i - 1, j, matrix, n, m , dp);
    int left_diag = matrix[i][j] + solve(i - 1, j - 1, matrix, n, m, dp);
    int right_diag = matrix[i][j] + solve(i - 1, j + 1, matrix, n, m, dp);

    return dp[i][j]=max({up, left_diag, right_diag});
}

int getMaxPathSumRecursive(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int maxSum = INT_MIN;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for (int j = 0; j < m; j++) {
        maxSum = max(maxSum, solve(n - 1, j, matrix, n, m ,dp));
    }

    return maxSum;
}

int main() {
    vector<vector<int>> matrix = {
        {10, 10, 2, 0, 20, 4},
        {1, 0, 0, 30, 2, 5},
        {0, 10, 4, 0, 2, 0},
        {1, 0, 2, 20, 0, 4}
    };
    cout << "memoization: " << getMaxPathSumRecursive(matrix) << endl;
    return 0;
}
