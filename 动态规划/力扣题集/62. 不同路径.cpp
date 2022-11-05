#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> Dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            Dp[0][i] = 1;
        }
        
        for (int i = 0; i < n; i++)
        {
            Dp[i][0] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                Dp[i][j] = Dp[i-1][j] + Dp[i][j-1];
            }
        }
        
        return Dp[m-1][n-1];
    }
};
//数学
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};

