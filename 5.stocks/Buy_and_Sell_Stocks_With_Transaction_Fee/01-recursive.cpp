// Recursive approach for DP-40 Buy and Sell Stocks With Transaction Fee
#include <bits/stdc++.h>
using namespace std;

int solve(int i, int buy, vector<int>& prices, int fee, int n) {
    if (i == n) return 0;

    if (buy) {
        return max(-prices[i] + solve(i + 1, 0, prices, fee, n), solve(i + 1, 1, prices, fee, n));
    } else {
        return max(prices[i] - fee + solve(i + 1, 1, prices, fee, n), solve(i + 1, 0, prices, fee, n));
    }
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    return solve(0, 1, prices, fee, n);
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << "Max Profit: " << maxProfit(prices, fee) << endl;
}
