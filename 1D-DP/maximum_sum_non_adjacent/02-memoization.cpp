// 02 memoization solution for Maximum sum non adjacent
#include <bits/stdc++.h> 
using namespace std;

int solve(int ind, vector<int>&nums,vector<int>&dp){
    if(ind==0) return nums[ind];
    if(ind < 0) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int pick=nums[ind]+solve(ind-2,nums,dp);

    int not_pick=solve(ind-1,nums,dp);

    return dp[ind]=max(pick,not_pick);
}

int main(){

    int n=4;
    vector<int>nums={2,1,4,9};

    vector<int>dp(n,-1);

    cout << "the answer is " << solve(n-1,nums,dp) <<endl;

    return 0;
}
