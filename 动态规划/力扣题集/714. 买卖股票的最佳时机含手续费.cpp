#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> Dp(n, vector<int>(2));

        Dp[0][0] = 0, Dp[0][1] = -prices[0] - fee;

        for (int i = 1; i < n; i++)
        {
            Dp[i][0] = max(Dp[i-1][1] + prices[i], Dp[i][0]);
            Dp[i][1] = max(Dp[i-1][1], Dp[i-1][0] - prices[i] - fee);
        }
        return max(Dp[n-1][0], Dp[n-1][1]);
    }
};