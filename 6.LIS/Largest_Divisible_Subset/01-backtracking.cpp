// Recursive approach for DP-44 Largest Divisible Subset
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> result;

    void dfs(vector<int>& nums, int index, vector<int>& current) {
        if (current.size() > result.size())
            result = current;

        for (int i = index; i < nums.size(); ++i) {
            if (current.empty() || nums[i] % current.back() == 0) {
                current.push_back(nums[i]);
                dfs(nums, i + 1, current);
                current.pop_back();
            }
        }
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        dfs(nums, 0, current);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<int> res = sol.largestDivisibleSubset(nums);
    for (int num : res) cout << num << " ";
    return 0;
}
