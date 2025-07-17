// Space_optimized approach for DP-37 Buy and Sell Stocks III
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy) {
                    curr[buy][cap] = max(-prices[ind] + ahead[0][cap],
                                         ahead[1][cap]);
                } else {
                    curr[buy][cap] = max(prices[ind] + ahead[1][cap - 1],
                                         ahead[0][cap]);
                }
            }
        }
        ahead = curr;
    }

    return ahead[1][2];
}

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
}
