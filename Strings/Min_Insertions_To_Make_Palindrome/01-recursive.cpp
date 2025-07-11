// 01 Recursive solution for 06 Min Insertions To Make Palindrome DP 29
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

int minInsertions(string s) {
    int n = s.size();
    int lpsLen = lps(0, n - 1, s);
    return n - lpsLen;
}

int main() {
    string s = "abcda";
    cout << "Minimum Insertions: " << minInsertions(s) << endl;
    return 0;
}

