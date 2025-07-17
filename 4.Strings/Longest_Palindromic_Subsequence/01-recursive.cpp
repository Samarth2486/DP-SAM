// 01 Recursive solution for 05 Longest Palindromic Subsequence DP 28
#include <bits/stdc++.h>
using namespace std;

int lps(int i, int j, string &s) {
    if (i > j) return 0;
    if (i == j) return 1;

    if (s[i] == s[j])
        return 2 + lps(i + 1, j - 1, s);
    else
        return max(lps(i + 1, j, s), lps(i, j - 1, s));
}

int main() {
    string s = "bbbab";
    cout << "Longest Palindromic Subsequence Length: " << lps(0, s.length() - 1, s) << endl;
    return 0;
}

