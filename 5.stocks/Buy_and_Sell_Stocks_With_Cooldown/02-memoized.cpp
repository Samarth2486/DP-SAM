// Memoized approach for DP-39 Buy and Sell Stocks With Cooldown
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>& dp) {
        if (ind >= n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy) {
            dp[ind][buy] = max(
                -prices[ind] + solve(ind + 1, 0, prices, n, dp), // Buy
                solve(ind + 1, 1, prices, n, dp)                  // Skip
            );
        } else {
            dp[ind][buy] = max(
                prices[ind] + solve(ind + 2, 1, prices, n, dp),  // Sell and cooldown
                solve(ind + 1, 0, prices, n, dp)                 // Skip
            );
        }

        return dp[ind][buy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, n, dp);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
