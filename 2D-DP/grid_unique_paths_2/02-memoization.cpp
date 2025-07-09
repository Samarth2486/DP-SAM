// 01 memoization solution for Grid unique paths 2
#include <iostream>
#include <vector>
using namespace std;

int uniquePathsMemo(int i, int j, vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp) {
    if (i >= n || j >= m || grid[i][j] == 1) return 0;
    if (i == n - 1 && j == m - 1) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = uniquePathsMemo(i + 1, j, grid, n, m, dp) + uniquePathsMemo(i, j + 1, grid, n, m, dp);
}

int main() {
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "Memoization: " << uniquePathsMemo(0, 0, obstacleGrid, n, m, dp) << endl;
    return 0;
}

