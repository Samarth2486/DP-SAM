// 03 Tabulation solution for Subset Sum Equal To Target
// subset_sum_tabulation.cpp
#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int target, vector<int>& arr) {
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= target)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            bool not_pick = dp[i - 1][j];
            bool pick = false;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            dp[i][j] = pick || not_pick;
        }
    }

    return dp[n - 1][target];
}

int main() {
    vector<int> arr = {2, 3, 7, 8, 10};
    int k = 11;
    cout << (subsetSumToK(arr.size(), k, arr) ? "Yes" : "No") << endl;
    return 0;
}
