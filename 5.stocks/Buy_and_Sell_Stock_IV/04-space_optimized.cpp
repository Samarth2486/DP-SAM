// Space_optimized approach for DP-38 Buy and Sell Stock IV
#include <bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0)), curr(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int trans = 0; trans < k; trans++) {
                if (buy) {
                    curr[buy][trans] = max(-prices[ind] + ahead[0][trans],
                                            ahead[1][trans]);
                } else {
                    curr[buy][trans] = max(prices[ind] + ahead[1][trans + 1],
                                            ahead[0][trans]);
                }
            }
        }
        ahead = curr;
    }
    return ahead[1][0];
}

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    cout << "Max Profit: " << maxProfit(k, prices) << endl;
}
