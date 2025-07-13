// Recursive approach for DP-48 Matrix Chain Multiplication
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& arr) {
        if (i == j) return 0;
        int mini = INT_MAX;
        for (int k = i; k < j; k++) {
            int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr) + solve(k + 1, j, arr);
            mini = min(mini, steps);
        }
        return mini;
    }

    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        return solve(1, n - 1, arr);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10 ,30 ,5 ,60};
    cout << "Min multiplications: " << sol.matrixMultiplication(arr) << endl;
    return 0;
}
