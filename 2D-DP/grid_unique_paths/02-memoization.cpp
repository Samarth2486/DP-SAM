// 02 memoization solution for Grid unique paths
#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j,vector<vector<int>>&dp){
    if(i==0 && j==0) return 1;
    if(i<0 || j < 0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int left=solve(i,j-1,dp);
    int up=solve(i-1,j,dp);

    return dp[i][j]=up+left;
}
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(m-1,n-1,dp);
    
}

int main(){
    int m=3;
    int n=7;

    int answer=uniquePaths(m,n);

    cout << answer <<endl;

    return 0;
}
