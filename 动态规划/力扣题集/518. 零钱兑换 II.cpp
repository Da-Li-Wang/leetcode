#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> Dp(amount + 1);
        for (auto it : coins)
        {
            Dp[it] = 1;
        }

        for (int i = 1; i < amount + 1; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                if (Dp[j] && Dp[i-j])
                {
                    Dp[i] += (Dp[j] * Dp[i - j]);
                }
            }
        }
        return Dp[amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> Dp(amount + 1);
        Dp[0] = 1;
        for (auto coin : coins)
        {
            for (int i = coin; i < amount + 1; i++)
            {
                Dp[i] += Dp[i - coin];
            }
        }
        return Dp[amount];
    }
};