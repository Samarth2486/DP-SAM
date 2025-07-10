// 01 recursive solution for Min path sum grid
#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int j, vector<vector<int>>& grid) {
    if (i == 0 && j == 0) return grid[0][0];
    if (i < 0 || j < 0) return 1e9;

    int up = grid[i][j] + solve(i - 1, j, grid);
    int left = grid[i][j] + solve(i, j - 1, grid);

    return min(up, left);
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int n = grid.size(), m = grid[0].size();
    cout << "Recursive: " << solve(n - 1, m - 1, grid) << endl;
    return 0;
}

