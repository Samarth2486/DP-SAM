// 04 Space Optimized solution for Subset Sum Equal To Target
#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int target, vector<int>& arr) {
    vector<bool> prev(target + 1, false);
    prev[0] = true;

    if (arr[0] <= target)
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int j = 1; j <= target; j++) {
            bool not_pick = prev[j];
            bool pick = false;
            if (arr[i] <= j)
                pick = prev[j - arr[i]];
            curr[j] = pick || not_pick;
        }
        prev = curr;
    }

    return prev[target];
}

int main() {
    vector<int> arr = {2, 3, 7, 8, 10};
    int k = 11;
    cout << (subsetSumToK(arr.size(), k, arr) ? "Yes" : "No") << endl;
    return 0;
}
