// Tabulation approach for DP-50 Minimum Cost to Cut the Stick
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

        for (int len = 1; len <= m; len++) {
            for (int i = 1; i <= m - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; k++) {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[1][m];
    }
};

int main() {
    Solution sol;
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    cout << "Minimum cost: " << sol.minCost(n, cuts) << endl;
    return 0;
}
