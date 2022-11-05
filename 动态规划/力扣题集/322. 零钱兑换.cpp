#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> Dp(amount + 1, amount + 1);
        Dp[amount] = 0;
        for(int i = amount; i > 0; i--)
        {
            if (Dp[i] == amount + 1)
            {
                continue;
            }
            
            for (auto it : coins)
            {
                if (i - it < 0)
                {
                    continue;  
                }
                else
                {
                    Dp[i-it] = min(Dp[i-it], Dp[i] + 1);
                }
            }
            
        }
        return Dp[0];
    }
};