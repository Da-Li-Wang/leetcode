#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();

        vector<vector<int>> Dp(m+1, vector<int>(n + 1));

        for (int i = 1; i < m+1; i++)
        {
            for (int j = 1; j < n+1; j++)
            {
                if (text1[i-1] == text2[j-1])
                {
                    Dp[i][j] = Dp[i-1][j-1] + 1;
                }
                else
                {
                    Dp[i][j] = max(Dp[i-1][j], Dp[i][j-1]);
                }
            }
        }
        return Dp[m][n];
    }
};