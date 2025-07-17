// 01 Recursive solution for 09 Distinct Subsequences DP 32
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string &s, string &t) {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (s[i] == t[j]) {
            return solve(i-1, j-1, s, t) + solve(i-1, j, s, t);
        } else {
            return solve(i-1, j, s, t);
        }
    }

    int numDistinct(string s, string t) {
        return solve(s.size() - 1, t.size() - 1, s, t);
    }
};

int main() {
    Solution sol;
    string s = "rabbbit", t = "rabbit";
    cout << "Output: " << sol.numDistinct(s, t) << endl; // Output: 3
    return 0;
}

