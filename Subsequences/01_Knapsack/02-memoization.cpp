#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (wt[0] <= W) return val[0];
        return 0;
    }

    if (dp[ind][W] != -1) return dp[ind][W];

    int not_pick = solve(ind - 1, W, val, wt, dp);
    int pick = INT_MIN;
    if (wt[ind] <= W)
        pick = val[ind] + solve(ind - 1, W - wt[ind], val, wt, dp);

    return dp[ind][W] = max(pick, not_pick);
}

int knapsack(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return solve(n - 1, W, val, wt, dp);
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    cout << "Max Profit (Memoization): " << knapsack(W, val, wt) << endl;
    return 0;
}

