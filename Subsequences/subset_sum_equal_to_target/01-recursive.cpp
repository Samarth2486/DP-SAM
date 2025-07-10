// 01 Recursive solution for Subset Sum Equal To Target
// subset_sum_recursive.cpp
#include <bits/stdc++.h>
using namespace std;

bool solve(int ind, int target, vector<int>& arr) {
    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;

    bool not_pick = solve(ind - 1, target, arr);
    bool pick = false;
    if (arr[ind] <= target)
        pick = solve(ind - 1, target - arr[ind], arr);

    return pick || not_pick;
}

bool subsetSumToK(int n, int k, vector<int>& arr) {
    return solve(n - 1, k, arr);
}

int main() {
    vector<int> arr = {2, 3, 7, 8, 10};
    int k = 11;
    cout << (subsetSumToK(arr.size(), k, arr) ? "Yes" : "No") << endl;
    return 0;
}

