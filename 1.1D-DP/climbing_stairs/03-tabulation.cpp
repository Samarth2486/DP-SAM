// 03 tabulation solution for Climbing stairs
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Ways to climb " << n << " stairs: " << dp[n] << endl;
    return 0;
}
