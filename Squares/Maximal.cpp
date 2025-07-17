#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to compute largest rectangle area in histogram
    int area(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, width * height);
            }
            st.push(i);
        }

        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans, area(heights));
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int result = sol.maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << result << endl;

    return 0;
}