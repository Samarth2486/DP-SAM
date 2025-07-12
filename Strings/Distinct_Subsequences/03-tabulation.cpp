// 03 Tabulation solution for 09 Distinct Subsequences DP 32
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));

        // Initialize first column with 1
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return (int)dp[n][m];
    }
};

int main() {
    Solution sol;
    string s = "rabbbit", t = "rabbit";
    cout << "Output: " << sol.numDistinct(s, t) << endl; // Output: 3
    return 0;
}

