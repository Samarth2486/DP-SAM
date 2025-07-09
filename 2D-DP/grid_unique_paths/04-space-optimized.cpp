#include<bits/stdc++.h>
using namespace std;


int uniquePaths(int m, int n) {
    vector<int>prev(n,1);

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            prev[j] = prev[j] + prev[j - 1];
        }
    }
    return prev[n - 1];
    
}

int main(){
    int m=3;
    int n=7;

    int answer=uniquePaths(m,n);

    cout << answer <<endl;

    return 0;
}