// 01 Recursive solution for Unbounded Knapsack
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int ind, int capacity, vector<int>& val, vector<int>& wt) {
        if (ind == 0) {
            return (capacity / wt[0]) * val[0];
        }

        int notTake = solve(ind - 1, capacity, val, wt);
        int take = 0;
        if (wt[ind] <= capacity)
            take = val[ind] + solve(ind, capacity - wt[ind], val, wt);

        return max(take, notTake);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        return solve(n - 1, capacity, val, wt);
    }
};

int main() {
    Solution sol;
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;
    cout << "Max Value (Recursive): " << sol.knapSack(val, wt, capacity) << endl;
    return 0;
}
