#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1)
        {
            return matrix[0][0];
        }
        
        vector<vector<int>> Dp(n);
        
        Dp[0] = matrix[0];

        for (int i = 1; i < n; i++)
        {
            Dp[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    Dp[i][j] == min(Dp[i-1][j], Dp[i-1][j+1])+ matrix[i][j];
                }
                else if (j == n-1)
                {
                    Dp[i][j] == min(Dp[i-1][j], Dp[i-1][j-1]) + matrix[i][j];
                }
                else
                {
                    Dp[i][j] == min(min(Dp[i-1][j], Dp[i-1][j-1]),Dp[i-1][j+1]) + matrix[i][j];
                }
            }
        }
        int ans = INT_MAX;
        for (auto it : Dp[n - 1])
        {
            ans = min(it, ans);
        }
        return ans;
    }
};