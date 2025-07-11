// 01 Recursive solution for Coin Change 2
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(int ind, int amount, vector<int>& coins) {
        if (ind == 0) {
            return (amount % coins[0] == 0) ? 1 : 0;
        }

        int notTake = countWays(ind - 1, amount, coins);
        int take = 0;
        if (coins[ind] <= amount)
            take = countWays(ind, amount - coins[ind], coins); // same ind for unbounded

        return take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        return countWays(coins.size() - 1, amount, coins);
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Ways (Recursive): " << sol.change(amount, coins) << endl;
    return 0;
}
