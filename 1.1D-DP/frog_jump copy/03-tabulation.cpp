// 03 tabulation solution for Frog jump
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    vector<int> heights = {10, 50, 10};
    vector<int> dp(n+1, 0);

    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = (i > 1) ? dp[i - 2] + abs(heights[i] - heights[i - 2]) : INT_MAX;
        dp[i] = min(left, right);
    }

    cout << "Tabulation: Minimum energy = " << dp[n] << endl;
    return 0;
}


