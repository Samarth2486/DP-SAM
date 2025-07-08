#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {
    int prev = nums[0], prev2 = 0;
    for (int i = 1; i < nums.size(); i++) {
        int take = nums[i] + prev2;
        int not_take = prev;
        int curr = max(take, not_take);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int rob(vector<int>& nums) {
    int n=nums.size();

    vector<int>temp1(nums.begin()+1,nums.end());
    vector<int>temp2(nums.begin(),nums.end()-1);

    return max(solve(temp1),solve(temp2));
}

int main() {
    vector<int> nums = {2, 3, 2,7,6,7};
    cout << "Max robbed = " << rob(nums) << endl;
    return 0;
}
