#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool checkPossible(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1) return false;
        int first = 0, second = 0;
        while (first < s1.size()) {
            if (second < s2.size() && s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }
        return second == s2.size();
    }

    static bool comp(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkPossible(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    int result = sol.longestStrChain(words);
    cout << "Longest String Chain Length: " << result << endl;
    return 0;
}
