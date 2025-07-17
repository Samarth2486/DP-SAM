// 03 Tabulation solution for Min Subset Sum Diff
// 03 Tabulation solution
#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= totalSum) dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int sum = 1; sum <= totalSum; sum++) {
            bool not_pick = dp[i - 1][sum];
            bool pick = false;
            if (arr[i] <= sum)
                pick = dp[i - 1][sum - arr[i]];
            dp[i][sum] = pick || not_pick;
        }
    }

    int minDiff = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (dp[n - 1][s1]) {
            int s2 = totalSum - s1;
            minDiff = min(minDiff, abs(s2 - s1));
        }
    }
    return minDiff;
}

int main() {
    vector<int> arr = {1, 2, 3, 9};
    cout << "Minimum Subset Sum Difference: " << minSubsetSumDifference(arr) << endl;
    return 0;
}
