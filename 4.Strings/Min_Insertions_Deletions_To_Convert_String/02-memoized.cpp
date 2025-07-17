// 02 Memoized solution for 07 Min Insertions Deletions To Convert String DP 30
#include <bits/stdc++.h>
using namespace std;

int lcs(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (a[i] == b[j])
        return dp[i][j] = 1 + lcs(i - 1, j - 1, a, b, dp);
    else
        return dp[i][j] = max(lcs(i - 1, j, a, b, dp), lcs(i, j - 1, a, b, dp));
}

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int lcsLen = lcs(n - 1, m - 1, word1, word2, dp);
    return n + m - 2 * lcsLen;
}

int main() {
    string word1 = "sea", word2 = "eat";
    cout << "Minimum Operations: " << minDistance(word1, word2) << endl;
    return 0;
}

