// 03 Tabulation solution for 03 Print LCS DP 26
#include <bits/stdc++.h>
using namespace std;

string findLCS(int n, int m, string &s1, string &s2){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the DP table
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct the LCS string
    int i = n, j = m;
    string lcs = "";
    while(i > 0 && j > 0){
        if(s1[i - 1] == s2[j - 1]){
            lcs += s1[i - 1];
            i--; j--;
        } else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main(){
    string s1 = "abcde", s2 = "ace";
    cout << findLCS(s1.size(), s2.size(), s1, s2) << endl;  // Output: ace
    return 0;
}

