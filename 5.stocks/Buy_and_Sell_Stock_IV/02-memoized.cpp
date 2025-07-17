// Memoized approach for DP-38 Buy and Sell Stock IV
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int buy, int transaction, vector<int>& prices, int k,
          vector<vector<vector<int>>>& dp, int n) {
    if (ind == n || transaction == k) return 0;
    if (dp[ind][buy][transaction] != -1) return dp[ind][buy][transaction];

    if (buy) {
        dp[ind][buy][transaction] = max(-prices[ind] + solve(ind + 1, 0, transaction, prices, k, dp, n),
                                        solve(ind + 1, 1, transaction, prices, k, dp, n));
    } else {
        dp[ind][buy][transaction] = max(prices[ind] + solve(ind + 1, 1, transaction + 1, prices, k, dp, n),
                                        solve(ind + 1, 0, transaction, prices, k, dp, n));
    }
    return dp[ind][buy][transaction];
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return solve(0, 1, 0, prices, k, dp, n);
}

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    cout << "Max Profit: " << maxProfit(k, prices) << endl;
}
