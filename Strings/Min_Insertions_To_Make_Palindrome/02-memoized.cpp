// 02 Memoized solution for 06 Min Insertions To Make Palindrome DP 29
#include <bits/stdc++.h>
using namespace std;

int lps(int i, int j, string &s, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (i == j) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = 2 + lps(i + 1, j - 1, s, dp);
    else
        return dp[i][j] = max(lps(i + 1, j, s, dp), lps(i, j - 1, s, dp));
}

int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int lpsLen = lps(0, n - 1, s, dp);
    return n - lpsLen;
}

int main() {
    string s = "abcda";
    cout << "Minimum Insertions: " << minInsertions(s) << endl;
    return 0;
}

