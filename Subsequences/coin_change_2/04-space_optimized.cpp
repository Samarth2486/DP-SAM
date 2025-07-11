// 04 Space Optimized solution for Coin Change 2
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);

        // Base case
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int a = coins[i]; a <= amount; a++) {
                dp[a] += dp[a - coins[i]];
            }
        }

        return dp[amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Ways (Space Optimized): " << sol.change(amount, coins) << endl;
    return 0;
}
