#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> Dp(n, vector<int>(2));
        if (n == 1)
        {
            return 0;
        }
        if (n == 2)
        {
            return (prices[1] - prices[0]) ? (prices[1] - prices[0]) : 0;
        }
        
        
        Dp[0][0] = 0, Dp[0][1] = -prices[0], Dp[1][0] = max(0, Dp[0][1] + prices[1]), Dp[1][1] = 0;

        for (int i = 2; i < n; ++i) {
            Dp[i][0] = max(Dp[i - 1][0], Dp[i - 1][1] + prices[i]);
            Dp[i][1] = max(Dp[i - 1][1], Dp[i - 2][0] - prices[i]);
        }
        return Dp[n - 1][0];
    }
};
