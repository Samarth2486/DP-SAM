// 04 Space_Optimized solution for 06 Min Insertions To Make Palindrome DP 29
#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s) {
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

    return n - prev[n];
}

int main() {
    string s = "abcda";
    cout << "Minimum Insertions: " << minInsertions(s) << endl;
    return 0;
}

