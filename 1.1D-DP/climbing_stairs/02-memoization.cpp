// 02 memoization solution for Climbing stairs
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp) {
    if (n <= 1) return 1;  // 1 way to stand at step 0 or 1
    if (dp[n] != -1) return dp[n];
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << "Ways to climb " << n << " stairs: " << solve(n, dp) << endl;
    return 0;
}
