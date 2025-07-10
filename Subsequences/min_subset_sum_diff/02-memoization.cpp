// 02 Memoization solution for Min Subset Sum Diff
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int sum, int totalSum, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind < 0) return abs((totalSum - sum) - sum);

    if (dp[ind][sum] != -1) return dp[ind][sum];

    int include = solve(ind - 1, sum + arr[ind], totalSum, arr, dp);
    int exclude = solve(ind - 1, sum, totalSum, arr, dp);

    return dp[ind][sum] = min(include, exclude);
}

int minSubsetSumDifference(vector<int>& arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
    return solve(n - 1, 0, totalSum, arr, dp);
}

int main() {
    vector<int> arr = {1, 2, 3, 9};
    cout << "Minimum Subset Sum Difference: " << minSubsetSumDifference(arr) << endl;
    return 0;
}