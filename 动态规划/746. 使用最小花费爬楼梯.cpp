#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size(); //共n阶台阶(算顶)
        vector<int> Dp(n+1);

        Dp[0] = 0, Dp[1] = 0;

        for (int i = 2; i < n; i++)
        {
            Dp[i] = min(Dp[i-1] + cost[i-1], Dp[i-2] + cost[i-2]);
        }
        
        return Dp[n];

    }
};
