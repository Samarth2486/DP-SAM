// Space_optimized approach for DP-39 Buy and Sell Stocks With Cooldown
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead2(2, 0); // dp[i+2]
    vector<int> ahead1(2, 0); // dp[i+1]
    vector<int> curr(2, 0);   // dp[i]

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                curr[buy] = max(-prices[ind] + ahead1[0], ahead1[1]);
            } else {
                curr[buy] = max(prices[ind] + ahead2[1], ahead1[0]);
            }
        }
        ahead2 = ahead1;
        ahead1 = curr;
    }

    return curr[1];
}

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Max Profit: " << maxProfit(prices) << endl;
}
