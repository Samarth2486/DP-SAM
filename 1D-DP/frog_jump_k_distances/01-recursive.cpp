// 01 recursive solution for Frog jump k distances
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int k, vector<int> &heights) {
    if (ind == 0) return 0;

    int minCost = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (ind - j >= 0) {
            int jump = solve(ind - j, k, heights) + abs(heights[ind] - heights[ind - j]);
            minCost = min(minCost, jump);
        }
    }
    return minCost;
}

int main() {
    int n = 6, k = 2;
    vector<int> heights = {10, 30, 40, 50, 20, 10};

    cout << "Recursive: Minimum energy = " << solve(n - 1, k, heights) << endl;
    return 0;
}

