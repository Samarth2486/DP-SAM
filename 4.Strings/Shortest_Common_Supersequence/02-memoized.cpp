// 02 Memoized solution for 08 Shortest Common Supersequence DP 31
#include <bits/stdc++.h>
using namespace std;

string scs(int i, int j, string &a, string &b, vector<vector<string>> &dp) {
    if (i < 0) return b.substr(0, j + 1);
    if (j < 0) return a.substr(0, i + 1);

    if (!dp[i][j].empty()) return dp[i][j];

    if (a[i] == b[j])
        return dp[i][j] = scs(i - 1, j - 1, a, b, dp) + a[i];
    else {
        string op1 = scs(i - 1, j, a, b, dp) + a[i];
        string op2 = scs(i, j - 1, a, b, dp) + b[j];
        return dp[i][j] = (op1.length() < op2.length()) ? op1 : op2;
    }
}

int main() {
    string str1 = "abac", str2 = "cab";
    int n = str1.size(), m = str2.size();
    vector<vector<string>> dp(n, vector<string>(m, ""));
    cout << "SCS: " << scs(n - 1, m - 1, str1, str2, dp) << endl;
    return 0;
}

