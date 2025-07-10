// 02 memoization solution for Min path sum grid
#include <iostream>
#include <vector>
using namespace std;

int solveMemo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return grid[0][0];
    if (i < 0 || j < 0) return 1e9;
    if (dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + solveMemo(i - 1, j, grid, dp);
    int left = grid[i][j] + solveMemo(i, j - 1, grid, dp);

    return dp[i][j] = min(up, left);
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "Memoization: " << solveMemo(n - 1, m - 1, grid, dp) << endl;
    return 0;
}

