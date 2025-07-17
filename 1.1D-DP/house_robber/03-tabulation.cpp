// 03 tabulation solution for House robber
#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,-1);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1) take+=dp[i-2];
        int not_take=dp[i-1];

        dp[i]=max(take,not_take);
    }
    return dp[n-1];
    
}

int main() {
    // Example input
    vector<int> nums = {2, 7, 9, 3, 1};

    int maxRobbed = rob(nums);
    cout << "Maximum money the robber can steal: " << maxRobbed << endl;

    return 0;
}
