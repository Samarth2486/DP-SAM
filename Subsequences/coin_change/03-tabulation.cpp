// 03 Tabulation solution for Minimum Coins
#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // Base case
    for (int t = 0; t <= amount; ++t) {
        if (t % coins[0] == 0)
            dp[0][t] = t / coins[0];
        else
            dp[0][t] = 1e9;
    }

    for (int ind = 1; ind < n; ++ind) {
        for (int t = 0; t <= amount; ++t) {
            int not_take = dp[ind - 1][t];
            int take = 1e9;
            if (coins[ind] <= t)
                take = 1 + dp[ind][t - coins[ind]];

            dp[ind][t] = min(take, not_take);
        }
    }

    return dp[n - 1][amount] >= 1e9 ? -1 : dp[n - 1][amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Minimum coins (Tabulation): " << coinChange(coins, amount) << endl;
    return 0;
}
