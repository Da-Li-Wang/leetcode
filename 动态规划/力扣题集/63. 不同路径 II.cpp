#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> Dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0])
            {
                break;
            }
            else
            {
                Dp[i][0] = 1;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i])
            {
                break;
            }
            else
            {
                Dp[0][i] = 1;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j])
                {
                    continue;
                }
                else
                {
                    Dp[i][j] = Dp[i-1][j] + Dp[i][j-1];
                }
            }
        }
        
        return Dp[m-1][n-1];
    }
};