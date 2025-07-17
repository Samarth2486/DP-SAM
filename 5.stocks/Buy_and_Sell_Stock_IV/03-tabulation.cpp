// Tabulation approach for DP-38 Buy and Sell Stock IV
#include <bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int trans = 0; trans < k; trans++) {
                if (buy) {
                    dp[ind][buy][trans] = max(-prices[ind] + dp[ind + 1][0][trans],
                                               dp[ind + 1][1][trans]);
                } else {
                    dp[ind][buy][trans] = max(prices[ind] + dp[ind + 1][1][trans + 1],
                                               dp[ind + 1][0][trans]);
                }
            }
        }
    }
    return dp[0][1][0];
}

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    cout << "Max Profit: " << maxProfit(k, prices) << endl;
}
