// 02 tabulation solution for Grid unique paths 2
#include <iostream>
#include <vector>
using namespace std;

int uniquePathsTabulation(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    if (grid[0][0] == 1) return 0;
    dp[0][0] = 1;

    for (int i = 1; i < n; i++)
        if (grid[i][0] == 0 && dp[i - 1][0] == 1)
            dp[i][0] = 1;

    for (int j = 1; j < m; j++)
        if (grid[0][j] == 0 && dp[0][j - 1] == 1)
            dp[0][j] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Tabulation: " << uniquePathsTabulation(obstacleGrid) << endl;
    return 0;
}

