// 03 tabulation solution for Min path sum grid
#include <iostream>
#include <vector>
using namespace std;

int minPathSumTabulation(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else {
                int up = i > 0 ? dp[i - 1][j] : 1e9;
                int left = j > 0 ? dp[i][j - 1] : 1e9;
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Tabulation: " << minPathSumTabulation(grid) << endl;
    return 0;
}

