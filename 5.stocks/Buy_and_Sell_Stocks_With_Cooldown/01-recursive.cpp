// Recursive approach for DP-39 Buy and Sell Stocks With Cooldown
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int buy, vector<int>& prices, int n) {
    if (ind >= n) return 0;

    if (buy) {
        return max(-prices[ind] + solve(ind + 1, 0, prices, n),
                    solve(ind + 1, 1, prices, n));
    } else {
        return max(prices[ind] + solve(ind + 2, 1, prices, n),
                    solve(ind + 1, 0, prices, n));
    }
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return solve(0, 1, prices, n);
}

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Max Profit: " << maxProfit(prices) << endl;
}
