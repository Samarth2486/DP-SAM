// 03 Tabulation solution for Count Subsets With Sum K
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // Base case
    if (arr[0] == 0)
        dp[0][0] = 2; // pick or not pick
    else
        dp[0][0] = 1; // not pick

    if (arr[0] != 0 && arr[0] <= k)
        dp[0][arr[0]] = 1; // pick

    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            int not_pick = dp[i - 1][target];
            int pick = 0;
            if (arr[i] <= target)
                pick = dp[i - 1][target - arr[i]];
            dp[i][target] = (pick + not_pick) % mod;
        }
    }

    return dp[n - 1][k];
}

int main() {
    vector<int> arr = {1, 2, 3, 3};
    int k = 6;
    cout << "Total ways: " << findWays(arr, k) << endl;
    return 0;
}
