// Recursive approach for DP-53 Palindrome Partitioning III
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, int n, string &s) {
        if (i == n) return 0;

        int mini = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                int cost = 1 + solve(j + 1, n, s);
                mini = min(mini, cost);
            }
        }
        return mini;
    }

    int minCut(string s) {
        int n = s.size();
        return solve(0, n, s) - 1;
    }
};

int main() {
    Solution sol;
    cout << sol.minCut("aab") << endl;  // Output: 1
    return 0;
}
