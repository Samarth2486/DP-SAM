// 04 Space Optimized solution for Rod Cutting Problem
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<int> dp(n + 1, 0);

        // Base case: fill with rod of length 1
        for (int len = 0; len <= n; len++)
            dp[len] = len * price[0];

        for (int ind = 1; ind < n; ind++) {
            for (int len = 0; len <= n; len++) {
                int notTake = dp[len];
                int take = 0;
                int rodLength = ind + 1;

                if (rodLength <= len)
                    take = price[ind] + dp[len - rodLength];

                dp[len] = max(take, notTake);
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Max Profit (Space Optimized): " << sol.cutRod(price) << endl;
    return 0;
}

