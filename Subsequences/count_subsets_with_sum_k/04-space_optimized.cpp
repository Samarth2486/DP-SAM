// 04 Space Optimized solution for Count Subsets With Sum K
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> prev(k + 1, 0), curr(k + 1, 0);

    // Base case
    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (arr[0] != 0 && arr[0] <= k)
        prev[arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        curr[0] = (arr[i] == 0) ? (2 * prev[0]) % mod : prev[0];
        for (int target = 1; target <= k; target++) {
            int not_pick = prev[target];
            int pick = 0;
            if (arr[i] <= target)
                pick = prev[target - arr[i]];
            curr[target] = (pick + not_pick) % mod;
        }
        prev = curr;
    }

    return prev[k];
}

int main() {
    vector<int> arr = {1, 2, 3, 3};
    int k = 6;
    cout << "Total ways: " << findWays(arr, k) << endl;
    return 0;
}

