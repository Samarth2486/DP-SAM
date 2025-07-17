// 02 memoization solution for Frog jump k distances
#include<bits/stdc++.h>
using namespace std;

int solve(int ind, int k , vector<int>&dp , vector<int>&heights){
    if(ind==0) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int min_cost=INT_MAX;

    for(int j=1;j<=k;j++){
        if(ind-j>=0){

            int jump=solve(ind-j,k,dp,heights)+abs(heights[ind]-heights[ind-j]);

            min_cost=min(min_cost,jump);
            
        }
    }

    return dp[ind]=min_cost;


}

int main(){
    int n=6;
    int k=3;
    vector<int> heights = {10, 30, 40, 50, 20, 10};
    vector<int>dp(n,-1);
    int answer=solve(n-1,k,dp,heights);

    cout << "the minimum energy required is:" << answer <<endl;
    return 0;
}

