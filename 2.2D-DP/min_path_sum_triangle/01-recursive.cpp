// 01 recursive solution for Min path sum triangle
#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int j, int n, vector<vector<int>>& triangle) {
    if (i == n - 1) return triangle[i][j];
    int down = triangle[i][j] + solve(i + 1, j, n, triangle);
    int diagonal = triangle[i][j] + solve(i + 1, j + 1, n, triangle);
    return min(down, diagonal);
}

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    int n = triangle.size();
    cout << "Recursive: " << solve(0, 0, n, triangle) << endl;
    return 0;
}

