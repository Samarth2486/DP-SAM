// 02 Memoization solution for Minimum Coins
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        return 1e9;
    }

    if (dp[ind][amount] != -1) return dp[ind][amount];

    int not_take = solve(ind - 1, amount, coins, dp);
    int take = 1e9;
    if (coins[ind] <= amount)
        take = 1 + solve(ind, amount - coins[ind], coins, dp);

    return dp[ind][amount] = min(take, not_take);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int res = solve(n - 1, amount, coins, dp);
    return res >= 1e9 ? -1 : res;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Minimum coins (Memoization): " << coinChange(coins, amount) << endl;
    return 0;
}

