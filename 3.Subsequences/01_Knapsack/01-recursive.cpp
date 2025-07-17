#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int W, vector<int>& val, vector<int>& wt) {
    if (ind == 0) {
        if (wt[0] <= W) return val[0];
        return 0;
    }

    int not_pick = solve(ind - 1, W, val, wt);
    int pick = INT_MIN;
    if (wt[ind] <= W)
        pick = val[ind] + solve(ind - 1, W - wt[ind], val, wt);

    return max(pick, not_pick);
}

int knapsack(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();
    return solve(n - 1, W, val, wt);
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    cout << "Max Profit (Recursive): " << knapsack(W, val, wt) << endl;
    return 0;
}

