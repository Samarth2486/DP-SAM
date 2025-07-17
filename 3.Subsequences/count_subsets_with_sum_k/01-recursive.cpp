// 01 Recursive solution for Count Subsets With Sum K
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int solve(int ind, vector<int>& arr, int k) {
    if (ind == 0) {
        if (k == 0 && arr[0] == 0) return 2;
        if (k == 0 || k == arr[0]) return 1;
        return 0;
    }

    int not_pick = solve(ind - 1, arr, k);
    int pick = 0;
    if (arr[ind] <= k) {
        pick = solve(ind - 1, arr, k - arr[ind]);
    }

    return (pick + not_pick) % mod;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    return solve(n - 1, arr, k);
}

int main() {
    vector<int> arr = {1, 2, 3, 3};
    int k = 6;
    cout << "Total ways: " << findWays(arr, k) << endl;
    return 0;
}
