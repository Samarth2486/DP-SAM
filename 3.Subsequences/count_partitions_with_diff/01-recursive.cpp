// 01 Recursive solution for Count Partitions With Diff
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int solve(int ind, int target, vector<int>& arr) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || target == arr[0]) return 1;
        return 0;
    }

    int not_pick = solve(ind - 1, target, arr);
    int pick = 0;
    if (arr[ind] <= target)
        pick = solve(ind - 1, target - arr[ind], arr);

    return (pick + not_pick) % mod;
}

int countPartitions(int n, int d, vector<int>& arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if ((total - d) < 0 || (total - d) % 2 != 0) return 0;
    return solve(n - 1, (total - d) / 2, arr);
}

int main() {
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;
    cout << countPartitions(arr.size(), d, arr) << endl;
}
