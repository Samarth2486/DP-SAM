// Recursive approach for DP-50 Minimum Cost to Cut the Stick
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int f(int i, int j, vector<int>& cuts) {
        if (i > j) return 0;

        int mini = INT_MAX;
        for (int k = i; k <= j; k++) {
            int cost = cuts[j+1] - cuts[i-1] + f(i, k - 1, cuts) + f(k + 1, j, cuts);
            mini = min(mini, cost);
        }
        return mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        return f(1, m, cuts);
    }
};

int main() {
    Solution sol;
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    cout << "Minimum cost: " << sol.minCost(n, cuts) << endl;
    return 0;
}
