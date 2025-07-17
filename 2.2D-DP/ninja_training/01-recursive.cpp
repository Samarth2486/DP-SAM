// 01 recursive solution for Ninja training
#include <bits/stdc++.h>
using namespace std;

int solve(int day, int last, vector<vector<int>>& points) {
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

    int maxi = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int temp1 = points[day][task] + solve(day - 1, task, points);
            maxi = max(maxi, temp1);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    // Write your code here.
    return solve(n - 1, 3, points);
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
