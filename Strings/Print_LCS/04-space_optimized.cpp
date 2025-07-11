// 04 Space_Optimized solution for 03 Print LCS DP 26
#include <bits/stdc++.h>
using namespace std;

int lcsLength(string &s1, string &s2) {
    int n = s1.length(), m = s2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return prev[m];
}

int main(){
    string s1 = "abcde", s2 = "ace";
    cout << "LCS length: " << lcsLength(s1, s2) << endl;  // Output: 3
    return 0;
}

