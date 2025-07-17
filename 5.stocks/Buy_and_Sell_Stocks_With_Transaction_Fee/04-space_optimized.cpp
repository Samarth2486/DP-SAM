// Space_optimized approach for DP-40 Buy and Sell Stocks With Transaction Fee
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                curr[buy] = max(-prices[i] + ahead[0], ahead[1]);
            } else {
                curr[buy] = max(prices[i] - fee + ahead[1], ahead[0]);
            }
        }
        ahead = curr;
    }

    return curr[1];
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << "Max Profit: " << maxProfit(prices, fee) << endl;
}

