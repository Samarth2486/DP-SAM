// 04 Space Optimized solution for Minimum Coins
#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    for (int t = 0; t <= amount; ++t) {
        if (t % coins[0] == 0)
            prev[t] = t / coins[0];
        else
            prev[t] = 1e9;
    }

    for (int ind = 1; ind < n; ++ind) {
        for (int t = 0; t <= amount; ++t) {
            int not_take = prev[t];
            int take = 1e9;
            if (coins[ind] <= t)
                take = 1 + curr[t - coins[ind]];
            curr[t] = min(take, not_take);
        }
        prev = curr;
    }

    return prev[amount] >= 1e9 ? -1 : prev[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Minimum coins (Space Optimized): " << coinChange(coins, amount) << endl;
    return 0;
}

