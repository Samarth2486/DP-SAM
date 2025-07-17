// 03 tabulation solution for Min path sum triangle
#include <iostream>
#include <vector>
using namespace std;

int minPathTabulation(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp = triangle;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] += min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
}

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << "Tabulation: " << minPathTabulation(triangle) << endl;
    return 0;
}

