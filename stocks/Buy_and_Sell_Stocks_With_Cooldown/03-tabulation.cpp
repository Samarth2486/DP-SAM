// Tabulation approach for DP-39 Buy and Sell Stocks With Cooldown
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0)); // n+2 to handle ind+2 safely

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0],
                                   dp[ind + 1][1]);
            } else {
                dp[ind][buy] = max(prices[ind] + dp[ind + 2][1],
                                   dp[ind + 1][0]);
            }
        }
    }

    return dp[0][1];
}

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Max Profit: " << maxProfit(prices) << endl;
}
