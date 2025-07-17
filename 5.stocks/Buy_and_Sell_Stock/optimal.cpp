//approach for DP-30 Best Time to Buy and Sell Stock
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int buy = prices[0];
        for (int i = 1; i < n; i++) {
            buy = min(buy, prices[i]);                 // update min price
            profit = max(profit, prices[i] - buy);     // update max profit
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input
    Solution sol;
    int result = sol.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}
