// 04 Space Optimized solution for Min Subset Sum Diff
#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    vector<bool> prev(totalSum + 1, false), curr(totalSum + 1, false);
    prev[0] = true;
    if (arr[0] <= totalSum) prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        curr = prev;
        for (int sum = 1; sum <= totalSum; sum++) {
            bool not_pick = prev[sum];
            bool pick = false;
            if (arr[i] <= sum)
                pick = prev[sum - arr[i]];
            curr[sum] = pick || not_pick;
        }
        prev = curr;
    }

    int minDiff = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (prev[s1]) {
            int s2 = totalSum - s1;
            minDiff = min(minDiff, abs(s2 - s1));
        }
    }
    return minDiff;
}

int main() {
    vector<int> arr = {1, 2, 3, 9};
    cout << "Minimum Subset Sum Difference: " << minSubsetSumDifference(arr) << endl;
    return 0;
}

