// 01 Recursive solution for 08 Shortest Common Supersequence DP 31
#include <bits/stdc++.h>
using namespace std;

string scs(int i, int j, string &a, string &b) {
    if (i < 0) return b.substr(0, j + 1);
    if (j < 0) return a.substr(0, i + 1);

    if (a[i] == b[j])
        return scs(i - 1, j - 1, a, b) + a[i];
    else {
        string op1 = scs(i - 1, j, a, b) + a[i];
        string op2 = scs(i, j - 1, a, b) + b[j];
        return (op1.length() < op2.length()) ? op1 : op2;
    }
}

int main() {
    string str1 = "abac", str2 = "cab";
    cout << "SCS: " << scs(str1.size() - 1, str2.size() - 1, str1, str2) << endl;
    return 0;
}

