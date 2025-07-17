// 02 Memoization solution for Coin Change 2
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0)
            return (amount % coins[0] == 0) ? 1 : 0;

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = countWays(ind - 1, amount, coins, dp);
        int take = 0;
        if (coins[ind] <= amount)
            take = countWays(ind, amount - coins[ind], coins, dp);

        return dp[ind][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return countWays(n - 1, amount, coins, dp);
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Ways (Memoized): " << sol.change(amount, coins) << endl;
    return 0;
}

