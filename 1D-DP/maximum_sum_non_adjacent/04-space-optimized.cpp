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

    int prev=nums[0];

    int prev2=0;

    for(int i=1;i<n;i++){

        int pick=nums[i]+prev2;
        int not_pick=prev;

        int curr=max(pick,not_pick);

        prev2=prev;
        prev=curr;
    }

    cout << "The answer is :" << prev  <<endl;

    return 0;

}