// 04 space optimized solution for Frog jump
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<int> heights = {10, 20, 30, 10};

    int prev = 0, prev2 = 0;
    for (int i = 1; i < n; i++) {
        int left = prev + abs(heights[i] - heights[i - 1]);
        int right = (i > 1) ? prev2 + abs(heights[i] - heights[i - 2]) : INT_MAX;
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }

    cout << "Space Optimized: Minimum energy = " << prev << endl;
    return 0;
}

