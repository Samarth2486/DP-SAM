#include <iostream>
#include <vector>
using namespace std;

int uniquePathsRec(int i, int j, vector<vector<int>>& grid, int n, int m) {
    if (i >= n || j >= m || grid[i][j] == 1) return 0;
    if (i == n - 1 && j == m - 1) return 1;

    return uniquePathsRec(i + 1, j, grid, n, m) + uniquePathsRec(i, j + 1, grid, n, m);
}

int main() {
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    cout << "Recursive: " << uniquePathsRec(0, 0, obstacleGrid, n, m) << endl;
    return 0;
}
