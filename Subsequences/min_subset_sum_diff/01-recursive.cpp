// 01 Recursive solution for Min Subset Sum Diff
// 01 Recursive solution
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int sum, int totalSum, vector<int>& arr) {
    if (ind < 0) return abs((totalSum - sum) - sum);

    int include = solve(ind - 1, sum + arr[ind], totalSum, arr);
    int exclude = solve(ind - 1, sum, totalSum, arr);

    return min(include, exclude);
}

int minSubsetSumDifference(vector<int>& arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    return solve(arr.size() - 1, 0, totalSum, arr);
}

int main() {
    vector<int> arr = {1, 2, 3, 9};
    cout << "Minimum Subset Sum Difference: " << minSubsetSumDifference(arr) << endl;
    return 0;
}
