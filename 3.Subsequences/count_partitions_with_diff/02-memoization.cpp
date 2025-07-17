// 02 Memoization solution for Count Partitions With Diff
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve1(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || target == arr[0]) return 1;
        return 0;
    }

    if (dp[ind][target] != -1) return dp[ind][target];

    int not_pick = solve1(ind - 1, target, arr, dp);
    int pick = 0;
    if (arr[ind] <= target) {
        pick = solve1(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = (pick + not_pick) % mod;
}

int solve(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return solve1(n - 1, target, arr, dp);
}

int countPartitions(int n, int d, vector<int>& arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if ((total - d) < 0 || (total - d) % 2 != 0) return 0;
    return solve(arr, (total - d) / 2);
}

int main() {
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;
    int n = arr.size();
    cout << "Number of partitions with difference " << d << ": "
         << countPartitions(n, d, arr) << endl;
    return 0;
}
