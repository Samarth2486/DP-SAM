#include <iostream>
#include <vector>
using namespace std;

int minPathSumOptimized(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++) {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];
            else {
                int up = i > 0 ? prev[j] : 1e9;
                int left = j > 0 ? curr[j - 1] : 1e9;
                curr[j] = grid[i][j] + min(up, left);
            }
        }
        prev = curr;
    }

    return prev[m - 1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 6},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Space Optimized: " << minPathSumOptimized(grid) << endl;
    return 0;
}
