// 02 memoization solution for Frog jump
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &dp, vector<int> &heights) {
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int left = solve(ind - 1, dp, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1) {
        right = solve(ind - 2, dp, heights) + abs(heights[ind] - heights[ind - 2]);
    }

    return dp[ind] = min(left, right);
}

int main() {
    int n = 4;
    vector<int> heights = {10, 20, 30, 10};
    vector<int> dp(n, -1);

    cout << "Memoization: Minimum energy = " << solve(n - 1, dp, heights) << endl;
    return 0;
}


