// 04 space optimized solution for House robber

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    int prev2=0;
    int prev=nums[0];
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1) take+=prev2;
        int not_take=prev;
        int curr=max(take,not_take);
        prev2=prev;
        prev=curr;
    }
    return prev;
    
}

int main() {
    // Example input
    vector<int> nums = {2, 7, 9, 3, 1};

    int maxRobbed = rob(nums);
    cout << "Maximum money the robber can steal: " << maxRobbed << endl;

    return 0;
}
