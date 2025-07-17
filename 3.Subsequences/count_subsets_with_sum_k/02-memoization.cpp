// 02 Memoization solution for Count Subsets With Sum K
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int solve(int ind, vector<int>& arr, int k, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (k == 0 && arr[0] == 0) return 2;
        if (k == 0 || k == arr[0]) return 1;
        return 0;
    }

    if (dp[ind][k] != -1) return dp[ind][k];

    int not_pick = solve(ind - 1, arr, k, dp);
    int pick = 0;
    if (arr[ind] <= k) {
        pick = solve(ind - 1, arr, k - arr[ind], dp);
    }

    return dp[ind][k] = (pick + not_pick) % mod;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, arr, k, dp);
}

int main() {
    vector<int> arr = {1, 2, 3, 3};
    int k = 6;
    cout << "Total ways: " << findWays(arr, k) << endl;
    return 0;
}

