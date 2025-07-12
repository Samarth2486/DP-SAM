// Memoized approach for DP-31 Buy and Sell Stock II
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
    if (ind == prices.size()) return 0;
    if (dp[ind][buy] != -1) return dp[ind][buy];

    if (buy) {
        dp[ind][buy] = max(-prices[ind] + solve(ind + 1, 0, prices, dp),
                           solve(ind + 1, 1, prices, dp));
    } else {
        dp[ind][buy] = max(prices[ind] + solve(ind + 1, 1, prices, dp),
                           solve(ind + 1, 0, prices, dp));
    }
    return dp[ind][buy];
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, prices, dp);
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
}
