// 01 Recursive solution for 02 Wildcard Matching DP 34
#include <bits/stdc++.h>
using namespace std;

bool isMatchUtil(int i, int j, string &s, string &p) {
    if (i < 0 && j < 0) return true;
    if (i < 0 && j >= 0) {
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') return false;
        }
        return true;
    }
    if (j < 0 && i >= 0) return false;

    if (s[i] == p[j] || p[j] == '?')
        return isMatchUtil(i - 1, j - 1, s, p);
    if (p[j] == '*')
        return isMatchUtil(i - 1, j, s, p) || isMatchUtil(i, j - 1, s, p);

    return false;
}

int main() {
    string s = "adceb", p = "*a*b";
    cout << (isMatchUtil(s.size() - 1, p.size() - 1, s, p) ? "true" : "false") << endl;
    return 0;
}

