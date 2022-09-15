#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> Dp(n + 1);
        Dp[0] = 1, Dp[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1 ; j >= 0; j--)
            {
                Dp[i] += (Dp[j] * Dp [i - j - 1]);
            }
        }
        return Dp[n];
    }
};