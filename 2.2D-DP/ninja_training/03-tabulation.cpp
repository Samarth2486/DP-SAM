// 03 tabulation solution for Ninja training
#include<bits/stdc++.h>
using namespace std;

int ninjaTraining(int n,vector<vector<int>>&points){
    vector<vector<int>>dp(n,vector<int>(4,0));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][1],points[0][0]);
    dp[0][3]=max({points[0][0],points[0][1],points[0][2]});

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int temp=points[day][task]+dp[day-1][task];
                    maxi=max(maxi,temp);
                }
            }
            dp[day][last]=maxi;
        }
    }

    return dp[n-1][3];

}
int main() {
    int n = 3;
    vector<vector<int>> points = {
        {17, 40, 80},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << "Maximum points: " << ninjaTraining(n, points) << endl;
    return 0;
}
