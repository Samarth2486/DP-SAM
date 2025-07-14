// Memoized approach for DP-53 Palindrome Partitioning III
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

    int solve(int i, int n, string &s, vector<int>& dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                int cost = 1 + solve(j + 1, n, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0, n, s, dp) - 1;
    }
};

int main() {
    Solution sol;
    cout << sol.minCut("aab") << endl;  // Output: 1
    return 0;
}
