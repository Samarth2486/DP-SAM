// 04 Space_Optimized solution for 07 Min Insertions Deletions To Convert String DP 30
#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return n + m - 2 * prev[m];
}

int main() {
    string word1 = "sea", word2 = "eat";
    cout << "Minimum Operations: " << minDistance(word1, word2) << endl;
    return 0;
}

