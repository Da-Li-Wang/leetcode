#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> Dp(m, vector<int>(n));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    Dp[i][j] = 0;
                    if (i == 0 || j == 0)
                    {
                        Dp[i][j] = 1;
                    }
                    else
                    {
                        Dp[i][j] = min(min(Dp[i-1][j], Dp[i][j-1]), Dp[i-1][j-1]) + 1;
                    } 
                    ans = max(ans, Dp[i][j]);
                }
                    
            }
        } 
        return ans*ans;
    }
};

