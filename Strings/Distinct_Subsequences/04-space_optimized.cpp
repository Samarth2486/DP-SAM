// 04 Space_Optimized solution for 09 Distinct Subsequences DP 32
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double> prev(m+1, 0), curr(m+1, 0);

        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            curr[0] = 1;
            for (int j = m; j >= 1; j--) {
                if (s[i-1] == t[j-1])
                    curr[j] = prev[j-1] + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return (int)prev[m];
    }
};

int main() {
    Solution sol;
    string s = "rabbbit", t = "rabbit";
    cout << "Output: " << sol.numDistinct(s, t) << endl; // Output: 3
    return 0;
}

