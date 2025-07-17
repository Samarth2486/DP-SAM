// 02 memoization solution for Min path sum triangle
#include <iostream>
#include <vector>
using namespace std;

int solveMemo(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    if (i == n - 1) return triangle[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    int down = triangle[i][j] + solveMemo(i + 1, j, n, triangle, dp);
    int diagonal = triangle[i][j] + solveMemo(i + 1, j + 1, n, triangle, dp);
    return dp[i][j] = min(down, diagonal);
}

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Memoization: " << solveMemo(0, 0, n, triangle, dp) << endl;
    return 0;
}

