#include <iostream>
#include <string>
#include <vector>

using namespace std;

//双重循环不写了

//动态规划 预处理目标字符串 适合多s1输入 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> Dp(n+1, vector<int>(26));

        for (int i = 0; i < 26; i++)
        {
            Dp[n][i] = n;
        }

        for (int i = n-1; i >= 0; i--)
        {
            for (int j = 0; j < 26; j++)
            {
                if (t[i] - 'a' == j)
                {
                    Dp[i][j] = i;
                }
                else
                {
                    Dp[i][j] = Dp[i+1][j];
                }
            }
        }
        
        int begin = 0;

        for (int i = 0; i < m; i++)
        {
            if (Dp[begin][s[i] - 'a'] == n)
            {
                return false;
            }
            else 
            {
                begin = Dp[begin][s[i] - 'a'] + 1;
            }
        }
        return true;   
    }
};