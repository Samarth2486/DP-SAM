// 02 memoization solution for Ninja training
#include <bits/stdc++.h>
using namespace std;

int solve(int day, int last, vector<vector<int>>& points,vector<vector<int>>&dp) {
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int temp = points[0][task];
                maxi = max(maxi, temp);
            }
        }
        return maxi;
    }

    if(dp[day][last]!=-1) return dp[day][last];

    int maxi = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int temp1 = points[day][task] + solve(day - 1, task, points,dp);
            maxi = max(maxi, temp1);
        }
    }
    return dp[day][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return solve(n - 1, 3, points,dp);
}

int main() {
    int n = 3;
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << "Maximum points: " << ninjaTraining(n, points) << endl;
    return 0;
}
