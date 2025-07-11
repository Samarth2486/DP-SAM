// 03 Tabulation solution for 05 Longest Palindromic Subsequence DP 28
#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}

int main() {
    string s = "bbbab";
    cout << "Longest Palindromic Subsequence Length: " << longestPalindromeSubseq(s) << endl;
    return 0;
}

