// 02 Memoized solution for 01 Longest Common Subsequence DP 25
#include <bits/stdc++.h>
using namespace std;

int lcs(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (text1[i] == text2[j])
        return dp[i][j] = 1 + lcs(i - 1, j - 1, text1, text2, dp);
    else
        return dp[i][j] = max(lcs(i - 1, j, text1, text2, dp), lcs(i, j - 1, text1, text2, dp));
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << lcs(n - 1, m - 1, text1, text2, dp) << endl;
    return 0;
}

