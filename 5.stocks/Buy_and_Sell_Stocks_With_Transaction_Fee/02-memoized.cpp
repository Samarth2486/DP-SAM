// Memoized approach for DP-40 Buy and Sell Stocks With Transaction Fee
#include <bits/stdc++.h>
using namespace std;

int solve(int i, int buy, vector<int>& prices, int fee, int n, vector<vector<int>>& dp) {
    if (i == n) return 0;
    if (dp[i][buy] != -1) return dp[i][buy];

    if (buy) {
        dp[i][buy] = max(-prices[i] + solve(i + 1, 0, prices, fee, n, dp),
                         solve(i + 1, 1, prices, fee, n, dp));
    } else {
        dp[i][buy] = max(prices[i] - fee + solve(i + 1, 1, prices, fee, n, dp),
                         solve(i + 1, 0, prices, fee, n, dp));
    }

    return dp[i][buy];
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, prices, fee, n, dp);
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << "Max Profit: " << maxProfit(prices, fee) << endl;
}
