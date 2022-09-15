#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> Dp(m, vector<int>(n));
        Dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++)
        {
            Dp[i][0] += Dp[i-1][0];
        }

        for (int i = 1; i < n; i++)
        {
            Dp[0][i] += Dp[0][i-1];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Dp[i][j] = min(Dp[i-1][j], Dp[i][j-1]) + grid[i][j];
            }
            
        }
        return Dp[m-1][n-1];
    }
};