// 01 Recursive solution for 03 Print LCS DP 26
#include <bits/stdc++.h>
using namespace std;

string lcs(int i, int j, string &s1, string &s2) {
    if (i < 0 || j < 0) return "";

    if (s1[i] == s2[j])
        return lcs(i - 1, j - 1, s1, s2) + s1[i];
    else {
        string left = lcs(i - 1, j, s1, s2);
        string right = lcs(i, j - 1, s1, s2);
        return (left.length() > right.length()) ? left : right;
    }
}

int main() {
    string s1 = "abcde", s2 = "ace";
    cout << lcs(s1.size() - 1, s2.size() - 1, s1, s2) << endl;  // Output: ace
    return 0;
}

