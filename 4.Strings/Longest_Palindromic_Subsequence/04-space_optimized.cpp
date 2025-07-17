// 04 Space_Optimized solution for 05 Longest Palindromic Subsequence DP 28
#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();

    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return prev[n];
}

int main() {
    string s = "bbbab";
    cout << "Longest Palindromic Subsequence Length: " << longestPalindromeSubseq(s) << endl;
    return 0;
}

