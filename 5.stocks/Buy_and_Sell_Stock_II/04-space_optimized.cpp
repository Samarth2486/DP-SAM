// Space_optimized approach for DP-31 Buy and Sell Stock II
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0);

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                curr[buy] = max(-prices[ind] + ahead[0], ahead[1]);
            } else {
                curr[buy] = max(prices[ind] + ahead[1], ahead[0]);
            }
        }
        ahead = curr;
    }
    return ahead[1];
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
}
