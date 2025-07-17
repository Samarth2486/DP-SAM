// 04 Space Optimized solution for Count Partitions With Diff
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int solve(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    if (arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    if (arr[0] != 0 && arr[0] <= target)
        prev[arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        curr[0] = (arr[i] == 0) ? (2 * prev[0]) % mod : prev[0];
        for (int t = 1; t <= target; t++) {
            int not_pick = prev[t];
            int pick = 0;
            if (arr[i] <= t)
                pick = prev[t - arr[i]];
            curr[t] = (pick + not_pick) % mod;
        }
        prev = curr;
    }

    return prev[target];
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
