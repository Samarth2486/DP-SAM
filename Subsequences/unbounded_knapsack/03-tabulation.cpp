// 03 Tabulation solution for Unbounded Knapsack
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        // Base case: fill first row
        for (int c = 0; c <= capacity; c++) {
            dp[0][c] = (c / wt[0]) * val[0];
        }

        for (int i = 1; i < n; i++) {
            for (int c = 0; c <= capacity; c++) {
                int notTake = dp[i - 1][c];
                int take = 0;
                if (wt[i] <= c)
                    take = val[i] + dp[i][c - wt[i]];
                dp[i][c] = max(take, notTake);
            }
        }

        return dp[n - 1][capacity];
    }
};

int main() {
    Solution sol;
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;
    cout << "Max Value (Tabulation): " << sol.knapSack(val, wt, capacity) << endl;
    return 0;
}
