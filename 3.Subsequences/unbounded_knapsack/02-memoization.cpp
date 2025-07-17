// 02 Memoization solution for Unbounded Knapsack
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int ind, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
        if (ind == 0)
            return (capacity / wt[0]) * val[0];

        if (dp[ind][capacity] != -1) return dp[ind][capacity];

        int notTake = solve(ind - 1, capacity, val, wt, dp);
        int take = 0;
        if (wt[ind] <= capacity)
            take = val[ind] + solve(ind, capacity - wt[ind], val, wt, dp);

        return dp[ind][capacity] = max(take, notTake);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return solve(n - 1, capacity, val, wt, dp);
    }
};

int main() {
    Solution sol;
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;
    cout << "Max Value (Memoized): " << sol.knapSack(val, wt, capacity) << endl;
    return 0;
}
