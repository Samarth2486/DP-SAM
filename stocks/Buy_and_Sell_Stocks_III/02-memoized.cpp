// Memoized approach for DP-37 Buy and Sell Stocks III
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int buy, int cap, vector<int>& prices, int n,
          vector<vector<vector<int>>>& dp) {
    if (ind == n || cap == 0) return 0;
    if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    if (buy) {
        dp[ind][buy][cap] = max(-prices[ind] + solve(ind + 1, 0, cap, prices, n, dp),
                                solve(ind + 1, 1, cap, prices, n, dp));
    } else {
        dp[ind][buy][cap] = max(prices[ind] + solve(ind + 1, 1, cap - 1, prices, n, dp),
                                solve(ind + 1, 0, cap, prices, n, dp));
    }

    return dp[ind][buy][cap];
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(0, 1, 2, prices, n, dp);
}

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
}
