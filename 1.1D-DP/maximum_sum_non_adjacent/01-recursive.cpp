// 01 recursive solution for Maximum sum non adjacent
#include <bits/stdc++.h> 
using namespace std;

int solve(int ind, vector<int>&nums){
    if(ind==0) return nums[ind];
    if(ind < 0) return 0;

    int pick=nums[ind]+solve(ind-2,nums);

    int not_pick=solve(ind-1,nums);

    return max(pick,not_pick);
}

int main(){

    int n=4;
    vector<int>nums={2,1,4,9};

    cout << "the answer is " << solve(n-1,nums) <<endl;

    return 0;
}

