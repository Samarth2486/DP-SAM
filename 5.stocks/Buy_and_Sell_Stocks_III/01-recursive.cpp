// Recursive approach for DP-37 Buy and Sell Stocks III
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int buy, int cap, vector<int>& prices, int n) {
    if (ind == n || cap == 0) return 0;

    if (buy) {
        return max(-prices[ind] + solve(ind + 1, 0, cap, prices, n),
                   solve(ind + 1, 1, cap, prices, n));
    } else {
        return max(prices[ind] + solve(ind + 1, 1, cap - 1, prices, n),
                   solve(ind + 1, 0, cap, prices, n));
    }
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return solve(0, 1, 2, prices, n);
}

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
}
