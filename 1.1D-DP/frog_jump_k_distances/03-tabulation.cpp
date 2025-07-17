// 03 tabulation solution for Frog jump k distances
#include <bits/stdc++.h>
using namespace std;

int frogJumpK(int n, int k, vector<int> &heights) {
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int cost = dp[i - j] + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, cost);
            }
        }
        dp[i] = minSteps;
    }

    return dp[n - 1];
}

int main() {
    int n = 6, k = 2;
    vector<int> heights = {10, 30, 40, 50, 20, 10};

    cout << "Minimum energy with k jumps: " << frogJumpK(n, k, heights) << endl;
    return 0;
}

