#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2)
        {
            return n;    
        }
        
        vector<int> Dp(n + 1);
        Dp[0] = 1, Dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            Dp[i] = Dp[i - 1] + Dp[i - 2];
        }
        return Dp[n];
    }
};