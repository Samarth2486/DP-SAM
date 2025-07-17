// 03 Tabulation solution for 07 Min Insertions Deletions To Convert String DP 30
#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return n + m - 2 * dp[n][m];
}

int main() {
    string word1 = "sea", word2 = "eat";
    cout << "Minimum Operations: " << minDistance(word1, word2) << endl;
    return 0;
}

