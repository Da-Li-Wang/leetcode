#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1)
        {
            return triangle[0][0];
        }
        
        vector<vector<int>> Dp(n);
        Dp[0] = triangle[0];
        for (int i = 1; i < n; i++)
        {
            Dp[i].resize(i+1);
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0)
                {
                    Dp[i][j] = Dp[i-1][j] + triangle[i][j];
                }
                else if (j == i)
                {
                    Dp[i][j] = Dp[i-1][j-1] + triangle[i][j];
                }
                else
                {
                    Dp[i][j] = min(Dp[i-1][j-1], Dp[i-1][j]) + triangle[i][j];
                }      
            }
        }
        int ans = INT_MAX;
        for (int it : Dp[n-1])
        {
            ans = min(ans, it);
        }
        return ans;
    }
};