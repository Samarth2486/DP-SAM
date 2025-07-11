#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for (int w = wt[0]; w <= W; ++w)
        prev[w] = val[0];

    for (int i = 1; i < n; ++i) {
        for (int w = 0; w <= W; ++w) {
            int not_pick = prev[w];
            int pick = (wt[i] <= w) ? val[i] + prev[w - wt[i]] : INT_MIN;
            curr[w] = max(pick, not_pick);
        }
        prev = curr;
    }

    return prev[W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    cout << "Max Profit (Space Optimized): " << knapsack(W, val, wt) << endl;
    return 0;
}

