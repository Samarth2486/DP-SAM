// 01 recursive solution for Frog jump
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int>& heights) {
    if (ind == 0) return 0;

    int left = solve(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = solve(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);

    return min(left, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin >> heights[i];

    cout << "Min energy (Recursive): " << solve(n - 1, heights) << endl;
    return 0;
}

