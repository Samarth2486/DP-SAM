// 01 Recursive solution for Rod Cutting Problem
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int ind, int len, vector<int>& price) {
        if (ind == 0)
            return len * price[0];  // Take as many of length 1 as possible

        int notTake = solve(ind - 1, len, price);
        int take = 0;
        int rodLength = ind + 1;

        if (rodLength <= len)
            take = price[ind] + solve(ind, len - rodLength, price);

        return max(take, notTake);
    }

    int cutRod(vector<int>& price) {
        int n = price.size();
        return solve(n - 1, n, price);
    }
};

int main() {
    Solution sol;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Max Profit (Recursive): " << sol.cutRod(price) << endl;
    return 0;
}

