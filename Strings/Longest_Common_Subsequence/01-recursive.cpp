// 01 Recursive solution for 01 Longest Common Subsequence DP 25
#include <bits/stdc++.h>
using namespace std;

int lcs(int i, int j, string &text1, string &text2) {
    if (i < 0 || j < 0) return 0;

    if (text1[i] == text2[j])
        return 1 + lcs(i - 1, j - 1, text1, text2);
    else
        return max(lcs(i - 1, j, text1, text2), lcs(i, j - 1, text1, text2));
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    cout << lcs(text1.size() - 1, text2.size() - 1, text1, text2) << endl;
    return 0;
}

