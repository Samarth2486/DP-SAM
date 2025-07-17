// Tabulation approach for DP-53 Palindrome Partitioning III
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

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int mini = INT_MAX;
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }

        return dp[0] - 1;
    }
};

int main() {
    Solution sol;
    cout << sol.minCut("aab") << endl;  // Output: 1
    return 0;
}
