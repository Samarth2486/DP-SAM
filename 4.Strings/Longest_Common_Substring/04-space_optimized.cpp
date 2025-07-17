// 04 Space_Optimized solution for 04 Longest Common Substring DP 27
// subsequence waale code aur isme ye difference hai ki agar match naa ho toh ommit nahi karta directly zero le lega
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr; // move current row to previous for next iteration
        }

        return ans;
    }
};

int main() {
    string s1 = "abcdfgh";
    string s2 = "abedfhr";

    Solution sol;
    int result = sol.longestCommonSubstr(s1, s2);

    cout << "Length of Longest Common Substring: " << result << endl;
    return 0;
}

