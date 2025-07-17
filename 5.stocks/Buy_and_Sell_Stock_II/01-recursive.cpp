// Recursive approach for DP-31 Buy and Sell Stock II
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int buy, vector<int>& prices) {
    if (ind == prices.size()) return 0;
    if (buy) {
        return max(-prices[ind] + solve(ind + 1, 0, prices), solve(ind + 1, 1, prices));
    } else {
        return max(prices[ind] + solve(ind + 1, 1, prices), solve(ind + 1, 0, prices));
    }
}

int maxProfit(vector<int>& prices) {
    return solve(0, 1, prices);
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
}
