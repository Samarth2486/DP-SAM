// 01 recursive solution for Grid unique paths
// 02 memoization solution for Grid unique paths
#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j){
    if(i==0 && j==0) return 1;
    if(i<0 || j < 0) return 0;


    int left=solve(i,j-1);
    int up=solve(i-1,j);

    return up+left;
}
int uniquePaths(int m, int n) {
    return solve(m-1,n-1);
    
}

int main(){
    int m=3;
    int n=2;

    int answer=uniquePaths(m,n);

    cout << answer <<endl;

    return 0;
}

