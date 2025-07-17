#include <iostream>
#include <vector>
using namespace std;

int uniquePathsOptimized(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> prev(m, 0);

    if (grid[0][0] == 1) return 0;
    prev[0] = 1;

    for (int i = 0; i < n; i++) {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                curr[j] = 0;
            } else {
                if (i == 0 && j == 0) curr[j] = 1;
                else {
                    int up = i > 0 ? prev[j] : 0;
                    int left = j > 0 ? curr[j - 1] : 0;
                    curr[j] = up + left;
                }
            }
        }
        prev = curr;
    }

    return prev[m - 1];
}

int main() {
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Space Optimized: " << uniquePathsOptimized(obstacleGrid) << endl;
    return 0;
}
