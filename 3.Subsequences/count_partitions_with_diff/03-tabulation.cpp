// 03 Tabulation solution for Count Partitions With Diff
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int solve(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Base Case
    if (arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= target; t++) {
            int not_pick = dp[i - 1][t];
            int pick = 0;
            if (arr[i] <= t)
                pick = dp[i - 1][t - arr[i]];
            dp[i][t] = (pick + not_pick) % mod;
        }
    }

    return dp[n - 1][target];
}

int countPartitions(int n, int d, vector<int>& arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if ((total - d) < 0 || (total - d) % 2 != 0) return 0;
    return solve(arr, (total - d) / 2);
}

int main() {
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;
    cout << countPartitions(arr.size(), d, arr) << endl;
}
