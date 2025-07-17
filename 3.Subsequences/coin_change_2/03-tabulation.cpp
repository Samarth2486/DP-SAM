// 03 Tabulation solution for Coin Change 2
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base Case
        for (int a = 0; a <= amount; a++) {
            dp[0][a] = (a % coins[0] == 0) ? 1 : 0;
        }

        for (int i = 1; i < n; i++) {
            for (int a = 0; a <= amount; a++) {
                int notTake = dp[i - 1][a];
                int take = 0;
                if (coins[i] <= a)
                    take = dp[i][a - coins[i]];
                dp[i][a] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Ways (Tabulation): " << sol.change(amount, coins) << endl;
    return 0;
}

