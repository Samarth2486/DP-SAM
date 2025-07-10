#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    for (int j1 = 0; j1 < c; j1++) {
        for (int j2 = 0; j2 < c; j2++) {
            dp[r - 1][j1][j2] = (j1 == j2) ? grid[r - 1][j1] : grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int nj1 = j1 + dj1, nj2 = j2 + dj2;
                        if (nj1 >= 0 && nj1 < c && nj2 >= 0 && nj2 < c) {
                            int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                            value += dp[i + 1][nj1][nj2];
                            maxi = max(maxi, value);
                        }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][c - 1];
}

int main() {
    vector<vector<int>> grid = {{3, 1, 1},
                                {2, 5, 1},
                                {1, 5, 5},
                                {2, 1, 1}};
    int r = grid.size(), c = grid[0].size();
    cout << "Max chocolates (Tabulation): " << maximumChocolates(r, c, grid) << endl;
}
