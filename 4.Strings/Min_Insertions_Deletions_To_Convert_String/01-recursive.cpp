// 01 Recursive solution for 07 Min Insertions Deletions To Convert String DP 30
#include <bits/stdc++.h>
using namespace std;

int lcs(int i, int j, string &a, string &b) {
    if (i < 0 || j < 0) return 0;

    if (a[i] == b[j])
        return 1 + lcs(i - 1, j - 1, a, b);
    else
        return max(lcs(i - 1, j, a, b), lcs(i, j - 1, a, b));
}

int minDistance(string word1, string word2) {
    int lcsLen = lcs(word1.size() - 1, word2.size() - 1, word1, word2);
    return word1.size() + word2.size() - 2 * lcsLen;
}

int main() {
    string word1 = "sea", word2 = "eat";
    cout << "Minimum Operations: " << minDistance(word1, word2) << endl;
    return 0;
}

