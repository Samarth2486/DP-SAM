// 02 Memoized solution for 04 Longest Common Substring DP 27
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, int &maxLen) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int count = 0;
        if (s1[i] == s2[j]) {
            count = 1 + solve(i - 1, j - 1, s1, s2, dp, maxLen);
            maxLen = max(maxLen, count);
        } else {
            solve(i - 1, j, s1, s2, dp, maxLen);
            solve(i, j - 1, s1, s2, dp, maxLen);
        }

        return dp[i][j] = count;
    }

    int longestCommonSubstr(string &s1, string &s2) {
        int n = s1.size(), m = s2.size(), maxLen = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solve(n - 1, m - 1, s1, s2, dp, maxLen);
        return maxLen;
    }
};

int main() {
    string s1 = "abcdfgh", s2 = "abedfhr";
    Solution sol;
    cout << "Length of Longest Common Substring: " << sol.longestCommonSubstr(s1, s2) << endl;
    return 0;
}

