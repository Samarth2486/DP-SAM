// 01 Recursive solution for Minimum Coins
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int amount, vector<int>& coins) {
    if (ind == 0) {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        return 1e9;
    }

    int not_take = solve(ind - 1, amount, coins);
    int take = 1e9;
    if (coins[ind] <= amount)
        take = 1 + solve(ind, amount - coins[ind], coins);

    return min(take, not_take);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int res = solve(n - 1, amount, coins);
    return res >= 1e9 ? -1 : res;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Minimum coins (Recursive): " << coinChange(coins, amount) << endl;
    return 0;
}
