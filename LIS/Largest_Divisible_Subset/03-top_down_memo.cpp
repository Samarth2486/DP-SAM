// Tabulation approach for DP-44 Largest Divisible Subset
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nums;
    vector<vector<vector<int>>> memo;

    vector<int> dfs(int prev, int curr) {
        if (curr == nums.size()) return {};

        if (!memo[prev + 1][curr].empty()) return memo[prev + 1][curr];

        vector<int> take, notTake = dfs(prev, curr + 1);

        if (prev == -1 || nums[curr] % nums[prev] == 0) {
            take = dfs(curr, curr + 1);
            take.insert(take.begin(), nums[curr]);
        }

        return memo[prev + 1][curr] = (take.size() > notTake.size() ? take : notTake);
    }

    vector<int> largestDivisibleSubset(vector<int>& input) {
        nums = input;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n));
        return dfs(-1, 0);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<int> res = sol.largestDivisibleSubset(nums);
    for (int num : res) cout << num << " ";
    return 0;
}
