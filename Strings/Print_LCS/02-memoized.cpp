// 02 Memoized solution for 03 Print LCS DP 26
#include <bits/stdc++.h>
using namespace std;

string lcs(int i, int j, string &s1, string &s2, vector<vector<string>> &dp) {
    if (i < 0 || j < 0) return "";
    if (!dp[i][j].empty()) return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = lcs(i - 1, j - 1, s1, s2, dp) + s1[i];
    else {
        string left = lcs(i - 1, j, s1, s2, dp);
        string right = lcs(i, j - 1, s1, s2, dp);
        return dp[i][j] = (left.length() > right.length()) ? left : right;
    }
}

int main() {
    string s1 = "abcde", s2 = "ace";
    int n = s1.size(), m = s2.size();
    vector<vector<string>> dp(n, vector<string>(m, ""));
    string result = lcs(n - 1, m - 1, s1, s2, dp);
    cout << result << endl;  // Output: ace
    return 0;
}

