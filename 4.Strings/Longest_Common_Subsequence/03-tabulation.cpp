// 03 Tabulation solution for 01 Longest Common Subsequence DP 25
#include <bits/stdc++.h>
using namespace std;

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}

