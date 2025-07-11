// 04 Space_Optimized solution for 08 Shortest Common Supersequence DP 31
// ye string directly reconstruct nahi kar paayega par
#include <bits/stdc++.h>
using namespace std;

// Only returns the length of SCS, not the actual string.
int shortestCommonSupersequenceLength(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // Build LCS length using space optimization
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    int lcsLen = prev[m];
    return n + m - lcsLen;
}

int main() {
    string str1 = "abac", str2 = "cab";
    cout << "SCS Length: " << shortestCommonSupersequenceLength(str1, str2) << endl;
    return 0;
}

