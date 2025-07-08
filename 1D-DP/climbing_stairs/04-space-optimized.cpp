// 04 space optimized solution for Climbing stairs
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    int prev = 1, prev2 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    cout << "Ways to climb " << n << " stairs: " << prev << endl;
    return 0;
}


