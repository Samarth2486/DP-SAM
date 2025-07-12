// 04 Space_Optimized solution for 10 Edit Distance DP 33
#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; j++) prev[j] = j;

    for (int i = 1; i <= n; i++) {
        curr[0] = i;
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min({
                    prev[j],     // delete
                    curr[j - 1], // insert
                    prev[j - 1]  // replace
                });
        }
        prev = curr;
    }

    return prev[m];
}

int main() {
    string word1 = "horse", word2 = "ros";
    cout << "Edit Distance: " << minDistance(word1, word2) << endl;
    return 0;
}

