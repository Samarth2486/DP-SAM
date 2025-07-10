#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0), curr(m, 0);

    // Initialize first row
    for (int j = 0; j < m; j++) {
        prev[j] = matrix[0][j];
    }

    // Build using only two rows
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = prev[j];
            int left_diag = (j > 0) ? prev[j - 1] : INT_MIN;
            int right_diag = (j < m - 1) ? prev[j + 1] : INT_MIN;

            curr[j] = matrix[i][j] + max({up, left_diag, right_diag});
        }
        prev = curr;
    }

    return *max_element(prev.begin(), prev.end());
}

int main() {
    vector<vector<int>> matrix = {
        {10, 10, 2, 0, 20, 4},
        {1, 0, 0, 30, 2, 5},
        {0, 10, 4, 0, 2, 0},
        {1, 0, 2, 20, 0, 4}
    };
    cout << "Space Optimized: " << getMaxPathSum(matrix) << endl;
    return 0;
}
