// 01 recursive solution for Climbing stairs
#include <bits/stdc++.h>
using namespace std;

int countWays(int n) {
    if (n <= 1) return 1;
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Ways to climb " << n << " stairs: " << countWays(n) << endl;
    return 0;
}

