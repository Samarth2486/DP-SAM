// 01 Recursive solution for Partition Equal Subset Sum
#include <bits/stdc++.h>
using namespace std;

bool solve1 (int ind , int target, vector<int>&nums){

    if(target==0) return true;

    if(ind==0) return nums[ind]==target;

    bool not_pick=solve1(ind-1,target,nums);
    bool pick=false;
    if(nums[ind]<=target){
        pick=solve1(ind-1,target-nums[ind],nums);
    }

    return pick || not_pick;

}

bool solve( vector<int>&nums, int target){
    if(target%2==1) return false;

    int sub_target=target/2;

    return solve1(nums.size()-1,sub_target,nums);


}

int main() {
    vector<int>nums={1,5,11,5};
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }

    cout << "can we partition:" << (solve(nums,sum)? "haan bhai" : "nahi bhai") <<endl;

    return 0;
}
