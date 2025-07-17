// 02 Memoization solution for Subset Sum Equal To Target
// subset_sum_memo.cpp
#include <bits/stdc++.h>
using namespace std;

bool solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;

    if (dp[ind][target] != -1) return dp[ind][target];

    bool not_pick = solve(ind - 1, target, arr, dp);
    bool pick = false;
    if (arr[ind] <= target)
        pick = solve(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = pick || not_pick;
}

bool subsetSumToK(int n, int k, vector<int>& arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}

int main() {
    vector<int> arr = {2, 3, 7, 8, 10};
    int k = 11;
    cout << (subsetSumToK(arr.size(), k, arr) ? "Yes" : "No") << endl;
    return 0;
}

