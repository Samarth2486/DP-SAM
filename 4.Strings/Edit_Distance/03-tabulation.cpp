// 03 Tabulation solution for 10 Edit Distance DP 33
#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill base cases
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j],     // delete
                                   dp[i][j - 1],     // insert
                                   dp[i - 1][j - 1]  // replace
                });
        }
    }

    return dp[n][m];
}

int main() {
    string word1 = "horse", word2 = "ros";
    cout << "Edit Distance: " << minDistance(word1, word2) << endl;
    return 0;
}

