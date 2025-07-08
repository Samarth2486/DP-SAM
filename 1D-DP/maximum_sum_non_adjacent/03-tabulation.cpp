// 03 tabulation solution for Maximum sum non adjacent
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=4;
    vector<int>nums={2,1,4,9};

    vector<int>dp(n,0);

    if(n==0){
        cout << "the answer is zero" <<endl;
        return 0;
    }

    dp[0]=nums[0];

    for(int i=1;i<n;i++){
        int pick=nums[i];

        if(i>1) pick+=dp[i-2];

        int not_pick=dp[i-1];

        dp[i]=max(pick,not_pick);
    }

    cout << "The answer is :" << dp[n-1]  <<endl;

    return 0;

}
