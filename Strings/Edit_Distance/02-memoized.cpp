// 02 Memoized solution for 10 Edit Distance DP 33
#include <bits/stdc++.h>
using namespace std;

int edit(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = edit(i - 1, j - 1, s1, s2, dp);
    else
        return dp[i][j] = 1 + min({
            edit(i - 1, j, s1, s2, dp),
            edit(i, j - 1, s1, s2, dp),
            edit(i - 1, j - 1, s1, s2, dp)
        });
}

int main() {
    string word1 = "horse", word2 = "ros";
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "Edit Distance: " << edit(n - 1, m - 1, word1, word2, dp) << endl;
    return 0;
}

