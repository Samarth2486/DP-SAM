// 01 Recursive solution for 04 Longest Common Substring DP 27
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, int &maxLen) {
        if (i < 0 || j < 0) return 0;

        int count = 0;
        if (s1[i] == s2[j]) {
            count = 1 + solve(i - 1, j - 1, s1, s2, maxLen);
            maxLen = max(maxLen, count);
        } else {
            solve(i - 1, j, s1, s2, maxLen);  // don't include current
            solve(i, j - 1, s1, s2, maxLen);
        }

        return count;
    }

    int longestCommonSubstr(string &s1, string &s2) {
        int maxLen = 0;
        solve(s1.size() - 1, s2.size() - 1, s1, s2, maxLen);
        return maxLen;
    }
};

int main() {
    string s1 = "abcdfgh", s2 = "abedfhr";
    Solution sol;
    cout << "Length of Longest Common Substring: " << sol.longestCommonSubstr(s1, s2) << endl;
    return 0;
}

