#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int begin = 0, ans = 1;
        vector<vector<int>> Dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            Dp[i][i] = 1;
        }
        
        for (int r = 1; r < n; r++)
        {
            for (int l = r-1; l < -1; l--)
            {
                if (s[l] == s[r] )
                {
                    if (r-l+1 >= 3)
                    {
                        int begin = l + 1, end = r - 1;
                        Dp[l][r] = Dp[begin][end] + 2;
                    }
                    else
                    {
                        Dp[l][r] = 2;
                    }
                }
                else
                {
                    Dp[l][r] = Dp[l+1][r];
                }
            }

        }
        return Dp[0][n-1];
    }
};


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            char c1 = s[i];
            for (int j = i + 1; j < n; j++) {
                char c2 = s[j];
                if (c1 == c2) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

