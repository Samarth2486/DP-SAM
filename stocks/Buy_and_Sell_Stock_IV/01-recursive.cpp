// Recursive approach for DP-38 Buy and Sell Stock IV
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int buy, int transaction, vector<int>& prices, int k, int n) {
    if (ind == n || transaction == k) return 0;

    if (buy) {
        return max(-prices[ind] + solve(ind + 1, 0, transaction, prices, k, n),
                    solve(ind + 1, 1, transaction, prices, k, n));
    } else {
        return max(prices[ind] + solve(ind + 1, 1, transaction + 1, prices, k, n),
                    solve(ind + 1, 0, transaction, prices, k, n));
    }
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    return solve(0, 1, 0, prices, k, n);
}

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    cout << "Max Profit: " << maxProfit(k, prices) << endl;
}
