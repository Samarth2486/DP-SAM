// Recursive approach for DP-54 Partition Array for Maximum Sum
#include<bits/stdc++.h>
using namespace std;



class Solution{
    public:

    int sub(int i, int k,int n, vector<int>&arr){
        if(i==n) return 0;
        int final_ans=0;
        int maxi=INT_MIN;
        int count=0;
        for(int j=i;j<min(i+k,n);j++){
            count++;
            maxi=max(maxi,arr[j]);
            int sum=count*maxi+sub(j+1,k,n,arr);
            final_ans=max(final_ans,sum);
        }

        return final_ans;

    }


    int solve(vector<int>&arr, int k){
        int n=arr.size();
        return sub(0,k,n,arr);
    }


};

int main(){
    Solution sol;
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;

    cout << "the final answer is: " << sol.solve(arr,k) <<endl;
    return 0;

}
