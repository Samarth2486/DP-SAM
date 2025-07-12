// Tabulation approach for DP-40 Buy and Sell Stocks With Transaction Fee
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            } else {
                dp[i][buy] = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
            }
        }
    }

    return dp[0][1];
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << "Max Profit: " << maxProfit(prices, fee) << endl;
}
