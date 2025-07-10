#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid) {
    if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;
    if (i == r - 1) return (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
            value += solve(i + 1, j1 + dj1, j2 + dj2, r, c, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return solve(0, 0, c - 1, r, c, grid);
}

int main() {
    vector<vector<int>> grid = {{3, 1, 1},
                                {2, 5, 1},
                                {1, 17, 5},
                                {2, 1, 1}};
    int r = grid.size(), c = grid[0].size();
    cout << "Max chocolates (Recursive): " << maximumChocolates(r, c, grid) << endl;
}
