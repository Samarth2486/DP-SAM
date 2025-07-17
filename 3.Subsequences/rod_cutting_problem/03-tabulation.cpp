// 03 Tabulation solution for Rod Cutting Problem
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base case: fill first row
        for (int len = 0; len <= n; len++)
            dp[0][len] = len * price[0];

        for (int ind = 1; ind < n; ind++) {
            for (int len = 0; len <= n; len++) {
                int notTake = dp[ind - 1][len];
                int take = 0;
                int rodLength = ind + 1;

                if (rodLength <= len)
                    take = price[ind] + dp[ind][len - rodLength];

                dp[ind][len] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};

int main() {
    Solution sol;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Max Profit (Tabulation): " << sol.cutRod(price) << endl;
    return 0;
}
