// Tabulation approach for DP-31 Buy and Sell Stock II
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            } else {
                dp[ind][buy] = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
            }
        }
    }
    return dp[0][1];
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
}
