#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Initialize first row
    for (int w = wt[0]; w <= W; ++w)
        dp[0][w] = val[0];

    for (int i = 1; i < n; ++i) {
        for (int w = 0; w <= W; ++w) {
            int not_pick = dp[i - 1][w];
            int pick = (wt[i] <= w) ? val[i] + dp[i - 1][w - wt[i]] : INT_MIN;
            dp[i][w] = max(pick, not_pick);
        }
    }

    return dp[n - 1][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    cout << "Max Profit (Tabulation): " << knapsack(W, val, wt) << endl;
    return 0;
}
