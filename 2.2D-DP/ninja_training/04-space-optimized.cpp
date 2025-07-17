#include<bits/stdc++.h>
using namespace std;

int ninjaTraining(int n,vector<vector<int>>&points){
    vector<int>prev(4,0);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][1],points[0][0]);
    prev[3]=max({points[0][0],points[0][1],points[0][2]});

    for(int day=1;day<n;day++){
        vector<int>curr(4,0);
        for(int last=0;last<4;last++){
            int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int temp=points[day][task]+prev[task];
                    maxi=max(maxi,temp);
                }
            }
            curr[last]=maxi;
        }
        prev=curr;
    }
    return prev[3];
}
int main() {
    int n = 3;
    vector<vector<int>> points = {
        {17, 40, 90},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << "Maximum points: " << ninjaTraining(n, points) << endl;
    return 0;
}
