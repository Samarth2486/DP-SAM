// Memoized approach for DP-50 Minimum Cost to Cut the Stick
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k = i; k <= j; k++) {
            int cost = cuts[j+1] - cuts[i-1] + f(i, k - 1, cuts, dp) + f(k + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        return f(1, m, cuts, dp);
    }
};

int main() {
    Solution sol;
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    cout << "Minimum cost: " << sol.minCost(n, cuts) << endl;
    return 0;
}
